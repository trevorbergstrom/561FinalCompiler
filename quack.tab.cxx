// A Bison parser, made by GNU Bison 3.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018 Free Software Foundation, Inc.

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

#line 37 "quack.tab.cxx" // lalr1.cc:407

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "quack.tab.hxx"

// User implementation prologue.

#line 51 "quack.tab.cxx" // lalr1.cc:415
// Unqualified %code blocks.
#line 19 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:416

	#include "lex.yy.h"
	#undef yylex
	#define yylex lexer.yylex
	void dump(AST::ASTNode* n);

#line 60 "quack.tab.cxx" // lalr1.cc:416


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

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
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
      *yycdebug_ << '\n';                       \
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
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 155 "quack.tab.cxx" // lalr1.cc:491

  /// Build a parser object.
  parser::parser (yy::Lexer& lexer_yyarg, AST::ASTNode** root_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      lexer (lexer_yyarg),
      root (root_yyarg)
  {}

  parser::~parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  parser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol ()
    : value ()
    , location ()
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value (other.value)
    , location (other.location)
  {
  }

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::clear ()
  {
    Base::clear ();
  }

  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = s.value;
    location = s.location;
  }

  // by_type.
  parser::by_type::by_type ()
    : type (empty_symbol)
  {}

  parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  void
  parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  void
  parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  int
  parser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  parser::by_state::by_state ()
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  void
  parser::by_state::clear ()
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s)
    : state (s)
  {}

  parser::symbol_number_type
  parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (const stack_symbol_type& that)
    : super_type (that.state, that.location)
  {
    value = that.value;
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.value, that.location)
  {
    // that is emptied.
    that.type = empty_symbol;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }


  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  void
  parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  void
  parser::yypop_ (unsigned n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << '\n';

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
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
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
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;

      // Default location.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
<<<<<<< HEAD
#line 76 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
=======
#line 75 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
>>>>>>> origin/master
    { 
		(yylhs.value.node) = new AST::ASTNode(Program);
		(yylhs.value.node)->append((yystack_[1].value.node));
		(yylhs.value.node)->append((yystack_[0].value.node));
		*root = (yylhs.value.node); 
		
	}
#line 585 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 3:
<<<<<<< HEAD
#line 85 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
=======
#line 84 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
>>>>>>> origin/master
    { (yylhs.value.node) = new AST::ASTNode(Classes); }
#line 591 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 4:
<<<<<<< HEAD
#line 86 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
=======
#line 85 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
>>>>>>> origin/master
    { 
		(yystack_[1].value.node)->append((yystack_[0].value.node));
		(yylhs.value.node) = (yystack_[1].value.node); 
	 }
#line 600 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 5:
<<<<<<< HEAD
#line 92 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
=======
#line 91 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    { 
		(yylhs.value.node) = new AST::ASTNode(Block);
		(yylhs.value.node)->sType_ = Statements;
	}
#line 609 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 6:
#line 95 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    { 
		(yylhs.value.node) = (yystack_[1].value.node);
		(yystack_[1].value.node)->append((yystack_[0].value.node));
	}
#line 618 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 7:
#line 101 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
>>>>>>> origin/master
    {
		(yylhs.value.node) = new AST::ASTNode(Class);
		(yystack_[8].value.node)->sType_ = ClassName;
		(yylhs.value.node)->append((yystack_[8].value.node));
		(yylhs.value.node)->append((yystack_[4].value.node));
		
		AST::ASTNode *method = new AST::ASTNode(Method);
		method->sType_ = Constructor;
		AST::ASTNode *methName = new AST::ASTNode(Ident, (yystack_[8].value.node)->strVal_);
		methName->sType_ = MethodName;
		method->append(methName);

		AST::ASTNode* ret = new AST::ASTNode(Ident, ReturnTyp, (yystack_[8].value.node)->strVal_);

		method->append((yystack_[6].value.node));
		method->append(ret);
		method->append((yystack_[2].value.node));
		(yylhs.value.node)->append(method);
		(yylhs.value.node)->append((yystack_[1].value.node));
	}
<<<<<<< HEAD
#line 625 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 6:
#line 114 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
		(yylhs.value.node) = new AST::ASTNode(Ident, SuperName, "Obj");
	}
#line 633 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 7:
#line 117 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
=======
#line 643 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 8:
#line 123 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
		(yylhs.value.node) = new AST::ASTNode(Ident, SuperName, "Obj");
	}
#line 651 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 9:
#line 126 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
>>>>>>> origin/master
    {
		(yystack_[0].value.node)->sType_ = SuperName;
		(yylhs.value.node) = (yystack_[0].value.node);
	}
<<<<<<< HEAD
#line 642 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 8:
#line 124 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    { (yylhs.value.node) = new AST::ASTNode(Methods); }
#line 648 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 9:
#line 125 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
=======
#line 660 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 10:
#line 133 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    { (yylhs.value.node) = new AST::ASTNode(Methods); }
#line 666 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 11:
#line 134 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
>>>>>>> origin/master
    {
		(yylhs.value.node) = (yystack_[1].value.node);
		(yystack_[1].value.node)->append((yystack_[0].value.node));
	}
<<<<<<< HEAD
#line 657 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 10:
#line 131 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
=======
#line 675 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 12:
#line 140 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
>>>>>>> origin/master
    { 
		(yylhs.value.node) = new AST::ASTNode(Method); 
		(yystack_[6].value.node)->sType_ = MethodName;
		(yylhs.value.node)->append((yystack_[6].value.node));
<<<<<<< HEAD
		(yylhs.value.node)->append((yystack_[4].value.node));
		(yystack_[1].value.node)->sType_ = ReturnTyp;
		(yylhs.value.node)->append((yystack_[1].value.node));
		(yystack_[0].value.node)->sType_ = Statements;
		(yylhs.value.node)->append((yystack_[0].value.node));
	}
