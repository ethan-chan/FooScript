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

  case 29:
#line 160 "parser.y" // lalr1.cc:846
    { driver.PumpStateCompleteCallbackStart(); }
#line 613 "parser.cpp" // lalr1.cc:846
    break;

  case 30:
#line 164 "parser.y" // lalr1.cc:846
    { driver.PumpStateClassEnd(); }
#line 619 "parser.cpp" // lalr1.cc:846
    break;

  case 33:
#line 173 "parser.y" // lalr1.cc:846
    { driver.PumpExpMul(); }
#line 625 "parser.cpp" // lalr1.cc:846
    break;

  case 34:
#line 174 "parser.y" // lalr1.cc:846
    { driver.PumpExpDiv(); }
#line 631 "parser.cpp" // lalr1.cc:846
    break;

  case 35:
#line 175 "parser.y" // lalr1.cc:846
    { driver.PumpExpMod(); }
#line 637 "parser.cpp" // lalr1.cc:846
    break;

  case 37:
#line 180 "parser.y" // lalr1.cc:846
    { driver.PumpExpAdd(); }
#line 643 "parser.cpp" // lalr1.cc:846
    break;

  case 38:
#line 181 "parser.y" // lalr1.cc:846
    { driver.PumpExpMin(); }
#line 649 "parser.cpp" // lalr1.cc:846
    break;

  case 40:
#line 186 "parser.y" // lalr1.cc:846
    {}
#line 655 "parser.cpp" // lalr1.cc:846
    break;

  case 41:
#line 187 "parser.y" // lalr1.cc:846
    {}
#line 661 "parser.cpp" // lalr1.cc:846
    break;

  case 43:
#line 192 "parser.y" // lalr1.cc:846
    {}
#line 667 "parser.cpp" // lalr1.cc:846
    break;

  case 44:
#line 193 "parser.y" // lalr1.cc:846
    {}
#line 673 "parser.cpp" // lalr1.cc:846
    break;

  case 45:
#line 194 "parser.y" // lalr1.cc:846
    {}
#line 679 "parser.cpp" // lalr1.cc:846
    break;

  case 46:
#line 195 "parser.y" // lalr1.cc:846
    {}
#line 685 "parser.cpp" // lalr1.cc:846
    break;

  case 48:
#line 200 "parser.y" // lalr1.cc:846
    {}
#line 691 "parser.cpp" // lalr1.cc:846
    break;

  case 49:
#line 201 "parser.y" // lalr1.cc:846
    {}
#line 697 "parser.cpp" // lalr1.cc:846
    break;

  case 51:
#line 206 "parser.y" // lalr1.cc:846
    {}
#line 703 "parser.cpp" // lalr1.cc:846
    break;

  case 53:
#line 211 "parser.y" // lalr1.cc:846
    {}
#line 709 "parser.cpp" // lalr1.cc:846
    break;

  case 55:
#line 216 "parser.y" // lalr1.cc:846
    {}
#line 715 "parser.cpp" // lalr1.cc:846
    break;

  case 57:
#line 221 "parser.y" // lalr1.cc:846
    {}
#line 721 "parser.cpp" // lalr1.cc:846
    break;

  case 59:
#line 226 "parser.y" // lalr1.cc:846
    {}
#line 727 "parser.cpp" // lalr1.cc:846
    break;

  case 61:
#line 238 "parser.y" // lalr1.cc:846
    { driver.PumpStateAssign(); }
#line 733 "parser.cpp" // lalr1.cc:846
    break;

  case 64:
#line 248 "parser.y" // lalr1.cc:846
    {}
#line 739 "parser.cpp" // lalr1.cc:846
    break;

  case 65:
#line 249 "parser.y" // lalr1.cc:846
    {}
#line 745 "parser.cpp" // lalr1.cc:846
    break;

  case 66:
#line 250 "parser.y" // lalr1.cc:846
    {}
