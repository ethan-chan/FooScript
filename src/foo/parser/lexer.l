%{
 
/*
 * Lexer.l file
 * To generate the lexical analyzer run: "flex Lexer.l"
 */
#include "foo_scanner.h"

typedef FooScript::Parser::FooParser FooParser; 

/* define yyterminate as this instead of NULL */
#define yyterminate() return FooParser::make_TOKEN_END(loc);

/* track locations accurately */
#define YY_USER_ACTION  loc.columns(yyleng);

%}
 
%option outfile="lexer.cpp" header-file="lexer.h"

/* enable scanner to generate debug output. disable this for release
 * versions. */
%option debug

%option nodefault

/* the manual says "somewhat more optimized" */
/* %option batch */

/* enable c++ scanner class generation */
%option c++

/* Maintaine the line number*/
%option yylineno

WS          [ \r\n\t]*
ID          [a-zA-Z_][a-zA-Z_0-9]*
DIGIT        [0-9]
HEX            [0-9A-Fa-f]
 
FLOAT_CONST                ([0-9]*\.[0-9]+)|([0-9]+\.)
FLOAT_EXP                [eE][-+]?[0-9]+
FLOAT_SUFFIX            [fFlL]


STRING_1                '([^']|\\.)*'
STRING_2                 \"([^"]|\\.)*\"

%%

%{
    // reset location
    // loc.step();
%}

"class"             { return FooParser::make_TOKEN_CLASS(loc); }
"<<"                { return FooParser::make_TOKEN_SHL(loc); }
">>"                { return FooParser::make_TOKEN_SHR(loc); }
"=="                { return FooParser::make_TOKEN_EQ(loc); }
"!="                { return FooParser::make_TOKEN_NE(loc); }
"<="                { return FooParser::make_TOKEN_LE(loc); }
">="                { return FooParser::make_TOKEN_GE(loc); }
"&&"                { return FooParser::make_TOKEN_LOG_AND(loc); }
"||"                { return FooParser::make_TOKEN_LOG_OR(loc); }
"++"                { return FooParser::make_TOKEN_INC(loc); }
"--"                { return FooParser::make_TOKEN_DEC(loc); }
".*"                { return FooParser::make_TOKEN_DOT_STAR(loc); }
"+="                { return FooParser::make_TOKEN_ADD_EQ(loc); }
"-="                { return FooParser::make_TOKEN_SUB_EQ(loc); }
"*="                { return FooParser::make_TOKEN_MUL_EQ(loc); }
"/="                { return FooParser::make_TOKEN_DIV_EQ(loc); }
"%="                { return FooParser::make_TOKEN_MOD_EQ(loc); }
"^="                { return FooParser::make_TOKEN_XOR_EQ(loc); }
"&="                { return FooParser::make_TOKEN_AND_EQ(loc); }
"|="                { return FooParser::make_TOKEN_OR_EQ(loc); }
">>="               { return FooParser::make_TOKEN_SHR_EQ(loc); }
"<<="               { return FooParser::make_TOKEN_SHL_EQ(loc); }
                    
{ID}                  { return FooParser::make_TOKEN_ID(yytext,loc); }
{DIGIT}+              { return FooParser::make_TOKEN_INT(std::atoi(yytext),loc); }
{FLOAT_CONST}{FLOAT_EXP}?{FLOAT_SUFFIX}?    { return FooParser::make_TOKEN_FLOAT(std::atof(yytext),loc); }
{DIGIT}+{FLOAT_EXP}{FLOAT_SUFFIX}?            { return FooParser::make_TOKEN_FLOAT(std::atof(yytext),loc); }
{STRING_1}                                  { return FooParser::make_TOKEN_STRING(yytext,loc); }
{STRING_2}                                  { return FooParser::make_TOKEN_STRING(yytext,loc); }

"!"                    { return FooParser::make_TOKEN_CMD_QUIT(loc); }

\n                    { loc.lines(yyleng); loc.step(); }
{WS}+                { loc.step(); }
.                   { return FooParser::symbol_type(static_cast<FooParser::token_type>(*yytext),loc); }

<<EOF>>             { return FooParser::make_TOKEN_END(loc); }

%%

#ifdef yylex
#undef yylex
#endif

int yyFlexLexer::yylex()
{
    std::cerr << "in ExampleFlexLexer::yylex() !" << std::endl;
    return 0;
}

int yyFlexLexer::yywrap(void){
    return 1;
}