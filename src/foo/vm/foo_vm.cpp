#include "stdafx.h"
#include "foo_vm.h"
#include "cmd_system.h"

#include <algorithm>

using namespace FooBase;
using namespace FooScript;
using Parser::FooVM;
using Parser::tIndex;

FooVM::tStaticClass::tStaticClass(
    const tToken& Name,
    FooVM::tSClassSPtr& ParentClsss,
    FooVM::tInsCursor StartCursor = 0) :
    name(Name),
    stack_top(0),
    level(0),
    parent(ParentClsss),
    start_cursor(StartCursor),
    end_cursor(0),
    tupple_param_count(0) {

}

FooVM::tStaticClass::~tStaticClass() {

}

Parser::tStackIndex FooVM::tStaticClass::GetLocalIndex(const tToken& Token) {
    auto Context = shared_from_this();
    bool FindIt = false;
    Parser::tStackIndex Index;
    // Level 代表了向上查找的层数
    Parser::tIndex  Level = 0;
    while (Context) {
        FindIt = Context->GetLocalIndex(Token, Index);
        if (FindIt) {
            break;
        }
        Level++;
        Context = Context->GetParent();
    }
    // 未找到，在当前 tContext 定义
    if (!FindIt) {
        Index = stack_top | FlagValIndexVar;
        local_value_index_map[Token] = Index;
        ++stack_top;
        Level = 0;
    }
    Index = (Index & (~ValueLevelPart)) | (Level << ValueLevelSHL);
    return Index;
}

bool FooVM::tStaticClass::GetLocalIndex(const tToken& Token, Parser::tStackIndex& Index) const {
    auto it = local_value_index_map.find(Token);
    if (local_value_index_map.end() == it) {
        return false;
    }
    else {
        Index = it->second;
        return true;
    }
}

FooVM::FooVM(FooCmdSystem& Fcs) : fcs(Fcs)
{
    // 初始化寄存器
    for (auto i = 0; i < MaxRegCount; i++) {
        regs[i] = Type::tValueSPtr(new Type::ValueObject());
    }

    // 初始化命令字符串
    RegisterDbgInstr(eInstr::I_NULL, "I_NULL", 0);
    RegisterDbgInstr(eInstr::I_ADD, "I_ADD", 3);
    RegisterDbgInstr(eInstr::I_MUL, "I_MUL", 3);
    RegisterDbgInstr(eInstr::I_MIN, "I_MIN", 3);
    RegisterDbgInstr(eInstr::I_DIV, "I_DIV", 3);
    RegisterDbgInstr(eInstr::I_MOD, "I_MOD", 3);
    RegisterDbgInstr(eInstr::I_ASSIGN, "I_ASSIGN", 2);
    RegisterDbgInstr(eInstr::I_CLASS, "I_CLASS", 2);
    RegisterDbgInstr(eInstr::I_CLASS_END, "I_CLASS_END", 0);
    RegisterDbgInstr(eInstr::I_CLASS_CALL_WITHOUT_ARG, "I_CLASS_CALL_WITHOUT_ARG", 1);
    RegisterDbgInstr(eInstr::I_CLASS_CALL_START, "I_CLASS_CALL_START", 1);
    RegisterDbgInstr(eInstr::I_CLASS_CALL_END, "I_CLASS_CALL_END", 0);
    RegisterDbgInstr(eInstr::I_CLASS_ARGU_CLAUSE, "I_CLASS_ARGU_CLAUSE", 1);
    RegisterDbgInstr(eInstr::I_CLASS_SET_PARA_CLAUSE, "I_CLASS_SET_PARA_CLAUSE", 2);
    RegisterDbgInstr(eInstr::I_CLASS_COMPLETE_CALLBACK, "I_CLASS_COMPLATE_CALLBACK", 1);
    RegisterDbgInstr(eInstr::I_MEMBER, "I_MEMBER", 2);
    RegisterDbgInstr(eInstr::I_CONTEXT_MEMBER, "I_CONTEXT_MEMBER", 1);


    InitVolatile();
}

FooVM::~FooVM() {

}   

void FooVM::Execute() {
    auto Size = instr_stream.size();
    while (cur_is_index < Size) {
        ExecuteByStep();
    }
}

void FooVM::Reset() {
    // 清空资源
    static_class_array.clear();
    const_value_stack.clear();
    instr_stream.clear();

    while (class_call_exp_stack.empty() == false) {
        class_call_exp_stack.pop();
    }

    // 重新初始化
    InitVolatile();
}

FooVM::tSClassSPtr FooVM::GetTopSClass() const {
    return global_static_class;
}