#line 751 "parser.cpp" // lalr1.cc:846
    break;

  case 67:
#line 251 "parser.y" // lalr1.cc:846
    {}
#line 757 "parser.cpp" // lalr1.cc:846
    break;

  case 68:
#line 252 "parser.y" // lalr1.cc:846
    {}
#line 763 "parser.cpp" // lalr1.cc:846
    break;

  case 69:
#line 253 "parser.y" // lalr1.cc:846
    {}
#line 769 "parser.cpp" // lalr1.cc:846
    break;

  case 70:
#line 254 "parser.y" // lalr1.cc:846
    {}
#line 775 "parser.cpp" // lalr1.cc:846
    break;

  case 71:
#line 255 "parser.y" // lalr1.cc:846
    {}
#line 781 "parser.cpp" // lalr1.cc:846
    break;

  case 72:
#line 256 "parser.y" // lalr1.cc:846
    {}
#line 787 "parser.cpp" // lalr1.cc:846
    break;

  case 73:
#line 257 "parser.y" // lalr1.cc:846
    {}
#line 793 "parser.cpp" // lalr1.cc:846
    break;

  case 74:
#line 258 "parser.y" // lalr1.cc:846
    {}
#line 799 "parser.cpp" // lalr1.cc:846
    break;

  case 87:
#line 307 "parser.y" // lalr1.cc:846
    { driver.ExitFooMode(); }
#line 805 "parser.cpp" // lalr1.cc:846
    break;

  case 88:
#line 313 "parser.y" // lalr1.cc:846
    { driver.PumpStateClassEnd(); }
#line 811 "parser.cpp" // lalr1.cc:846
    break;

  case 90:
#line 321 "parser.y" // lalr1.cc:846
    { driver.PumpStateClass(yystack_[0].value.as< std::string > ()); }
#line 817 "parser.cpp" // lalr1.cc:846
    break;

  case 92:
#line 325 "parser.y" // lalr1.cc:846
    { }
#line 823 "parser.cpp" // lalr1.cc:846
    break;

  case 93:
#line 326 "parser.y" // lalr1.cc:846
    {}
#line 829 "parser.cpp" // lalr1.cc:846
    break;

  case 94:
#line 330 "parser.y" // lalr1.cc:846
    { driver.PumpStateClassDefStart(); }
#line 835 "parser.cpp" // lalr1.cc:846
    break;

  case 95:
#line 333 "parser.y" // lalr1.cc:846
    { driver.PumpStateClassDefEnd(); }
#line 841 "parser.cpp" // lalr1.cc:846
    break;

  case 99:
#line 346 "parser.y" // lalr1.cc:846
    { driver.PumpClassParaClause(); }
#line 847 "parser.cpp" // lalr1.cc:846
    break;

  case 100:
#line 347 "parser.y" // lalr1.cc:846
    { driver.PumpClassParaSetClause(); }
#line 853 "parser.cpp" // lalr1.cc:846
    break;

  case 104:
#line 360 "parser.y" // lalr1.cc:846
    { driver.PumpClassArguClause(); }
#line 859 "parser.cpp" // lalr1.cc:846
    break;


