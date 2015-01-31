#pragma once

#include <map>
#include <string>
#include <vector>
#include <array>
#include "syntax\def.h"

namespace FooScript {
    class FooCmdSystem;
    namespace Parser {

        enum class eInstr : unsigned int {
            I_NULL = 0,
            I_ADD,
            I_MUL,
            I_MIN,
            I_DIV,
            I_MOD,
            I_ASSIGN,
            I_CLASS,
            I_CLASS_END,
            I_CLASS_CALL_WITHOUT_ARG,
            I_CLASS_CALL_START,
            I_CLASS_CALL_END,
            I_CLASS_ARGU_CLAUSE,
            I_CLASS_SET_PARA_CLAUSE,
            I_CLASS_COMPLETE_CALLBACK,
            I_MEMBER,
            I_CONTEXT_MEMBER
        };

        static const unsigned int MaxRegCount = 6;

        typedef unsigned int    tIndex;
        typedef tIndex          tRegIndex;
        typedef tIndex          tConstIndex;
        typedef tIndex          tMemIndex;
        typedef tIndex          tStackIndex;

        static const unsigned int FlagValIndexReg = 0x80000000;
        static const unsigned int FlagValIndexRegRet = 0x80000000;


        static const unsigned int FlagValIndexConst = 0x40000000;
        static const unsigned int FlagValIndexVar = 0x20000000;
        static const unsigned int FlagValIndexMem = 0x10000000;

        static const unsigned int ValueLevelPart = 0xF000000;
        static const unsigned int ValueLevelSHL = 24;
        static const unsigned int ValueIndexPart = 0xFFFFFF;
        static const unsigned int max_param_count = 0xFFFFFFFF;

        static const unsigned int MemFromContext = 0x100000;

        class FooVM final {
        private:
            typedef unsigned int         tInsCursor;
        public:
            class tStaticClass;
            typedef std::shared_ptr<tStaticClass>   tSClassSPtr;

            // 静态类，保存类的静态数据部分
            class tStaticClass : public std::enable_shared_from_this<tStaticClass> {
            private:
                typedef std::map<tToken, tStackIndex>    tLocals;
            public:
                tStaticClass(
                    const tToken& Name, 
                    tSClassSPtr& ParentClsss, 
                    tInsCursor StartCursor);
                virtual ~tStaticClass();

                tStaticClass(tStaticClass const&) = delete;
                tStaticClass& operator=(tStaticClass const&) = delete;
            public:
                tStackIndex     GetLocalIndex(const tToken& Token);
               
                tSClassSPtr GetParent() const { return parent; }
                tIndex          GetLocalSlotCount() const { return stack_top; }

                tToken GetName() const {
                    return name;
                }

                tInsCursor GetStartCursor() const {
                    return start_cursor;
                }

                tInsCursor GetEndCursor() const {
                    return end_cursor;
                }

                tIndex GetTupleParamCount() const {
                    return tupple_param_count;
                }

                void SetEndCursor(tInsCursor EndCursor) {
                    end_cursor = EndCursor;
                }

                bool IsInterClass() const {
                    return start_cursor == 0;
                }

                void IncParamCount() { tupple_param_count++; }

                void SetInfiniteParams() {
                    tupple_param_count = max_param_count;
                }
            private:
                bool            GetLocalIndex(const tToken& Token, tStackIndex& Index) const;
            private:
                tToken              name;
                // 当前局部变量的名字个数上限
                tStackIndex         stack_top;
                // 当前静态类在词法结构中的层级
                tIndex              level;
                // 当前静态类中定义的局部变量的名字及对应的索引
                tLocals             local_value_index_map;
                tSClassSPtr         parent;
                tInsCursor          start_cursor;
                tInsCursor          end_cursor;
                tIndex              tupple_param_count;
            };

        private:
            typedef unsigned int         tRegIndex;

            // 实现 foo 中的类
            // 类是也是值对象
            class tContext;
            typedef std::shared_ptr<tContext> tContextSPtr;

            class tClass : public Type::ValueObject {
                friend FooVM;
            public:
                tClass(tSClassSPtr& StaticClass, tContextSPtr& ParentContext) :
                    Type::ValueObject(Type::objectValue),
                    static_class(StaticClass),
                    parent_context(ParentContext)
                    {};
                tClass(tClass const&) = delete;
                tClass& operator=(tClass const&) = delete;

            public:
                virtual void Execute(tContextSPtr& context) {}
            protected:
                tToken GetName() const {
                    return static_class->GetName();
                }

                tInsCursor GetStartCursor() const {
                    return static_class->GetStartCursor();
                }