FooVM::tSClassSPtr FooVM::CreateSClass(
    const tToken& Name,
    tSClassSPtr& Parent, 
    tIndex& SClassIndex) {
    auto StaticClass = tSClassSPtr(new 
        tStaticClass(Name, Parent, 
        Name == "" ? instr_stream.size() + 2 : instr_stream.size() + 3));
    static_class_array.push_back(StaticClass);
    SClassIndex = static_class_array.size() - 1;
    return StaticClass;
}

void FooVM::PushInstr(Parser::eInstr Instr) {
    PushData(static_cast<int>(Instr));
}

/*
void FooVM::PushInstr(Parser::eInstr Instr, tIndex Arg1) {
    PushData(static_cast<int>(Instr));
    PushData(Arg1);
}

void FooVM::PushInstr(Parser::eInstr Instr, tIndex Arg1, tIndex Arg2) {
    PushData(static_cast<int>(Instr));
    PushData(Arg1);
    PushData(Arg2);
}

void FooVM::PushInstr(Parser::eInstr Instr, tIndex Arg1, tIndex Arg2, tIndex Arg3) {

}
*/

void FooVM::PushData(tIndex Data) {
    instr_stream.push_back(Data);
}

void FooVM::PushRet(tIndex Ret) {
    PushData(Ret);
}

void FooVM::InitVolatile() {
    is_in_mutual = false;
    const_value_stack_top = 0;
    cur_reg = 0;
    cur_is_index = 0;

    // 初始全局静态类
    tIndex TempIndex = 0;
    global_static_class = CreateSClass("global", tSClassSPtr(nullptr), TempIndex);
    global_class = tClassSPtr(new tClass(global_static_class, tContextSPtr(nullptr)));
    global_context = tContextSPtr(new tContext(global_class));
    EnterContext(global_context);

    RegisterInterClass<print>();
    RegisterInterClass<IF>();
}

void FooVM::ExecuteByStep() {
    auto CurInstr = static_cast<eInstr>(GetCurInstr());
    MoveToNextInstr();
    switch (CurInstr)
    {
    case eInstr::I_MUL:
        ExecuteArith(std::multiplies<double>());
        break;
    case eInstr::I_ADD:
        ExecuteArith(std::plus<double>());
        break;
    case eInstr::I_MIN:
        ExecuteArith(std::minus<double>());
        break;
    case eInstr::I_DIV:
        ExecuteArithDiv();
        break;
    case eInstr::I_MOD:
        ExecuteArithMod();
        break;
        // statement
    case eInstr::I_ASSIGN:
        ExecuteStateAssgin();
        break;
    case eInstr::I_CLASS:
        ExecuteStateClass();
        break;
    case eInstr::I_CLASS_END:
        ExecuteStateClassEnd();
        break;
    case eInstr::I_CLASS_CALL_WITHOUT_ARG:
        ExecuteClassCallWithoutArg();
        break;
    case eInstr::I_CLASS_CALL_START:
        ExecuteClassCallStart();
        break;
    case eInstr::I_CLASS_CALL_END:
        ExecuteClassCallEnd();
        break;
    case eInstr::I_CLASS_ARGU_CLAUSE:
        ExecuteClassArguClause();
        break;
    case eInstr::I_CLASS_SET_PARA_CLAUSE:
        ExecuteClassSetParaClause();
        break;
    case eInstr::I_CLASS_COMPLETE_CALLBACK:
        ExecuteClassCompleteCallback();
        break;
    case eInstr::I_MEMBER:
        ExecuteMemberAccess();
        break;
    case eInstr::I_CONTEXT_MEMBER:
        ExecuteContextMemberAccess();
        break;
    default:
        throw std::runtime_error("VM error: Invalid instruction(1).");
        break;
    }
}

tIndex FooVM::FetchIndex() {
    auto Index = GetCurInstr();
    MoveToNextInstr();
    return Index;
}


Type::tValueSPtr FooVM::FetchValuePtr() {
    auto& Arg = FetchArgRef();
    if (Arg.isObject()) {
        return Arg.asObjectSPtr();
    }
    else {
        throw std::runtime_error("Not a class.");
    }
}

Type::tValueSPtr& FooVM::FetchRet() {
    auto Index = FetchIndex() & ValueIndexPart;
    return regs[Index];
}

