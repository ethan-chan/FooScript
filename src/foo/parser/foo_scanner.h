#pragma once



#if ! defined(yyFlexLexerOnce)
#include "FlexLexer.h"
#endif

#undef YY_NULL
#define  YY_NULL nullptr

#include "parser.h"
#include <sstream>

# define YY_DECL \
  FooScript::Parser::FooParser::symbol_type \
    FooScript::Parser::FooScanner::yylex (FooScript::Parser::FooDriver& driver)
// ... and declare it for the parser's sake.
//YY_DECL;

namespace FooScript{
    namespace Parser{
        class FooScanner : public yyFlexLexer{
        public:
            typedef FooScript::Parser::FooParser::symbol_type tSymbol;
            typedef FooScript::Parser::FooParser::semantic_type tSemantic;
            FooScanner() : yyFlexLexer(&ss) {}

            void PushString(const std::string& CmdString);

            // find function body in lexer.cpp (YY_DECL)
            virtual tSymbol yylex(
                FooDriver& Driver);

            virtual void yyrestart() {
                yyFlexLexer::yyrestart(&ss);
            }

            virtual void yyrestart(std::istream* ss) {
                yyFlexLexer::yyrestart(ss);
            }

        private:
            FooScript::Parser::location loc;
            std::stringstream ss;
        };
    }
}