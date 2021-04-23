/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

	#include<stdio.h>
	#include<stdlib.h>

	#ifndef EXPTREE_H
	#define EXPTREE_H
	#include"exptree.h"
	#endif

	#ifndef SYMBOLS_H
	#define SYMBOLS_H
	#include "symbol_table.h"
	#endif

	#ifndef TYPES_H
	#define TYPES_H
	#include "type_table.h"
	#endif

	#include "exptree.c"
	#include "compiler.c"
	#include "symbol_table.c"
	#include "type_table.c"

	int yylex(void);
	void yyerror(const char *s);
	int getfLabel();

	// int yydebug = 1;
	int flabel = 0;

#line 102 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    START = 258,
    END = 259,
    DECL = 260,
    ENDDECL = 261,
    IF = 262,
    THEN = 263,
    ELSE = 264,
    ENDIF = 265,
    WHILE = 266,
    DO = 267,
    ENDWHILE = 268,
    READ = 269,
    WRITE = 270,
    CONTINUE = 271,
    BREAK = 272,
    REPEAT = 273,
    UNTIL = 274,
    MAIN = 275,
    ARGS = 276,
    RETURN = 277,
    ALLOC = 278,
    DEALLOC = 279,
    INT = 280,
    STR = 281,
    TYPE = 282,
    ENDTYPE = 283,
    NUM = 284,
    VAR = 285,
    ADD = 286,
    SUB = 287,
    MUL = 288,
    DIV = 289,
    EQUALS = 290,
    SLT = 291,
    SGT = 292,
    LTE = 293,
    GTE = 294,
    NEQ = 295,
    EQU = 296,
    STRING = 297,
    ARR_INDEX = 298
  };
#endif
/* Tokens.  */
#define START 258
#define END 259
#define DECL 260
#define ENDDECL 261
#define IF 262
#define THEN 263
#define ELSE 264
#define ENDIF 265
#define WHILE 266
#define DO 267
#define ENDWHILE 268
#define READ 269
#define WRITE 270
#define CONTINUE 271
#define BREAK 272
#define REPEAT 273
#define UNTIL 274
#define MAIN 275
#define ARGS 276
#define RETURN 277
#define ALLOC 278
#define DEALLOC 279
#define INT 280
#define STR 281
#define TYPE 282
#define ENDTYPE 283
#define NUM 284
#define VAR 285
#define ADD 286
#define SUB 287
#define MUL 288
#define DIV 289
#define EQUALS 290
#define SLT 291
#define SGT 292
#define LTE 293
#define GTE 294
#define NEQ 295
#define EQU 296
#define STRING 297
#define ARR_INDEX 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 35 "parser.y"

	struct tnode* node;
	int integer;
	char* string;
	struct Param* fparams;
	struct FieldlistNode* fieldnode;
	struct TypetableNode* typenode;

#line 249 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   461

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  214

#define YYUNDEFTOK  2
#define YYMAXUTOK   298


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      50,    51,     2,     2,    47,     2,    52,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    46,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    48,     2,    49,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,    45,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   115,   115,   116,   117,   118,   125,   124,   131,   130,
     138,   139,   144,   144,   155,   159,   167,   175,   176,   177,
     182,   186,   187,   191,   195,   196,   197,   200,   201,   202,
     203,   204,   205,   211,   212,   218,   216,   232,   233,   234,
     238,   239,   240,   244,   251,   252,   256,   257,   261,   265,
     266,   270,   276,   285,   286,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   303,   307,   311,   314,   317,
     320,   321,   325,   326,   327,   331,   332,   336,   340,   344,
     345,   346,   347,   348,   349,   353,   354,   355,   356,   360,
     361,   362,   363,   364,   365,   369,   370,   374,   375,   376,
     380,   381,   385,   386,   387
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "START", "END", "DECL", "ENDDECL", "IF",
  "THEN", "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE", "READ", "WRITE",
  "CONTINUE", "BREAK", "REPEAT", "UNTIL", "MAIN", "ARGS", "RETURN",
  "ALLOC", "DEALLOC", "INT", "STR", "TYPE", "ENDTYPE", "NUM", "VAR", "ADD",
  "SUB", "MUL", "DIV", "EQUALS", "SLT", "SGT", "LTE", "GTE", "NEQ", "EQU",
  "STRING", "ARR_INDEX", "'{'", "'}'", "';'", "','", "'['", "']'", "'('",
  "')'", "'.'", "$accept", "code", "typedefSection", "$@1", "$@2",
  "typedefList", "typeDefinition", "$@3", "fieldList", "fieldDeclaration",
  "fieldType", "globalDeclarations", "declarationList", "declaration",
  "dataType", "variableList", "functionDefinitionList",
  "functionDefinition", "$@4", "returnType", "parameterList", "parameter",
  "localDeclarationBlock", "localDeclarationList", "localDeclaration",
  "localVariableList", "functionBody", "mainFunction", "statementList",
  "statement", "inputStatement", "outputStatement", "allocStatement",
  "deAllocStatement", "assignmentStatement", "ifStatement",
  "whileStatement", "jumpStatement", "functionCallStatement",
  "returnStatement", "expression", "arithmeticExpression",
  "logicalExpression", "constant", "variable", "field", "argList", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   123,   125,    59,    44,    91,    93,
      40,    41,    46
};
# endif