Type::tValueSPtr& FooVM::FetchClassRet() {
    return regs[FlagValIndexRegRet & ValueIndexPart];
}
/*
Type::tValueSPtr& FooVM::FetchValByIndex(tIndex Index) {
    auto Pos = Index & ValueIndexPart;

    if (Index & FlagValIndexReg) {
        // 寄存器
        return regs[Pos];
    }
    else if (Index & FlagValIndexConst) {
        // 常量
        return const_value_stack[Pos];
    }
    else if (Index & FlagValIndexVar) {
        // 变量
        auto CurContext = GetCurrentContext();
        return CurContext->GetLocal(Index);
    }
    else {
        throw std::runtime_error("Invalid value Index.");
    }
}
*/

Type::ValueObject& FooVM::FetchArgRef() {
    auto Index = FetchIndex();
    if (Index & FlagValIndexMem) {
        // 如果值索引表明当前值为一个某个对象成员的引用
        auto& Value = FetchMemRefByIndex(Index);
        JumpToInstr(GetCurInstrCursor() + GetMemberLevel(Index));
        return Value;
    }
    else {
        return FetchValRefByIndex(Index);
    }
}

Type::ValueObject& FooVM::FetchValRefByIndex(tIndex Index) const {
    auto Pos = Index & ValueIndexPart;

    if (Index & FlagValIndexReg) {
        // 寄存器
        return *regs[Pos];
    }
    else if (Index & FlagValIndexConst) {
        // 常量
        return *const_value_stack[Pos];
    }
    else if (Index & FlagValIndexVar) {
        // 变量
        auto CurContext = GetCurrentContext();
        return CurContext->GetLocal(Index);
    }
    else {
        throw std::runtime_error("Invalid value Index.");
    }
}

Type::ValueObject& FooVM::FetchMemRefByIndex(tIndex Index) const {
    // Pos 代表递归成员变量访问时，当前层索引
    auto Pos = GetMemberLevel(Index) - 1;
    auto CurCursor = GetCurInstrCursor();

    Type::ValueObject* pTop = nullptr;
    if (IsMemberFromContext(Index)) {
        // 从当前上下文开始递归
        // .a.b.c
        pTop = GetCurrentContext().get();
    }
    else {
        // 从某个对象开始递归
        // a.b.c
        pTop = &FetchValRefByIndex(instr_stream[CurCursor + Pos]);
        Pos--;
    }
    while (true) {
        auto& Child = FetchValRefByIndex(instr_stream[CurCursor + Pos]);
        auto& Top = pTop->operator[](Child.asString());
        if (Pos == 0) {
            return Top;
        }
        if (Top.isObject()) {
            pTop = Top.asObjectSPtr().get();
        }
        else {
            pTop = &Top;
        }
        Pos--;
    }
}

FooVM::tSClassSPtr FooVM::GetSClassByIndex(tIndex Index) const {
    return static_class_array[Index];
}   

template<class _Pr>
void FooVM::ExecuteArith(_Pr& Pred) {
    auto& right = FetchArgRef();
    auto& left = FetchArgRef();
    auto Ret = FetchRet();
    Type::tFloat fRet;
    Type::tInt nRet;
    if (left.type() == Type::ValueType::realValue) {
        if (right.type() == Type::ValueType::realValue) {
            fRet = Pred(left.asDouble(), right.asDouble());
        }
        else {
            fRet = Pred(left.asDouble(), static_cast<Type::tFloat>(right.asInt64()));
        }
        *Ret = fRet;
    }
    else {
        if (right.type() == Type::ValueType::realValue) {
            fRet = Pred(static_cast<Type::tFloat>(left.asInt64()), right.asDouble());
            *Ret = fRet;
        }
        else {
            nRet = static_cast<Type::tInt>(Pred(
                static_cast<Type::tFloat>(left.asInt64()),
                static_cast<Type::tFloat>(right.asInt64())));
            *Ret = nRet;
        }
    }
}

void FooVM::ExecuteArithDiv() {
    auto& right = FetchArgRef();
    auto& left = FetchArgRef();
    auto Ret = FetchRet();
    Type::tInt nRet;
    auto v = std::div(left.asInt64(), right.asInt64());
    nRet = v.quot;
    *Ret = nRet;
}

void FooVM::ExecuteArithMod() {
    auto& right = FetchArgRef();
    auto& left = FetchArgRef();
    auto Ret = FetchRet();
    Type::tInt nRet;
    auto v = std::div(left.asInt64(), right.asInt64());
    nRet = v.rem;
    *Ret = nRet;
}

void FooVM::ExecuteStateAssgin() {
    // 此处不能使用引用
    auto right = FetchArgRef();
    auto& left_ref = FetchArgRef();
    //auto CurContext = GetCurrentContext();
    //CurContext->SetLocal(Index, Arg2);
    left_ref = right;
}

