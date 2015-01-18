%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.0"

%debug 

%output  "parser.cpp"
%defines "parser.h"


%language "c++"
%define api.namespace { FooScript::Parser }
%define parser_class_name { FooParser } 
%define api.token.constructor
%define api.value.type variant
%define parse.assert
%locations
 
//%define api.pure  // we use c++

%code requires {
#include "syntax\def.h"
namespace FooScript{
    namespace Parser{ 
        class FooScanner;  
        class FooDriver; 
    }
}
}

// The parsing context.
// %param { FooScript::Parser::FooScanner  &scanner  }
 %param { FooScript::Parser::FooDriver  &driver  }
//%parse-param { FooScript::Parser::FooDriver  &driver }

%code{
#include "foo_driver.h"
#undef yylex
#define yylex driver.scanner.yylex
}

%token TOKEN_END 0 

%token <std::string> TOKEN_ID

%token <FooScript::Type::tInt>    TOKEN_INT
%token <double> TOKEN_FLOAT
%token <char>   TOKEN_CHAR
%token <std::string> TOKEN_STRING

%token TOKEN_CLASS

%token TOKEN_SHL                        // "<<"    
%token TOKEN_SHR                        // ">>"    
%token TOKEN_EQ                         // "=="    
%token TOKEN_NE                         // "!="    
%token TOKEN_LE                         // "<="    
%token TOKEN_GE                         // ">="    
%token TOKEN_LOG_AND                    // "&&"    
%token TOKEN_LOG_OR                     // "||"    
%token TOKEN_INC                        // "++"    
%token TOKEN_DEC                        // "--"    
%token TOKEN_DOT_STAR                   // ".*"    
%token TOKEN_ADD_EQ;                    // "+="    
%token TOKEN_SUB_EQ;                    // "-="    
%token TOKEN_MUL_EQ;                    // "*="    
%token TOKEN_DIV_EQ;                    // "/="    
%token TOKEN_MOD_EQ;                    // "%="    
%token TOKEN_XOR_EQ;                    // "^="    
%token TOKEN_AND_EQ;                    // "&="    
%token TOKEN_OR_EQ;                     // "|="    
%token TOKEN_SHR_EQ;                    // ">>="    
%token TOKEN_SHL_EQ;                    // "<<="    

%token TOKEN_CMD_QUIT                   // "!"

%type <std::string> identifier


%start translation_unit
 
%%

/*----------------------------------------------------------------------
 * Lexical elements.
 *----------------------------------------------------------------------*/
identifier
    : TOKEN_ID          { $$ = $1; driver.PumpElemID($1); }
    ;

literal
    : integer_literal   
    | floating_literal   
    | string_literal   
    ;

integer_literal
    : TOKEN_INT         { driver.PumpLiterInt($1); }
    ;

floating_literal
    : TOKEN_FLOAT       { driver.PumpLiterFloat($1); }
    ;

string_literal
    : TOKEN_STRING      { driver.PumpLiterString($1); }

/*----------------------------------------------------------------------
 * Translation unit.
 *----------------------------------------------------------------------*/

translation_unit
    : TOKEN_END
    | statement_seq TOKEN_END
    | command_seq
    ;

/*----------------------------------------------------------------------
 * Expressions.
 *----------------------------------------------------------------------*/     
primary_expression
    : literal
    | '(' expression ')'
    | identifier
    ;

postfix_expression
    : primary_expression
    | postfix_expression '[' expression ']'             {}
    | postfix_call
    | '.' TOKEN_ID                                      { driver.PumpExpContextMember($2); }
    | '$''.' TOKEN_ID                                   { driver.PumpExpContextStaticMember($3); }
    | postfix_expression '.' TOKEN_ID                   { driver.PumpExpMember($3); }
    | postfix_expression TOKEN_INC                      {}
    | postfix_expression TOKEN_DEC                      {}
    ;

postfix_call
    : postfix_expression '(' ')' postfix_call_post_callback_opt                 { driver.PumpStateClassCallWithoutArg(); }
    | postfix_call_start postfix_call_end        {}
    ;

postfix_call_start
    : postfix_expression '('                     { driver.PumpStateClassCallStart(); }
    ;
postfix_call_end
    :  function_argu_clause_list ')' postfix_call_post_callback_opt             { driver.PumpStateClassCallEnd(); }
    ;

/*
postfix_call_pre_callback_opt
    : ':' statement_seq.opt '#'
    ;
*/
postfix_call_post_callback_opt
    :
    | ':' statement_seq.opt '#'
    ;

unary_expression
    : postfix_expression
    ;

multiplicative_expression
    : unary_expression
    | multiplicative_expression '*' unary_expression    { driver.PumpExpMul(); }
    | multiplicative_expression '/' unary_expression    { driver.PumpExpDiv(); }
    | multiplicative_expression '%' unary_expression    { driver.PumpExpMod(); }
    ;