                tInsCursor GetEndCursor() const {
                    return static_class->GetEndCursor();
                }

                tIndex  GetTupleParamCount() const{
                    return static_class->GetTupleParamCount();
                }

                bool IsInterClass() const {
                    //return static_class->IsInterClass();
                    return GetStartCursor() == 0;
                }

                tContextSPtr GetParentContext() {
                    return  parent_context;
                }

                void SetInfiniteParams() {
                    static_class->SetInfiniteParams();
                }
            private:
                tSClassSPtr     static_class;
                tContextSPtr    parent_context;
            };

            typedef std::shared_ptr<tClass> tClassSPtr;

            class tInterClass : public tClass, public std::enable_shared_from_this<tInterClass> {
                using tClass::tClass;
            public:
                virtual void Execute(tContextSPtr& context) = 0;
            };
            typedef std::shared_ptr<tInterClass> tInterClassSPtr;

            class print : public tInterClass {
                using tInterClass::tInterClass;
            public:
                print(FooCmdSystem& Fcs, tSClassSPtr& StaticClass, tContextSPtr& ParentContext) :
                    fcs(Fcs), tInterClass(StaticClass, ParentContext) {
                    SetInfiniteParams();
                }
            public:
                virtual void Execute(tContextSPtr& context);
            protected:
                FooCmdSystem&                            fcs;
            };

            class IF : public tInterClass {
                using tInterClass::tInterClass;
                class ELSE : public tInterClass {
                public:
                    ELSE(FooCmdSystem& Fcs, tSClassSPtr& StaticClass, tContextSPtr& ParentContext) :
                        fcs(Fcs), tInterClass(StaticClass, ParentContext) {
                    }
                    virtual void Execute(tContextSPtr& context) {

                    }
                    protected:
                        FooCmdSystem&                            fcs;
                };
            public:
                IF(FooCmdSystem& Fcs, tSClassSPtr& StaticClass, tContextSPtr& ParentContext) :
                    fcs(Fcs), tInterClass(StaticClass, ParentContext) {
                    _else_static_class = tSClassSPtr(new tStaticClass("else", StaticClass, 0));
                }
            public:
                virtual void Execute(tContextSPtr& context);
            protected:
                FooCmdSystem&                            fcs;
                tSClassSPtr                              _else_static_class;
            };

            // 类执行后，生成的上下文对象，上下文与类共同组成了闭包
            // 上下文在每个类执行前创建
            class tContext : public Type::ValueObject, public std::enable_shared_from_this<tContext> {
                friend FooVM; // 访问 GetLocal
                friend tInterClass; // 访问 GetLocal 
            public:
                 explicit tContext(tClassSPtr& Class) :
                    Type::ValueObject(Type::objectValue),
                    prev_context(nullptr),
                    cur_class(Class),
                    return_cursor(0) {
                }
                tContext(
                    tClassSPtr& Class, 
                    tContextSPtr& PrevContext) : 
                    Type::ValueObject(Type::objectValue),
                    prev_context(PrevContext),
                    cur_class(Class),
                    return_cursor(0) {
                }
                tContext(tContext const&) = delete;
                tContext& operator=(tContext const&) = delete;
            public:
                void Execute() {
                    cur_class->Execute(shared_from_this());
                }

                void SetReturnValue(Type::tValueSPtr& Ret) {
                    return_value = Ret;
                }
            protected:
                tToken GetName() const {
                    return cur_class->GetName();
                }

                tInsCursor GetStartCursor() const {
                    return cur_class->GetStartCursor();
                }

                bool IsInterClass() const {
                    //return static_class->IsInterClass();
                    return GetStartCursor() == 0;
                }

                tContextSPtr GetParentContext() {
                    return  cur_class->GetParentContext();
                }

                tContextSPtr GetPrevContext() {
                    return  prev_context;
                }

                // 通过索引获取局部变量
                // 如不存在，则创建一个空值对象
                Type::ValueObject& GetLocal(tIndex Index) {
                    tIndex Level = (Index & ValueLevelPart) >> ValueLevelSHL;
                    tIndex Pos = Index & ValueIndexPart;

                    tContextSPtr CurContext = shared_from_this();
                    tIndex CurLevel = 0;
                    while (CurLevel < Level) {
                        CurContext = CurContext->GetParentContext();
                        CurLevel++;
                    }
                    Type::ValueObject& Value = CurContext->FindLocal(Pos);
                    // 如果不存在，则创建一个
                    /*
                    if (nullptr == ValueSPtr) {
                        auto NewValuePstr = Type::tValueSPtr(new Type::ValueObject(Type::nullValue));
                        variable_stack[Pos] = NewValuePstr;
                        return variable_stack[Pos];
                    }
                    */
                    return Value;
                }