#line 672 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 11:
#line 142 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
		(yylhs.value.node) = new AST::ASTNode(Method);
		(yystack_[4].value.node)->sType_ = MethodName;
		(yylhs.value.node)->append((yystack_[4].value.node));
		(yylhs.value.node)->append((yystack_[2].value.node));
		AST::ASTNode* ret = new AST::ASTNode(Ident, "Nothing");
		ret->sType_ = ReturnTyp;
		(yylhs.value.node)->append(ret);
		(yystack_[0].value.node)->sType_ = Statements;
		(yylhs.value.node)->append((yystack_[0].value.node));
	}
#line 688 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 12:
#line 156 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    { (yylhs.value.node) = new AST::ASTNode(Formal_args); }
#line 694 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 13:
#line 157 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    { (yylhs.value.node) = (yystack_[0].value.node); }
#line 700 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 14:
#line 160 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
=======
		(yylhs.value.node)->append((yystack_[4].value.node));
		(yystack_[1].value.node)->sType_ = ReturnTyp;
		(yylhs.value.node)->append((yystack_[1].value.node));
		(yystack_[0].value.node)->sType_ = Statements;
		(yylhs.value.node)->append((yystack_[0].value.node));
	}
#line 690 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 13:
#line 151 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
		(yylhs.value.node) = new AST::ASTNode(Method);
		(yystack_[4].value.node)->sType_ = MethodName;
		(yylhs.value.node)->append((yystack_[4].value.node));
		(yylhs.value.node)->append((yystack_[2].value.node));
		AST::ASTNode* ret = new AST::ASTNode(Ident, "Nothing");
		ret->sType_ = ReturnTyp;
		(yylhs.value.node)->append(ret);
		(yystack_[0].value.node)->sType_ = Statements;
		(yylhs.value.node)->append((yystack_[0].value.node));
	}
#line 706 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 14:
#line 164 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    { (yylhs.value.node) = new AST::ASTNode(Formal_args); }
#line 712 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 15:
#line 165 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    { (yylhs.value.node) = (yystack_[0].value.node); }
#line 718 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 16:
#line 168 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
>>>>>>> origin/master
    {
		(yylhs.value.node) = (yystack_[2].value.node);
		(yystack_[2].value.node)->append((yystack_[0].value.node));
	}
<<<<<<< HEAD
#line 709 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 15:
#line 164 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
=======
#line 727 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 17:
#line 172 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
>>>>>>> origin/master
    {
		(yylhs.value.node) = new AST::ASTNode(Formal_args);
		(yylhs.value.node)->append((yystack_[0].value.node));
		
<<<<<<< HEAD
	}
#line 719 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 16:
#line 171 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
		(yylhs.value.node) = new AST::ASTNode(ClassArgs);
		(yystack_[2].value.node)->sType_ = VarIdent;
		(yylhs.value.node)->append((yystack_[2].value.node));
		(yystack_[0].value.node)->sType_ = TypeIdent;
		(yylhs.value.node)->append((yystack_[0].value.node));
	}
#line 731 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 17:
#line 181 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
=======
	}
#line 737 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 18:
#line 179 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
		(yylhs.value.node) = new AST::ASTNode(ClassArgs);
		(yystack_[2].value.node)->sType_ = VarIdent;
		(yylhs.value.node)->append((yystack_[2].value.node));
		(yystack_[0].value.node)->sType_ = TypeIdent;
		(yylhs.value.node)->append((yystack_[0].value.node));
	}
#line 749 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 19:
#line 188 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
>>>>>>> origin/master
    { 
		(yylhs.value.node) = new AST::ASTNode(If);
		(yylhs.value.node)->append((yystack_[3].value.node));
		(yystack_[2].value.node)->sType_ = TrueState;
		(yylhs.value.node)->append((yystack_[2].value.node));
		(yylhs.value.node)->append((yystack_[1].value.node));
		(yylhs.value.node)->append((yystack_[0].value.node));
	}
<<<<<<< HEAD
#line 744 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 18:
#line 190 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
		(yylhs.value.node) = new AST::ASTNode(Block);
	}
#line 752 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 19:
#line 193 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
=======
#line 762 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 20:
#line 197 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
		(yylhs.value.node) = new AST::ASTNode(Block);
	}
#line 770 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 21:
#line 200 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
>>>>>>> origin/master
    { 
		(yylhs.value.node) = new AST::ASTNode(Block);
		(yylhs.value.node)->append((yystack_[1].value.node));
		(yylhs.value.node)->append((yystack_[0].value.node));
	}
<<<<<<< HEAD
#line 762 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 20:
#line 199 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
=======
#line 780 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 22:
#line 206 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
>>>>>>> origin/master
    { 
		(yylhs.value.node) = new AST::ASTNode(If);
		(yylhs.value.node)->append((yystack_[1].value.node));
		(yystack_[0].value.node)->sType_ = FalseState;
		(yylhs.value.node)->append((yystack_[0].value.node));
		
	}
<<<<<<< HEAD
#line 774 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 21:
#line 207 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    { (yylhs.value.node) = new AST::ASTNode(Block);
	}
#line 781 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 22:
#line 209 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
		(yystack_[0].value.node)->sType_ = FalseState;
		(yylhs.value.node) = (yystack_[0].value.node); 
	}
#line 790 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 23:
#line 216 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
		(yylhs.value.node) = (yystack_[1].value.node);
       	  }
#line 798 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 24:
#line 221 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    { 
		(yylhs.value.node) = new AST::ASTNode(Block);
		(yylhs.value.node)->sType_ = Statements;
	}
