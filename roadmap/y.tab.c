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

	#ifndef CLASS_H
	#define CLASS_H
	#include "class_table.h"
	#endif

	#include "exptree.c"
	#include "compiler.c"
	#include "symbol_table.c"
	#include "type_table.c"
	#include "class_table.c"

	int yylex(void);
	void yyerror(const char *s);
	int getfLabel();

	// int yydebug = 1;
	int flabel = 0;

#line 108 "y.tab.c"

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
    CLASSBEGIN = 262,
    ENDCLASS = 263,
    IF = 264,
    THEN = 265,
    ELSE = 266,
    ENDIF = 267,
    WHILE = 268,
    DO = 269,
    ENDWHILE = 270,
    READ = 271,
    WRITE = 272,
    CONTINUE = 273,
    BREAK = 274,
    REPEAT = 275,
    UNTIL = 276,
    MAIN = 277,
    ARGS = 278,
    RETURN = 279,
    ALLOC = 280,
    DEALLOC = 281,
    INT = 282,
    STR = 283,
    NULL_TOKEN = 284,
    TYPE = 285,
    ENDTYPE = 286,
    SELF = 287,
    NEW = 288,
    BREAKPOINT = 289,
    NUM = 290,
    VAR = 291,
    ADD = 292,
    SUB = 293,
    MUL = 294,
    DIV = 295,
    EQUALS = 296,
    SLT = 297,
    SGT = 298,
    LTE = 299,
    GTE = 300,
    NEQ = 301,
    EQU = 302,
    STRING = 303,
    ARR_INDEX = 304
  };
#endif
/* Tokens.  */
#define START 258
#define END 259
#define DECL 260
#define ENDDECL 261
#define CLASSBEGIN 262
#define ENDCLASS 263
#define IF 264
#define THEN 265
#define ELSE 266
#define ENDIF 267
#define WHILE 268
#define DO 269
#define ENDWHILE 270
#define READ 271
#define WRITE 272
#define CONTINUE 273
#define BREAK 274
#define REPEAT 275
#define UNTIL 276
#define MAIN 277
#define ARGS 278
#define RETURN 279
#define ALLOC 280
#define DEALLOC 281
#define INT 282
#define STR 283
#define NULL_TOKEN 284
#define TYPE 285
#define ENDTYPE 286
#define SELF 287
#define NEW 288
#define BREAKPOINT 289
#define NUM 290
#define VAR 291
#define ADD 292
#define SUB 293
#define MUL 294
#define DIV 295
#define EQUALS 296
#define SLT 297
#define SGT 298
#define LTE 299
#define GTE 300
#define NEQ 301
#define EQU 302
#define STRING 303
#define ARR_INDEX 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 41 "parser.y"

	struct tnode* node;
	int integer;
	char* string;
	struct Param* fparams;
	struct FieldlistNode* fieldnode;
	struct TypetableNode* typenode;
	struct ClassMethodNode* classMethodNode;

#line 268 "y.tab.c"

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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   592

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  121
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  257

#define YYUNDEFTOK  2
#define YYMAXUTOK   304


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
      53,    54,     2,     2,    55,     2,    58,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    52,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    56,     2,    57,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,     2,    51,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   136,   136,   137,   144,   143,   149,   155,   156,   161,
     161,   172,   176,   184,   192,   193,   196,   197,   202,   201,
     211,   218,   219,   223,   229,   230,   234,   241,   242,   248,
     246,   265,   266,   270,   271,   275,   279,   280,   281,   285,
     286,   287,   288,   289,   290,   296,   297,   303,   301,   318,
     319,   320,   324,   331,   332,   336,   337,   341,   345,   346,
     350,   356,   367,   368,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   387,   391,   395,   398,
     401,   405,   406,   410,   411,   412,   416,   417,   421,   425,
     429,   432,   433,   434,   435,   436,   437,   441,   442,   446,
     447,   448,   449,   453,   454,   455,   456,   457,   458,   462,
     463,   464,   468,   469,   470,   474,   475,   476,   477,   481,
     482,   483
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "START", "END", "DECL", "ENDDECL",
  "CLASSBEGIN", "ENDCLASS", "IF", "THEN", "ELSE", "ENDIF", "WHILE", "DO",
  "ENDWHILE", "READ", "WRITE", "CONTINUE", "BREAK", "REPEAT", "UNTIL",
  "MAIN", "ARGS", "RETURN", "ALLOC", "DEALLOC", "INT", "STR", "NULL_TOKEN",
  "TYPE", "ENDTYPE", "SELF", "NEW", "BREAKPOINT", "NUM", "VAR", "ADD",
  "SUB", "MUL", "DIV", "EQUALS", "SLT", "SGT", "LTE", "GTE", "NEQ", "EQU",
  "STRING", "ARR_INDEX", "'{'", "'}'", "';'", "'('", "')'", "','", "'['",
  "']'", "'.'", "$accept", "code", "typedefSection", "$@1", "typedefList",
  "typeDefinition", "$@2", "fieldList", "fieldDeclaration",
  "classdefSection", "classdefList", "classDefinition", "$@3", "className",
  "classFieldList", "classField", "classMethodList", "classMethod",
  "classMethodDefList", "classMethodDefintion", "$@4",
  "globalDeclarations", "declarationList", "declaration", "dataTypeString",
  "variableList", "functionDefinitionList", "functionDefinition", "$@5",
  "parameterList", "parameter", "localDeclarationBlock",
  "localDeclarationList", "localDeclaration", "localVariableList",
  "functionBody", "mainFunction", "statementList", "statement",
  "inputStatement", "outputStatement", "allocStatement",
  "deAllocStatement", "assignmentStatement", "ifStatement",
  "whileStatement", "jumpStatement", "returnStatement", "newStatement",
  "breakStatement", "expression", "functionCallStatement",
  "arithmeticExpression", "logicalExpression", "constant", "variable",
  "field", "argList", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     123,   125,    59,    40,    41,    44,    91,    93,    46
};
# endif