#define YYPACT_NINF (-93)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-78)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      25,    -2,   -17,   -20,    44,    62,    45,   -93,   -93,   -93,
     -93,    10,   -93,    59,    52,    65,    94,   -93,   118,   -17,
     -93,   -93,    45,   -93,    95,   -93,   -93,   -93,    24,   130,
      89,   -93,    54,   -93,   -93,   -93,    45,   -93,   -93,   113,
     116,    -2,   -93,   148,   122,   144,   -93,   -93,   -93,    -2,
     131,   159,    60,   -93,   110,   185,   125,    63,   -93,   -93,
      -2,   -93,   162,    -2,    -2,   215,   -93,   -93,   -93,   -19,
     -93,   164,   151,   -93,   143,    91,   175,    43,   -93,   156,
     161,   215,   163,   167,   -93,   -93,   215,    67,   168,   -93,
      29,   -93,    67,   117,   166,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   398,   -93,   -93,   -93,   -93,
     -93,   173,   -93,   174,   185,   -93,   -93,   -93,   136,   -93,
     -93,    67,    67,   244,    67,    67,     3,    71,   409,    67,
      67,    67,   179,   251,   -93,   177,   -93,    67,    67,    67,
      67,   107,    67,    67,    67,    67,    67,    67,   -93,   -93,
     -93,   -93,   184,   267,   283,   171,   299,   315,   188,    67,
     331,   379,   409,   105,   182,   -93,   -93,   -93,   120,   120,
     -93,   -93,   190,   409,   420,   420,   420,   420,   420,   420,
     215,   -93,   216,   213,    67,   -93,   -93,    67,   114,   -93,
     -93,    67,   189,   191,   196,   215,   215,   215,   347,   363,
     -93,   409,   -93,   -93,    76,   157,   172,   -93,   215,   -93,
     -93,   -93,   186,   -93
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     6,     0,     0,     0,     5,    24,    25,
      26,     0,    22,     0,     0,     0,     0,     1,     0,    37,
      38,    39,     0,    34,     0,     4,    20,    21,    30,     0,
       0,    12,     0,    11,     9,    37,     0,    33,     3,     0,
       0,    42,    23,     0,     0,     0,     7,    10,     2,    42,
       0,     0,     0,    41,    27,    45,     0,     0,    31,    43,
       0,    32,     0,    42,     0,     0,    17,    18,    19,     0,
      15,     0,     0,    40,     0,     0,     0,     0,    47,     0,
       0,     0,     0,     0,    75,    76,     0,     0,     0,    95,
      98,    96,     0,     0,     0,    55,    56,    63,    64,    57,
      58,    59,    60,    61,    62,     0,    81,    82,    83,    84,
      99,     0,    14,     0,    45,    28,    29,    50,     0,    44,
      46,     0,     0,     0,     0,     0,     0,    98,    78,     0,
       0,   104,     0,     0,    52,     0,    54,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    13,    16,
      35,    48,     0,     0,     0,     0,     0,     0,     0,   104,
       0,     0,   103,     0,   101,   100,    79,    53,    85,    86,
      87,    88,     0,    69,    89,    90,    91,    92,    93,    94,
       0,    49,     0,     0,     0,    65,    66,     0,     0,    68,
      97,     0,    80,     0,     0,    51,     0,     0,     0,     0,
      80,   102,    67,    36,     0,     0,     0,    74,     0,    71,
      72,    73,     0,    70
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -93,   -93,   -93,   -93,   -93,   -93,   211,   -93,   -93,   178,
     -93,   241,   -93,   237,     1,   -93,   231,    15,   -93,   -93,
      17,   192,   139,   -93,   187,   -93,   -93,     7,   -81,   -92,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -83,   -93,   -93,   -93,   -93,   135,   104
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,    15,    16,    32,    33,    45,    69,    70,
      71,     6,    11,    12,    51,    29,    22,    23,   180,    24,
      52,    53,    65,    77,    78,   118,   194,     7,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   163
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     123,   135,    13,    14,   128,   126,    66,    67,    -8,   133,
      79,    68,    13,    25,    80,    81,    26,    82,    83,    84,
      85,    86,   158,     8,     9,    87,   111,    88,    10,    38,
       1,   135,    89,    90,   135,     8,     9,    37,   153,   154,
      10,   156,   157,    48,    17,    91,   160,   161,   162,   119,
       2,    37,     3,    92,   168,   169,   170,   171,   173,   174,
     175,   176,   177,   178,   179,    76,    57,     1,     8,     9,
      19,    20,    40,    10,    41,    21,   162,   130,    76,   131,
      75,   132,    46,    79,    31,   208,   209,    80,    81,    28,
      82,    83,    84,    85,    86,    31,    89,   127,    87,   195,
      88,   198,    30,   135,   199,    89,    90,    60,   201,    91,
      60,    61,   135,   135,    72,   204,   205,    92,    91,   130,
     135,   159,    34,   132,    79,    39,    92,   212,    80,    81,
     172,    82,    83,    84,    85,    86,    89,   127,    60,    87,
      44,    88,   116,    35,    20,    50,    89,    90,    21,    91,
      66,    67,   191,   139,   140,    68,   192,    92,    62,    91,
      63,   191,   134,    49,    79,   200,    55,    92,    80,    81,
     210,    82,    83,    84,    85,    86,    42,    43,    54,    87,
      58,    88,   151,   152,   197,   211,    89,    90,    56,    59,
      64,    74,   115,    79,   113,   114,   213,    80,    81,    91,
      82,    83,    84,    85,    86,   117,   121,    92,    87,   164,
      88,   122,   136,   124,   181,    89,    90,   125,   129,   148,
     149,   184,    79,   167,   196,   197,    80,    81,    91,    82,
      83,    84,    85,    86,   132,   -77,    92,    87,   187,    88,
     193,   203,   202,    47,    89,    90,    18,   112,    27,    36,
       0,    79,    73,   150,     0,   155,    81,    91,    82,    83,
      84,    85,    86,   188,   120,    92,    87,   165,    88,     0,
       0,     0,     0,    89,    90,     0,     0,     0,     0,     0,
       0,     0,   137,   138,   139,   140,    91,   142,   143,   144,
     145,   146,   147,     0,    92,     0,     0,     0,   137,   138,
     139,   140,   166,   142,   143,   144,   145,   146,   147,     0,
       0,     0,     0,     0,   137,   138,   139,   140,   182,   142,
     143,   144,   145,   146,   147,     0,     0,     0,     0,     0,
     137,   138,   139,   140,   183,   142,   143,   144,   145,   146,
     147,     0,     0,     0,     0,     0,   137,   138,   139,   140,
     185,   142,   143,   144,   145,   146,   147,     0,     0,     0,
       0,     0,   137,   138,   139,   140,   186,   142,   143,   144,
     145,   146,   147,     0,     0,     0,     0,     0,   137,   138,
     139,   140,   189,   142,   143,   144,   145,   146,   147,     0,
       0,     0,     0,     0,   137,   138,   139,   140,   206,   142,
     143,   144,   145,   146,   147,     0,     0,     0,     0,     0,
     137,   138,   139,   140,   207,   142,   143,   144,   145,   146,
     147,     0,     0,     0,     0,     0,     0,     0,   190,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     137,   138,   139,   140,     0,   142,   143,   144,   145,   146,
     147,   137,   138,   139,   140,     0,   -78,   -78,   -78,   -78,
     -78,   -78
};