#line 807 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 25:
#line 225 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    { 
		(yylhs.value.node) = (yystack_[1].value.node);
		(yystack_[1].value.node)->append((yystack_[0].value.node));
	}
#line 816 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 26:
#line 231 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
=======
#line 792 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 23:
#line 214 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    { (yylhs.value.node) = new AST::ASTNode(Block);
	}
#line 799 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 24:
#line 216 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
		(yylhs.value.node) = new AST::ASTNode(Block);
		(yystack_[0].value.node)->sType_ = FalseState;
		(yylhs.value.node)->append((yystack_[0].value.node)); 
	}
#line 809 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 25:
#line 223 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
		(yylhs.value.node) = (yystack_[1].value.node);
       	  }
#line 817 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 26:
#line 228 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
>>>>>>> origin/master
    {
		(yylhs.value.node) = new AST::ASTNode(While);
		(yylhs.value.node)->append((yystack_[1].value.node));
		(yylhs.value.node)->append((yystack_[0].value.node));
	}
<<<<<<< HEAD
#line 826 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 27:
#line 238 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
		(yylhs.value.node) = new AST::ASTNode(Assign);
		(yylhs.value.node)->append((yystack_[5].value.node));
		(yystack_[5].value.node)->append((yystack_[3].value.node));
		(yystack_[1].value.node)->sType_ = R_expr;
		(yylhs.value.node)->append((yystack_[1].value.node));
	}
#line 838 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 28:
#line 245 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
=======
#line 827 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 27:
#line 235 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
		(yylhs.value.node) = new AST::ASTNode(Assign);
		(yylhs.value.node)->append((yystack_[5].value.node));
		(yylhs.value.node)->append((yystack_[3].value.node));
		(yystack_[1].value.node)->sType_ = R_expr;
		(yylhs.value.node)->append((yystack_[1].value.node));
	}
#line 839 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 28:
#line 242 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
>>>>>>> origin/master
    {
		(yylhs.value.node) = new AST::ASTNode(Assign);
		(yylhs.value.node)->append((yystack_[3].value.node));
		(yystack_[1].value.node)->sType_ = R_expr;
		(yylhs.value.node)->append((yystack_[1].value.node));
	}
<<<<<<< HEAD
#line 849 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 29:
#line 251 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
		(yylhs.value.node) = (yystack_[1].value.node);
	}
#line 857 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 30:
#line 256 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
=======
#line 850 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 29:
#line 248 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
		(yylhs.value.node) = (yystack_[1].value.node);
	}
#line 858 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 30:
#line 253 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
>>>>>>> origin/master
    {
		(yylhs.value.node) = new AST::ASTNode(Return);
		(yystack_[1].value.node)->sType_ = R_expr;
		(yylhs.value.node)->append((yystack_[1].value.node));
	}
#line 867 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 31:
<<<<<<< HEAD
#line 263 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
=======
#line 260 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
>>>>>>> origin/master
    {
		(yylhs.value.node) = (yystack_[0].value.node);
	}
#line 875 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 32:
<<<<<<< HEAD
#line 269 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
=======
#line 265 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
>>>>>>> origin/master
    {
		(yylhs.value.node) = new AST::ASTNode(Typecase);
		(yylhs.value.node)->append((yystack_[3].value.node));
		(yylhs.value.node)->append((yystack_[1].value.node));
	}
#line 885 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 33:
<<<<<<< HEAD
#line 276 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
=======
#line 272 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
>>>>>>> origin/master
    {
		(yylhs.value.node) = new AST::ASTNode(Type_alt);
		(yylhs.value.node)->append((yystack_[3].value.node));
		(yylhs.value.node)->append((yystack_[1].value.node));
		(yylhs.value.node)->append((yystack_[0].value.node));
	}
<<<<<<< HEAD
#line 896 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 34:
#line 285 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
=======
#line 897 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 34:
#line 280 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
>>>>>>> origin/master
    {
		(yylhs.value.node) = (yystack_[0].value.node);
		(yylhs.value.node)->sType_ = Loc;
	}
#line 905 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 35:
<<<<<<< HEAD
#line 289 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
=======
#line 284 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
>>>>>>> origin/master
    {
		(yylhs.value.node) = new AST::ASTNode(Dot);
		(yylhs.value.node)->sType_ = L_expr;
		(yylhs.value.node)->append((yystack_[2].value.node));
		(yystack_[0].value.node)->sType_ = R_expr;
		(yylhs.value.node)->append((yystack_[0].value.node));
	}
#line 918 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 36:
<<<<<<< HEAD
#line 299 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
=======
#line 293 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
>>>>>>> origin/master
    { 
		(yylhs.value.node) = new AST::ASTNode(Strconst, (yystack_[0].value.str));
	}
#line 926 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 37:
<<<<<<< HEAD
#line 302 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
=======
#line 296 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
>>>>>>> origin/master
    {
		(yylhs.value.node) = new AST::ASTNode(Intconst, (yystack_[0].value.num));
	}
#line 934 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 38:
<<<<<<< HEAD
#line 305 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
=======
#line 299 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
>>>>>>> origin/master
    {
		(yylhs.value.node) = new AST::ASTNode(Load);
		(yylhs.value.node)->append((yystack_[0].value.node));
		(yylhs.value.node)->sType_ = L_expr;
	}
<<<<<<< HEAD
#line 943 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 39:
#line 310 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
=======
#line 944 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 39:
#line 304 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
>>>>>>> origin/master
    { 
		(yylhs.value.node) = new AST::ASTNode(Call);
		(yylhs.value.node)->sType_ = Plus;
		(yylhs.value.node)->append((yystack_[2].value.node));
<<<<<<< HEAD
		AST::ASTNode* nm = new AST::ASTNode(Plus);
=======
		AST::ASTNode* nm = new AST::ASTNode(Ident, "Plus");
>>>>>>> origin/master
		nm->sType_ = Method;
		(yylhs.value.node)->append(nm);
		AST::ASTNode *a = new AST::ASTNode(Actual_args);
		a->append((yystack_[0].value.node));
		(yylhs.value.node)->append(a);
	 }
