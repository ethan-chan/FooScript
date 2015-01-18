///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   reg_parser.h
//  Version     :   1.0
//  Author      :   Chenyizhan
//  Date        :   2014.03.24
//  Comment     :   Óï·¨½âÎöÆ÷
//
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <functional>
#include <stack>

#include "syntax\def.h"

namespace FooScript{
    class FooCmdSystem;
    namespace Parser{

        class FooDriver;

        class RegParser final{
        public:
            typedef std::function<void(const tCmdString&)> HandlerType;
            typedef std::map<tToken, HandlerType> tKeyHandler;
            typedef std::map<tToken, HandlerType> tMacroHandler;


            enum tOpType{
                op_type_undef = 0,
                op_type_lv,
                op_type_ls,
                op_type_lm,
                op_type_dv,
                op_type_dm
            };

            struct TestNode {
                wchar_t type[100];
                wchar_t name[10];
                wchar_t detail[100];
            };
        public:
            RegParser(FooCmdSystem& Fcs, FooDriver& Fd);
            ~RegParser();

            // delete
            RegParser() = delete;
            RegParser(RegParser const&) = delete;
            RegParser& operator=(RegParser const&) = delete;

            void Execute(const tCmdString& CmdString);
        protected:
            void RegisterFunction(const tToken& Cmd, const HandlerType& KeyFunc);

            void _foo(const tCmdString& CmdString);
            void _foo_block(const tCmdString& CmdString);

            void _list_value(const tCmdString& CmdString);
            void _list_stream(const tCmdString& CmdString);
            void _list_member(const tCmdString& CmdString);
            void _step_over(const tCmdString& CmdString);
            void _step_into(const tCmdString& CmdString);

            void _test(const tCmdString& CmdString);

            void CleanOutputDir(const std::wstring& Dir);

            void StartCase(const std::wstring& CasePath);

            void ExecuteTokenString(
                const tCmdString::const_iterator&    begin,
                const tCmdString::const_iterator&    end);

            tCmdString::const_iterator SkipSpace(
                const tCmdString::const_iterator& begin,
                const tCmdString::const_iterator& end
                ) const;

        private:
            // parse
            tKeyHandler                        khs;
            // compile
            std::wstring                    _test_input_dir;
            std::wstring                    _test_output_dir;

            FooCmdSystem&                    fcs;
            FooDriver&                      fd;
        };
        const char key_start_foo[] = "!";
        const char key_start_foo_block[] = "!!";

        const char key_lv[] = "lv";
        const char key_ls[] = "ls";
        const char key_lm[] = "lm";
        const char key_p[]  = "p";
        const char key_t[] = "t";
        const char key_test[] = "test";
    }
}