#define YYPACT_NINF (-121)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-71)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -23,  -121,    23,     7,   -15,  -121,    24,    49,  -121,   -25,
    -121,  -121,     2,  -121,    35,    15,    17,    43,  -121,  -121,
    -121,  -121,    59,  -121,  -121,  -121,    -1,  -121,    82,    98,
     116,    17,  -121,  -121,    15,    15,  -121,  -121,    21,     0,
      74,    79,  -121,  -121,   -11,  -121,   118,    15,  -121,   124,
      15,   132,  -121,   139,   123,    15,   127,  -121,   128,  -121,
      15,   130,   147,   133,   153,    47,  -121,   134,    27,   140,
      62,  -121,  -121,   186,   141,   158,  -121,    72,  -121,  -121,
    -121,    15,  -121,    15,   160,   191,   148,    15,  -121,   144,
      15,  -121,    76,   145,    15,   348,   191,     5,  -121,   165,
      80,  -121,  -121,   175,     3,  -121,   162,   164,   348,   167,
     168,  -121,  -121,   348,    46,   170,  -121,   154,  -121,  -121,
     -34,  -121,    46,   190,   161,  -121,  -121,  -121,  -121,  -121,
    -121,  -121,  -121,  -121,  -121,  -121,   523,   166,  -121,  -121,
    -121,  -121,   174,  -121,  -121,  -121,   176,  -121,  -121,    18,
    -121,  -121,    46,    46,   386,    46,    46,   231,   534,  -121,
      46,   -24,    46,    46,    14,   414,  -121,   178,  -121,    46,
      46,    46,    46,    36,    46,    46,    46,    46,    46,    46,
      46,   348,    15,  -121,   192,   427,   440,   179,   453,   466,
     180,   479,   173,  -121,   534,    83,   398,   173,  -121,  -121,
    -121,   104,   104,  -121,  -121,   181,   182,   534,   545,   545,
     545,   545,   545,   545,    91,   185,   348,    96,  -121,   227,
     225,    46,  -121,  -121,    46,  -121,  -121,    46,  -121,   188,
     210,  -121,  -121,   203,   348,   348,   492,   505,   534,  -121,
     200,   191,   152,   272,   159,  -121,  -121,  -121,   348,  -121,
    -121,  -121,   348,   310,   205,  -121,  -121
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       6,     4,     0,    15,     0,     1,     0,    32,     9,     0,
       8,    20,     0,    17,     0,     0,     0,     0,     5,     7,
      14,    16,     0,    36,    37,    38,     0,    34,     0,    36,
       0,     0,    46,     3,     0,     0,    31,    33,    42,     0,
       0,     0,    45,     2,     0,    12,     0,     0,    22,     0,
      51,     0,    35,     0,     0,    51,     0,    11,     0,    21,
      18,     0,     0,     0,     0,     0,    50,     0,    39,     0,
       0,    10,    13,     0,     0,     0,    25,     0,    23,    52,
      44,     0,    43,    51,     0,    54,     0,     0,    24,     0,
      51,    49,     0,     0,     0,     0,    54,     0,    28,     0,
       0,    41,    40,     0,     0,    56,     0,     0,     0,     0,
       0,    86,    87,     0,     0,     0,   111,     0,    90,   109,
     113,   110,     0,     0,     0,    64,    65,    72,    73,    66,
      67,    68,    69,    71,    74,    75,     0,    92,    93,    94,
      95,    96,   114,    47,    19,    27,     0,    26,    59,     0,
      53,    55,     0,     0,     0,     0,     0,     0,    88,    92,
       0,     0,   121,     0,     0,     0,    61,     0,    63,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     121,     0,    51,    57,     0,     0,     0,     0,     0,     0,
       0,     0,   117,   118,   120,     0,     0,   116,   115,    91,
      62,    99,   100,   101,   102,     0,     0,    80,   103,   104,
     105,   106,   107,   108,     0,     0,    60,     0,    58,     0,
       0,     0,    76,    77,     0,    79,    97,     0,   112,     0,
       0,    98,    48,     0,     0,     0,     0,     0,   119,    78,
       0,    54,     0,     0,     0,    85,    89,    29,     0,    82,
      83,    84,     0,     0,     0,    81,    30
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -121,  -121,  -121,  -121,  -121,   249,  -121,  -121,   215,  -121,
    -121,   250,  -121,  -121,  -121,   214,  -121,   204,  -121,   171,
    -121,  -121,  -121,   243,    32,  -121,  -121,   239,  -121,   -54,
     193,   -92,  -121,   169,  -121,    19,   241,   -93,  -120,  -121,
    -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,
     -65,   -95,  -121,  -121,  -121,  -121,   -61,    95
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     9,    10,    17,    44,    45,     7,
      12,    13,    73,    14,    47,    48,    60,    61,    97,    98,
     252,    16,    26,    27,    64,    39,    31,    32,   181,    65,
      66,    95,   104,   105,   149,   215,    33,   216,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   159,   138,   139,   140,   141,   142,   195
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     137,    70,   123,   167,   143,    36,    18,     1,   117,   150,
      20,     8,   192,   137,     6,   154,    23,    24,   137,   162,
     157,     8,   163,     5,   164,    25,    23,    24,   137,    92,
      23,    24,    23,    24,   167,    25,   100,   167,    11,    25,
      56,    25,    23,    24,    29,    24,   117,    28,    30,   158,
     197,    25,    52,    25,    15,    53,   144,   165,    28,   137,
      11,   205,   137,    30,    35,   116,    46,    49,   117,   206,
     183,   119,   120,   184,    50,   116,    46,    51,   117,    62,
      83,   119,   120,    84,   121,    22,   137,   185,   186,   122,
     188,   189,    75,    34,   121,   191,   167,   194,   196,   122,
     193,    80,    81,   198,   201,   202,   203,   204,   207,   208,
     209,   210,   211,   212,   213,   194,    86,    81,    38,    99,
      40,   137,   167,   167,    78,    90,   103,    54,   217,    99,
     101,    81,    55,   167,   147,    81,   103,   226,   227,   137,
     137,   242,   243,   171,   172,   231,   227,   137,   137,   247,
     233,    81,    41,   137,    58,   253,   236,   137,   137,   237,
      63,   106,   238,   248,   249,   107,   108,    67,   109,   110,
     111,   112,   113,   235,   251,    68,   114,    69,   115,    71,
      72,   116,    76,    77,   117,    78,   118,   119,   120,    79,
      85,    82,    87,    88,    89,    93,    94,    90,    96,   106,
     121,   146,   102,   107,   108,   122,   109,   110,   111,   112,
     113,   148,   161,   168,   114,   152,   115,   153,   -70,   116,
     155,   156,   117,   160,   118,   119,   120,   180,   218,   182,
     200,   164,   221,   224,   229,   230,   232,   234,   121,   235,
     106,   166,   239,   122,   107,   108,   240,   109,   110,   111,
     112,   113,   190,   241,   246,   114,   256,   115,    19,    57,
     116,    59,    21,   117,    74,   118,   119,   120,   145,    37,
      42,   254,    43,   151,    91,   214,     0,     0,     0,   121,
       0,   106,     0,     0,   122,   107,   108,   250,   109,   110,
     111,   112,   113,     0,     0,     0,   114,     0,   115,     0,
       0,   116,     0,     0,   117,     0,   118,   119,   120,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   106,
     121,     0,   255,   107,   108,   122,   109,   110,   111,   112,
     113,     0,     0,     0,   114,     0,   115,     0,     0,   116,
       0,     0,   117,     0,   118,   119,   120,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   106,   121,     0,
       0,   107,   108,   122,   109,   110,   111,   112,   113,     0,
       0,     0,   114,     0,   115,     0,     0,   116,     0,     0,
     117,     0,   118,   119,   120,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   106,   121,     0,     0,   187,
     108,   122,   109,   110,   111,   112,   113,     0,     0,     0,
     114,     0,   115,     0,     0,   116,     0,     0,   117,     0,
     118,   119,   120,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,   169,   170,   171,   172,   122,
     174,   175,   176,   177,   178,   179,     0,     0,     0,     0,
       0,   169,   170,   171,   172,   228,   174,   175,   176,   177,
     178,   179,     0,     0,   169,   170,   171,   172,   199,   174,
     175,   176,   177,   178,   179,     0,     0,   169,   170,   171,
     172,   219,   174,   175,   176,   177,   178,   179,     0,     0,
     169,   170,   171,   172,   220,   174,   175,   176,   177,   178,
     179,     0,     0,   169,   170,   171,   172,   222,   174,   175,
     176,   177,   178,   179,     0,     0,   169,   170,   171,   172,
     223,   174,   175,   176,   177,   178,   179,     0,     0,   169,
     170,   171,   172,   225,   174,   175,   176,   177,   178,   179,
       0,     0,   169,   170,   171,   172,   244,   174,   175,   176,
     177,   178,   179,     0,     0,     0,     0,     0,     0,   245,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   169,   170,   171,   172,     0,   174,   175,   176,   177,
     178,   179,   169,   170,   171,   172,     0,   -71,   -71,   -71,
     -71,   -71,   -71
};