                void SetLocal(tIndex Index, Type::tValueSPtr& ValueSPtr) {
                    tIndex Level = (Index & ValueLevelPart) >> ValueLevelSHL;
                    tIndex Pos = Index & ValueIndexPart;

                    tContextSPtr CurContext = shared_from_this();
                    tIndex CurLevel = 0;
                    while (CurLevel < Level) {
                        CurContext = CurContext->GetParentContext();
                        CurLevel++;
                    }
                    CurContext->SetLocalByPos(Pos, ValueSPtr);
                }

                void SetLocalByPos(tIndex Pos, Type::tValueSPtr& ValueSPtr) {
                    Enlarge(Pos);
                    variable_stack[Pos] = ValueSPtr;
                }

                Type::ValueObject& FindLocal(tIndex Index) {
                    Enlarge(Index);
                    return variable_stack[Index];
                }

                // 压入固定存在的局部变量
                // 用于初始化内部（由虚拟机提供）局部变量
                void PushInterLocal(Type::tValueSPtr& ValueSPtr) {
                    variable_stack.push_back(ValueSPtr);
                }
                // 设置参数其实也是设置局部变量
                // 区别就是参数是顺序最先设置，所以不用 resize
                // 传入参数如果超出上限，则丢弃超出部分
                void PushArg(Type::ValueObject& Value) {
                    if (variable_stack.size() < GetTupleParamCount() )
                        variable_stack.push_back(Value);
                }

                tIndex GetLocalSlotCount() const { return variable_stack.size(); }

                tIndex GetTupleParamCount() const { return cur_class->GetTupleParamCount(); }

                void SetReturnCursor(tInsCursor ReturnCursor) {
                    return_cursor = ReturnCursor;
                }
                tInsCursor GetReturnCursor() const {
                    return return_cursor;
                }

                Type::tValueSPtr GetReturnValue() const {
                    return return_value;
                }
            private:
                void Enlarge(tIndex Pos) {
                    if (Pos + 1 > GetLocalSlotCount()) {
                        variable_stack.resize(Pos + 1);
                    }
                }
            private:
                // 变量
                std::vector<Type::ValueObject>          variable_stack;
                tContextSPtr                            prev_context;
                tClassSPtr                              cur_class;
                tInsCursor                              return_cursor;
                Type::tValueSPtr                        return_value;
            };

            class tDebugInstr {
            public:
                tDebugInstr() {}
                tDebugInstr(const tCmdString& InstrName, tIndex Count) :
                    instr_name(InstrName), argu_ret_count(Count) {

                }
                tCmdString      GetName() const { return instr_name; }
                tIndex          GetSlotCount() const { return argu_ret_count; }
            private:
                tCmdString      instr_name;
                tIndex          argu_ret_count;
            };
        public:
            explicit FooVM(FooCmdSystem& Fcs);
            virtual ~FooVM();
        public:

            void Execute();
            void Reset();
            void DebugExecuteByStepInto();

            bool IsInMutual() const { return is_in_mutual; }

            tSClassSPtr GetTopSClass() const;
            tSClassSPtr CreateSClass(
                const tToken& Name,
                tSClassSPtr& Parent, 
                tIndex& SClassIndex);
            
            tIndex GetCurrentInstrCount() const { return instr_stream.size(); }

            void PushInstr(eInstr Instr);
            /*
            void PushInstr(eInstr Instr, tIndex Arg1);
            void PushInstr(eInstr Instr, tIndex Arg1, tIndex Arg2);
            void PushInstr(eInstr Instr, tIndex Arg1, tIndex Arg2, tIndex Arg3);
            */
            void PushData(tIndex Data);

            void PushRet(tIndex Ret);

            bool IsMemberIndex(tIndex Index) const {
                return (Index & FlagValIndexMem) != 0;
            }

            bool IsMemberFromContext(tIndex Index) const {
                return (Index & MemFromContext) != 0;
            }

            tIndex IncMemberIndex(tIndex Index) const {
                return ++Index;
            }

            tIndex GetMemberLevel(tIndex Index) const {
                return Index & (~(FlagValIndexMem | MemFromContext));
            }

            template <typename T>
            tConstIndex GetConstIndex(const T& v) {
                const_value_stack.push_back(Type::tValueSPtr(new Type::ValueObject(v)));
                tIndex Index = ((const_value_stack_top++) | FlagValIndexConst);
                return Index;
            }