static const yytype_int16 yycheck[] =
{
      81,    93,     1,    20,    87,    86,    25,    26,    28,    92,
       7,    30,    11,     6,    11,    12,     6,    14,    15,    16,
      17,    18,    19,    25,    26,    22,    45,    24,    30,    22,
       5,   123,    29,    30,   126,    25,    26,    22,   121,   122,
      30,   124,   125,    36,     0,    42,   129,   130,   131,     6,
      25,    36,    27,    50,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,    64,    49,     5,    25,    26,
      25,    26,    48,    30,    50,    30,   159,    48,    77,    50,
      63,    52,    28,     7,    30,     9,    10,    11,    12,    30,
      14,    15,    16,    17,    18,    30,    29,    30,    22,   180,
      24,   184,    50,   195,   187,    29,    30,    47,   191,    42,
      47,    51,   204,   205,    51,   196,   197,    50,    42,    48,
     212,    50,    28,    52,     7,    30,    50,   208,    11,    12,
      23,    14,    15,    16,    17,    18,    29,    30,    47,    22,
      51,    24,    51,    25,    26,    29,    29,    30,    30,    42,
      25,    26,    47,    33,    34,    30,    51,    50,    48,    42,
      50,    47,    45,    50,     7,    51,    44,    50,    11,    12,
      13,    14,    15,    16,    17,    18,    46,    47,    30,    22,
      49,    24,    46,    47,    12,    13,    29,    30,    44,    30,
       5,    29,    49,     7,    30,    44,    10,    11,    12,    42,
      14,    15,    16,    17,    18,    30,    50,    50,    22,    30,
      24,    50,    46,    50,    30,    29,    30,    50,    50,    46,
      46,    50,     7,    46,     8,    12,    11,    12,    42,    14,
      15,    16,    17,    18,    52,    46,    50,    22,    50,    24,
      50,    45,    51,    32,    29,    30,     5,    69,    11,    18,
      -1,     7,    60,   114,    -1,    11,    12,    42,    14,    15,
      16,    17,    18,   159,    77,    50,    22,   132,    24,    -1,
      -1,    -1,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    33,    34,    42,    36,    37,    38,
      39,    40,    41,    -1,    50,    -1,    -1,    -1,    31,    32,
      33,    34,    51,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    31,    32,    33,    34,    51,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      31,    32,    33,    34,    51,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,
      51,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    31,    32,    33,    34,    51,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    -1,    31,    32,
      33,    34,    51,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    31,    32,    33,    34,    51,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      31,    32,    33,    34,    51,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      31,    32,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    31,    32,    33,    34,    -1,    36,    37,    38,    39,
      40,    41
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,    25,    27,    54,    55,    64,    80,    25,    26,
      30,    65,    66,    67,    20,    56,    57,     0,    64,    25,
      26,    30,    69,    70,    72,    80,     6,    66,    30,    68,
      50,    30,    58,    59,    28,    25,    69,    70,    80,    30,
      48,    50,    46,    47,    51,    60,    28,    59,    80,    50,
      29,    67,    73,    74,    30,    44,    44,    73,    49,    30,
      47,    51,    48,    50,     5,    75,    25,    26,    30,    61,
      62,    63,    51,    74,    29,    73,    67,    76,    77,     7,
      11,    12,    14,    15,    16,    17,    18,    22,    24,    29,
      30,    42,    50,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    45,    62,    30,    44,    49,    51,    30,    78,     6,
      77,    50,    50,    81,    50,    50,    81,    30,    93,    50,
      48,    50,    52,    93,    45,    82,    46,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    46,    46,
      75,    46,    47,    93,    93,    11,    93,    93,    19,    50,
      93,    93,    93,    99,    30,    98,    51,    46,    93,    93,
      93,    93,    23,    93,    93,    93,    93,    93,    93,    93,
      71,    30,    51,    51,    50,    51,    51,    50,    99,    51,
      49,    47,    51,    50,    79,    81,     8,    12,    93,    93,
      51,    93,    51,    45,    81,    81,    51,    51,     9,    10,
      13,    13,    81,    10
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    53,    54,    54,    54,    54,    56,    55,    57,    55,
      58,    58,    60,    59,    61,    61,    62,    63,    63,    63,
      64,    65,    65,    66,    67,    67,    67,    68,    68,    68,
      68,    68,    68,    69,    69,    71,    70,    72,    72,    72,
      73,    73,    73,    74,    75,    75,    76,    76,    77,    78,
      78,    79,    80,    81,    81,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    83,    84,    85,    86,    87,
      88,    88,    89,    89,    89,    90,    90,    91,    92,    93,
      93,    93,    93,    93,    93,    94,    94,    94,    94,    95,
      95,    95,    95,    95,    95,    96,    96,    97,    97,    97,
      98,    98,    99,    99,    99
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     2,     1,     0,     4,     0,     3,
       2,     1,     0,     6,     2,     1,     3,     1,     1,     1,
       3,     2,     1,     3,     1,     1,     1,     3,     6,     6,
       1,     4,     4,     2,     1,     0,    10,     1,     1,     1,
       3,     1,     0,     2,     3,     0,     2,     1,     3,     3,
       1,     1,     8,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     5,     4,     3,
       9,     7,     7,     7,     6,     1,     1,     4,     2,     3,
       4,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     4,     1,     1,
       3,     3,     3,     1,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 6:
#line 125 "parser.y"
                        {
				typeTableCreate();
			}
#line 1631 "y.tab.c"
    break;

  case 7:
#line 129 "parser.y"
                                                                {}
#line 1637 "y.tab.c"
    break;

  case 8:
#line 131 "parser.y"
                        {
				typeTableCreate();
			}
#line 1645 "y.tab.c"
    break;

  case 9:
#line 134 "parser.y"
                                                                {}
#line 1651 "y.tab.c"
    break;

  case 10:
#line 138 "parser.y"
                                                                {}
#line 1657 "y.tab.c"
    break;

  case 11:
#line 139 "parser.y"
                                                                        {}
#line 1663 "y.tab.c"
    break;

  case 12:
#line 144 "parser.y"
                    {
				createTypeTableEntry((yyvsp[0].string));
			}
#line 1671 "y.tab.c"
    break;

  case 13:
#line 148 "parser.y"
                        {	
				addFieldsToTypeTable((yyvsp[-5].string), (yyvsp[-2].fieldnode)); 
			}
#line 1679 "y.tab.c"
    break;

  case 14:
#line 156 "parser.y"
                        {   
				(yyval.fieldnode) = addToFieldList((yyvsp[0].fieldnode), (yyvsp[-1].fieldnode));
			}
#line 1687 "y.tab.c"
    break;

  case 15:
#line 160 "parser.y"
                        {
				(yyval.fieldnode) = addToFieldList((yyvsp[0].fieldnode), NULL);
			}
#line 1695 "y.tab.c"
    break;

  case 16:
#line 168 "parser.y"
                        {
				(yyval.fieldnode) = createFieldNode((yyvsp[-2].typenode), (yyvsp[-1].string));
			}
#line 1703 "y.tab.c"
    break;

  case 17:
#line 175 "parser.y"
                        {	(yyval.typenode) = findTypeTableEntry((yyvsp[0].string));	}
#line 1709 "y.tab.c"
    break;

  case 18:
#line 176 "parser.y"
                        {	(yyval.typenode) = findTypeTableEntry((yyvsp[0].string));	}
#line 1715 "y.tab.c"
    break;

  case 19:
#line 177 "parser.y"
                        {	(yyval.typenode) = findTypeTableEntry((yyvsp[0].string));	}
#line 1721 "y.tab.c"
    break;

  case 20:
#line 182 "parser.y"
                                                {}
#line 1727 "y.tab.c"
    break;

  case 21:
#line 186 "parser.y"
                                                        {}
#line 1733 "y.tab.c"
    break;

  case 22:
#line 187 "parser.y"
                                                                        {}
#line 1739 "y.tab.c"
    break;

  case 23:
#line 191 "parser.y"
                                                        {}
#line 1745 "y.tab.c"
    break;

  case 24:
#line 195 "parser.y"
                        {	(yyval.typenode) = findTypeTableEntry((yyvsp[0].string));	}
#line 1751 "y.tab.c"
    break;

  case 25:
#line 196 "parser.y"
                        {	(yyval.typenode) = findTypeTableEntry((yyvsp[0].string));	}
#line 1757 "y.tab.c"
    break;

  case 26:
#line 197 "parser.y"
                        {	(yyval.typenode) = findTypeTableEntry((yyvsp[0].string));	}
#line 1763 "y.tab.c"
    break;

  case 27:
#line 200 "parser.y"
                                                                        {	addGlobalVariable((yyvsp[0].string), (yyvsp[-3].typenode), 		1, 		  -1, NULL);	}
#line 1769 "y.tab.c"
    break;

  case 28:
#line 201 "parser.y"
                                                                {	addGlobalVariable((yyvsp[-3].string), (yyvsp[-6].typenode), 	(yyvsp[-1].integer), -1, NULL);		}
#line 1775 "y.tab.c"
    break;

  case 29:
#line 202 "parser.y"
                                                        {   addGlobalVariable((yyvsp[-3].string), (yyvsp[-6].typenode), 		0, getfLabel(), (yyvsp[-1].fparams));	}
#line 1781 "y.tab.c"
    break;

  case 30:
#line 203 "parser.y"
                                                                                                {	addGlobalVariable((yyvsp[0].string), (yyvsp[-1].typenode), 		1, 		  -1, NULL); 	}
#line 1787 "y.tab.c"
    break;

  case 31:
#line 204 "parser.y"
                                                                                {	addGlobalVariable((yyvsp[-3].string), (yyvsp[-4].typenode), 	(yyvsp[-2].integer), -1, NULL);		}
#line 1793 "y.tab.c"
    break;

  case 32:
#line 205 "parser.y"
                                                                        {   addGlobalVariable((yyvsp[-3].string), (yyvsp[-4].typenode), 		0, getfLabel(), (yyvsp[-1].fparams));	}
#line 1799 "y.tab.c"
    break;

  case 35:
#line 218 "parser.y"
                                {
					if(checkNameEquivalence((yyvsp[-3].fparams), (yyvsp[-5].string)) == 0){
						printf("ILLEGAL FUNCTION DEFINITION\n");
						exit(-1);
					}
					addParamstoLSymbol((yyvsp[-3].fparams));
				}
#line 1811 "y.tab.c"
    break;

  case 36:
#line 226 "parser.y"
                        {
				startCodeGen((yyvsp[-8].string), (yyvsp[-1].node));
				terminateFunction();
			}
#line 1820 "y.tab.c"
    break;

  case 37:
#line 232 "parser.y"
                        {	(yyval.typenode) = findTypeTableEntry((yyvsp[0].string));	}
#line 1826 "y.tab.c"
    break;

  case 38:
#line 233 "parser.y"
                        {	(yyval.typenode) = findTypeTableEntry((yyvsp[0].string));	}
#line 1832 "y.tab.c"
    break;

  case 39:
#line 234 "parser.y"
                        {	(yyval.typenode) = findTypeTableEntry((yyvsp[0].string));	}
#line 1838 "y.tab.c"
    break;

  case 40:
#line 238 "parser.y"
                                                        { (yyval.fparams) = addParameter((yyvsp[-2].fparams), (yyvsp[0].fparams)); }
#line 1844 "y.tab.c"
    break;

  case 41:
#line 239 "parser.y"
                                                                        { (yyval.fparams) = (yyvsp[0].fparams); }
#line 1850 "y.tab.c"
    break;

  case 42:
#line 240 "parser.y"
                        {}
#line 1856 "y.tab.c"
    break;

  case 43:
#line 245 "parser.y"
                        { 	
				(yyval.fparams) = createParameter((yyvsp[0].string), (yyvsp[-1].typenode));
			}
#line 1864 "y.tab.c"
    break;

  case 44:
#line 251 "parser.y"
                                                        { (yyval.node) = (yyvsp[-1].node); }
#line 1870 "y.tab.c"
    break;

  case 45:
#line 252 "parser.y"
                        {}
#line 1876 "y.tab.c"
    break;

  case 48:
#line 261 "parser.y"
                                                        {}
#line 1882 "y.tab.c"
    break;

  case 49:
#line 265 "parser.y"
                                                        {	addLocalVariable((yyvsp[0].string), (yyvsp[-3].typenode));	}
#line 1888 "y.tab.c"
    break;

  case 50:
#line 266 "parser.y"
                                                                                {	addLocalVariable((yyvsp[0].string), (yyvsp[-1].typenode)); 	}
#line 1894 "y.tab.c"
    break;

  case 51:
#line 270 "parser.y"
                                { 	(yyval.node) = (yyvsp[0].node);	}
#line 1900 "y.tab.c"
    break;

  case 52:
#line 277 "parser.y"
                        {
				startCodeGen("main", (yyvsp[-1].node));
				printf("COMPLETED\n");
			}
#line 1909 "y.tab.c"
    break;

  case 53:
#line 285 "parser.y"
                                                        {	(yyval.node) = makeConnectorNode((yyvsp[-2].node), (yyvsp[-1].node));		}
#line 1915 "y.tab.c"
    break;

  case 54:
#line 286 "parser.y"
                                                                {	(yyval.node) = makeConnectorNode((yyvsp[-1].node), NULL);	}
#line 1921 "y.tab.c"
    break;

  case 55:
#line 290 "parser.y"
                                                        {  (yyval.node) = (yyvsp[0].node); }
#line 1927 "y.tab.c"
    break;

  case 56:
#line 291 "parser.y"
                                                        {  (yyval.node) = (yyvsp[0].node); }
#line 1933 "y.tab.c"
    break;

  case 57:
#line 292 "parser.y"
                                                        {  (yyval.node) = (yyvsp[0].node); }
#line 1939 "y.tab.c"
    break;

  case 58:
#line 293 "parser.y"
                                                                {  (yyval.node) = (yyvsp[0].node); }
#line 1945 "y.tab.c"
    break;

  case 59:
#line 294 "parser.y"
                                                        {  (yyval.node) = (yyvsp[0].node); }
#line 1951 "y.tab.c"
    break;

  case 60:
#line 295 "parser.y"
                                                        {  (yyval.node) = (yyvsp[0].node); }
#line 1957 "y.tab.c"
    break;

  case 61:
#line 296 "parser.y"
                                                {  (yyval.node) = (yyvsp[0].node); }
#line 1963 "y.tab.c"
    break;

  case 62:
#line 297 "parser.y"
                                                        {  (yyval.node) = (yyvsp[0].node); }
#line 1969 "y.tab.c"
    break;

  case 63:
#line 298 "parser.y"
                                                        {  (yyval.node) = (yyvsp[0].node); }
#line 1975 "y.tab.c"
    break;

  case 64:
#line 299 "parser.y"
                                                        {  (yyval.node) = (yyvsp[0].node); }
#line 1981 "y.tab.c"
    break;

  case 65:
#line 303 "parser.y"
                                        {	(yyval.node) = makeReadNode((yyvsp[-1].node));	}
#line 1987 "y.tab.c"
    break;

  case 66:
#line 307 "parser.y"
                                        { 	(yyval.node) = makeWriteNode((yyvsp[-1].node));	}
#line 1993 "y.tab.c"
    break;

  case 67:
#line 311 "parser.y"
                                                        {  (yyval.node) = makeAllocNode((yyvsp[-4].node)); }
#line 1999 "y.tab.c"
    break;

  case 68:
#line 314 "parser.y"
                                                                {  (yyval.node) = makeDeAllocNode((yyvsp[-1].node)); }
#line 2005 "y.tab.c"
    break;

  case 69:
#line 317 "parser.y"
                                                        {	(yyval.node) = makeOperatorNode(0, "=",(yyvsp[-2].node),(yyvsp[0].node));	}
#line 2011 "y.tab.c"
    break;

  case 70:
#line 320 "parser.y"
                                                                                                { 	(yyval.node) = makeIfNode((yyvsp[-6].node), (yyvsp[-3].node), (yyvsp[-1].node)); 	}
#line 2017 "y.tab.c"
    break;

  case 71:
#line 321 "parser.y"
                                                                                                                { 	(yyval.node) = makeIfNode((yyvsp[-4].node), (yyvsp[-1].node), NULL); 	}
#line 2023 "y.tab.c"
    break;

  case 72:
#line 325 "parser.y"
                                                                        {	(yyval.node) = makeWhileNode(0, (yyvsp[-4].node), (yyvsp[-1].node));	}
#line 2029 "y.tab.c"
    break;

  case 73:
#line 326 "parser.y"
                                                                        {	(yyval.node) = makeWhileNode(1, (yyvsp[-2].node), (yyvsp[-5].node)); 	}
#line 2035 "y.tab.c"
    break;

  case 74:
#line 327 "parser.y"
                                                                                {	(yyval.node) = makeWhileNode(2, (yyvsp[-1].node), (yyvsp[-4].node));	}
#line 2041 "y.tab.c"
    break;

  case 75:
#line 331 "parser.y"
                                {	(yyval.node) = makeJumpStatement(0);	}
#line 2047 "y.tab.c"
    break;

  case 76:
#line 332 "parser.y"
                                {	(yyval.node) = makeJumpStatement(1);	}
#line 2053 "y.tab.c"
    break;

  case 77:
#line 336 "parser.y"
                                        {	(yyval.node) = makeFunctionCallNode((yyvsp[-3].string), (yyvsp[-1].node));	}
#line 2059 "y.tab.c"
    break;

  case 78:
#line 340 "parser.y"
                                        { 	(yyval.node) = makeReturnNode((yyvsp[0].node)); }
#line 2065 "y.tab.c"
    break;

  case 79:
#line 344 "parser.y"
                                                {  	(yyval.node) = (yyvsp[-1].node); 	}
#line 2071 "y.tab.c"
    break;

  case 80:
#line 345 "parser.y"
                                                {	(yyval.node) = makeFunctionCallNode((yyvsp[-3].string), (yyvsp[-1].node));	}
#line 2077 "y.tab.c"
    break;

  case 81:
#line 346 "parser.y"
                                        {  	(yyval.node) = (yyvsp[0].node); 		}
#line 2083 "y.tab.c"
    break;

  case 82:
#line 347 "parser.y"
                                                {  	(yyval.node) = (yyvsp[0].node); 		}
#line 2089 "y.tab.c"
    break;

  case 83:
#line 348 "parser.y"
                                                        {  	(yyval.node) = (yyvsp[0].node); 		}
#line 2095 "y.tab.c"
    break;

  case 84:
#line 349 "parser.y"
                                                        {  	(yyval.node) = (yyvsp[0].node); 		}
#line 2101 "y.tab.c"
    break;

  case 85:
#line 353 "parser.y"
                                                        {	(yyval.node) = makeOperatorNode(1, "+",  (yyvsp[-2].node), (yyvsp[0].node));	}
#line 2107 "y.tab.c"
    break;

  case 86:
#line 354 "parser.y"
                                                        {	(yyval.node) = makeOperatorNode(1, "-",  (yyvsp[-2].node), (yyvsp[0].node));	}
#line 2113 "y.tab.c"
    break;

  case 87:
#line 355 "parser.y"
                                                        {	(yyval.node) = makeOperatorNode(1, "*",  (yyvsp[-2].node), (yyvsp[0].node));	}
#line 2119 "y.tab.c"
    break;

  case 88:
#line 356 "parser.y"
                                                        {	(yyval.node) = makeOperatorNode(1, "/",  (yyvsp[-2].node), (yyvsp[0].node));	}
#line 2125 "y.tab.c"
    break;

  case 89:
#line 360 "parser.y"
                                                {	(yyval.node) = makeOperatorNode(2, "<",  (yyvsp[-2].node), (yyvsp[0].node));	}
#line 2131 "y.tab.c"
    break;

  case 90:
#line 361 "parser.y"
                                                {	(yyval.node) = makeOperatorNode(2, ">",  (yyvsp[-2].node), (yyvsp[0].node));	}
#line 2137 "y.tab.c"
    break;

  case 91:
#line 362 "parser.y"
                                                {	(yyval.node) = makeOperatorNode(2, "<=", (yyvsp[-2].node), (yyvsp[0].node));	}
#line 2143 "y.tab.c"
    break;

  case 92:
#line 363 "parser.y"
                                                {	(yyval.node) = makeOperatorNode(2, ">=", (yyvsp[-2].node), (yyvsp[0].node));	}
#line 2149 "y.tab.c"
    break;

  case 93:
#line 364 "parser.y"
                                                {	(yyval.node) = makeOperatorNode(2, "!=", (yyvsp[-2].node), (yyvsp[0].node));	}
#line 2155 "y.tab.c"
    break;

  case 94:
#line 365 "parser.y"
                                                {	(yyval.node) = makeOperatorNode(2, "==", (yyvsp[-2].node), (yyvsp[0].node));	}
#line 2161 "y.tab.c"
    break;

  case 95:
#line 369 "parser.y"
                                                {	(yyval.node) = makeConstantNode(findTypeTableEntry("int"), (yyvsp[0].integer), NULL); 	}
#line 2167 "y.tab.c"
    break;

  case 96:
#line 370 "parser.y"
                                        {	(yyval.node) = makeConstantNode(findTypeTableEntry("string"), 0, (yyvsp[0].string));	}
#line 2173 "y.tab.c"
    break;

  case 97:
#line 374 "parser.y"
                                        {	(yyval.node) = makeVariableNode((yyvsp[-3].string), (yyvsp[-1].node));	}
#line 2179 "y.tab.c"
    break;

  case 98:
#line 375 "parser.y"
                                                                {	(yyval.node) = makeVariableNode((yyvsp[0].string), makeConstantNode(findTypeTableEntry("int"), 0, NULL)); }
#line 2185 "y.tab.c"
    break;

  case 99:
#line 376 "parser.y"
                                                        { 	(yyval.node) = makeFieldNode((yyvsp[0].fieldnode), makeConstantNode(findTypeTableEntry("int"), 0, NULL)); }
#line 2191 "y.tab.c"
    break;

  case 100:
#line 380 "parser.y"
                                                {	(yyval.fieldnode) = makeVariableChain((yyvsp[-2].string), NULL, (yyvsp[0].fieldnode)); 			}
#line 2197 "y.tab.c"
    break;

  case 101:
#line 381 "parser.y"
                                                {	(yyval.fieldnode) = makeVariableChain((yyvsp[-2].string), (yyvsp[0].string), NULL); 	}
#line 2203 "y.tab.c"
    break;

  case 102:
#line 385 "parser.y"
                                        { (yyval.node) = makeConnectorNode((yyvsp[-2].node), (yyvsp[0].node));	}
#line 2209 "y.tab.c"
    break;

  case 103:
#line 386 "parser.y"
                                                        { (yyval.node) = makeConnectorNode(NULL, (yyvsp[0].node));  		}
#line 2215 "y.tab.c"
    break;

  case 104:
#line 387 "parser.y"
                        {}
#line 2221 "y.tab.c"
    break;


#line 2225 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 389 "parser.y"


int getfLabel() {
	return flabel++;
}

void yyerror(char const *s)
{
    printf("yyerror: %s",s);
}

extern FILE* yyin;

int main(int argc, char* argv[]) {
	if(argc > 1) {
		FILE* fp = fopen(argv[1],"r");
		if(fp)
			yyin = fp;
	}
	yyparse();
	return 0;
}