static const yytype_int16 yycheck[] =
{
      95,    55,    95,   123,    96,     6,    31,    30,    32,     6,
       8,    36,    36,   108,     7,   108,    27,    28,   113,    53,
     113,    36,    56,     0,    58,    36,    27,    28,   123,    83,
      27,    28,    27,    28,   154,    36,    90,   157,    36,    36,
      51,    36,    27,    28,    27,    28,    32,    15,    16,   114,
      36,    36,    52,    36,     5,    55,    51,   122,    26,   154,
      36,    25,   157,    31,     5,    29,    34,    35,    32,    33,
      52,    35,    36,    55,    53,    29,    44,    56,    32,    47,
      53,    35,    36,    56,    48,    50,   181,   152,   153,    53,
     155,   156,    60,    50,    48,   160,   216,   162,   163,    53,
     161,    54,    55,   164,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,    54,    55,    36,    87,
      22,   216,   242,   243,    52,    53,    94,    53,   182,    97,
      54,    55,    53,   253,    54,    55,   104,    54,    55,   234,
     235,   234,   235,    39,    40,    54,    55,   242,   243,   241,
      54,    55,    36,   248,    36,   248,   221,   252,   253,   224,
      36,     9,   227,    11,    12,    13,    14,    35,    16,    17,
      18,    19,    20,    14,    15,    36,    24,    54,    26,    52,
      52,    29,    52,    36,    32,    52,    34,    35,    36,    36,
      50,    57,     6,    52,    36,    35,     5,    53,    50,     9,
      48,    36,    57,    13,    14,    53,    16,    17,    18,    19,
      20,    36,    58,    52,    24,    53,    26,    53,    52,    29,
      53,    53,    32,    53,    34,    35,    36,    53,    36,    53,
      52,    58,    53,    53,    53,    53,    51,    10,    48,    14,
       9,    51,    54,    53,    13,    14,    36,    16,    17,    18,
      19,    20,    21,    50,    54,    24,    51,    26,     9,    44,
      29,    47,    12,    32,    60,    34,    35,    36,    97,    26,
      31,   252,    31,   104,    81,   180,    -1,    -1,    -1,    48,
      -1,     9,    -1,    -1,    53,    13,    14,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    24,    -1,    26,    -1,
      -1,    29,    -1,    -1,    32,    -1,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,
      48,    -1,    12,    13,    14,    53,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    24,    -1,    26,    -1,    -1,    29,
      -1,    -1,    32,    -1,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    48,    -1,
      -1,    13,    14,    53,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    24,    -1,    26,    -1,    -1,    29,    -1,    -1,
      32,    -1,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     9,    48,    -1,    -1,    13,
      14,    53,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      24,    -1,    26,    -1,    -1,    29,    -1,    -1,    32,    -1,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    37,    38,    39,    40,    53,
      42,    43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,
      -1,    37,    38,    39,    40,    57,    42,    43,    44,    45,
      46,    47,    -1,    -1,    37,    38,    39,    40,    54,    42,
      43,    44,    45,    46,    47,    -1,    -1,    37,    38,    39,
      40,    54,    42,    43,    44,    45,    46,    47,    -1,    -1,
      37,    38,    39,    40,    54,    42,    43,    44,    45,    46,
      47,    -1,    -1,    37,    38,    39,    40,    54,    42,    43,
      44,    45,    46,    47,    -1,    -1,    37,    38,    39,    40,
      54,    42,    43,    44,    45,    46,    47,    -1,    -1,    37,
      38,    39,    40,    54,    42,    43,    44,    45,    46,    47,
      -1,    -1,    37,    38,    39,    40,    54,    42,    43,    44,
      45,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    37,    38,    39,    40,    -1,    42,    43,    44,    45,
      46,    47,    37,    38,    39,    40,    -1,    42,    43,    44,
      45,    46,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    30,    60,    61,    62,     0,     7,    68,    36,    63,
      64,    36,    69,    70,    72,     5,    80,    65,    31,    64,
       8,    70,    50,    27,    28,    36,    81,    82,    83,    27,
      83,    85,    86,    95,    50,     5,     6,    82,    36,    84,
      22,    36,    86,    95,    66,    67,    83,    73,    74,    83,
      53,    56,    52,    55,    53,    53,    51,    67,    36,    74,
      75,    76,    83,    36,    83,    88,    89,    35,    36,    54,
      88,    52,    52,    71,    76,    83,    52,    36,    52,    36,
      54,    55,    57,    53,    56,    50,    54,     6,    52,    36,
      53,    89,    88,    35,     5,    90,    50,    77,    78,    83,
      88,    54,    57,    83,    91,    92,     9,    13,    14,    16,
      17,    18,    19,    20,    24,    26,    29,    32,    34,    35,
      36,    48,    53,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,    90,    51,    78,    36,    54,    36,    93,
       6,    92,    53,    53,    96,    53,    53,    96,   109,   110,
      53,    58,    53,    56,    58,   109,    51,    97,    52,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      53,    87,    53,    52,    55,   109,   109,    13,   109,   109,
      21,   109,    36,   115,   109,   116,   109,    36,   115,    54,
      52,   109,   109,   109,   109,    25,    33,   109,   109,   109,
     109,   109,   109,   109,   116,    94,    96,    88,    36,    54,
      54,    53,    54,    54,    53,    54,    54,    55,    57,    53,
      53,    54,    51,    54,    10,    14,   109,   109,   109,    54,
      36,    50,    96,    96,    54,    54,    54,    90,    11,    12,
      15,    15,    79,    96,    94,    12,    51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    59,    60,    60,    62,    61,    61,    63,    63,    65,
      64,    66,    66,    67,    68,    68,    69,    69,    71,    70,
      72,    73,    73,    74,    75,    75,    76,    77,    77,    79,
      78,    80,    80,    81,    81,    82,    83,    83,    83,    84,
      84,    84,    84,    84,    84,    85,    85,    87,    86,    88,
      88,    88,    89,    90,    90,    91,    91,    92,    93,    93,
      94,    95,    96,    96,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    98,    99,   100,   101,
     102,   103,   103,   104,   104,   104,   105,   105,   106,   107,
     108,   109,   109,   109,   109,   109,   109,   110,   110,   111,
     111,   111,   111,   112,   112,   112,   112,   112,   112,   113,
     113,   113,   114,   114,   114,   115,   115,   115,   115,   116,
     116,   116
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     4,     0,     4,     0,     2,     1,     0,
       6,     2,     1,     3,     3,     0,     2,     1,     0,     9,
       1,     2,     1,     3,     3,     2,     5,     2,     1,     0,
      10,     3,     0,     2,     1,     3,     1,     1,     1,     3,
       6,     6,     1,     4,     4,     2,     1,     0,    10,     3,
       1,     0,     2,     3,     0,     2,     1,     3,     3,     1,
       1,     8,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     5,     4,
       3,     9,     7,     7,     7,     6,     1,     1,     2,     6,
       1,     3,     1,     1,     1,     1,     1,     4,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     4,     1,     1,     3,     3,     3,     3,     3,
       1,     0
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
  case 4:
#line 144 "parser.y"
                        {
				typeTableCreate();
			}
#line 1702 "y.tab.c"
    break;

  case 5:
#line 148 "parser.y"
                                                                {}
#line 1708 "y.tab.c"
    break;

  case 6:
#line 149 "parser.y"
                        {
				typeTableCreate();
			}
#line 1716 "y.tab.c"
    break;

  case 7:
#line 155 "parser.y"
                                                                {}
#line 1722 "y.tab.c"
    break;

  case 8:
#line 156 "parser.y"
                                                                        {}
#line 1728 "y.tab.c"
    break;

  case 9:
#line 161 "parser.y"
                    {
				createTypeTableEntry((yyvsp[0].string));
			}
#line 1736 "y.tab.c"
    break;

  case 10:
#line 165 "parser.y"
                        {	
				addFieldsToTypeTable((yyvsp[-5].string), (yyvsp[-2].fieldnode)); 
			}
#line 1744 "y.tab.c"
    break;

  case 11:
#line 173 "parser.y"
                        {   
				(yyval.fieldnode) = addToFieldList((yyvsp[0].fieldnode), (yyvsp[-1].fieldnode));
			}
#line 1752 "y.tab.c"
    break;

  case 12:
#line 177 "parser.y"
                        {
				(yyval.fieldnode) = addToFieldList((yyvsp[0].fieldnode), NULL);
			}
#line 1760 "y.tab.c"
    break;

  case 13:
#line 185 "parser.y"
                        {
				(yyval.fieldnode) = createFieldNode(findTypeTableEntry((yyvsp[-2].string)), (yyvsp[-1].string));
			}
#line 1768 "y.tab.c"
    break;

  case 14:
#line 192 "parser.y"
                                                 {}
#line 1774 "y.tab.c"
    break;

  case 15:
#line 193 "parser.y"
                  {}
#line 1780 "y.tab.c"
    break;

  case 16:
#line 196 "parser.y"
                                                {}
#line 1786 "y.tab.c"
    break;

  case 17:
#line 197 "parser.y"
                                                                {}
#line 1792 "y.tab.c"
    break;

  case 18:
#line 202 "parser.y"
                        {
				addFieldToClass((yyvsp[-4].string), (yyvsp[-1].fieldnode));
				addMethodsToClass((yyvsp[-4].string), (yyvsp[0].classMethodNode));
			}
#line 1801 "y.tab.c"
    break;

  case 19:
#line 207 "parser.y"
                        {}
#line 1807 "y.tab.c"
    break;

  case 20:
#line 211 "parser.y"
                                        {	
						createClassTableEntry((yyvsp[0].string));
						(yyval.string) = (yyvsp[0].string);
					}
#line 1816 "y.tab.c"
    break;

  case 21:
#line 218 "parser.y"
                                                        {	(yyval.fieldnode) = addToClassFieldNodeList((yyvsp[0].fieldnode), (yyvsp[-1].fieldnode));	}
#line 1822 "y.tab.c"
    break;

  case 22:
#line 219 "parser.y"
                                                                        {	(yyval.fieldnode) = addToClassFieldNodeList((yyvsp[0].fieldnode), NULL);	}
#line 1828 "y.tab.c"
    break;

  case 23:
#line 224 "parser.y"
                {
			(yyval.fieldnode) = createClassFieldNode((yyvsp[-2].string), (yyvsp[-1].string));
		}
#line 1836 "y.tab.c"
    break;

  case 24:
#line 229 "parser.y"
                                                {	(yyval.classMethodNode) = addToClassMethodList((yyvsp[-1].classMethodNode), (yyvsp[-2].classMethodNode));		}
#line 1842 "y.tab.c"
    break;

  case 25:
#line 230 "parser.y"
                                                                {	(yyval.classMethodNode) = addToClassMethodList((yyvsp[-1].classMethodNode), NULL);	}
#line 1848 "y.tab.c"
    break;

  case 26:
#line 235 "parser.y"
                        {
				(yyval.classMethodNode) = createClassMethodNode((yyvsp[-3].string), getfLabel(), findTypeTableEntry((yyvsp[-4].string)), (yyvsp[-1].fparams));
			}
#line 1856 "y.tab.c"
    break;

  case 27:
#line 241 "parser.y"
                                                                {}
#line 1862 "y.tab.c"
    break;

  case 28:
#line 242 "parser.y"
                                                                                {}
#line 1868 "y.tab.c"
    break;

  case 29:
#line 248 "parser.y"
                                {
					checkMethodValidity((yyvsp[-5].string), (yyvsp[-3].fparams));
					addParamstoLSymbol((yyvsp[-3].fparams));
					addSelfToLSymbol();
				}
#line 1878 "y.tab.c"
    break;

  case 30:
#line 254 "parser.y"
                        {
				// printf("FUNCTION CODEGEN TAKES PLACE\n");
				startCodeGen((yyvsp[-8].string), 1, (yyvsp[-1].node));
				terminateFunction();
			}
#line 1888 "y.tab.c"
    break;

  case 31:
#line 265 "parser.y"
                                                {}
#line 1894 "y.tab.c"
    break;

  case 32:
#line 266 "parser.y"
                  {}
#line 1900 "y.tab.c"
    break;

  case 33:
#line 270 "parser.y"
                                                        {}
#line 1906 "y.tab.c"
    break;

  case 34:
#line 271 "parser.y"
                                                                        {}
#line 1912 "y.tab.c"
    break;

  case 35:
#line 275 "parser.y"
                                                        {}
#line 1918 "y.tab.c"
    break;

  case 36:
#line 279 "parser.y"
                        {	(yyval.string) = (yyvsp[0].string);	}
#line 1924 "y.tab.c"
    break;

  case 37:
#line 280 "parser.y"
                        {	(yyval.string) = (yyvsp[0].string);	}
#line 1930 "y.tab.c"
    break;

  case 38:
#line 281 "parser.y"
                        {	(yyval.string) = (yyvsp[0].string);	}
#line 1936 "y.tab.c"
    break;

  case 39:
#line 285 "parser.y"
                                                                        {	addGlobalVariable((yyvsp[0].string), (yyvsp[-3].string), 		1, 		  -1, NULL);	}
#line 1942 "y.tab.c"
    break;

  case 40:
#line 286 "parser.y"
                                                                {	addGlobalVariable((yyvsp[-3].string), (yyvsp[-6].string), 	(yyvsp[-1].integer), -1, NULL);		}
#line 1948 "y.tab.c"
    break;

  case 41:
#line 287 "parser.y"
                                                        {   addGlobalVariable((yyvsp[-3].string), (yyvsp[-6].string), 		0, getfLabel(), (yyvsp[-1].fparams));	}
#line 1954 "y.tab.c"
    break;

  case 42:
#line 288 "parser.y"
                                                                                                {	addGlobalVariable((yyvsp[0].string), (yyvsp[-1].string), 		1, 		  -1, NULL); 	}
#line 1960 "y.tab.c"
    break;

  case 43:
#line 289 "parser.y"
                                                                                {	addGlobalVariable((yyvsp[-3].string), (yyvsp[-4].string), 	(yyvsp[-2].integer), -1, NULL);		}
#line 1966 "y.tab.c"
    break;

  case 44:
#line 290 "parser.y"
                                                                        {   addGlobalVariable((yyvsp[-3].string), (yyvsp[-4].string), 		0, getfLabel(), (yyvsp[-1].fparams));	}
#line 1972 "y.tab.c"
    break;

  case 47:
#line 303 "parser.y"
                                {
					if(checkNameEquivalence((yyvsp[-3].fparams), (yyvsp[-5].string)) == 0){
						printf("ILLEGAL FUNCTION DEFINITION\n");
						exit(-1);
					}
					addParamstoLSymbol((yyvsp[-3].fparams));
				}
#line 1984 "y.tab.c"
    break;

  case 48:
#line 311 "parser.y"
                        {
				startCodeGen((yyvsp[-8].string), 0, (yyvsp[-1].node));
				terminateFunction();
			}
#line 1993 "y.tab.c"
    break;

  case 49:
#line 318 "parser.y"
                                                        { (yyval.fparams) = addParameter((yyvsp[-2].fparams), (yyvsp[0].fparams)); }
#line 1999 "y.tab.c"
    break;

  case 50:
#line 319 "parser.y"
                                                                        { (yyval.fparams) = (yyvsp[0].fparams); }
#line 2005 "y.tab.c"
    break;

  case 51:
#line 320 "parser.y"
                        {	(yyval.fparams) = NULL;	}
#line 2011 "y.tab.c"
    break;

  case 52:
#line 325 "parser.y"
                        { 	
				(yyval.fparams) = createParameter((yyvsp[0].string), findTypeTableEntry((yyvsp[-1].string)));
			}
#line 2019 "y.tab.c"
    break;

  case 53:
#line 331 "parser.y"
                                                        { (yyval.node) = (yyvsp[-1].node); }
#line 2025 "y.tab.c"
    break;

  case 54:
#line 332 "parser.y"
                        {	(yyval.node) = NULL;	}
#line 2031 "y.tab.c"
    break;

  case 57:
#line 341 "parser.y"
                                                                {}
#line 2037 "y.tab.c"
    break;

  case 58:
#line 345 "parser.y"
                                                        {	addLocalVariable((yyvsp[0].string), findTypeTableEntry((yyvsp[-3].string)));	}
#line 2043 "y.tab.c"
    break;

  case 59:
#line 346 "parser.y"
                                                                                {	addLocalVariable((yyvsp[0].string), findTypeTableEntry((yyvsp[-1].string))); 	}
#line 2049 "y.tab.c"
    break;

  case 60:
#line 350 "parser.y"
                                { 	(yyval.node) = (yyvsp[0].node);	}
#line 2055 "y.tab.c"
    break;

  case 61:
#line 357 "parser.y"
                        {
				// printf("AST COMPLETED\n");
				// exit(0);
				startCodeGen("main", 0, (yyvsp[-1].node));
				printf("COMPLETED\n");
			}
#line 2066 "y.tab.c"
    break;

  case 62:
#line 367 "parser.y"
                                                        {	(yyval.node) = makeConnectorNode((yyvsp[-2].node), (yyvsp[-1].node));		}
#line 2072 "y.tab.c"
    break;

  case 63:
#line 368 "parser.y"
                                                                {	(yyval.node) = makeConnectorNode((yyvsp[-1].node), NULL);	}
#line 2078 "y.tab.c"
    break;

  case 64:
#line 372 "parser.y"
                                                        {  (yyval.node) = (yyvsp[0].node); }
#line 2084 "y.tab.c"
    break;

  case 65:
#line 373 "parser.y"
                                                        {  (yyval.node) = (yyvsp[0].node); }
#line 2090 "y.tab.c"
    break;

  case 66:
#line 374 "parser.y"
                                                        {  (yyval.node) = (yyvsp[0].node); }
#line 2096 "y.tab.c"
    break;

  case 67:
#line 375 "parser.y"
                                                                {  (yyval.node) = (yyvsp[0].node); }
#line 2102 "y.tab.c"
    break;

  case 68:
#line 376 "parser.y"
                                                        {  (yyval.node) = (yyvsp[0].node); }
#line 2108 "y.tab.c"
    break;

  case 69:
#line 377 "parser.y"
                                                        {  (yyval.node) = (yyvsp[0].node); }
#line 2114 "y.tab.c"
    break;

  case 70:
#line 378 "parser.y"
                                                {  (yyval.node) = (yyvsp[0].node); }
#line 2120 "y.tab.c"
    break;

  case 71:
#line 379 "parser.y"
                                                        {  (yyval.node) = (yyvsp[0].node); }
#line 2126 "y.tab.c"
    break;

  case 72:
#line 380 "parser.y"
                                                        {  (yyval.node) = (yyvsp[0].node); }
#line 2132 "y.tab.c"
    break;

  case 73:
#line 381 "parser.y"
                                                        {  (yyval.node) = (yyvsp[0].node); }
#line 2138 "y.tab.c"
    break;

  case 74:
#line 382 "parser.y"
                                                        {  (yyval.node) = (yyvsp[0].node);	}
#line 2144 "y.tab.c"
    break;

  case 75:
#line 383 "parser.y"
                                                        {  (yyval.node) = (yyvsp[0].node); }
#line 2150 "y.tab.c"
    break;

  case 76:
#line 387 "parser.y"
                                        {	(yyval.node) = makeReadNode((yyvsp[-1].node));	}
#line 2156 "y.tab.c"
    break;

  case 77:
#line 391 "parser.y"
                                        { 	(yyval.node) = makeWriteNode((yyvsp[-1].node));	}
#line 2162 "y.tab.c"
    break;

  case 78:
#line 395 "parser.y"
                                                        {  (yyval.node) = makeAllocNode((yyvsp[-4].node)); }
#line 2168 "y.tab.c"
    break;

  case 79:
#line 398 "parser.y"
                                                                {  (yyval.node) = makeDeAllocNode((yyvsp[-1].node)); }
#line 2174 "y.tab.c"
    break;

  case 80:
#line 401 "parser.y"
                                                        {	(yyval.node) = makeOperatorNode(0, "=",(yyvsp[-2].node),(yyvsp[0].node));	}
#line 2180 "y.tab.c"
    break;

  case 81:
#line 405 "parser.y"
                                                                                                { 	(yyval.node) = makeIfNode((yyvsp[-6].node), (yyvsp[-3].node), (yyvsp[-1].node)); 	}
#line 2186 "y.tab.c"
    break;

  case 82:
#line 406 "parser.y"
                                                                                                                { 	(yyval.node) = makeIfNode((yyvsp[-4].node), (yyvsp[-1].node), NULL); 	}
#line 2192 "y.tab.c"
    break;

  case 83:
#line 410 "parser.y"
                                                                        {	(yyval.node) = makeWhileNode(0, (yyvsp[-4].node), (yyvsp[-1].node));	}
#line 2198 "y.tab.c"
    break;

  case 84:
#line 411 "parser.y"
                                                                        {	(yyval.node) = makeWhileNode(1, (yyvsp[-2].node), (yyvsp[-5].node)); 	}
#line 2204 "y.tab.c"
    break;

  case 85:
#line 412 "parser.y"
                                                                                {	(yyval.node) = makeWhileNode(2, (yyvsp[-1].node), (yyvsp[-4].node));	}
#line 2210 "y.tab.c"
    break;

  case 86:
#line 416 "parser.y"
                                {	(yyval.node) = makeJumpStatement(0);	}
#line 2216 "y.tab.c"
    break;

  case 87:
#line 417 "parser.y"
                                {	(yyval.node) = makeJumpStatement(1);	}
#line 2222 "y.tab.c"
    break;

  case 88:
#line 421 "parser.y"
                                        { 	(yyval.node) = makeReturnNode((yyvsp[0].node)); }
#line 2228 "y.tab.c"
    break;

  case 89:
#line 425 "parser.y"
                                                { (yyval.node) = makeClassConstructorNode((yyvsp[-5].node), (yyvsp[-1].string)); }
#line 2234 "y.tab.c"
    break;

  case 90:
#line 429 "parser.y"
                                        { (yyval.node) = makeBreakPointNode(); }
#line 2240 "y.tab.c"
    break;

  case 91:
#line 432 "parser.y"
                                                {  	(yyval.node) = (yyvsp[-1].node); 	}
#line 2246 "y.tab.c"
    break;

  case 92:
#line 433 "parser.y"
                                        {	(yyval.node) = (yyvsp[0].node);		}
#line 2252 "y.tab.c"
    break;

  case 93:
#line 434 "parser.y"
                                        {  	(yyval.node) = (yyvsp[0].node); 		}
#line 2258 "y.tab.c"
    break;

  case 94:
#line 435 "parser.y"
                                                {  	(yyval.node) = (yyvsp[0].node); 		}
#line 2264 "y.tab.c"
    break;

  case 95:
#line 436 "parser.y"
                                                        {  	(yyval.node) = (yyvsp[0].node); 		}
#line 2270 "y.tab.c"
    break;

  case 96:
#line 437 "parser.y"
                                                        {  	(yyval.node) = (yyvsp[0].node); 		}
#line 2276 "y.tab.c"
    break;

  case 97:
#line 441 "parser.y"
                                                {	(yyval.node) = makeFunctionCallNode((yyvsp[-3].string), (yyvsp[-1].node));	}
#line 2282 "y.tab.c"
    break;

  case 98:
#line 442 "parser.y"
                                        {	(yyval.node) = makeClassMethodCallNode((yyvsp[-3].fieldnode), (yyvsp[-1].node));	}
#line 2288 "y.tab.c"
    break;

  case 99:
#line 446 "parser.y"
                                                        {	(yyval.node) = makeOperatorNode(1, "+",  (yyvsp[-2].node), (yyvsp[0].node));	}
#line 2294 "y.tab.c"
    break;

  case 100:
#line 447 "parser.y"
                                                        {	(yyval.node) = makeOperatorNode(1, "-",  (yyvsp[-2].node), (yyvsp[0].node));	}
#line 2300 "y.tab.c"
    break;

  case 101:
#line 448 "parser.y"
                                                        {	(yyval.node) = makeOperatorNode(1, "*",  (yyvsp[-2].node), (yyvsp[0].node));	}
#line 2306 "y.tab.c"
    break;

  case 102:
#line 449 "parser.y"
                                                        {	(yyval.node) = makeOperatorNode(1, "/",  (yyvsp[-2].node), (yyvsp[0].node));	}
#line 2312 "y.tab.c"
    break;

  case 103:
#line 453 "parser.y"
                                                {	(yyval.node) = makeOperatorNode(2, "<",  (yyvsp[-2].node), (yyvsp[0].node));	}
#line 2318 "y.tab.c"
    break;

  case 104:
#line 454 "parser.y"
                                                {	(yyval.node) = makeOperatorNode(2, ">",  (yyvsp[-2].node), (yyvsp[0].node));	}
#line 2324 "y.tab.c"
    break;

  case 105:
#line 455 "parser.y"
                                                {	(yyval.node) = makeOperatorNode(2, "<=", (yyvsp[-2].node), (yyvsp[0].node));	}
#line 2330 "y.tab.c"
    break;

  case 106:
#line 456 "parser.y"
                                                {	(yyval.node) = makeOperatorNode(2, ">=", (yyvsp[-2].node), (yyvsp[0].node));	}
#line 2336 "y.tab.c"
    break;

  case 107:
#line 457 "parser.y"
                                                {	(yyval.node) = makeOperatorNode(2, "!=", (yyvsp[-2].node), (yyvsp[0].node));	}
#line 2342 "y.tab.c"
    break;

  case 108:
#line 458 "parser.y"
                                                {	(yyval.node) = makeOperatorNode(2, "==", (yyvsp[-2].node), (yyvsp[0].node));	}
#line 2348 "y.tab.c"
    break;

  case 109:
#line 462 "parser.y"
                                                {	(yyval.node) = makeConstantNode(findTypeTableEntry("int"), (yyvsp[0].integer), NULL); 	}
#line 2354 "y.tab.c"
    break;

  case 110:
#line 463 "parser.y"
                                        {	(yyval.node) = makeConstantNode(findTypeTableEntry("string"), 0, (yyvsp[0].string));		}
#line 2360 "y.tab.c"
    break;

  case 111:
#line 464 "parser.y"
                                        {   (yyval.node) = makeConstantNode(findTypeTableEntry("void"), 0, NULL);				}
#line 2366 "y.tab.c"
    break;

  case 112:
#line 468 "parser.y"
                                        {	(yyval.node) = makeVariableNode((yyvsp[-3].string), (yyvsp[-1].node));	}
#line 2372 "y.tab.c"
    break;

  case 113:
#line 469 "parser.y"
                                                                {	(yyval.node) = makeVariableNode((yyvsp[0].string), makeConstantNode(findTypeTableEntry("int"), 0, NULL)); }
#line 2378 "y.tab.c"
    break;

  case 114:
#line 470 "parser.y"
                                                        { 	(yyval.node) = makeFieldNode((yyvsp[0].fieldnode), makeConstantNode(findTypeTableEntry("int"), 0, NULL)); }
#line 2384 "y.tab.c"
    break;

  case 115:
#line 474 "parser.y"
                                                {	(yyval.fieldnode) = makeVariableChain((yyvsp[-2].string), NULL, (yyvsp[0].fieldnode)); 			}
#line 2390 "y.tab.c"
    break;

  case 116:
#line 475 "parser.y"
                                                {	(yyval.fieldnode) = makeVariableChain((yyvsp[-2].string), (yyvsp[0].string), NULL); 	}
#line 2396 "y.tab.c"
    break;

  case 117:
#line 476 "parser.y"
                                        {	(yyval.fieldnode) = makeVariableChain("SELF", (yyvsp[0].string), NULL);	}
#line 2402 "y.tab.c"
    break;

  case 118:
#line 477 "parser.y"
                                        { 	(yyval.fieldnode) = makeVariableChain("SELF", NULL, (yyvsp[0].fieldnode));	}
#line 2408 "y.tab.c"
    break;

  case 119:
#line 481 "parser.y"
                                        { (yyval.node) = makeConnectorNode((yyvsp[-2].node), (yyvsp[0].node));	}
#line 2414 "y.tab.c"
    break;

  case 120:
#line 482 "parser.y"
                                                        { (yyval.node) = makeConnectorNode(NULL, (yyvsp[0].node));  		}
#line 2420 "y.tab.c"
    break;

  case 121:
#line 483 "parser.y"
                        {	(yyval.node) = NULL;	}
#line 2426 "y.tab.c"
    break;


#line 2430 "y.tab.c"

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
#line 485 "parser.y"


int getfLabel() {
	return flabel++;
}

void yyerror(char const *s)
{
    printf("yyerror: %s\n",s);
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