#line 863 "parser.cpp" // lalr1.cc:846
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

  const signed char  FooParser ::yytable_ninf_ = -79;

  const signed char
   FooParser ::yypact_[] =
  {
       3,   -38,   -38,   -38,   -38,   -38,     2,   -38,    60,    12,
     -14,   -38,   -38,   -38,   -38,   -38,   -38,    30,   -38,    70,
      -5,    60,   -38,   -13,     0,    43,    11,    50,    28,    55,
      10,    75,    25,    22,    57,    53,    59,   -38,   -38,     9,
     -38,   -38,    73,    80,   -38,    81,   -38,   109,   -38,   -38,
     -38,    82,    60,   112,   -38,   -38,    15,   -38,   -38,    -3,
     -38,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,   -38,
     -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,
     -38,    60,   -38,    60,   -38,   -38,    15,   -38,    84,   -38,
       2,   -38,   -38,   -38,    83,   -38,    85,    15,   -38,    60,
     -38,   -38,   -38,   -13,   -13,     0,     0,    43,    43,    43,
      43,    11,    11,    50,    28,    55,    10,    75,   -38,    68,
      86,   -38,    71,   -38,    -1,   -38,   -38,   -38,   -38,   -38,
     -38,   -38,    60,   -38,     2,   -38,   -38
  };

  const unsigned char
   FooParser ::yydefact_[] =
  {
       0,     9,     2,     6,     7,     8,     0,    87,     0,     0,
       0,    81,    14,    12,     3,     4,     5,     0,    15,    31,
      27,     0,    32,    36,    39,    42,    47,    50,    52,    54,
      56,    58,    62,    75,     0,     0,     0,    85,    79,     0,
      11,    80,     0,    91,    90,     0,    18,     0,     1,    21,
      22,    25,     0,     0,    29,    17,    83,    24,   104,     0,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    68,
      69,    65,    66,    67,    73,    72,    74,    70,    71,    64,
      61,     0,    82,     0,    10,    86,    83,    88,    94,    89,
       0,    13,    19,    23,     0,    20,     0,    84,    26,     0,
      33,    34,    35,    37,    38,    40,    41,    45,    46,    43,
      44,    48,    49,    51,    53,    55,    57,    59,    63,    76,
       0,    92,    99,    93,     0,    96,    98,    16,    30,    28,
     103,   101,     0,    95,     0,   100,    97
  };

  const short int
   FooParser ::yypgoto_[] =
  {
     -38,    -6,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,
     -38,   -38,   -38,   -38,   -38,   -26,     4,    26,    29,    35,
      45,    46,    49,    51,    48,   -38,   -20,   -38,   -38,   -38,
      -4,   -38,   -37,   -38,    31,   129,   -38,   -38,   -38,   -38,
     -38,   -38,   -38,   -38,   -12,   -38,   -38,   -38,    21
  };

  const short int
   FooParser ::yydefgoto_[] =
  {
      -1,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    57,    55,    56,   139,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    90,    91,
      35,    36,    37,    38,   106,   107,    40,    41,    42,    43,
      99,   100,   133,   134,   135,   136,    97,    59,    60
  };

  const short int
   FooParser ::yytable_[] =
  {
      44,    58,    95,     1,    45,     2,     2,     3,     4,    94,
       5,     6,     2,     3,     4,    46,     5,     6,     2,     3,
       4,    47,     5,     6,    68,    69,    61,    62,    63,   108,
      48,   143,    54,     7,     8,   110,   111,   112,     9,    10,
       8,    78,    64,    65,     9,    10,     8,   109,   104,   144,
       9,    10,    66,    67,    11,    70,    71,   -60,    76,   -60,
      11,    72,    73,     2,     3,     4,    11,     5,   113,   114,
      95,   128,   -77,   129,    74,   -60,   -60,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    49,    50,    58,
      77,     8,   115,   116,   132,     9,    10,   117,   118,   119,
     120,    51,    75,    52,    92,    53,    89,   121,   122,    93,
      96,    98,   102,   101,   103,   105,   131,   137,   -78,   123,
     142,   124,   145,   138,   141,   125,   127,   130,   126,    39,
     140,     0,   146,     0,     0,     0,     0,     0,   132
  };

  const short int
   FooParser ::yycheck_[] =
  {
       6,    21,    39,     0,     8,     3,     3,     4,     5,     0,
       7,     8,     3,     4,     5,     3,     7,     8,     3,     4,
       5,    35,     7,     8,    13,    14,    39,    40,    41,    32,
       0,    32,    37,    30,    31,    61,    62,    63,    35,    36,
      31,    16,    42,    43,    35,    36,    31,    50,    52,    50,
      35,    36,     9,    10,    51,    44,    45,    32,    48,    34,
      51,    11,    12,     3,     4,     5,    51,     7,    64,    65,
     107,    91,    50,    93,    46,    50,    51,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    17,    18,   109,
      15,    31,    66,    67,   100,    35,    36,    68,    69,    70,
      71,    31,    47,    33,    51,    35,    49,    72,    73,    50,
      37,    31,     3,    32,    32,     3,    32,    34,    50,    74,
      49,    75,   142,    38,    38,    76,    78,    96,    77,     0,
     109,    -1,   144,    -1,    -1,    -1,    -1,    -1,   144
  };

  const unsigned char
   FooParser ::yystos_[] =
  {
       0,     0,     3,     4,     5,     7,     8,    30,    31,    35,
      36,    51,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    82,    83,    84,    85,    87,
      88,    89,    90,    91,    53,    82,     3,    35,     0,    17,
      18,    31,    33,    35,    37,    64,    65,    63,    78,    99,
     100,    39,    40,    41,    42,    43,     9,    10,    13,    14,
      44,    45,    11,    12,    46,    47,    48,    15,    16,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    49,
      80,    81,    51,    50,     0,    84,    37,    98,    31,    92,
      93,    32,     3,    32,    82,     3,    86,    87,    32,    50,
      67,    67,    67,    68,    68,    69,    69,    70,    70,    70,
      70,    71,    71,    72,    73,    74,    75,    76,    78,    78,
      86,    32,    53,    94,    95,    96,    97,    34,    38,    66,
     100,    38,    49,    32,    50,    78,    96
  };

  const unsigned char
   FooParser ::yyr1_[] =
  {
       0,    52,    53,    54,    54,    54,    55,    56,    57,    58,
      58,    58,    59,    59,    59,    60,    60,    60,    60,    60,
      60,    60,    60,    61,    61,    62,    63,    64,    64,    65,
      66,    67,    68,    68,    68,    68,    69,    69,    69,    70,
      70,    70,    71,    71,    71,    71,    71,    72,    72,    72,
      73,    73,    74,    74,    75,    75,    76,    76,    77,    77,
      78,    78,    79,    80,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    82,    82,    83,    83,    84,
      84,    85,    85,    86,    86,    87,    87,    88,    89,    90,
      91,    92,    92,    92,    93,    94,    95,    95,    96,    97,
      97,    98,    99,    99,   100
  };

  const unsigned char
   FooParser ::yyr2_[] =
  {
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     3,     1,     1,     4,     2,     2,     3,
       3,     2,     2,     3,     2,     2,     2,     0,     3,     1,
       1,     1,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     3,     1,
       1,     1,     2,     0,     1,     1,     2,     1,     2,     2,
       2,     0,     2,     2,     1,     2,     1,     3,     1,     1,
       3,     3,     1,     3,     1
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
  "postfix_call_post_callback_opt", "postfix_call_post_callback_start",
  "postfix_call_post_callback_end", "unary_expression",
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
     164,   168,   172,   173,   174,   175,   179,   180,   181,   185,
     186,   187,   191,   192,   193,   194,   195,   199,   200,   201,
     205,   206,   210,   211,   215,   216,   220,   221,   225,   226,
     237,   238,   242,   245,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   262,   263,   267,   268,   279,
     280,   284,   285,   294,   296,   299,   300,   307,   313,   317,
     321,   323,   325,   326,   330,   333,   337,   338,   342,   346,
     347,   351,   355,   356,   360
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
#line 1271 "parser.cpp" // lalr1.cc:1156
#line 363 "parser.y" // lalr1.cc:1157


 void FooScript::Parser::FooParser::error(const location_type& l,
                          const std::string& m)
{
    std::cout << "Location: " << l << std::endl;
    std::cout << "Error: " << m << std::endl;
}