<<<<<<< HEAD
#line 959 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 40:
#line 321 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
=======
#line 960 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 40:
#line 315 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
>>>>>>> origin/master
    {
		(yylhs.value.node) = new AST::ASTNode(Call);
		(yylhs.value.node)->sType_ = Minus;
		(yylhs.value.node)->append((yystack_[2].value.node));
<<<<<<< HEAD
		AST::ASTNode* nm = new AST::ASTNode(Minus);
=======
		AST::ASTNode* nm = new AST::ASTNode(Ident, "Minus");
>>>>>>> origin/master
		nm->sType_ = Method;
		(yylhs.value.node)->append(nm);
		AST::ASTNode *a = new AST::ASTNode(Actual_args);
		a->append((yystack_[0].value.node));
		(yylhs.value.node)->append(a);
	}
<<<<<<< HEAD
#line 975 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 41:
#line 332 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
=======
#line 976 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 41:
#line 326 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
>>>>>>> origin/master
    {
		(yylhs.value.node) = new AST::ASTNode(Call);
		(yylhs.value.node)->sType_ = Mult;
		(yylhs.value.node)->append((yystack_[2].value.node));
<<<<<<< HEAD
		AST::ASTNode* nm = new AST::ASTNode(Mult);
=======
		AST::ASTNode* nm = new AST::ASTNode(Ident, "Mult");
>>>>>>> origin/master
		nm->sType_ = Method;
		(yylhs.value.node)->append(nm);
		AST::ASTNode *a = new AST::ASTNode(Actual_args);
		a->append((yystack_[0].value.node));
		(yylhs.value.node)->append(a);
	}
<<<<<<< HEAD
#line 991 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 42:
#line 343 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
=======
#line 992 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 42:
#line 337 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
>>>>>>> origin/master
    {
		(yylhs.value.node) = new AST::ASTNode(Call);
		(yylhs.value.node)->sType_ = Div;
		(yylhs.value.node)->append((yystack_[2].value.node));
<<<<<<< HEAD
		AST::ASTNode* nm = new AST::ASTNode(Div);
=======
		AST::ASTNode* nm = new AST::ASTNode(Ident, "Div");
>>>>>>> origin/master
		nm->sType_ = Method;
		(yylhs.value.node)->append(nm);
		AST::ASTNode *a = new AST::ASTNode(Actual_args);
		a->append((yystack_[0].value.node));
		(yylhs.value.node)->append(a);
	}
<<<<<<< HEAD
#line 1007 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 43:
#line 354 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
=======
#line 1008 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 43:
#line 348 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
>>>>>>> origin/master
    {
		(yylhs.value.node) = new AST::ASTNode(Minus);
		(yylhs.value.node)->append((yystack_[0].value.node));
	}
<<<<<<< HEAD
#line 1016 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 44:
#line 358 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
		(yylhs.value.node) = (yystack_[1].value.node);
	}
#line 1024 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 45:
#line 364 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
=======
#line 1017 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 44:
#line 352 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
		(yylhs.value.node) = (yystack_[1].value.node);
	}
#line 1025 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 45:
#line 358 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
>>>>>>> origin/master
    {
		(yylhs.value.node) = new AST::ASTNode(Call);
		(yylhs.value.node)->sType_ = Equals;
		(yylhs.value.node)->append((yystack_[2].value.node));
<<<<<<< HEAD
		AST::ASTNode* nm = new AST::ASTNode(Equals);
=======
		AST::ASTNode* nm = new AST::ASTNode(Ident, "Equals");
>>>>>>> origin/master
		nm->sType_ = Method;
		(yylhs.value.node)->append(nm);
		AST::ASTNode *a = new AST::ASTNode(Actual_args);
		a->append((yystack_[0].value.node));
		(yylhs.value.node)->append(a);
	}
<<<<<<< HEAD
#line 1040 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 46:
#line 375 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
=======
#line 1041 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 46:
#line 369 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
>>>>>>> origin/master
    {
		(yylhs.value.node) = new AST::ASTNode(Call);
		(yylhs.value.node)->sType_ = AtMost;
		(yylhs.value.node)->append((yystack_[2].value.node));
<<<<<<< HEAD
		AST::ASTNode* nm = new AST::ASTNode(AtMost);
=======
		AST::ASTNode* nm = new AST::ASTNode(Ident, "AtMost");
>>>>>>> origin/master
		nm->sType_ = Method;
		(yylhs.value.node)->append(nm);
		AST::ASTNode *a = new AST::ASTNode(Actual_args);
		a->append((yystack_[0].value.node));
		(yylhs.value.node)->append(a);
	}
<<<<<<< HEAD
#line 1056 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 47:
#line 386 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
=======
#line 1057 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 47:
#line 380 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
>>>>>>> origin/master
    {
		(yylhs.value.node) = new AST::ASTNode(Call);
		(yylhs.value.node)->sType_ = AtLeast;
		(yylhs.value.node)->append((yystack_[2].value.node));
<<<<<<< HEAD
		AST::ASTNode* nm = new AST::ASTNode(AtLeast);
=======
		AST::ASTNode* nm = new AST::ASTNode(Ident, "AtLeast");
>>>>>>> origin/master
		nm->sType_ = Method;
		(yylhs.value.node)->append(nm);
		AST::ASTNode *a = new AST::ASTNode(Actual_args);
		a->append((yystack_[0].value.node));
		(yylhs.value.node)->append(a);
	}