void FooVM::ExecuteStateClass() {
    //auto CurClass = tClassSPtr(new tClass(global_static_class));
    auto& CurObject = FetchArgRef();
    // 获取静态类索引
    auto CurSClassIndex = FetchIndex();

    auto CurSClass = GetSClassByIndex(CurSClassIndex);
    auto CurContext = GetCurrentContext();
    auto CurClass = tClassSPtr(new tClass(CurSClass, CurContext));
    auto CurObjectPtr = std::static_pointer_cast<Type::ValueObject>(CurClass);
    CurObject = Type::ValueObject(CurObjectPtr);
    JumpToInstr(CurClass->GetEndCursor());
}

void FooVM::ExecuteStateClassEnd() {
    auto CurContext = GetCurrentContext();
    auto& Ret = FetchClassRet();
    auto ValuePtr = std::static_pointer_cast<Type::ValueObject>(CurContext);
    auto ValueObjectPtr = Type::tValueSPtr(new Type::ValueObject(ValuePtr));
    Ret = ValueObjectPtr;

    ExecuteClassContextExit(CurContext);
}

void FooVM::ExecuteClassCallWithoutArg() {
    // 当前类
    auto CurValueSPtr = FetchValuePtr();
    // 保存上下文对象
    auto PrevContext = GetCurrentContext();
    auto CurClassSPtr = std::dynamic_pointer_cast<tClass>(CurValueSPtr);
    auto CurContext = tContextSPtr(new tContext(CurClassSPtr, PrevContext));
    ExecuteClassContextEnter(CurContext);
    ExecuteClassCall(CurContext);
}

void FooVM::ExecuteClassCallStart() {
    auto CurValueSPtr = FetchValuePtr();
    auto PrevContext = GetCurrentContext();
    auto CurClassSPtr = std::dynamic_pointer_cast<tClass>(CurValueSPtr);
    auto CurContext = tContextSPtr(new tContext(CurClassSPtr, PrevContext));
    class_call_exp_stack.push(CurContext);
}

void FooVM::ExecuteClassCallEnd() {
    // 获得类表达式顶层子嵌套，然后将其弹出
    auto CurContext = class_call_exp_stack.top();
    class_call_exp_stack.pop();

    ExecuteClassContextEnter(CurContext);
    ExecuteClassCall(CurContext);
}

void FooVM::ExecuteClassCall(tContextSPtr& Context) {
    if (Context->IsInterClass()) {
        Context->Execute();
        // 内部类直接执行成完
        ExecuteClassContextExit(Context);
    }
    else {
        auto ClassStartCursor = Context->GetStartCursor();
        JumpToInstr(ClassStartCursor);
    }
}

void FooVM::ExecuteClassContextEnter(tContextSPtr& Context) {
    // 设置返回地址
    Context->SetReturnCursor(GetCurInstrCursor());
    // 压入执行栈，准备执行
    EnterContext(Context);
}

void FooVM::ExecuteClassContextExit(tContextSPtr& Context) {
    auto ReturnCursor = Context->GetReturnCursor();
    JumpToInstr(ReturnCursor);
    auto CurContext = GetCurrentContext();
    auto PrevContext = CurContext->GetPrevContext();
    EnterContext(PrevContext);
}

void FooVM::ExecuteClassArguClause() {
    auto Arg = FetchArgRef();
    auto ContextCalled = class_call_exp_stack.top();
    ContextCalled->PushArg(Arg);
}

void FooVM::ExecuteClassSetParaClause() {
    auto& Right = FetchArgRef();
    auto& Left = FetchArgRef();
    // 默认参数只有在目标值为空时才进行设置
    if (Left.isNull())
        Left = Right;
}

void FooVM::ExecuteClassCompleteCallback() {
    // 获取静态类索引
    auto CurSClassIndex = FetchIndex();

    // 创建类对象，并跳至类结尾
    auto CurSClass = GetSClassByIndex(CurSClassIndex);
    auto PrevContext = GetCurrentContext();
    auto CurClass = tClassSPtr(new tClass(CurSClass, PrevContext));
    auto CurObjectPtr = std::static_pointer_cast<Type::ValueObject>(CurClass);
    JumpToInstr(CurClass->GetEndCursor());

    // 创建上下文对象
    auto CurContext = tContextSPtr(new tContext(CurClass, PrevContext));
    // 进入上下文
    ExecuteClassContextEnter(CurContext);
    // 开始执行
    ExecuteClassCall(CurContext);
}

