// A Bison parser, made by GNU Bison 3.0.

// Skeleton interface for Bison LALR(1) parsers in C++

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

/**
 ** \file parser.h
 ** Define the  FooScript::Parser ::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
// //                    "%code requires" blocks.
#line 20 "parser.y" // lalr1.cc:371

#include "syntax\def.h"
namespace FooScript{
    namespace Parser{ 
        class FooScanner;  
        class FooDriver; 
    }
}

#line 54 "parser.h" // lalr1.cc:371

# include <cassert>
# include <vector>
# include <iostream>
# include <stdexcept>
# include <string>
# include "stack.hh"
# include "location.hh"
#include <typeinfo>
#ifndef YYASSERT
# include <cassert>
# define YYASSERT assert
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

#line 11 "parser.y" // lalr1.cc:371
namespace  FooScript { namespace Parser  {
#line 77 "parser.h" // lalr1.cc:371



  /// A char[S] buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current state.
  template <size_t S>
  struct variant
  {
    /// Type of *this.
    typedef variant<S> self_type;

    /// Empty construction.
    variant ()
      : yytname_ (YY_NULL)
    {}

    /// Construct and fill.
    template <typename T>
    variant (const T& t)
      : yytname_ (typeid (T).name ())
    {
      YYASSERT (sizeof (T) <= S);
      new (yyas_<T> ()) T (t);
    }

    /// Destruction, allowed only if empty.
    ~variant ()
    {
      YYASSERT (!yytname_);
    }

    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    build ()
    {
      YYASSERT (!yytname_);
      YYASSERT (sizeof (T) <= S);
      yytname_ = typeid (T).name ();
      return *new (yyas_<T> ()) T;
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    build (const T& t)
    {
      YYASSERT (!yytname_);
      YYASSERT (sizeof (T) <= S);
      yytname_ = typeid (T).name ();
      return *new (yyas_<T> ()) T (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as ()
    {
      YYASSERT (yytname_ == typeid (T).name ());
      YYASSERT (sizeof (T) <= S);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const
    {
      YYASSERT (yytname_ == typeid (T).name ());
      YYASSERT (sizeof (T) <= S);
      return *yyas_<T> ();
    }

    /// Swap the content with \a other, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsability.
    /// Swapping between built and (possibly) non-built is done with
    /// variant::move ().
    template <typename T>
    void
    swap (self_type& other)
    {
      YYASSERT (yytname_);
      YYASSERT (yytname_ == other.yytname_);
      std::swap (as<T> (), other.as<T> ());
    }

    /// Move the content of \a other to this.
    ///
    /// Destroys \a other.
    template <typename T>
    void
    move (self_type& other)
    {
      YYASSERT (!yytname_);
      build<T> ();
      swap<T> (other);
      other.destroy<T> ();
    }

    /// Copy the content of \a other to this.
    template <typename T>
    void
    copy (const self_type& other)
    {
      build<T> (other.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytname_ = YY_NULL;
    }

  private:
    /// Prohibit blind copies.
    self_type& operator=(const self_type&);
    variant (const self_type&);

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ ()
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[S];
    } yybuffer_;

    /// Whether the content is built: if defined, the name of the stored type.
    const char *yytname_;
  };


  /// A Bison parser.
  class  FooParser 
  {
  public:
#ifndef YYSTYPE
    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // TOKEN_INT
      char dummy1[sizeof(FooScript::Type::tInt)];

      // TOKEN_CHAR
      char dummy2[sizeof(char)];

      // TOKEN_FLOAT
      char dummy3[sizeof(double)];

      // TOKEN_ID
      // TOKEN_STRING
      // identifier
      char dummy4[sizeof(std::string)];
};

    /// Symbol semantic values.
    typedef variant<sizeof(union_type)> semantic_type;
#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m);
      location_type location;
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        TOKEN_END = 0,
        TOKEN_ID = 258,
        TOKEN_INT = 259,
        TOKEN_FLOAT = 260,
        TOKEN_CHAR = 261,
        TOKEN_STRING = 262,
        TOKEN_CLASS = 263,
        TOKEN_SHL = 264,
        TOKEN_SHR = 265,
        TOKEN_EQ = 266,
        TOKEN_NE = 267,
        TOKEN_LE = 268,
        TOKEN_GE = 269,
        TOKEN_LOG_AND = 270,
        TOKEN_LOG_OR = 271,
        TOKEN_INC = 272,
        TOKEN_DEC = 273,
        TOKEN_DOT_STAR = 274,
        TOKEN_ADD_EQ = 275,
        TOKEN_SUB_EQ = 276,
        TOKEN_MUL_EQ = 277,
        TOKEN_DIV_EQ = 278,
        TOKEN_MOD_EQ = 279,
        TOKEN_XOR_EQ = 280,
        TOKEN_AND_EQ = 281,
        TOKEN_OR_EQ = 282,
        TOKEN_SHR_EQ = 283,
        TOKEN_SHL_EQ = 284,
        TOKEN_CMD_QUIT = 285
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Internal symbol number.
    typedef int symbol_number_type;

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef unsigned char token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ();

      /// Copy constructor.
      basic_symbol (const basic_symbol& other);

      /// Constructor for valueless symbols, and symbols from each type.

  basic_symbol (typename Base::kind_type t, const location_type& l);

  basic_symbol (typename Base::kind_type t, const FooScript::Type::tInt v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const char v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const double v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::string v, const location_type& l);


      /// Constructor for symbols with semantic value.
      basic_symbol (typename Base::kind_type t,
                    const semantic_type& v,
                    const location_type& l);

      ~basic_symbol ();

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& other);
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

      /// Copy constructor.
      by_type (const by_type& other);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// -1 when this symbol is empty.
      symbol_number_type type_get () const;

      /// The token.
      token_type token () const;

      enum { empty = 0 };

      /// The symbol type.
      /// -1 when this symbol is empty.
      token_number_type type;
    };

    /// "External" symbols: returned by the scanner.
    typedef basic_symbol<by_type> symbol_type;

    // Symbol constructors declarations.
    static inline
    symbol_type
    make_TOKEN_END (const location_type& l);

    static inline
    symbol_type
    make_TOKEN_ID (const std::string& v, const location_type& l);

    static inline
    symbol_type
    make_TOKEN_INT (const FooScript::Type::tInt& v, const location_type& l);

    static inline
    symbol_type
    make_TOKEN_FLOAT (const double& v, const location_type& l);

    static inline
    symbol_type
    make_TOKEN_CHAR (const char& v, const location_type& l);

    static inline
    symbol_type
    make_TOKEN_STRING (const std::string& v, const location_type& l);

    static inline
    symbol_type
    make_TOKEN_CLASS (const location_type& l);

    static inline
    symbol_type
    make_TOKEN_SHL (const location_type& l);

    static inline
    symbol_type
    make_TOKEN_SHR (const location_type& l);

    static inline
    symbol_type
    make_TOKEN_EQ (const location_type& l);

    static inline
    symbol_type
    make_TOKEN_NE (const location_type& l);

    static inline
    symbol_type
    make_TOKEN_LE (const location_type& l);

    static inline
    symbol_type
    make_TOKEN_GE (const location_type& l);

    static inline
    symbol_type
    make_TOKEN_LOG_AND (const location_type& l);

    static inline
    symbol_type
    make_TOKEN_LOG_OR (const location_type& l);

    static inline
    symbol_type
    make_TOKEN_INC (const location_type& l);

    static inline
    symbol_type
    make_TOKEN_DEC (const location_type& l);

    static inline
    symbol_type
    make_TOKEN_DOT_STAR (const location_type& l);

    static inline
    symbol_type
    make_TOKEN_ADD_EQ (const location_type& l);

    static inline
    symbol_type
    make_TOKEN_SUB_EQ (const location_type& l);

    static inline
    symbol_type
    make_TOKEN_MUL_EQ (const location_type& l);

    static inline
    symbol_type
    make_TOKEN_DIV_EQ (const location_type& l);

    static inline
    symbol_type
    make_TOKEN_MOD_EQ (const location_type& l);

    static inline
    symbol_type
    make_TOKEN_XOR_EQ (const location_type& l);

    static inline
    symbol_type
    make_TOKEN_AND_EQ (const location_type& l);

    static inline
    symbol_type
    make_TOKEN_OR_EQ (const location_type& l);

    static inline
    symbol_type
    make_TOKEN_SHR_EQ (const location_type& l);

    static inline
    symbol_type
    make_TOKEN_SHL_EQ (const location_type& l);

    static inline
    symbol_type
    make_TOKEN_CMD_QUIT (const location_type& l);


    /// Build a parser object.
     FooParser  (FooScript::Parser::FooDriver  &driver_yyarg);
    virtual ~ FooParser  ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

  private:
    /// This class is not copyable.
     FooParser  (const  FooParser &);
     FooParser & operator= (const  FooParser &);

    /// State numbers.
    typedef int state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yytoken   the lookahead token type, or yyempty_.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         symbol_number_type yytoken) const;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yylhs     the nonterminal to push on the stack
    state_type yy_lr_goto_state_ (state_type yystate, int yylhs);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    static token_number_type yytranslate_ (token_type t);

    // Tables.
  // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
  // STATE-NUM.
  static const signed char yypact_[];

  // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
  // Performed when YYTABLE does not specify something else to do.  Zero
  // means the default is an error.
  static const unsigned char yydefact_[];

  // YYPGOTO[NTERM-NUM].
  static const short int yypgoto_[];

  // YYDEFGOTO[NTERM-NUM].
  static const short int yydefgoto_[];

  // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
  // positive, shift that token.  If negative, reduce the rule whose
  // number is the opposite.  If YYTABLE_NINF, syntax error.
  static const short int yytable_[];

  static const short int yycheck_[];

  // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
  // symbol of state STATE-NUM.
  static const unsigned char yystos_[];

  // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
  static const unsigned char yyr1_[];

  // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
  static const unsigned char yyr2_[];


#if YYDEBUG
    /// For a symbol, its name in clear.
    static const char* const yytname_[];

  // YYRLINE[YYN] -- Source line where rule number YYN was defined.
  static const unsigned short int yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    // Debugging.
    int yydebug_;
    std::ostream* yycdebug_;

    /// \brief Display a symbol type, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param s         The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state ();

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s);

      /// Copy constructor.
      by_state (const by_state& other);

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// "empty" when empty.
      symbol_number_type type_get () const;

      enum { empty = 0 };

      /// The state.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, symbol_type& sym);
      /// Assignment, needed by push_back.
      stack_symbol_type& operator= (const stack_symbol_type& that);
    };

    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, stack_symbol_type& s);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, state_type s, symbol_type& sym);

    /// Pop \a n symbols the three stacks.
    void yypop_ (unsigned int n = 1);

    // Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 138,           //< Last index in yytable_.
      yynnts_ = 49,  //< Number of nonterminal symbols.
      yyempty_ = -2,
      yyfinal_ = 48, //< Termination state number.
      yyterror_ = 1,
      yyerrcode_ = 256,
      yyntokens_ = 52    //< Number of tokens.
    };


    // User arguments.
    FooScript::Parser::FooDriver  &driver;
  };

  // Symbol number corresponding to token number t.
  inline
   FooParser ::token_number_type
   FooParser ::yytranslate_ (token_type t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    38,    36,    41,    46,     2,
      31,    32,    39,    42,    50,    43,    35,    40,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    37,    51,
      44,    49,    45,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    33,     2,    34,    47,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    48,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30
    };
    const unsigned int user_token_number_max_ = 285;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

  inline
   FooParser ::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
   FooParser ::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
   FooParser ::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
      switch (other.type_get ())
    {
      case 4: // TOKEN_INT
        value.copy< FooScript::Type::tInt > (other.value);
        break;

      case 6: // TOKEN_CHAR
        value.copy< char > (other.value);
        break;

      case 5: // TOKEN_FLOAT
        value.copy< double > (other.value);
        break;

      case 3: // TOKEN_ID
      case 7: // TOKEN_STRING
      case 53: // identifier
        value.copy< std::string > (other.value);
        break;

      default:
        break;
    }

  }


  template <typename Base>
  inline
   FooParser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {
    (void) v;
      switch (this->type_get ())
    {
      case 4: // TOKEN_INT
        value.copy< FooScript::Type::tInt > (v);
        break;

      case 6: // TOKEN_CHAR
        value.copy< char > (v);
        break;

      case 5: // TOKEN_FLOAT
        value.copy< double > (v);
        break;

      case 3: // TOKEN_ID
      case 7: // TOKEN_STRING
      case 53: // identifier
        value.copy< std::string > (v);
        break;

      default:
        break;
    }
}


  // Implementation of basic_symbol constructor for each type.

  template <typename Base>
   FooParser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
   FooParser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const FooScript::Type::tInt v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
   FooParser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const char v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
   FooParser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const double v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
   FooParser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::string v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  template <typename Base>
  inline
   FooParser ::basic_symbol<Base>::~basic_symbol ()
  {
    // User destructor.
    symbol_number_type yytype = this->type_get ();
    switch (yytype)
    {
   default:
      break;
    }

    // Type destructor.
    switch (yytype)
    {
      case 4: // TOKEN_INT
        value.template destroy< FooScript::Type::tInt > ();
        break;

      case 6: // TOKEN_CHAR
        value.template destroy< char > ();
        break;

      case 5: // TOKEN_FLOAT
        value.template destroy< double > ();
        break;

      case 3: // TOKEN_ID
      case 7: // TOKEN_STRING
      case 53: // identifier
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

  }

  template <typename Base>
  inline
  void
   FooParser ::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
      switch (this->type_get ())
    {
      case 4: // TOKEN_INT
        value.move< FooScript::Type::tInt > (s.value);
        break;

      case 6: // TOKEN_CHAR
        value.move< char > (s.value);
        break;

      case 5: // TOKEN_FLOAT
        value.move< double > (s.value);
        break;

      case 3: // TOKEN_ID
      case 7: // TOKEN_STRING
      case 53: // identifier
        value.move< std::string > (s.value);
        break;

      default:
        break;
    }

    location = s.location;
  }

  // by_type.
  inline
   FooParser ::by_type::by_type ()
     : type (empty)
  {}

  inline
   FooParser ::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
   FooParser ::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
   FooParser ::by_type::move (by_type& that)
  {
    type = that.type;
    that.type = empty;
  }

  inline
  int
   FooParser ::by_type::type_get () const
  {
    return type;
  }

  inline
   FooParser ::token_type
   FooParser ::by_type::token () const
  {
    // YYTOKNUM[NUM] -- (External) token number corresponding to the
    // (internal) symbol number NUM (which must be that of a token).  */
    static
    const unsigned short int
    yytoken_number_[] =
    {
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,    40,    41,    91,    93,    46,    36,    58,    35,    42,
      47,    37,    43,    45,    60,    62,    38,    94,   124,    61,
      44,    59
    };
    return static_cast<token_type> (yytoken_number_[type]);
  }
  // Implementation of make_symbol for each symbol type.
   FooParser ::symbol_type
   FooParser ::make_TOKEN_END (const location_type& l)
  {
    return symbol_type (token::TOKEN_END, l);

  }

   FooParser ::symbol_type
   FooParser ::make_TOKEN_ID (const std::string& v, const location_type& l)
  {
    return symbol_type (token::TOKEN_ID, v, l);

  }

   FooParser ::symbol_type
   FooParser ::make_TOKEN_INT (const FooScript::Type::tInt& v, const location_type& l)
  {
    return symbol_type (token::TOKEN_INT, v, l);

  }

   FooParser ::symbol_type
   FooParser ::make_TOKEN_FLOAT (const double& v, const location_type& l)
  {
    return symbol_type (token::TOKEN_FLOAT, v, l);

  }

   FooParser ::symbol_type
   FooParser ::make_TOKEN_CHAR (const char& v, const location_type& l)
  {
    return symbol_type (token::TOKEN_CHAR, v, l);

  }

   FooParser ::symbol_type
   FooParser ::make_TOKEN_STRING (const std::string& v, const location_type& l)
  {
    return symbol_type (token::TOKEN_STRING, v, l);

  }

   FooParser ::symbol_type
   FooParser ::make_TOKEN_CLASS (const location_type& l)
  {
    return symbol_type (token::TOKEN_CLASS, l);

  }

   FooParser ::symbol_type
   FooParser ::make_TOKEN_SHL (const location_type& l)
  {
    return symbol_type (token::TOKEN_SHL, l);

  }

   FooParser ::symbol_type
   FooParser ::make_TOKEN_SHR (const location_type& l)
  {
    return symbol_type (token::TOKEN_SHR, l);

  }

   FooParser ::symbol_type
   FooParser ::make_TOKEN_EQ (const location_type& l)
  {
    return symbol_type (token::TOKEN_EQ, l);

  }

   FooParser ::symbol_type
   FooParser ::make_TOKEN_NE (const location_type& l)
  {
    return symbol_type (token::TOKEN_NE, l);

  }

   FooParser ::symbol_type
   FooParser ::make_TOKEN_LE (const location_type& l)
  {
    return symbol_type (token::TOKEN_LE, l);

  }

   FooParser ::symbol_type
   FooParser ::make_TOKEN_GE (const location_type& l)
  {
    return symbol_type (token::TOKEN_GE, l);

  }

   FooParser ::symbol_type
   FooParser ::make_TOKEN_LOG_AND (const location_type& l)
  {
    return symbol_type (token::TOKEN_LOG_AND, l);

  }

   FooParser ::symbol_type
   FooParser ::make_TOKEN_LOG_OR (const location_type& l)
  {
    return symbol_type (token::TOKEN_LOG_OR, l);

  }

   FooParser ::symbol_type
   FooParser ::make_TOKEN_INC (const location_type& l)
  {
    return symbol_type (token::TOKEN_INC, l);

  }

   FooParser ::symbol_type
   FooParser ::make_TOKEN_DEC (const location_type& l)
  {
    return symbol_type (token::TOKEN_DEC, l);

  }

   FooParser ::symbol_type
   FooParser ::make_TOKEN_DOT_STAR (const location_type& l)
  {
    return symbol_type (token::TOKEN_DOT_STAR, l);

  }

   FooParser ::symbol_type
   FooParser ::make_TOKEN_ADD_EQ (const location_type& l)
  {
    return symbol_type (token::TOKEN_ADD_EQ, l);

  }

   FooParser ::symbol_type
   FooParser ::make_TOKEN_SUB_EQ (const location_type& l)
  {
    return symbol_type (token::TOKEN_SUB_EQ, l);

  }

   FooParser ::symbol_type
   FooParser ::make_TOKEN_MUL_EQ (const location_type& l)
  {
    return symbol_type (token::TOKEN_MUL_EQ, l);

  }

   FooParser ::symbol_type
   FooParser ::make_TOKEN_DIV_EQ (const location_type& l)
  {
    return symbol_type (token::TOKEN_DIV_EQ, l);

  }

   FooParser ::symbol_type
   FooParser ::make_TOKEN_MOD_EQ (const location_type& l)
  {
    return symbol_type (token::TOKEN_MOD_EQ, l);

  }

   FooParser ::symbol_type
   FooParser ::make_TOKEN_XOR_EQ (const location_type& l)
  {
    return symbol_type (token::TOKEN_XOR_EQ, l);

  }

   FooParser ::symbol_type
   FooParser ::make_TOKEN_AND_EQ (const location_type& l)
  {
    return symbol_type (token::TOKEN_AND_EQ, l);

  }

   FooParser ::symbol_type
   FooParser ::make_TOKEN_OR_EQ (const location_type& l)
  {
    return symbol_type (token::TOKEN_OR_EQ, l);

  }

   FooParser ::symbol_type
   FooParser ::make_TOKEN_SHR_EQ (const location_type& l)
  {
    return symbol_type (token::TOKEN_SHR_EQ, l);

  }

   FooParser ::symbol_type
   FooParser ::make_TOKEN_SHL_EQ (const location_type& l)
  {
    return symbol_type (token::TOKEN_SHL_EQ, l);

  }

   FooParser ::symbol_type
   FooParser ::make_TOKEN_CMD_QUIT (const location_type& l)
  {
    return symbol_type (token::TOKEN_CMD_QUIT, l);

  }


#line 11 "parser.y" // lalr1.cc:371
} } //  FooScript::Parser 
#line 1234 "parser.h" // lalr1.cc:371




#endif // !YY_YY_PARSER_H_INCLUDED