            tRegIndex GetEmptyRegIndex() {
                if (MaxRegCount <= cur_reg) {
                    cur_reg = 0;
                }
                return (cur_reg++) | FlagValIndexReg;
            }

            tMemIndex GetMemberIndex(bool AccessContext) {
                if (AccessContext) {
                    return FlagValIndexMem | MemFromContext + 1;
                }
                else {
                    return FlagValIndexMem + 2;
                }
            }

            void ListStream() const;
            void EnterMutualMode();

        private:
            void InitVolatile();

            void ExecuteByStep();
            template <typename T>
            void RegisterInterClass() {
                // 获取类名
                std::string Name(typeid(T).name());
                Name = Name.substr(Name.rfind(':') + 1);
                std::transform(Name.begin(), Name.end(), Name.begin(), ::tolower);

                // 注册变量
                auto Index = global_static_class->GetLocalIndex(Name);
                auto SClassSPtr = tSClassSPtr(new tStaticClass(Name, global_static_class));
                auto ValueSPtr = std::static_pointer_cast<
                    Type::ValueObject>(std::shared_ptr<T>(new T(fcs, SClassSPtr, global_context)));
                global_context->PushInterLocal(ValueSPtr);
            }

            tIndex           FetchIndex();
            Type::tValueSPtr FetchValuePtr();
            Type::tValueSPtr& FetchRet();
            Type::tValueSPtr& FetchClassRet();
            Type::ValueObject& FetchArgRef();
            Type::ValueObject& FetchValRefByIndex(tIndex Index) const;
            Type::ValueObject& FetchMemRefByIndex(tIndex Index) const;

            void SetClassRetReg(tContextSPtr& Context);

            tSClassSPtr GetSClassByIndex(tIndex Index) const;

            template<class _Pr>
            void ExecuteArith(_Pr& Pred);
            void ExecuteArithDiv();
            void ExecuteArithMod();

            void ExecuteStateAssgin();
            void ExecuteStateClass();
            void ExecuteStateClassEnd();

            void ExecuteClassCallWithoutArg();
            void ExecuteClassCallStart();
            void ExecuteClassCallEnd();
            void ExecuteClassCall(tContextSPtr& Context);
            void ExecuteClassContextEnter(tContextSPtr& Context);
            void ExecuteClassContextExit(tContextSPtr& Context);

            void ExecuteClassArguClause();
            void ExecuteClassSetParaClause();

            void ExecuteClassCompleteCallback();

            void ExecuteMemberAccess();
            void ExecuteContextMemberAccess();

            void MoveToNextInstr();
            tIndex GetCurInstr() const ;
            void JumpToInstr(tInsCursor Cursor);
            tInsCursor GetCurInstrCursor() const;

            tContextSPtr GetCurrentContext() const { return cur_context; }
            void EnterContext(tContextSPtr& ContextSPtr) { cur_context = ContextSPtr; }

            // Debug
            void RegisterDbgInstr(eInstr Instr, const tCmdString& Name, tIndex ArguAndRetCount);

            struct DbgInstrZeroSlot {};
            struct DbgInstrOneSlot {};
            struct DbgInstrTwoSlot {};
            struct DbgInstrThreeSlot {};
            struct DbgInstrFourSlot {};

            tInsCursor DebugPrintInstr(tInsCursor Cursor, bool IsInExecute) const;
            tCmdString GetStoreName(tIndex Index) const;
            tCmdString GetValue(tIndex Index) const;
            void ExitMutualMode() { is_in_mutual = false; }
        private:
            FooCmdSystem&                            fcs;
            // 是否在交互模式
            bool                                    is_in_mutual;
            // 静态类数组，用于创建类对象时，通过索引获得静态对象
            std::vector<tSClassSPtr>                static_class_array;

            // 全局常量
            std::vector<Type::tValueSPtr>           const_value_stack;
            tConstIndex                             const_value_stack_top;
            // 寄存器
            std::array<Type::tValueSPtr,MaxRegCount>    regs;
            tRegIndex                                   cur_reg;
            
            // 指令流
            std::vector<unsigned int>               instr_stream;
            tInsCursor                              cur_is_index;

            tContextSPtr                            cur_context;

            // 类调用表达式嵌套栈
            std::stack<tContextSPtr>                class_call_exp_stack;

            // global
            tSClassSPtr                             global_static_class;
            tClassSPtr                              global_class;
            tContextSPtr                            global_context;

            // 调试
            std::map<eInstr, tDebugInstr>           debug_instrs;
        };
    }
}