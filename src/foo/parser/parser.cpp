// A Bison parser, made by GNU Bison 3.0.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2013 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "parser.cpp" // lalr1.cc:398

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

#include "parser.h"

// User implementation prologue.

#line 51 "parser.cpp" // lalr1.cc:406
// Unqualified %code blocks.
#line 35 "parser.y" // lalr1.cc:407

#include "foo_driver.h"
#undef yylex
#define yylex driver.scanner.yylex

#line 59 "parser.cpp" // lalr1.cc:407


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyempty = true)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 11 "parser.y" // lalr1.cc:473
namespace  FooScript { namespace Parser  {
#line 145 "parser.cpp" // lalr1.cc:473

  /// Build a parser object.
   FooParser :: FooParser  (FooScript::Parser::FooDriver  &driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {}

   FooParser ::~ FooParser  ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  inline
   FooParser ::by_state::by_state ()
    : state (empty)
  {}

  inline
   FooParser ::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
   FooParser ::by_state::move (by_state& that)
  {
    state = that.state;
    that.state = empty;
  }

  inline
   FooParser ::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
   FooParser ::symbol_number_type
   FooParser ::by_state::type_get () const
  {
    return state == empty ? 0 : yystos_[state];
  }

  inline
   FooParser ::stack_symbol_type::stack_symbol_type ()
  {}


  inline
   FooParser ::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
      switch (that.type_get ())
    {
      case 4: // TOKEN_INT
        value.move< FooScript::Type::tInt > (that.value);
        break;

      case 6: // TOKEN_CHAR
        value.move< char > (that.value);
        break;

      case 5: // TOKEN_FLOAT
        value.move< double > (that.value);
        break;

      case 3: // TOKEN_ID
      case 7: // TOKEN_STRING
      case 53: // identifier
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty;
  }

  inline
   FooParser ::stack_symbol_type&
   FooParser ::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 4: // TOKEN_INT
        value.copy< FooScript::Type::tInt > (that.value);
        break;

      case 6: // TOKEN_CHAR
        value.copy< char > (that.value);
        break;

      case 5: // TOKEN_FLOAT
        value.copy< double > (that.value);
        break;

      case 3: // TOKEN_ID
      case 7: // TOKEN_STRING
      case 53: // identifier
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
   FooParser ::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
   FooParser ::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
   FooParser ::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
   FooParser ::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
   FooParser ::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
   FooParser ::debug_stream () const
  {
    return *yycdebug_;
  }

  void
   FooParser ::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


   FooParser ::debug_level_type
   FooParser ::debug_level () const
  {
    return yydebug_;
  }

  void
   FooParser ::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline  FooParser ::state_type
   FooParser ::yy_lr_goto_state_ (state_type yystate, int yylhs)
  {
    int yyr = yypgoto_[yylhs - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yylhs - yyntokens_];
  }

  inline bool
   FooParser ::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
   FooParser ::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
   FooParser ::parse ()
  {
    /// Whether yyla contains a lookahead.
    bool yyempty = true;

    // State.
    int yyn;
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// $$ and @$.
    stack_symbol_type yylhs;

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULL, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyempty)
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            symbol_type yylookahead (yylex (driver));
            yyla.move (yylookahead);
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
        yyempty = false;
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Discard the token being shifted.
    yyempty = true;

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
    /* Variants are always initialized to an empty instance of the
       correct type. The default $$=$1 action is NOT applied when using
       variants.  */
      switch (yyr1_[yyn])
    {
      case 4: // TOKEN_INT
        yylhs.value.build< FooScript::Type::tInt > ();
        break;

      case 6: // TOKEN_CHAR
        yylhs.value.build< char > ();
        break;

      case 5: // TOKEN_FLOAT
        yylhs.value.build< double > ();
        break;

      case 3: // TOKEN_ID
      case 7: // TOKEN_STRING
      case 53: // identifier
        yylhs.value.build< std::string > ();
        break;

      default:
        break;
    }


    // Compute the default @$.
    {
      slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
      YYLLOC_DEFAULT (yylhs.location, slice, yylen);
    }

    // Perform the reduction.
    YY_REDUCE_PRINT (yyn);
    try
      {
        switch (yyn)
          {
  case 2:
#line 87 "parser.y" // lalr1.cc:846
    { yylhs.value.as< std::string > () = yystack_[0].value.as< std::string > (); driver.PumpElemID(yystack_[0].value.as< std::string > ()); }
#line 529 "parser.cpp" // lalr1.cc:846
    break;

  case 6:
#line 97 "parser.y" // lalr1.cc:846
    { driver.PumpLiterInt(yystack_[0].value.as< FooScript::Type::tInt > ()); }
#line 535 "parser.cpp" // lalr1.cc:846
    break;

  case 7:
#line 101 "parser.y" // lalr1.cc:846
    { driver.PumpLiterFloat(yystack_[0].value.as< double > ()); }
#line 541 "parser.cpp" // lalr1.cc:846
    break;

  case 8:
#line 105 "parser.y" // lalr1.cc:846
    { driver.PumpLiterString(yystack_[0].value.as< std::string > ()); }
#line 547 "parser.cpp" // lalr1.cc:846
    break;

  case 16:
#line 128 "parser.y" // lalr1.cc:846
    {}
#line 553 "parser.cpp" // lalr1.cc:846
    break;

  case 18:
#line 130 "parser.y" // lalr1.cc:846
    { driver.PumpExpContextMember(yystack_[0].value.as< std::string > ()); }
#line 559 "parser.cpp" // lalr1.cc:846
    break;

  case 19:
#line 131 "parser.y" // lalr1.cc:846
    { driver.PumpExpContextStaticMember(yystack_[0].value.as< std::string > ()); }
#line 565 "parser.cpp" // lalr1.cc:846
    break;

  case 20:
#line 132 "parser.y" // lalr1.cc:846
    { driver.PumpExpMember(yystack_[0].value.as< std::string > ()); }
#line 571 "parser.cpp" // lalr1.cc:846
    break;

  case 21:
#line 133 "parser.y" // lalr1.cc:846
    {}
#line 577 "parser.cpp" // lalr1.cc:846
    break;

  case 22:
#line 134 "parser.y" // lalr1.cc:846
    {}
#line 583 "parser.cpp" // lalr1.cc:846
    break;

  case 23:
#line 138 "parser.y" // lalr1.cc:846
    { driver.PumpStateClassCallWithoutArg(); }
#line 589 "parser.cpp" // lalr1.cc:846
    break;

  case 24:
#line 139 "parser.y" // lalr1.cc:846
    {}
#line 595 "parser.cpp" // lalr1.cc:846
    break;

  case 25:
#line 143 "parser.y" // lalr1.cc:846
    { driver.PumpStateClassCallStart(); }
#line 601 "parser.cpp" // lalr1.cc:846
    break;

  case 26:
#line 146 "parser.y" // lalr1.cc:846
    { driver.PumpStateClassCallEnd(); }
#line 607 "parser.cpp" // lalr1.cc:846
    break;

  case 31:
#line 165 "parser.y" // lalr1.cc:846
    { driver.PumpExpMul(); }
#line 613 "parser.cpp" // lalr1.cc:846
    break;

  case 32:
#line 166 "parser.y" // lalr1.cc:846
    { driver.PumpExpDiv(); }
#line 619 "parser.cpp" // lalr1.cc:846
    break;

  case 33:
#line 167 "parser.y" // lalr1.cc:846
    { driver.PumpExpMod(); }
#line 625 "parser.cpp" // lalr1.cc:846
    break;

  case 35:
#line 172 "parser.y" // lalr1.cc:846
    { driver.PumpExpAdd(); }
#line 631 "parser.cpp" // lalr1.cc:846
    break;

  case 36:
#line 173 "parser.y" // lalr1.cc:846
    { driver.PumpExpMin(); }
#line 637 "parser.cpp" // lalr1.cc:846
    break;

  case 38:
#line 178 "parser.y" // lalr1.cc:846
    {}
#line 643 "parser.cpp" // lalr1.cc:846
    break;

  case 39:
#line 179 "parser.y" // lalr1.cc:846
    {}
#line 649 "parser.cpp" // lalr1.cc:846
    break;

  case 41:
#line 184 "parser.y" // lalr1.cc:846
    {}
#line 655 "parser.cpp" // lalr1.cc:846
    break;

  case 42:
#line 185 "parser.y" // lalr1.cc:846
    {}
#line 661 "parser.cpp" // lalr1.cc:846
    break;

  case 43:
#line 186 "parser.y" // lalr1.cc:846
    {}
#line 667 "parser.cpp" // lalr1.cc:846
    break;

  case 44:
#line 187 "parser.y" // lalr1.cc:846
    {}
#line 673 "parser.cpp" // lalr1.cc:846
    break;

  case 46:
#line 192 "parser.y" // lalr1.cc:846
    {}
#line 679 "parser.cpp" // lalr1.cc:846
    break;

  case 47:
#line 193 "parser.y" // lalr1.cc:846
    {}
#line 685 "parser.cpp" // lalr1.cc:846
    break;

  case 49:
#line 198 "parser.y" // lalr1.cc:846
    {}
#line 691 "parser.cpp" // lalr1.cc:846
    break;

  case 51:
#line 203 "parser.y" // lalr1.cc:846
    {}
#line 697 "parser.cpp" // lalr1.cc:846
    break;

  case 53:
#line 208 "parser.y" // lalr1.cc:846
    {}
#line 703 "parser.cpp" // lalr1.cc:846
    break;

  case 55:
#line 213 "parser.y" // lalr1.cc:846
    {}
#line 709 "parser.cpp" // lalr1.cc:846
    break;

  case 57:
#line 218 "parser.y" // lalr1.cc:846
    {}
#line 715 "parser.cpp" // lalr1.cc:846
    break;

  case 59:
#line 230 "parser.y" // lalr1.cc:846
    { driver.PumpStateAssign(); }
#line 721 "parser.cpp" // lalr1.cc:846
    break;

  case 62:
#line 240 "parser.y" // lalr1.cc:846
    {}
#line 727 "parser.cpp" // lalr1.cc:846
    break;

  case 63:
#line 241 "parser.y" // lalr1.cc:846
    {}
#line 733 "parser.cpp" // lalr1.cc:846
    break;

  case 64:
#line 242 "parser.y" // lalr1.cc:846
    {}
#line 739 "parser.cpp" // lalr1.cc:846
    break;

  case 65:
#line 243 "parser.y" // lalr1.cc:846
    {}
#line 745 "parser.cpp" // lalr1.cc:846
    break;

  case 66:
#line 244 "parser.y" // lalr1.cc:846
    {}
#line 751 "parser.cpp" // lalr1.cc:846
    break;

  case 67:
#line 245 "parser.y" // lalr1.cc:846
    {}
#line 757 "parser.cpp" // lalr1.cc:846
    break;

  case 68:
#line 246 "parser.y" // lalr1.cc:846
    {}
#line 763 "parser.cpp" // lalr1.cc:846
    break;

  case 69:
#line 247 "parser.y" // lalr1.cc:846
    {}
#line 769 "parser.cpp" // lalr1.cc:846
    break;

  case 70:
#line 248 "parser.y" // lalr1.cc:846
    {}
#line 775 "parser.cpp" // lalr1.cc:846
    break;

  case 71:
#line 249 "parser.y" // lalr1.cc:846
    {}
#line 781 "parser.cpp" // lalr1.cc:846
    break;

  case 72:
#line 250 "parser.y" // lalr1.cc:846
    {}
#line 787 "parser.cpp" // lalr1.cc:846
    break;

  case 85:
#line 299 "parser.y" // lalr1.cc:846
    { driver.ExitFooMode(); }
#line 793 "parser.cpp" // lalr1.cc:846
    break;

  case 86:
#line 305 "parser.y" // lalr1.cc:846
    { driver.PumpStateClassEnd(); }
#line 799 "parser.cpp" // lalr1.cc:846
    break;

  case 88:
#line 313 "parser.y" // lalr1.cc:846
    { driver.PumpStateClass(yystack_[0].value.as< std::string > ()); }
#line 805 "parser.cpp" // lalr1.cc:846
    break;

  case 90:
#line 317 "parser.y" // lalr1.cc:846
    { }
#line 811 "parser.cpp" // lalr1.cc:846
    break;

  case 91:
#line 318 "parser.y" // lalr1.cc:846
    {}
#line 817 "parser.cpp" // lalr1.cc:846
    break;

  case 92:
#line 322 "parser.y" // lalr1.cc:846
    { driver.PumpStateClassDefStart(); }
#line 823 "parser.cpp" // lalr1.cc:846
    break;

  case 93:
#line 325 "parser.y" // lalr1.cc:846
    { driver.PumpStateClassDefEnd(); }
#line 829 "parser.cpp" // lalr1.cc:846
    break;

  case 97:
#line 338 "parser.y" // lalr1.cc:846
    { driver.PumpClassParaClause(); }
#line 835 "parser.cpp" // lalr1.cc:846
    break;

  case 98:
#line 339 "parser.y" // lalr1.cc:846
    { driver.PumpClassParaSetClause(); }
#line 841 "parser.cpp" // lalr1.cc:846
    break;

  case 102:
#line 352 "parser.y" // lalr1.cc:846
    { driver.PumpClassArguClause(); }
#line 847 "parser.cpp" // lalr1.cc:846
    break;


#line 851 "parser.cpp" // lalr1.cc:846
          default:
            break;
          }
      }
    catch (const syntax_error& yyexc)
      {
        error (yyexc);
        YYERROR;
      }
    YY_SYMBOL_PRINT ("-> $$ =", yylhs);
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    // Shift the result of the reduction.
    yypush_ (YY_NULL, yylhs);
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state,
                                           yyempty ? yyempty_ : yyla.type_get ()));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyempty)
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyempty = true;
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* $$ was initialized before running the user action.  */
    YY_SYMBOL_PRINT ("Error: discarding", yylhs);
    yylhs.~stack_symbol_type();
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyempty)
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyempty)
          yy_destroy_ (YY_NULL, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULL, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
   FooParser ::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
   FooParser ::yysyntax_error_ (state_type, symbol_number_type) const
  {
    return YY_("syntax error");
  }


  const signed char  FooParser ::yypact_ninf_ = -38;

  const signed char  FooParser ::yytable_ninf_ = -77;

  const signed char
   FooParser ::yypact_[] =
  {
       3,   -38,   -38,   -38,   -38,   -38,     2,   -38,    70,    18,
       6,   -38,   -38,   -38,   -38,   -38,   -38,    43,   -38,    45,
     -38,    70,   -38,    -9,   -15,    26,    12,    47,   -31,     5,
      13,    34,    21,    17,    87,    28,    19,   -38,   -38,     9,
     -38,   -38,    53,    65,   -38,    66,   -38,    94,   -38,   -38,
     -38,    67,    70,    97,   -38,   -38,    -8,   -38,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,   -38,   -38,   -38,   -38,
     -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,    70,   -38,
      70,   -38,   -38,    15,   -38,    71,   -38,     2,   -38,   -38,
      80,    68,   -38,    80,    70,   -38,   -38,   -38,    -9,    -9,
     -15,   -15,    26,    26,    26,    26,    12,    12,    47,   -31,
       5,    13,    34,   -38,    54,    82,    15,   -38,    69,   -38,
      -3,   -38,   -38,    15,   -38,   -38,   -38,   -38,   -38,    70,
     -38,     2,    83,   -38,   -38,   -38
  };

  const unsigned char
   FooParser ::yydefact_[] =
  {
       0,     9,     2,     6,     7,     8,     0,    85,     0,     0,
       0,    79,    14,    12,     3,     4,     5,     0,    15,    29,
      17,     0,    30,    34,    37,    40,    45,    48,    50,    52,
      54,    56,    60,    73,     0,     0,     0,    83,    77,     0,
      11,    78,     0,    89,    88,     0,    18,     0,     1,    21,
      22,    25,     0,     0,    24,   102,     0,   100,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    66,    67,    63,    64,
      65,    71,    70,    72,    68,    69,    62,    59,     0,    80,
       0,    10,    84,    81,    86,    92,    87,     0,    13,    19,
      27,     0,    20,    27,     0,    31,    32,    33,    35,    36,
      38,    39,    43,    44,    41,    42,    46,    47,    49,    51,
      53,    55,    57,    61,    74,     0,    82,    90,    97,    91,
       0,    94,    96,    81,    23,    16,    26,   101,    99,     0,
      93,     0,     0,    98,    95,    28
  };

  const signed char
   FooParser ::yypgoto_[] =
  {
     -38,    -6,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,
     -38,   -38,    22,    23,    31,     1,    20,    25,    51,    52,
      50,    55,    56,   -38,   -20,   -38,   -38,   -38,    -4,   -38,
     -37,   -38,    -7,   127,   -38,   -38,   -38,   -38,   -38,   -38,
     -38,   -38,   -13,   -38,   -38,   -38,    29
  };

  const short int
   FooParser ::yydefgoto_[] =
  {
      -1,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    54,   134,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    87,    88,    35,    36,
      37,    38,   125,   126,    40,    41,    42,    43,    96,    97,
     129,   130,   131,   132,    94,    56,    57
  };

  const short int
   FooParser ::yytable_[] =
  {
      44,    55,    92,     1,    45,     2,     2,     3,     4,    91,
       5,     6,     2,     3,     4,    71,     5,     6,     2,     3,
       4,    46,     5,     6,   103,    65,    66,    61,    62,   140,
      58,    59,    60,     7,     8,    63,    64,    75,     9,    10,
       8,    47,   104,    48,     9,    10,     8,   141,   101,    74,
       9,    10,    72,   -58,    11,   -58,    67,    68,    69,    70,
      11,    73,    49,    50,   110,   111,    11,   -75,   123,    90,
     124,   -58,   -58,     2,     3,     4,    51,     5,    52,    89,
      53,   105,   106,   107,    55,   112,   113,   114,   115,    92,
      93,   128,   108,   109,   116,   117,    95,    99,    98,   100,
     102,     8,   135,   127,   -76,     9,    10,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,   133,   139,   143,
     138,   145,   118,   120,   119,   136,   142,    39,   144,   121,
       0,   122,     0,   137,     0,   128,    86
  };

  const short int
   FooParser ::yycheck_[] =
  {
       6,    21,    39,     0,     8,     3,     3,     4,     5,     0,
       7,     8,     3,     4,     5,    46,     7,     8,     3,     4,
       5,     3,     7,     8,    32,    13,    14,    42,    43,    32,
      39,    40,    41,    30,    31,     9,    10,    16,    35,    36,
      31,    35,    50,     0,    35,    36,    31,    50,    52,    15,
      35,    36,    47,    32,    51,    34,    44,    45,    11,    12,
      51,    48,    17,    18,    63,    64,    51,    50,    88,    50,
      90,    50,    51,     3,     4,     5,    31,     7,    33,    51,
      35,    58,    59,    60,   104,    65,    66,    67,    68,   126,
      37,    97,    61,    62,    69,    70,    31,     3,    32,    32,
       3,    31,    34,    32,    50,    35,    36,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    37,    49,   139,
      38,    38,    71,    73,    72,   103,   133,     0,   141,    74,
      -1,    75,    -1,   104,    -1,   141,    49
  };

  const unsigned char
   FooParser ::yystos_[] =
  {
       0,     0,     3,     4,     5,     7,     8,    30,    31,    35,
      36,    51,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    80,    81,    82,    83,    85,
      86,    87,    88,    89,    53,    80,     3,    35,     0,    17,
      18,    31,    33,    35,    63,    76,    97,    98,    39,    40,
      41,    42,    43,     9,    10,    13,    14,    44,    45,    11,
      12,    46,    47,    48,    15,    16,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    49,    78,    79,    51,
      50,     0,    82,    37,    96,    31,    90,    91,    32,     3,
      32,    80,     3,    32,    50,    65,    65,    65,    66,    66,
      67,    67,    68,    68,    68,    68,    69,    69,    70,    71,
      72,    73,    74,    76,    76,    84,    85,    32,    53,    92,
      93,    94,    95,    37,    64,    34,    64,    98,    38,    49,
      32,    50,    84,    76,    94,    38
  };

  const unsigned char
   FooParser ::yyr1_[] =
  {
       0,    52,    53,    54,    54,    54,    55,    56,    57,    58,
      58,    58,    59,    59,    59,    60,    60,    60,    60,    60,
      60,    60,    60,    61,    61,    62,    63,    64,    64,    65,
      66,    66,    66,    66,    67,    67,    67,    68,    68,    68,
      69,    69,    69,    69,    69,    70,    70,    70,    71,    71,
      72,    72,    73,    73,    74,    74,    75,    75,    76,    76,
      77,    78,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    80,    80,    81,    81,    82,    82,    83,
      83,    84,    84,    85,    85,    86,    87,    88,    89,    90,
      90,    90,    91,    92,    93,    93,    94,    95,    95,    96,
      97,    97,    98
  };

  const unsigned char
   FooParser ::yyr2_[] =
  {
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     3,     1,     1,     4,     1,     2,     3,
       3,     2,     2,     4,     2,     2,     3,     0,     3,     1,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     2,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     3,     1,     1,     1,
       2,     0,     1,     1,     2,     1,     2,     2,     2,     0,
       2,     2,     1,     2,     1,     3,     1,     1,     3,     3,
       1,     3,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const  FooParser ::yytname_[] =
  {
  "TOKEN_END", "error", "$undefined", "TOKEN_ID", "TOKEN_INT",
  "TOKEN_FLOAT", "TOKEN_CHAR", "TOKEN_STRING", "TOKEN_CLASS", "TOKEN_SHL",
  "TOKEN_SHR", "TOKEN_EQ", "TOKEN_NE", "TOKEN_LE", "TOKEN_GE",
  "TOKEN_LOG_AND", "TOKEN_LOG_OR", "TOKEN_INC", "TOKEN_DEC",
  "TOKEN_DOT_STAR", "TOKEN_ADD_EQ", "TOKEN_SUB_EQ", "TOKEN_MUL_EQ",
  "TOKEN_DIV_EQ", "TOKEN_MOD_EQ", "TOKEN_XOR_EQ", "TOKEN_AND_EQ",
  "TOKEN_OR_EQ", "TOKEN_SHR_EQ", "TOKEN_SHL_EQ", "TOKEN_CMD_QUIT", "'('",
  "')'", "'['", "']'", "'.'", "'$'", "':'", "'#'", "'*'", "'/'", "'%'",
  "'+'", "'-'", "'<'", "'>'", "'&'", "'^'", "'|'", "'='", "','", "';'",
  "$accept", "identifier", "literal", "integer_literal",
  "floating_literal", "string_literal", "translation_unit",
  "primary_expression", "postfix_expression", "postfix_call",
  "postfix_call_start", "postfix_call_end",
  "postfix_call_post_callback_opt", "unary_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "assignment_expression", "assignment_left", "assignment_right",
  "assignment_operator", "expression", "expression_list", "statement",
  "expression_statement", "statement_seq.opt", "statement_seq",
  "command_seq", "function_definition", "function_head", "function_id",
  "function_def_opt", "function_def_Start", "function_def_end",
  "function_param_clause_list", "function_param_clause",
  "function_param_clause_core", "function_body",
  "function_argu_clause_list", "function_argu_clause", YY_NULL
  };


  const unsigned short int
   FooParser ::yyrline_[] =
  {
       0,    87,    87,    91,    92,    93,    97,   101,   105,   112,
     113,   114,   121,   122,   123,   127,   128,   129,   130,   131,
     132,   133,   134,   138,   139,   143,   146,   154,   156,   160,
     164,   165,   166,   167,   171,   172,   173,   177,   178,   179,
     183,   184,   185,   186,   187,   191,   192,   193,   197,   198,
     202,   203,   207,   208,   212,   213,   217,   218,   229,   230,
     234,   237,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   254,   255,   259,   260,   271,   272,   276,
     277,   286,   288,   291,   292,   299,   305,   309,   313,   315,
     317,   318,   322,   325,   329,   330,   334,   338,   339,   343,
     347,   348,   352
  };

  // Print the state stack on the debug stream.
  void
   FooParser ::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
   FooParser ::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


#line 11 "parser.y" // lalr1.cc:1156
} } //  FooScript::Parser 
#line 1258 "parser.cpp" // lalr1.cc:1156
#line 355 "parser.y" // lalr1.cc:1157


 void FooScript::Parser::FooParser::error(const location_type& l,
                          const std::string& m)
{
    std::cout << "Location: " << l << std::endl;
    std::cout << "Error: " << m << std::endl;
}