<<<<<<< HEAD
#line 1072 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 48:
#line 397 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
=======
#line 1073 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 48:
#line 391 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
>>>>>>> origin/master
    {
		(yylhs.value.node) = new AST::ASTNode(Call);
		(yylhs.value.node)->sType_ = Less;
		(yylhs.value.node)->append((yystack_[2].value.node));
<<<<<<< HEAD
		AST::ASTNode* nm = new AST::ASTNode(Less);
=======
		AST::ASTNode* nm = new AST::ASTNode(Ident, "Less");
>>>>>>> origin/master
		nm->sType_ = Method;
		(yylhs.value.node)->append(nm);
		AST::ASTNode *a = new AST::ASTNode(Actual_args);
		a->append((yystack_[0].value.node));
		(yylhs.value.node)->append(a);
	}
<<<<<<< HEAD
#line 1088 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 49:
#line 408 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
=======
#line 1089 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 49:
#line 402 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
>>>>>>> origin/master
    {
		(yylhs.value.node) = new AST::ASTNode(Call);
		(yylhs.value.node)->sType_ = Greater;
		(yylhs.value.node)->append((yystack_[2].value.node));
<<<<<<< HEAD
		AST::ASTNode* nm = new AST::ASTNode(Greater);
=======
		AST::ASTNode* nm = new AST::ASTNode(Ident, "Greater");
>>>>>>> origin/master
		nm->sType_ = Method;
		(yylhs.value.node)->append(nm);
		AST::ASTNode *a = new AST::ASTNode(Actual_args);
		a->append((yystack_[0].value.node));
		(yylhs.value.node)->append(a);
	}
<<<<<<< HEAD
#line 1104 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 50:
#line 419 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
=======
#line 1105 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 50:
#line 413 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
>>>>>>> origin/master
    {
		(yylhs.value.node) = new AST::ASTNode(Call);
		(yylhs.value.node)->sType_ = And;
		(yylhs.value.node)->append((yystack_[2].value.node));
<<<<<<< HEAD
		AST::ASTNode* nm = new AST::ASTNode(And);
=======
		AST::ASTNode* nm = new AST::ASTNode(Ident, "And");
>>>>>>> origin/master
		nm->sType_ = Method;
		(yylhs.value.node)->append(nm);
		AST::ASTNode *a = new AST::ASTNode(Actual_args);
		a->append((yystack_[0].value.node));
		(yylhs.value.node)->append(a);
	}
<<<<<<< HEAD
#line 1120 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 51:
#line 430 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
=======
#line 1121 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 51:
#line 424 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
>>>>>>> origin/master
    { 
		(yylhs.value.node) = new AST::ASTNode(Call);
		(yylhs.value.node)->sType_ = Or;
		(yylhs.value.node)->append((yystack_[2].value.node));
<<<<<<< HEAD
		AST::ASTNode* nm = new AST::ASTNode(Or);
=======
		AST::ASTNode* nm = new AST::ASTNode(Ident, "Or");
>>>>>>> origin/master
		nm->sType_ = Method;
		(yylhs.value.node)->append(nm);
		AST::ASTNode *a = new AST::ASTNode(Actual_args);
		a->append((yystack_[0].value.node));
		(yylhs.value.node)->append(a);
	}
<<<<<<< HEAD
#line 1136 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 52:
#line 441 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
=======
#line 1137 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 52:
#line 435 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
>>>>>>> origin/master
    {
		(yylhs.value.node) = new AST::ASTNode(Not);
		(yylhs.value.node)->append((yystack_[0].value.node));
	}
<<<<<<< HEAD
#line 1145 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 53:
#line 447 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
=======
#line 1146 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 53:
#line 441 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
>>>>>>> origin/master
    {
		(yylhs.value.node) = new AST::ASTNode(Call);
		(yylhs.value.node)->append((yystack_[5].value.node));
		(yystack_[3].value.node)->sType_ = Method;
		(yylhs.value.node)->append((yystack_[3].value.node));
		(yylhs.value.node)->append((yystack_[1].value.node));
	}
<<<<<<< HEAD
#line 1157 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 54:
#line 455 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
=======
#line 1158 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 54:
#line 449 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
>>>>>>> origin/master
    {
		(yylhs.value.node) = new AST::ASTNode(Constructor);
		(yylhs.value.node)->append((yystack_[3].value.node));
		(yylhs.value.node)->append((yystack_[1].value.node));
	}
<<<<<<< HEAD
#line 1167 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 55:
#line 464 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    { (yylhs.value.node) = new AST::ASTNode(Actual_args); }
#line 1173 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 56:
#line 466 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
=======
#line 1168 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 55:
#line 457 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    { (yylhs.value.node) = new AST::ASTNode(Actual_args); }
#line 1174 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 56:
#line 459 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
>>>>>>> origin/master
    {
		(yylhs.value.node) = new AST::ASTNode(Actual_args);
		(yylhs.value.node)->append((yystack_[2].value.node));
		(yylhs.value.node)->append((yystack_[0].value.node));
	}
<<<<<<< HEAD
#line 1183 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 57:
#line 471 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
=======
#line 1184 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 57:
#line 464 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
>>>>>>> origin/master
    {
		(yylhs.value.node) = new AST::ASTNode(MethodArg);
		(yylhs.value.node)->append((yystack_[0].value.node));
	}
<<<<<<< HEAD
#line 1192 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 58:
#line 478 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
		(yylhs.value.node) = new AST::ASTNode(Ident, (yystack_[0].value.str));
	}
#line 1200 "quack.tab.cxx" // lalr1.cc:870
    break;