additive_expression
    : multiplicative_expression
    | additive_expression '+' multiplicative_expression     { driver.PumpExpAdd(); }
    | additive_expression '-' multiplicative_expression     { driver.PumpExpMin(); }
    ;

shift_expression
    : additive_expression
    | shift_expression TOKEN_SHL additive_expression     {}
    | shift_expression TOKEN_SHR additive_expression     {}
    ;

relational_expression
    : shift_expression
    | relational_expression '<' shift_expression            {}
    | relational_expression '>' shift_expression            {}
    | relational_expression TOKEN_LE shift_expression       {}
    | relational_expression TOKEN_GE shift_expression       {}
    ;

equality_expression
    : relational_expression
    | equality_expression TOKEN_EQ relational_expression    {}
    | equality_expression TOKEN_NE relational_expression    {}
    ;

and_expression
    : equality_expression
    | and_expression '&' equality_expression                {}
    ;

exclusive_or_expression
    : and_expression
    | exclusive_or_expression '^' and_expression            {}
    ;

inclusive_or_expression
    : exclusive_or_expression
    | inclusive_or_expression '|' exclusive_or_expression   {}
    ;

logical_and_expression
    : inclusive_or_expression
    | logical_and_expression TOKEN_LOG_AND inclusive_or_expression             {}
    ;

logical_or_expression
    : logical_and_expression
    | logical_or_expression TOKEN_LOG_OR logical_and_expression                {}
    ;

/*  与函数前置、后置回调冲突
conditional_expression
    : logical_or_expression
    | logical_or_expression  '?' expression ':' assignment_expression          {}
    ;
*/

assignment_expression
    : logical_or_expression
    | assignment_left assignment_right          { driver.PumpStateAssign(); }
    ;

assignment_left
    : logical_or_expression
    ;
assignment_right
    : assignment_operator assignment_expression
    ;
assignment_operator
    : '='                    {}
    | TOKEN_MUL_EQ           {}
    | TOKEN_DIV_EQ           {}
    | TOKEN_MOD_EQ           {}
    | TOKEN_ADD_EQ           {}
    | TOKEN_SUB_EQ           {}
    | TOKEN_SHR_EQ           {}
    | TOKEN_SHL_EQ           {}
    | TOKEN_AND_EQ           {}
    | TOKEN_XOR_EQ           {}
    | TOKEN_OR_EQ            {}
    ;

expression
    : assignment_expression 
    | expression_list ',' assignment_expression       
    ; 

expression_list:
    assignment_expression
    | expression_list ',' assignment_expression
    ;

//expression_list_opt:
//    /* epsilon */
//    | expression_list                               
//    ;
/*----------------------------------------------------------------------
 * Statements.
 *----------------------------------------------------------------------*/
statement
    : expression_statement
    | function_definition
    ;

expression_statement
    : ';'
    | expression ';'
    ;

/*
compound_statement
    : ':' statement_seq.opt '#'
    ;
*/

statement_seq.opt
    :  /**/
    | statement_seq
    ;
statement_seq
    : statement
    | statement_seq statement
    ;

/*----------------------------------------------------------------------
 * Commands.
 *----------------------------------------------------------------------*/
command_seq
    : TOKEN_CMD_QUIT { driver.ExitFooMode(); }
    ;
/*----------------------------------------------------------------------
 * Declarators.
 *----------------------------------------------------------------------*/
function_definition
    : function_head function_body       { driver.PumpStateClassEnd(); }     
    ;

function_head
    : function_id function_def_opt            
    ;

function_id
    : TOKEN_CLASS identifier                       { driver.PumpStateClass($2); }
    ;
function_def_opt
    :
    | '(' ')'                 { }
    | function_def_Start function_def_end        {}
    ;

function_def_Start
    : '('                     { driver.PumpStateClassDefStart(); }
    ;
function_def_end
    :  function_param_clause_list ')'                       { driver.PumpStateClassDefEnd(); }
    ;

function_param_clause_list
    : function_param_clause                                  
    | function_param_clause_list ',' function_param_clause    
    ;

function_param_clause
    : function_param_clause_core                            
    ; 
                                                        
function_param_clause_core
    : identifier                                            { driver.PumpClassParaClause(); }
    | identifier '=' assignment_expression                  { driver.PumpClassParaSetClause(); }
    ;

function_body
    : ':' statement_seq.opt '#'
    ;

function_argu_clause_list
    : function_argu_clause                                  
    | function_argu_clause_list ',' function_argu_clause    
    ;

function_argu_clause
    : assignment_expression                            { driver.PumpClassArguClause(); }
    ; 
                                                       
%%

 void FooScript::Parser::FooParser::error(const location_type& l,
                          const std::string& m)
{
    std::cout << "Location: " << l << std::endl;
    std::cout << "Error: " << m << std::endl;
}