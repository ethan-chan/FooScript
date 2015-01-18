#pragma once

#include <stack>
#include <vector>

#include "syntax\def.h"
#include "foo_scanner.h"
#include "vm\foo_vm.h"

namespace FooScript{
    class FooCmdSystem;
    namespace Parser{

        class FooDriver final{
            friend FooParser;    // access protected member scanner
        public:
            typedef FooScript::Parser::FooParser::semantic_type tSemantic;
        protected:

            typedef std::stack<FooVM::tSClassSPtr>         tStaticClassStack;

        public:
            FooDriver(FooCmdSystem& Fcs);
            virtual ~FooDriver() {}
            // delete
            FooDriver() = delete;
            FooDriver(FooDriver const&) = delete;
            FooDriver& operator=(FooDriver const&) = delete;

        public:
            void Execute(const tCmdString& CmdString);

            void Reset();
            
            // 提供给 FooParser
            void PumpElemID(const tToken& Token);
            
            void PumpLiterString(const std::string& v);
            void PumpLiterInt(FooScript::Type::tInt v);
            void PumpLiterFloat(double v);

            void PumpStateAssign();
            void PumpStateClass(const tToken& Token);
            void PumpStateClassDefStart();
            void PumpStateClassDefEnd();
            void PumpStateClassEnd();

            void PumpStateClassCallStart();
            void PumpStateClassCallEnd();
            void PumpStateClassCallWithoutArg();

            void PumpClassArguClause();
            void PumpClassParaClause();
            void PumpClassParaSetClause();

            void PumpExpMember(const tToken& Token);
            void PumpExpContextMember(const tToken& Token);
            void PumpExpContextStaticMember(const tToken& Token);

            void PumpExpAdd();
            void PumpExpMul();
            void PumpExpMin();
            void PumpExpDiv();
            void PumpExpMod();

            // 用于调试
            void ExitFooMode();
            void ListStream() const;
            void EnterMutualMode();
            void DebugExecuteByStepInto();
        private:
            void Init();

            void DealOneArgExp(Parser::eInstr Instr);
            void DealTwoArgExp(Parser::eInstr Instr);

            void VMPushInstr(eInstr Instr);
            void VMPushOneArgInstr(eInstr Instr);
            void VMPushTwoArgInstr(eInstr Instr);
            void VMPushRet(tRegIndex Index);
            void VMPushData(tIndex Index);

            void TransValueExp();

            void Parse(const tCmdString& CmdString);

        protected:
            FooScanner scanner;

        private:
            FooCmdSystem&        fcs;
            FooParser           parser;

            // bison 返回的逆波兰式
            std::stack<tStackIndex>                 exp_value_stack;
            // 解析过程中用到的嵌套 Class
            tStaticClassStack                       static_class_stack;
            // 解析过程中用到的嵌套函数调用
            //std::stack<tStackIndex>                 fun_call_stack;
            // 虚拟机
            FooVM                                   vm;
        };
    }
}