#line 1204 "quack.tab.cxx" // lalr1.cc:870
=======
#line 1193 "quack.tab.cxx" // lalr1.cc:870
    break;

  case 58:
#line 470 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:870
    {
		(yylhs.value.node) = new AST::ASTNode(Ident, (yystack_[0].value.str));
	}
#line 1201 "quack.tab.cxx" // lalr1.cc:870
    break;


#line 1205 "quack.tab.cxx" // lalr1.cc:870
>>>>>>> origin/master
            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
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
    if (!yyla.empty ())
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
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char parser::yypact_ninf_ = -51;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
<<<<<<< HEAD
     -51,    10,    50,   -51,     0,   -51,     3,   -51,    42,   -51,
     -51,    76,    76,    76,    76,    76,    76,    76,   -51,   -51,
     -16,   129,    58,     0,   -51,   147,   201,   214,   214,    22,
      28,   227,   -18,     0,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,     0,   -51,    76,    49,
      54,   -51,    57,   -51,     0,   -51,   -51,   -51,   -51,    76,
      56,   165,    22,    22,    22,    22,    22,    -2,    -2,    28,
      28,    65,    65,    67,    -3,    88,     0,     0,    66,    69,
     115,    72,   227,    76,   -51,    76,   -51,     0,    68,   -51,
     -51,   -51,     0,   -51,    76,    75,   -51,   -51,   183,    -1,
     -51,   -51,   -51,   214,   -51,   -51,   -51,     3,     3,   -51,
       2,     0,   -51,   -51,    71,     0,    80,    44,     0,   -51,
      75,   -51
=======
     -51,     4,    20,   -51,     7,    50,   -51,   -51,    13,   -51,
     -51,    19,    19,    19,    19,    19,    19,    19,   -51,   -51,
     -16,   114,    17,     7,   -51,   132,   196,   209,   209,   229,
      12,   222,   -18,     7,    19,    19,    19,    19,    19,    19,
      19,    19,    19,    19,    19,    19,     7,   -51,    19,     1,
      23,   -51,    25,   -51,     7,   -51,   -51,   -51,   -51,    19,
      24,   160,   229,   229,   229,   229,   229,   137,   137,    12,
      12,     8,     8,    34,    -8,    55,     7,     7,    35,    33,
       3,    36,   222,    19,   -51,    19,   -51,     7,    39,   -51,
     -51,   -51,     7,   -51,    19,    40,   -51,   -51,   178,    -1,
     -51,   -51,   -51,   209,   -51,   -51,   -51,    50,    50,   -51,
       2,     7,   -51,   -51,    43,     7,    46,    14,     7,   -51,
      40,   -51