void FooVM::ExecuteMemberAccess() {
    auto& Parent = FetchValuePtr();
    auto ChildIndex = FetchIndex();
    // 延迟取值
    //auto& Ret = FetchArg();
}

void FooVM::ExecuteContextMemberAccess() {
    auto ChildIndex = FetchIndex();
    auto ChildName = FetchValRefByIndex(ChildIndex).asString();
    auto CurContext = GetCurrentContext();
    // 延迟取值
    //auto& Ret = FetchArg();
}

void FooVM::MoveToNextInstr() {
    cur_is_index++;
}

tIndex FooVM::GetCurInstr() const {
    return instr_stream[GetCurInstrCursor()];
}

void FooVM::JumpToInstr(tInsCursor Cursor) {
    cur_is_index = Cursor;
}

FooVM::tInsCursor FooVM::GetCurInstrCursor() const {
    return cur_is_index;
}

void FooVM::RegisterDbgInstr(Parser::eInstr Instr, const tCmdString& Name, tIndex ArguAndRetCount) {
    tDebugInstr InstrObj(Name, ArguAndRetCount);
    debug_instrs[Instr] = InstrObj;
}

FooVM::tInsCursor FooVM::DebugPrintInstr(tInsCursor Cursor, bool IsInExecute) const {
    auto CurInstr = static_cast<const eInstr>(instr_stream[Cursor]);
    auto& InstrObj = debug_instrs.find(CurInstr)->second;
    auto Name = InstrObj.GetName();
    // 获取参数与返回值的总个数
    auto SlotCount = InstrObj.GetSlotCount();
    if (Cursor == GetCurInstrCursor()) {
        fcs.LOG_DEBUG() << "--";
        auto Context = GetCurrentContext();
        while (Context) {
            fcs.LOG_DEBUG() << "<" << Context->GetName();
            Context = Context->GetParentContext();
        }
        fcs.LOG_DEBUG() << FooBase::Log::FooLogEnd;
    }
    fcs.LOG_DEBUG()
        << std::setfill('0') << std::setw(4) << Cursor << " "
        << std::setw(8)
        << std::hex
        << static_cast<int>(CurInstr) << " " << Name << FooBase::Log::FooLogEnd;
    Cursor++;
    for (auto i = 0; i < SlotCount; i++) {
        auto Index = instr_stream[Cursor];
        fcs.LOG_DEBUG()
            << std::setfill('0') << std::setw(4) << Cursor << " "
            << std::setw(8)
            << std::hex
            << Index << " "
            << GetStoreName(Index) << " ";
        if (IsInExecute)
            fcs.LOG_DEBUG()
            << GetValue(Index);

        fcs.LOG_DEBUG() << FooBase::Log::FooLogEnd;
        Cursor++;
        if (IsMemberIndex(Index)) {
            auto Count = GetMemberLevel(Index);
            Cursor += Count;
        }
    }
    return Cursor;
}

tCmdString FooVM::GetStoreName(tIndex Index) const {
    if (Index & FlagValIndexReg) {
        // 寄存器
        return "reg   ";
    }
    else if (Index & FlagValIndexConst) {
        // 常量
        return "const ";
    }
    else if (Index & FlagValIndexVar) {
        // 变量
        return "var   ";
    }
    else if(Index & FlagValIndexMem) {
        return "member";
    }
    else {
        return "";
    }
}


tCmdString FooVM::GetValue(tIndex Index) const {
    if (Index <= FlagValIndexMem) return "";
    if (IsMemberIndex(Index)) {
        auto& Value = FetchMemRefByIndex(Index);
        return Value.ToString();
    }
    else {
        auto& Value = FetchValRefByIndex(Index);
        return Value.ToString();
    }

}
void FooVM::ListStream() const {
    auto Size = instr_stream.size();
    tInsCursor Cursor = 0;
    while (Cursor < Size) {
        Cursor = DebugPrintInstr(Cursor, false);
    }
}

void FooVM::EnterMutualMode() {
    is_in_mutual = true;
}

void FooVM::DebugExecuteByStepInto() {
    auto PreCursor = GetCurInstrCursor();
    ExecuteByStep();
    DebugPrintInstr(PreCursor, true);
}


// Internal function
void FooVM::print::Execute(tContextSPtr& context) {
    auto Len = context->GetLocalSlotCount();
    auto& Log = fcs.LOG_DATA();
    for (auto i = 0; i < Len; i++) {
        if (i != 0) {
            Log << " ";
        }
        Log << context->GetLocal(i).ToString();
    }
    Log << FooBase::Log::FooLogEnd;
}

void FooVM::IF::Execute(tContextSPtr& context) {
}