>>>>>>> origin/master
  };

  const unsigned char
  parser::yydefact_[] =
  {
<<<<<<< HEAD
       3,     0,    24,     1,     0,     4,     2,    58,     0,    36,
      37,     0,     0,     0,     0,     0,     0,    55,    25,    31,
      38,     0,    34,    12,    38,     0,     0,     0,     0,    52,
      43,    57,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    29,    55,     0,
      13,    15,     0,    30,     0,    24,    18,    26,    44,     0,
       0,     0,    50,    51,    45,    46,    47,    48,    49,    39,
      40,    42,    41,    35,     0,     6,     0,     0,     0,     0,
       0,    21,    56,     0,    28,    55,    54,     0,     0,    14,
      16,    32,     0,    23,     0,     0,    19,    17,     0,     0,
       7,    24,    24,     0,    22,    27,    53,     8,    33,    20,
       0,     0,     5,     9,     0,    12,     0,     0,     0,    11,
       0,    10
=======
       3,     0,     5,     1,     0,     2,     4,    58,     0,    36,
      37,     0,     0,     0,     0,     0,     0,    55,     6,    31,
      38,     0,    34,    14,    38,     0,     0,     0,     0,    52,
      43,    57,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    29,    55,     0,
      15,    17,     0,    30,     0,     5,    20,    26,    44,     0,
       0,     0,    50,    51,    45,    46,    47,    48,    49,    39,
      40,    42,    41,    35,     0,     8,     0,     0,     0,     0,
       0,    23,    56,     0,    28,    55,    54,     0,     0,    16,
      18,    32,     0,    25,     0,     0,    21,    19,     0,     0,
       9,     5,     5,     0,    24,    27,    53,    10,    33,    22,
       0,     0,     7,    11,     0,    14,     0,     0,     0,    13,
       0,    12
>>>>>>> origin/master
  };

  const signed char
  parser::yypgoto_[] =
  {
<<<<<<< HEAD
     -51,   -51,   -51,   -51,   -51,   -51,   -51,     1,   -51,    34,
     -51,   -51,   -51,   -51,   -26,   -50,   -51,   -51,    -5,    23,
     -44,    -4
=======
     -51,   -51,   -51,   -50,   -51,   -51,   -51,   -51,   -36,   -51,
       5,   -51,   -51,   -51,   -51,   -27,   -51,   -51,    -3,    83,
     -45,    -4
>>>>>>> origin/master
  };

  const signed char
  parser::yydefgoto_[] =
  {
<<<<<<< HEAD
      -1,     1,     2,     5,    88,   110,   113,    49,    50,    51,
      18,    81,    96,    97,    56,     6,    19,    78,    24,    21,
=======
      -1,     1,     2,     5,     6,    88,   110,   113,    49,    50,
      51,    18,    81,    96,    97,    56,    19,    78,    24,    21,
>>>>>>> origin/master
      32,    22
  };

  const unsigned char
  parser::yytable_[] =
  {
<<<<<<< HEAD
       8,    20,    57,     7,    74,    80,     7,     9,    10,   111,
       3,    58,    11,    12,    13,    59,    33,    14,    34,    52,
      15,    42,    43,    44,    45,    46,    86,    16,   106,    60,
      59,    17,    59,   112,    25,    26,    27,    28,    29,    30,
      31,    99,    73,    40,    41,    42,    43,    44,    45,    46,
      79,   107,   108,    44,    45,    46,     4,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,   104,
      23,    31,    52,    90,    55,    20,   118,   109,    75,     7,
       9,    10,    82,   100,    94,    95,    48,    76,   102,    77,
      83,   119,    46,    15,   121,    85,    87,    91,   101,   115,
      16,    92,    20,    20,    17,    55,    98,   114,    31,   117,
      89,    52,     0,     0,   120,     0,   116,   103,     7,     9,
      10,     0,     0,     0,    11,    12,    13,     0,     0,    14,
       0,     0,    15,     0,     0,     0,     0,     0,     0,    16,
       0,     0,     0,    17,    35,    36,    93,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,     0,     0,     0,
       0,     0,    35,    36,    47,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,     0,     0,     0,     0,     0,
      35,    36,    53,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,     0,     0,     0,     0,     0,    35,    36,
      84,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,     0,     0,     0,     0,     0,    35,    36,   105,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    35,
      36,    54,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    35,    36,    55,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46
=======
       8,    57,    20,    74,     3,    80,     7,     9,    10,   111,
       7,    58,    11,    12,    13,    59,    33,    14,    34,    52,
      15,    86,     7,     9,    10,    59,     4,    16,   106,    60,
      75,    17,    59,   112,    93,    46,    15,    44,    45,    46,
      99,    23,    73,    16,    55,    48,   118,    17,    94,    95,
      79,   107,   108,     7,     9,    10,    76,    77,    83,    11,
      12,    13,    85,    87,    14,    92,    91,    15,   104,   101,
      55,   115,    52,    90,    16,   117,   109,    20,    17,   116,
       0,    89,     0,   100,     0,     0,     0,     0,   102,     0,
     119,     0,     0,   121,    25,    26,    27,    28,    29,    30,
      31,     0,     0,     0,    20,    20,     0,   114,     0,     0,
       0,    52,     0,     0,   120,     0,     0,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    35,
      36,    31,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    82,     0,     0,     0,     0,    35,    36,    47,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      42,    43,    44,    45,    46,     0,    98,    53,    31,     0,
       0,     0,     0,     0,     0,    35,    36,   103,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,     0,     0,
       0,     0,     0,    35,    36,    84,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,     0,     0,     0,     0,
       0,    35,    36,   105,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    35,    36,    54,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    35,    36,    55,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      40,    41,    42,    43,    44,    45,    46
>>>>>>> origin/master
  };

  const signed char
  parser::yycheck_[] =
  {
<<<<<<< HEAD
       4,     6,    28,     3,    48,    55,     3,     4,     5,     7,
       0,    29,     9,    10,    11,    33,    32,    14,    34,    23,
      17,    23,    24,    25,    26,    27,    29,    24,    29,    33,
      33,    28,    33,    31,    11,    12,    13,    14,    15,    16,
      17,    85,    46,    21,    22,    23,    24,    25,    26,    27,
      54,   101,   102,    25,    26,    27,     6,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    95,
      28,    48,    76,    77,    30,    80,    32,   103,    29,     3,
       4,     5,    59,    87,    12,    13,    28,    33,    92,    32,
      34,   117,    27,    17,   120,    28,     8,    31,    30,    28,
      24,    32,   107,   108,    28,    30,    83,   111,    85,    29,
      76,   115,    -1,    -1,   118,    -1,   115,    94,     3,     4,
       5,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,
      -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    28,    15,    16,    31,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,    -1,    15,    16,    35,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,
      15,    16,    35,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,    -1,    15,    16,
      35,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,    -1,    15,    16,    35,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    15,
      16,    30,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    15,    16,    30,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27
=======
       4,    28,     5,    48,     0,    55,     3,     4,     5,     7,
       3,    29,     9,    10,    11,    33,    32,    14,    34,    23,
      17,    29,     3,     4,     5,    33,     6,    24,    29,    33,
      29,    28,    33,    31,    31,    27,    17,    25,    26,    27,
      85,    28,    46,    24,    30,    28,    32,    28,    12,    13,
      54,   101,   102,     3,     4,     5,    33,    32,    34,     9,
      10,    11,    28,     8,    14,    32,    31,    17,    95,    30,
      30,    28,    76,    77,    24,    29,   103,    80,    28,   115,
      -1,    76,    -1,    87,    -1,    -1,    -1,    -1,    92,    -1,
     117,    -1,    -1,   120,    11,    12,    13,    14,    15,    16,
      17,    -1,    -1,    -1,   107,   108,    -1,   111,    -1,    -1,
      -1,   115,    -1,    -1,   118,    -1,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    15,
      16,    48,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    59,    -1,    -1,    -1,    -1,    15,    16,    35,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      23,    24,    25,    26,    27,    -1,    83,    35,    85,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    94,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    -1,    -1,    15,    16,    35,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    -1,
      -1,    15,    16,    35,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    15,    16,    30,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    15,    16,    30,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      21,    22,    23,    24,    25,    26,    27
>>>>>>> origin/master
  };

  const unsigned char
  parser::yystos_[] =
  {
<<<<<<< HEAD
       0,    37,    38,     0,     6,    39,    51,     3,    57,     4,
       5,     9,    10,    11,    14,    17,    24,    28,    46,    52,
      54,    55,    57,    28,    54,    55,    55,    55,    55,    55,
      55,    55,    56,    32,    34,    15,    16,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    35,    28,    43,
      44,    45,    57,    35,    30,    30,    50,    50,    29,    33,
      57,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    57,    56,    29,    33,    32,    53,    57,
      51,    47,    55,    34,    35,    28,    29,     8,    40,    45,
      57,    31,    32,    31,    12,    13,    48,    49,    55,    56,
      57,    30,    57,    55,    50,    35,    29,    51,    51,    50,
      41,     7,    31,    42,    57,    28,    43,    29,    32,    50,
      57,    50
=======
       0,    37,    38,     0,     6,    39,    40,     3,    57,     4,
       5,     9,    10,    11,    14,    17,    24,    28,    47,    52,
      54,    55,    57,    28,    54,    55,    55,    55,    55,    55,
      55,    55,    56,    32,    34,    15,    16,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    35,    28,    44,
      45,    46,    57,    35,    30,    30,    51,    51,    29,    33,
      57,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    57,    56,    29,    33,    32,    53,    57,
      39,    48,    55,    34,    35,    28,    29,     8,    41,    46,
      57,    31,    32,    31,    12,    13,    49,    50,    55,    56,
      57,    30,    57,    55,    51,    35,    29,    39,    39,    51,
      42,     7,    31,    43,    57,    28,    44,    29,    32,    51,
      57,    51
>>>>>>> origin/master
  };

  const unsigned char
  parser::yyr1_[] =
  {
<<<<<<< HEAD
       0,    36,    37,    38,    38,    39,    40,    40,    41,    41,
      42,    42,    43,    43,    44,    44,    45,    46,    47,    47,
      48,    49,    49,    50,    51,    51,    46,    46,    46,    46,
      46,    46,    52,    53,    54,    54,    55,    55,    55,    55,
=======
       0,    36,    37,    38,    38,    39,    39,    40,    41,    41,
      42,    42,    43,    43,    44,    44,    45,    45,    46,    47,
      48,    48,    49,    50,    50,    51,    47,    47,    47,    47,
      47,    47,    52,    53,    54,    54,    55,    55,    55,    55,
>>>>>>> origin/master
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    56,    56,    56,    57
  };

  const unsigned char
  parser::yyr2_[] =
  {
<<<<<<< HEAD
       0,     2,     2,     0,     2,    10,     0,     2,     0,     2,
       8,     6,     0,     1,     3,     1,     3,     5,     0,     2,
       3,     0,     2,     3,     0,     2,     3,     6,     4,     2,
=======
       0,     2,     2,     0,     2,     0,     2,    10,     0,     2,
       0,     2,     8,     6,     0,     1,     3,     1,     3,     5,
       0,     2,     3,     0,     2,     3,     3,     6,     4,     2,
>>>>>>> origin/master
       3,     1,     5,     4,     1,     3,     1,     1,     1,     3,
       3,     3,     3,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     6,     4,     0,     3,     1,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "$end", "error", "$undefined", "IDENT", "STR_LIT", "INT_LIT", "CLASS",
  "DEF", "EXTENDS", "RETURN", "TYPECASE", "IF", "ELIF", "ELSE", "WHILE",
  "AND", "OR", "NOT", "EQUALS", "ATMOST", "ATLEAST", "'<'", "'>'", "'+'",
  "'-'", "'/'", "'*'", "'.'", "'('", "')'", "'{'", "'}'", "':'", "','",
<<<<<<< HEAD
  "'='", "';'", "$accept", "program", "classes", "class", "extends",
  "methods", "method", "formal_arg_list", "formal_args", "formal_arg",
  "statement", "elifs", "elif", "else", "statement_block", "statements",
=======
  "'='", "';'", "$accept", "program", "classes", "statements", "class",
  "extends", "methods", "method", "formal_arg_list", "formal_args",
  "formal_arg", "statement", "elifs", "elif", "else", "statement_block",
>>>>>>> origin/master
  "typecase", "type_alt", "l_expr", "r_expr", "actual_args", "ident", YY_NULLPTR
  };


  const unsigned short
  parser::yyrline_[] =
  {
<<<<<<< HEAD
       0,    76,    76,    85,    86,    92,   114,   117,   124,   125,
     131,   142,   156,   157,   160,   164,   171,   181,   190,   193,
     199,   207,   209,   216,   221,   225,   231,   238,   245,   251,
     256,   263,   269,   276,   285,   289,   299,   302,   305,   310,
     321,   332,   343,   354,   358,   364,   375,   386,   397,   408,
     419,   430,   441,   447,   455,   464,   466,   471,   478
=======
       0,    75,    75,    84,    85,    91,    95,   101,   123,   126,
     133,   134,   140,   151,   164,   165,   168,   172,   179,   188,
     197,   200,   206,   214,   216,   223,   228,   235,   242,   248,
     253,   260,   265,   272,   280,   284,   293,   296,   299,   304,
     315,   326,   337,   348,   352,   358,   369,   380,   391,   402,
     413,   424,   435,   441,   449,   457,   459,   464,   470
>>>>>>> origin/master
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  parser::token_number_type
  parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      28,    29,    26,    23,    33,    24,    27,    25,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    32,    35,
      21,    34,    22,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    30,     2,    31,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20
    };
    const unsigned user_token_number_max_ = 275;
    const token_number_type undef_token_ = 2;

    if (static_cast<int> (t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // yy
<<<<<<< HEAD
#line 1638 "quack.tab.cxx" // lalr1.cc:1181
#line 482 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:1182
=======
#line 1639 "quack.tab.cxx" // lalr1.cc:1181
#line 473 "/Users/trevorbergstrom/NewCompiler/quack.yxx" // lalr1.cc:1182
>>>>>>> origin/master

#include "Messages.h"

void yy::parser::error(const location_type& loc, const std::string& msg)
{
  report::error_at(loc, msg);
}

void dump(AST::ASTNode* n) {
    // std::cout << "*** Building: " << n->str() << std::endl;
}
