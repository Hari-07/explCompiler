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
    EXTENDS = 290,
    NUM = 291,
    VAR = 292,
    ADD = 293,
    SUB = 294,
    MUL = 295,
    DIV = 296,
    EQUALS = 297,
    SLT = 298,
    SGT = 299,
    LTE = 300,
    GTE = 301,
    NEQ = 302,
    EQU = 303,
    STRING = 304,
    ARR_INDEX = 305
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
#define EXTENDS 290
#define NUM 291
#define VAR 292
#define ADD 293
#define SUB 294
#define MUL 295
#define DIV 296
#define EQUALS 297
#define SLT 298
#define SGT 299
#define LTE 300
#define GTE 301
#define NEQ 302
#define EQU 303
#define STRING 304
#define ARR_INDEX 305

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

#line 270 "y.tab.c"

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
#define YYLAST   560

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
#define YYNRULES  124
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  262

#define YYUNDEFTOK  2
#define YYMAXUTOK   305


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
      54,    55,     2,     2,    56,     2,    59,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    53,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    57,     2,    58,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,    52,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   136,   136,   137,   144,   143,   149,   155,   156,   161,
     161,   172,   176,   184,   192,   193,   196,   197,   202,   201,
     210,   209,   219,   223,   231,   232,   236,   242,   243,   247,
     254,   255,   261,   259,   278,   279,   283,   284,   288,   292,
     293,   294,   298,   299,   300,   301,   302,   303,   309,   310,
     316,   314,   331,   332,   333,   337,   344,   345,   349,   350,
     354,   358,   359,   363,   369,   380,   381,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   400,
     404,   408,   411,   414,   418,   419,   423,   424,   425,   429,
     430,   434,   438,   442,   445,   446,   447,   448,   449,   450,
     454,   455,   459,   460,   461,   462,   466,   467,   468,   469,
     470,   471,   475,   476,   477,   481,   482,   483,   487,   488,
     489,   490,   494,   495,   496
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
  "TYPE", "ENDTYPE", "SELF", "NEW", "BREAKPOINT", "EXTENDS", "NUM", "VAR",
  "ADD", "SUB", "MUL", "DIV", "EQUALS", "SLT", "SGT", "LTE", "GTE", "NEQ",
  "EQU", "STRING", "ARR_INDEX", "'{'", "'}'", "';'", "'('", "')'", "','",
  "'['", "']'", "'.'", "$accept", "code", "typedefSection", "$@1",
  "typedefList", "typeDefinition", "$@2", "fieldList", "fieldDeclaration",
  "classdefSection", "classdefList", "classDefinition", "$@3", "$@4",
  "className", "classFieldList", "classField", "classMethodList",
  "classMethod", "classMethodDefList", "classMethodDefintion", "$@5",
  "globalDeclarations", "declarationList", "declaration", "dataTypeString",
  "variableList", "functionDefinitionList", "functionDefinition", "$@6",
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
     305,   123,   125,    59,    40,    41,    44,    91,    93,    46
};
# endif

#define YYPACT_NINF (-131)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-74)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      27,  -131,    15,    34,    25,  -131,    45,    84,  -131,    13,
    -131,    59,     3,  -131,    51,   -19,   -15,    81,  -131,  -131,
     100,  -131,  -131,    91,  -131,  -131,  -131,    -3,  -131,   121,
     138,   124,   -15,  -131,  -131,   -19,  -131,   -19,  -131,  -131,
       9,    11,   109,   111,  -131,  -131,    19,  -131,   129,   -19,
    -131,   -19,   127,   137,   -19,   145,  -131,   147,   131,   -19,
     136,  -131,   139,  -131,   -19,   181,   141,   153,  -131,    63,
     160,    66,  -131,   142,    23,   148,    68,  -131,  -131,   195,
     -19,  -131,   149,  -131,   -19,  -131,  -131,   -19,  -131,   -19,
     166,   199,   154,   -19,    41,  -131,   169,    70,  -131,    72,
     151,   -19,   327,   199,    47,  -131,  -131,   156,  -131,  -131,
    -131,   170,    -1,  -131,   161,   163,   327,   164,   174,  -131,
    -131,   327,    16,   175,  -131,   155,  -131,  -131,    22,  -131,
      16,   207,   179,  -131,  -131,  -131,  -131,  -131,  -131,  -131,
    -131,  -131,  -131,  -131,   490,   182,  -131,  -131,  -131,  -131,
     180,  -131,  -131,   -19,  -131,    30,  -131,  -131,    16,    16,
     353,    16,    16,   249,   501,  -131,    16,    -9,    16,    16,
      17,   381,  -131,   184,  -131,    16,    16,    16,    16,     6,
      16,    16,    16,    16,    16,    16,    16,   327,    75,  -131,
     201,   394,   407,   186,   420,   433,   188,   446,   187,  -131,
     501,    80,   365,   187,  -131,  -131,  -131,    32,    32,  -131,
    -131,   191,   193,   501,   512,   512,   512,   512,   512,   512,
      88,   196,   327,   198,  -131,   240,   237,    16,  -131,  -131,
      16,  -131,  -131,    16,  -131,   197,   216,  -131,  -131,   199,
     327,   327,   459,   472,   501,  -131,   200,  -131,   159,   275,
     134,  -131,  -131,   327,   327,  -131,  -131,  -131,   202,   301,
    -131,  -131
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       6,     4,     0,    15,     0,     1,     0,    35,     9,     0,
       8,    22,     0,    17,     0,     0,     0,     0,     5,     7,
       0,    14,    16,     0,    39,    40,    41,     0,    37,     0,
      39,     0,     0,    49,     3,     0,    23,     0,    34,    36,
      45,     0,     0,     0,    48,     2,     0,    12,     0,     0,
      25,    20,     0,     0,    54,     0,    38,     0,     0,    54,
       0,    11,     0,    24,    18,     0,     0,     0,    28,     0,
       0,     0,    53,     0,    42,     0,     0,    10,    13,     0,
       0,    27,     0,    26,    54,    55,    47,     0,    46,    54,
       0,    57,     0,     0,     0,    31,     0,     0,    52,     0,
       0,     0,     0,    57,     0,    21,    30,     0,    29,    44,
      43,     0,     0,    59,     0,     0,     0,     0,     0,    89,
      90,     0,     0,     0,   114,     0,    93,   112,   116,   113,
       0,     0,     0,    67,    68,    75,    76,    69,    70,    71,
      72,    74,    77,    78,     0,    95,    96,    97,    98,    99,
     117,    50,    19,    54,    62,     0,    56,    58,     0,     0,
       0,     0,     0,     0,    91,    95,     0,     0,   124,     0,
       0,     0,    64,     0,    66,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   124,     0,     0,    60,
       0,     0,     0,     0,     0,     0,     0,     0,   120,   121,
     123,     0,     0,   119,   118,    94,    65,   102,   103,   104,
     105,     0,     0,    83,   106,   107,   108,   109,   110,   111,
       0,     0,    63,     0,    61,     0,     0,     0,    79,    80,
       0,    82,   100,     0,   115,     0,     0,   101,    51,    57,
       0,     0,     0,     0,   122,    81,     0,    32,     0,     0,
       0,    88,    92,     0,     0,    85,    86,    87,     0,     0,
      33,    84
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -131,  -131,  -131,  -131,  -131,   248,  -131,  -131,   214,  -131,
    -131,   252,  -131,  -131,  -131,  -131,   222,   223,   -47,   183,
     -84,  -131,  -131,  -131,   247,   118,  -131,  -131,   245,  -131,
     -52,   192,   -97,  -131,   168,  -131,    29,   255,  -100,  -130,
    -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,
    -131,   -71,  -102,  -131,  -131,  -131,  -131,   -67,   110
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     9,    10,    17,    46,    47,     7,
      12,    13,    79,    65,    14,    49,    50,    51,    52,    94,
      95,   253,    16,    27,    28,    70,    41,    32,    33,   187,
      71,    72,   102,   112,   113,   155,   221,    34,   222,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   165,   146,   147,   148,   149,   150,   201
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     145,   173,   131,    38,    66,   156,   151,    76,    24,    25,
     106,    21,    30,    25,   145,     5,   160,    66,    26,   145,
     106,   163,    26,   125,    24,    25,    24,    25,   198,   145,
     173,   211,    97,   173,    26,   124,    26,    99,   125,   212,
      11,     6,   127,   128,    18,   124,    24,    25,   125,   125,
       8,   164,   127,   128,   203,   129,    26,     1,   145,   171,
     130,   145,     8,    54,    56,   129,    55,    57,    24,    25,
     130,    60,   177,   178,    24,    25,   168,    89,    26,   169,
      90,   170,    11,   189,    26,   145,   190,   191,   192,    15,
     194,   195,   173,   105,    20,   197,    37,   200,   202,   152,
     199,   188,    23,   204,   207,   208,   209,   210,   213,   214,
     215,   216,   217,   218,   219,   200,    83,    84,   173,   173,
     145,    86,    87,    92,    87,   108,    87,   109,    87,   173,
     223,    87,    35,    29,    31,   232,   233,    36,   145,   145,
     248,   249,   247,   237,   233,    29,   145,   145,   241,   257,
      31,   145,   145,    48,   259,    53,   242,   145,    40,   243,
      42,    43,   244,    58,    48,    59,    62,    53,   114,    67,
     254,   255,   115,   116,    69,   117,   118,   119,   120,   121,
      68,    73,    67,   122,    74,   123,    75,    80,   124,    77,
      82,   125,    78,   126,    81,   127,   128,    85,    96,    91,
      88,    93,   100,    84,   101,   103,   107,   154,   129,   110,
     153,    96,    96,   130,   167,   158,   114,   159,   161,   111,
     115,   116,    96,   117,   118,   119,   120,   121,   162,   166,
     111,   122,   174,   123,   186,   -73,   124,   206,   224,   125,
     227,   126,   230,   127,   128,   235,   170,   236,   238,   239,
     240,   241,   245,   246,   260,   252,   129,    19,   114,   172,
      61,   130,   115,   116,    22,   117,   118,   119,   120,   121,
     196,    63,    64,   122,    39,   123,   104,    44,   124,    98,
     157,   125,   258,   126,   114,   127,   128,    45,   115,   116,
     256,   117,   118,   119,   120,   121,   220,     0,   129,   122,
       0,   123,     0,   130,   124,     0,     0,   125,     0,   126,
     114,   127,   128,   261,   115,   116,     0,   117,   118,   119,
     120,   121,     0,     0,   129,   122,     0,   123,     0,   130,
     124,     0,     0,   125,     0,   126,   114,   127,   128,     0,
     115,   116,     0,   117,   118,   119,   120,   121,     0,     0,
     129,   122,     0,   123,     0,   130,   124,     0,     0,   125,
       0,   126,   114,   127,   128,     0,   193,   116,     0,   117,
     118,   119,   120,   121,     0,     0,   129,   122,     0,   123,
       0,   130,   124,     0,     0,   125,     0,   126,     0,   127,
     128,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   129,   175,   176,   177,   178,   130,   180,   181,
     182,   183,   184,   185,     0,     0,     0,     0,     0,   175,
     176,   177,   178,   234,   180,   181,   182,   183,   184,   185,
       0,     0,   175,   176,   177,   178,   205,   180,   181,   182,
     183,   184,   185,     0,     0,   175,   176,   177,   178,   225,
     180,   181,   182,   183,   184,   185,     0,     0,   175,   176,
     177,   178,   226,   180,   181,   182,   183,   184,   185,     0,
       0,   175,   176,   177,   178,   228,   180,   181,   182,   183,
     184,   185,     0,     0,   175,   176,   177,   178,   229,   180,
     181,   182,   183,   184,   185,     0,     0,   175,   176,   177,
     178,   231,   180,   181,   182,   183,   184,   185,     0,     0,
     175,   176,   177,   178,   250,   180,   181,   182,   183,   184,
     185,     0,     0,     0,     0,     0,     0,   251,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   175,
     176,   177,   178,     0,   180,   181,   182,   183,   184,   185,
     175,   176,   177,   178,     0,   -74,   -74,   -74,   -74,   -74,
     -74
};

static const yytype_int16 yycheck[] =
{
     102,   131,   102,     6,    51,     6,   103,    59,    27,    28,
      94,     8,    27,    28,   116,     0,   116,    64,    37,   121,
     104,   121,    37,    32,    27,    28,    27,    28,    37,   131,
     160,    25,    84,   163,    37,    29,    37,    89,    32,    33,
      37,     7,    36,    37,    31,    29,    27,    28,    32,    32,
      37,   122,    36,    37,    37,    49,    37,    30,   160,   130,
      54,   163,    37,    54,    53,    49,    57,    56,    27,    28,
      54,    52,    40,    41,    27,    28,    54,    54,    37,    57,
      57,    59,    37,    53,    37,   187,    56,   158,   159,     5,
     161,   162,   222,    52,    35,   166,     5,   168,   169,    52,
     167,   153,    51,   170,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,    53,    54,   248,   249,
     222,    55,    56,    55,    56,    55,    56,    55,    56,   259,
      55,    56,    51,    15,    16,    55,    56,    37,   240,   241,
     240,   241,   239,    55,    56,    27,   248,   249,    14,    15,
      32,   253,   254,    35,   254,    37,   227,   259,    37,   230,
      22,    37,   233,    54,    46,    54,    37,    49,     9,    51,
      11,    12,    13,    14,    37,    16,    17,    18,    19,    20,
      53,    36,    64,    24,    37,    26,    55,     6,    29,    53,
      37,    32,    53,    34,    53,    36,    37,    37,    80,    51,
      58,     6,    36,    54,     5,    51,    37,    37,    49,    58,
      54,    93,    94,    54,    59,    54,     9,    54,    54,   101,
      13,    14,   104,    16,    17,    18,    19,    20,    54,    54,
     112,    24,    53,    26,    54,    53,    29,    53,    37,    32,
      54,    34,    54,    36,    37,    54,    59,    54,    52,    51,
      10,    14,    55,    37,    52,    55,    49,     9,     9,    52,
      46,    54,    13,    14,    12,    16,    17,    18,    19,    20,
      21,    49,    49,    24,    27,    26,    93,    32,    29,    87,
     112,    32,   253,    34,     9,    36,    37,    32,    13,    14,
      15,    16,    17,    18,    19,    20,   186,    -1,    49,    24,
      -1,    26,    -1,    54,    29,    -1,    -1,    32,    -1,    34,
       9,    36,    37,    12,    13,    14,    -1,    16,    17,    18,
      19,    20,    -1,    -1,    49,    24,    -1,    26,    -1,    54,
      29,    -1,    -1,    32,    -1,    34,     9,    36,    37,    -1,
      13,    14,    -1,    16,    17,    18,    19,    20,    -1,    -1,
      49,    24,    -1,    26,    -1,    54,    29,    -1,    -1,    32,
      -1,    34,     9,    36,    37,    -1,    13,    14,    -1,    16,
      17,    18,    19,    20,    -1,    -1,    49,    24,    -1,    26,
      -1,    54,    29,    -1,    -1,    32,    -1,    34,    -1,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    38,    39,    40,    41,    54,    43,    44,
      45,    46,    47,    48,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    58,    43,    44,    45,    46,    47,    48,
      -1,    -1,    38,    39,    40,    41,    55,    43,    44,    45,
      46,    47,    48,    -1,    -1,    38,    39,    40,    41,    55,
      43,    44,    45,    46,    47,    48,    -1,    -1,    38,    39,
      40,    41,    55,    43,    44,    45,    46,    47,    48,    -1,
      -1,    38,    39,    40,    41,    55,    43,    44,    45,    46,
      47,    48,    -1,    -1,    38,    39,    40,    41,    55,    43,
      44,    45,    46,    47,    48,    -1,    -1,    38,    39,    40,
      41,    55,    43,    44,    45,    46,    47,    48,    -1,    -1,
      38,    39,    40,    41,    55,    43,    44,    45,    46,    47,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    55,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    38,
      39,    40,    41,    -1,    43,    44,    45,    46,    47,    48,
      38,    39,    40,    41,    -1,    43,    44,    45,    46,    47,
      48
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    30,    61,    62,    63,     0,     7,    69,    37,    64,
      65,    37,    70,    71,    74,     5,    82,    66,    31,    65,
      35,     8,    71,    51,    27,    28,    37,    83,    84,    85,
      27,    85,    87,    88,    97,    51,    37,     5,     6,    84,
      37,    86,    22,    37,    88,    97,    67,    68,    85,    75,
      76,    77,    78,    85,    54,    57,    53,    56,    54,    54,
      52,    68,    37,    76,    77,    73,    78,    85,    53,    37,
      85,    90,    91,    36,    37,    55,    90,    53,    53,    72,
       6,    53,    37,    53,    54,    37,    55,    56,    58,    54,
      57,    51,    55,     6,    79,    80,    85,    90,    91,    90,
      36,     5,    92,    51,    79,    52,    80,    37,    55,    55,
      58,    85,    93,    94,     9,    13,    14,    16,    17,    18,
      19,    20,    24,    26,    29,    32,    34,    36,    37,    49,
      54,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,    92,    52,    54,    37,    95,     6,    94,    54,    54,
      98,    54,    54,    98,   111,   112,    54,    59,    54,    57,
      59,   111,    52,    99,    53,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    54,    89,    90,    53,
      56,   111,   111,    13,   111,   111,    21,   111,    37,   117,
     111,   118,   111,    37,   117,    55,    53,   111,   111,   111,
     111,    25,    33,   111,   111,   111,   111,   111,   111,   111,
     118,    96,    98,    55,    37,    55,    55,    54,    55,    55,
      54,    55,    55,    56,    58,    54,    54,    55,    52,    51,
      10,    14,   111,   111,   111,    55,    37,    92,    98,    98,
      55,    55,    55,    81,    11,    12,    15,    15,    96,    98,
      52,    12
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    60,    61,    61,    63,    62,    62,    64,    64,    66,
      65,    67,    67,    68,    69,    69,    70,    70,    72,    71,
      73,    71,    74,    74,    75,    75,    76,    77,    77,    78,
      79,    79,    81,    80,    82,    82,    83,    83,    84,    85,
      85,    85,    86,    86,    86,    86,    86,    86,    87,    87,
      89,    88,    90,    90,    90,    91,    92,    92,    93,    93,
      94,    95,    95,    96,    97,    98,    98,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,   100,
     101,   102,   103,   104,   105,   105,   106,   106,   106,   107,
     107,   108,   109,   110,   111,   111,   111,   111,   111,   111,
     112,   112,   113,   113,   113,   113,   114,   114,   114,   114,
     114,   114,   115,   115,   115,   116,   116,   116,   117,   117,
     117,   117,   118,   118,   118
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     4,     0,     4,     0,     2,     1,     0,
       6,     2,     1,     3,     3,     0,     2,     1,     0,     9,
       0,     8,     1,     3,     2,     1,     3,     3,     2,     5,
       2,     1,     0,    10,     3,     0,     2,     1,     3,     1,
       1,     1,     3,     6,     6,     1,     4,     4,     2,     1,
       0,    10,     3,     1,     0,     2,     3,     0,     2,     1,
       3,     3,     1,     1,     8,     3,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     5,     4,     3,     9,     7,     7,     7,     6,     1,
       1,     2,     6,     1,     3,     1,     1,     1,     1,     1,
       4,     4,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     4,     1,     1,     3,     3,
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
  case 4:
#line 144 "parser.y"
                        {
				typeTableCreate();
			}
#line 1701 "y.tab.c"
    break;

  case 5:
#line 148 "parser.y"
                                                                {}
#line 1707 "y.tab.c"
    break;

  case 6:
#line 149 "parser.y"
                        {
				typeTableCreate();
			}
#line 1715 "y.tab.c"
    break;

  case 7:
#line 155 "parser.y"
                                                                {}
#line 1721 "y.tab.c"
    break;

  case 8:
#line 156 "parser.y"
                                                                        {}
#line 1727 "y.tab.c"
    break;

  case 9:
#line 161 "parser.y"
                    {
				createTypeTableEntry((yyvsp[0].string));
			}
#line 1735 "y.tab.c"
    break;

  case 10:
#line 165 "parser.y"
                        {	
				addFieldsToTypeTable((yyvsp[-5].string), (yyvsp[-2].fieldnode)); 
			}
#line 1743 "y.tab.c"
    break;

  case 11:
#line 173 "parser.y"
                        {   
				(yyval.fieldnode) = addToFieldList((yyvsp[0].fieldnode), (yyvsp[-1].fieldnode));
			}
#line 1751 "y.tab.c"
    break;

  case 12:
#line 177 "parser.y"
                        {
				(yyval.fieldnode) = addToFieldList((yyvsp[0].fieldnode), NULL);
			}
#line 1759 "y.tab.c"
    break;

  case 13:
#line 185 "parser.y"
                        {
				(yyval.fieldnode) = createFieldNode(findTypeTableEntry((yyvsp[-2].string)), (yyvsp[-1].string));
			}
#line 1767 "y.tab.c"
    break;

  case 14:
#line 192 "parser.y"
                                                 {}
#line 1773 "y.tab.c"
    break;

  case 15:
#line 193 "parser.y"
                  {}
#line 1779 "y.tab.c"
    break;

  case 16:
#line 196 "parser.y"
                                                {}
#line 1785 "y.tab.c"
    break;

  case 17:
#line 197 "parser.y"
                                                                {}
#line 1791 "y.tab.c"
    break;

  case 18:
#line 202 "parser.y"
                        {
				addFieldToClass((yyvsp[-4].string), (yyvsp[-1].fieldnode));
				addMethodsToClass((yyvsp[-4].string), (yyvsp[0].classMethodNode));
				createFunctionTable();
			}
#line 1801 "y.tab.c"
    break;

  case 19:
#line 208 "parser.y"
                        {}
#line 1807 "y.tab.c"
    break;

  case 20:
#line 210 "parser.y"
                        {
				addMethodsToClass((yyvsp[-3].string), (yyvsp[0].classMethodNode));
				createFunctionTable();
			}
#line 1816 "y.tab.c"
    break;

  case 21:
#line 215 "parser.y"
                        {}
#line 1822 "y.tab.c"
    break;

  case 22:
#line 219 "parser.y"
                                        {	
						createClassTableEntry((yyvsp[0].string), NULL);
						(yyval.string) = (yyvsp[0].string);
					}
#line 1831 "y.tab.c"
    break;

  case 23:
#line 224 "parser.y"
                {
			createClassTableEntry((yyvsp[-2].string), findClassTableEntry((yyvsp[0].string)));
			(yyval.string) = (yyvsp[-2].string);
		}
#line 1840 "y.tab.c"
    break;

  case 24:
#line 231 "parser.y"
                                                        {	(yyval.fieldnode) = addToClassFieldNodeList((yyvsp[0].fieldnode), (yyvsp[-1].fieldnode));	}
#line 1846 "y.tab.c"
    break;

  case 25:
#line 232 "parser.y"
                                                                        {	(yyval.fieldnode) = addToClassFieldNodeList((yyvsp[0].fieldnode), NULL);	}
#line 1852 "y.tab.c"
    break;

  case 26:
#line 237 "parser.y"
                {
			(yyval.fieldnode) = createClassFieldNode((yyvsp[-2].string), (yyvsp[-1].string));
		}
#line 1860 "y.tab.c"
    break;

  case 27:
#line 242 "parser.y"
                                                {	(yyval.classMethodNode) = addToClassMethodList((yyvsp[-1].classMethodNode), (yyvsp[-2].classMethodNode));		}
#line 1866 "y.tab.c"
    break;

  case 28:
#line 243 "parser.y"
                                                                {	(yyval.classMethodNode) = addToClassMethodList((yyvsp[-1].classMethodNode), NULL);	}
#line 1872 "y.tab.c"
    break;

  case 29:
#line 248 "parser.y"
                        {
				(yyval.classMethodNode) = createClassMethodNode((yyvsp[-3].string), getfLabel(), findTypeTableEntry((yyvsp[-4].string)), (yyvsp[-1].fparams));
			}
#line 1880 "y.tab.c"
    break;

  case 30:
#line 254 "parser.y"
                                                                {}
#line 1886 "y.tab.c"
    break;

  case 31:
#line 255 "parser.y"
                                                                                {}
#line 1892 "y.tab.c"
    break;

  case 32:
#line 261 "parser.y"
                                {
					checkMethodValidity((yyvsp[-5].string), (yyvsp[-3].fparams));
					addParamstoLSymbol((yyvsp[-3].fparams));
					addSelfToLSymbol();
				}
#line 1902 "y.tab.c"
    break;

  case 33:
#line 267 "parser.y"
                        {
				// printf("FUNCTION CODEGEN TAKES PLACE\n");
				startCodeGen((yyvsp[-8].string), 1, (yyvsp[-1].node));
				terminateFunction();
			}
#line 1912 "y.tab.c"
    break;

  case 34:
#line 278 "parser.y"
                                                {}
#line 1918 "y.tab.c"
    break;

  case 35:
#line 279 "parser.y"
                  {}
#line 1924 "y.tab.c"
    break;

  case 36:
#line 283 "parser.y"
                                                        {}
#line 1930 "y.tab.c"
    break;

  case 37:
#line 284 "parser.y"
                                                                        {}
#line 1936 "y.tab.c"
    break;

  case 38:
#line 288 "parser.y"
                                                        {}
#line 1942 "y.tab.c"
    break;

  case 39:
#line 292 "parser.y"
                        {	(yyval.string) = (yyvsp[0].string);	}
#line 1948 "y.tab.c"
    break;

  case 40:
#line 293 "parser.y"
                        {	(yyval.string) = (yyvsp[0].string);	}
#line 1954 "y.tab.c"
    break;

  case 41:
#line 294 "parser.y"
                        {	(yyval.string) = (yyvsp[0].string);	}
#line 1960 "y.tab.c"
    break;

  case 42:
#line 298 "parser.y"
                                                                        {	addGlobalVariable((yyvsp[0].string), (yyvsp[-3].string), 		1, 		  -1, NULL);	}
#line 1966 "y.tab.c"
    break;

  case 43:
#line 299 "parser.y"
                                                                {	addGlobalVariable((yyvsp[-3].string), (yyvsp[-6].string), 	(yyvsp[-1].integer), -1, NULL);		}
#line 1972 "y.tab.c"
    break;

  case 44:
#line 300 "parser.y"
                                                        {   addGlobalVariable((yyvsp[-3].string), (yyvsp[-6].string), 		0, getfLabel(), (yyvsp[-1].fparams));	}
#line 1978 "y.tab.c"
    break;

  case 45:
#line 301 "parser.y"
                                                                                                {	addGlobalVariable((yyvsp[0].string), (yyvsp[-1].string), 		1, 		  -1, NULL); 	}
#line 1984 "y.tab.c"
    break;

  case 46:
#line 302 "parser.y"
                                                                                {	addGlobalVariable((yyvsp[-3].string), (yyvsp[-4].string), 	(yyvsp[-2].integer), -1, NULL);		}
#line 1990 "y.tab.c"
    break;

  case 47:
#line 303 "parser.y"
                                                                        {   addGlobalVariable((yyvsp[-3].string), (yyvsp[-4].string), 		0, getfLabel(), (yyvsp[-1].fparams));	}
#line 1996 "y.tab.c"
    break;

  case 50:
#line 316 "parser.y"
                                {
					if(checkNameEquivalence((yyvsp[-3].fparams), (yyvsp[-5].string)) == 0){
						printf("ILLEGAL FUNCTION DEFINITION\n");
						exit(-1);
					}
					addParamstoLSymbol((yyvsp[-3].fparams));
				}
#line 2008 "y.tab.c"
    break;

  case 51:
#line 324 "parser.y"
                        {
				startCodeGen((yyvsp[-8].string), 0, (yyvsp[-1].node));
				terminateFunction();
			}
#line 2017 "y.tab.c"
    break;

  case 52:
#line 331 "parser.y"
                                                        { (yyval.fparams) = addParameter((yyvsp[-2].fparams), (yyvsp[0].fparams)); }
#line 2023 "y.tab.c"
    break;

  case 53:
#line 332 "parser.y"
                                                                        { (yyval.fparams) = (yyvsp[0].fparams); }
#line 2029 "y.tab.c"
    break;

  case 54:
#line 333 "parser.y"
                        {	(yyval.fparams) = NULL;	}
#line 2035 "y.tab.c"
    break;

  case 55:
#line 338 "parser.y"
                        { 	
				(yyval.fparams) = createParameter((yyvsp[0].string), findTypeTableEntry((yyvsp[-1].string)));
			}
#line 2043 "y.tab.c"
    break;

  case 56:
#line 344 "parser.y"
                                                        { (yyval.node) = (yyvsp[-1].node); }
#line 2049 "y.tab.c"
    break;

  case 57:
#line 345 "parser.y"
                        {	(yyval.node) = NULL;	}
#line 2055 "y.tab.c"
    break;

  case 60:
#line 354 "parser.y"
                                                                {}
#line 2061 "y.tab.c"
    break;

  case 61:
#line 358 "parser.y"
                                                        {	addLocalVariable((yyvsp[0].string), (yyvsp[-3].string));	}
#line 2067 "y.tab.c"
    break;

  case 62:
#line 359 "parser.y"
                                                                                {	addLocalVariable((yyvsp[0].string), (yyvsp[-1].string)); 	}
#line 2073 "y.tab.c"
    break;

  case 63:
#line 363 "parser.y"
                                { 	(yyval.node) = (yyvsp[0].node);	}
#line 2079 "y.tab.c"
    break;

  case 64:
#line 370 "parser.y"
                        {
				// printf("AST COMPLETED\n");
				// exit(0);
				startCodeGen("main", 0, (yyvsp[-1].node));
				printf("COMPLETED\n");
			}
#line 2090 "y.tab.c"
    break;

  case 65:
#line 380 "parser.y"
                                                        {	(yyval.node) = makeConnectorNode((yyvsp[-2].node), (yyvsp[-1].node));		}
#line 2096 "y.tab.c"
    break;

  case 66:
#line 381 "parser.y"
                                                                {	(yyval.node) = makeConnectorNode((yyvsp[-1].node), NULL);	}
#line 2102 "y.tab.c"
    break;

  case 67:
#line 385 "parser.y"
                                                        {  (yyval.node) = (yyvsp[0].node); }
#line 2108 "y.tab.c"
    break;

  case 68:
#line 386 "parser.y"
                                                        {  (yyval.node) = (yyvsp[0].node); }
#line 2114 "y.tab.c"
    break;

  case 69:
#line 387 "parser.y"
                                                        {  (yyval.node) = (yyvsp[0].node); }
#line 2120 "y.tab.c"
    break;

  case 70:
#line 388 "parser.y"
                                                                {  (yyval.node) = (yyvsp[0].node); }
#line 2126 "y.tab.c"
    break;

  case 71:
#line 389 "parser.y"
                                                        {  (yyval.node) = (yyvsp[0].node); }
#line 2132 "y.tab.c"
    break;

  case 72:
#line 390 "parser.y"
                                                        {  (yyval.node) = (yyvsp[0].node); }
#line 2138 "y.tab.c"
    break;

  case 73:
#line 391 "parser.y"
                                                {  (yyval.node) = (yyvsp[0].node); }
#line 2144 "y.tab.c"
    break;

  case 74:
#line 392 "parser.y"
                                                        {  (yyval.node) = (yyvsp[0].node); }
#line 2150 "y.tab.c"
    break;

  case 75:
#line 393 "parser.y"
                                                        {  (yyval.node) = (yyvsp[0].node); }
#line 2156 "y.tab.c"
    break;

  case 76:
#line 394 "parser.y"
                                                        {  (yyval.node) = (yyvsp[0].node); }
#line 2162 "y.tab.c"
    break;

  case 77:
#line 395 "parser.y"
                                                        {  (yyval.node) = (yyvsp[0].node);	}
#line 2168 "y.tab.c"
    break;

  case 78:
#line 396 "parser.y"
                                                        {  (yyval.node) = (yyvsp[0].node); }
#line 2174 "y.tab.c"
    break;

  case 79:
#line 400 "parser.y"
                                        {	(yyval.node) = makeReadNode((yyvsp[-1].node));	}
#line 2180 "y.tab.c"
    break;

  case 80:
#line 404 "parser.y"
                                        { 	(yyval.node) = makeWriteNode((yyvsp[-1].node));	}
#line 2186 "y.tab.c"
    break;

  case 81:
#line 408 "parser.y"
                                                        {  (yyval.node) = makeAllocNode((yyvsp[-4].node)); }
#line 2192 "y.tab.c"
    break;

  case 82:
#line 411 "parser.y"
                                                                {  (yyval.node) = makeDeAllocNode((yyvsp[-1].node)); }
#line 2198 "y.tab.c"
    break;

  case 83:
#line 414 "parser.y"
                                                        {	(yyval.node) = makeOperatorNode(0, "=",(yyvsp[-2].node),(yyvsp[0].node));	}
#line 2204 "y.tab.c"
    break;

  case 84:
#line 418 "parser.y"
                                                                                                { 	(yyval.node) = makeIfNode((yyvsp[-6].node), (yyvsp[-3].node), (yyvsp[-1].node)); 	}
#line 2210 "y.tab.c"
    break;

  case 85:
#line 419 "parser.y"
                                                                                                                { 	(yyval.node) = makeIfNode((yyvsp[-4].node), (yyvsp[-1].node), NULL); 	}
#line 2216 "y.tab.c"
    break;

  case 86:
#line 423 "parser.y"
                                                                        {	(yyval.node) = makeWhileNode(0, (yyvsp[-4].node), (yyvsp[-1].node));	}
#line 2222 "y.tab.c"
    break;

  case 87:
#line 424 "parser.y"
                                                                        {	(yyval.node) = makeWhileNode(1, (yyvsp[-2].node), (yyvsp[-5].node)); 	}
#line 2228 "y.tab.c"
    break;

  case 88:
#line 425 "parser.y"
                                                                                {	(yyval.node) = makeWhileNode(2, (yyvsp[-1].node), (yyvsp[-4].node));	}
#line 2234 "y.tab.c"
    break;

  case 89:
#line 429 "parser.y"
                                {	(yyval.node) = makeJumpStatement(0);	}
#line 2240 "y.tab.c"
    break;

  case 90:
#line 430 "parser.y"
                                {	(yyval.node) = makeJumpStatement(1);	}
#line 2246 "y.tab.c"
    break;

  case 91:
#line 434 "parser.y"
                                        { 	(yyval.node) = makeReturnNode((yyvsp[0].node)); }
#line 2252 "y.tab.c"
    break;

  case 92:
#line 438 "parser.y"
                                                { (yyval.node) = makeClassConstructorNode((yyvsp[-5].node), (yyvsp[-1].string)); }
#line 2258 "y.tab.c"
    break;

  case 93:
#line 442 "parser.y"
                                        { (yyval.node) = makeBreakPointNode(); }
#line 2264 "y.tab.c"
    break;

  case 94:
#line 445 "parser.y"
                                                {  	(yyval.node) = (yyvsp[-1].node); 	}
#line 2270 "y.tab.c"
    break;

  case 95:
#line 446 "parser.y"
                                        {	(yyval.node) = (yyvsp[0].node);		}
#line 2276 "y.tab.c"
    break;

  case 96:
#line 447 "parser.y"
                                        {  	(yyval.node) = (yyvsp[0].node); 		}
#line 2282 "y.tab.c"
    break;

  case 97:
#line 448 "parser.y"
                                                {  	(yyval.node) = (yyvsp[0].node); 		}
#line 2288 "y.tab.c"
    break;

  case 98:
#line 449 "parser.y"
                                                        {  	(yyval.node) = (yyvsp[0].node); 		}
#line 2294 "y.tab.c"
    break;

  case 99:
#line 450 "parser.y"
                                                        {  	(yyval.node) = (yyvsp[0].node); 		}
#line 2300 "y.tab.c"
    break;

  case 100:
#line 454 "parser.y"
                                                {	(yyval.node) = makeFunctionCallNode((yyvsp[-3].string), (yyvsp[-1].node));	}
#line 2306 "y.tab.c"
    break;

  case 101:
#line 455 "parser.y"
                                        {	(yyval.node) = makeClassMethodCallNode((yyvsp[-3].fieldnode), (yyvsp[-1].node));	}
#line 2312 "y.tab.c"
    break;

  case 102:
#line 459 "parser.y"
                                                        {	(yyval.node) = makeOperatorNode(1, "+",  (yyvsp[-2].node), (yyvsp[0].node));	}
#line 2318 "y.tab.c"
    break;

  case 103:
#line 460 "parser.y"
                                                        {	(yyval.node) = makeOperatorNode(1, "-",  (yyvsp[-2].node), (yyvsp[0].node));	}
#line 2324 "y.tab.c"
    break;

  case 104:
#line 461 "parser.y"
                                                        {	(yyval.node) = makeOperatorNode(1, "*",  (yyvsp[-2].node), (yyvsp[0].node));	}
#line 2330 "y.tab.c"
    break;

  case 105:
#line 462 "parser.y"
                                                        {	(yyval.node) = makeOperatorNode(1, "/",  (yyvsp[-2].node), (yyvsp[0].node));	}
#line 2336 "y.tab.c"
    break;

  case 106:
#line 466 "parser.y"
                                                {	(yyval.node) = makeOperatorNode(2, "<",  (yyvsp[-2].node), (yyvsp[0].node));	}
#line 2342 "y.tab.c"
    break;

  case 107:
#line 467 "parser.y"
                                                {	(yyval.node) = makeOperatorNode(2, ">",  (yyvsp[-2].node), (yyvsp[0].node));	}
#line 2348 "y.tab.c"
    break;

  case 108:
#line 468 "parser.y"
                                                {	(yyval.node) = makeOperatorNode(2, "<=", (yyvsp[-2].node), (yyvsp[0].node));	}
#line 2354 "y.tab.c"
    break;

  case 109:
#line 469 "parser.y"
                                                {	(yyval.node) = makeOperatorNode(2, ">=", (yyvsp[-2].node), (yyvsp[0].node));	}
#line 2360 "y.tab.c"
    break;

  case 110:
#line 470 "parser.y"
                                                {	(yyval.node) = makeOperatorNode(2, "!=", (yyvsp[-2].node), (yyvsp[0].node));	}
#line 2366 "y.tab.c"
    break;

  case 111:
#line 471 "parser.y"
                                                {	(yyval.node) = makeOperatorNode(2, "==", (yyvsp[-2].node), (yyvsp[0].node));	}
#line 2372 "y.tab.c"
    break;

  case 112:
#line 475 "parser.y"
                                                {	(yyval.node) = makeConstantNode(findTypeTableEntry("int"), (yyvsp[0].integer), NULL); 	}
#line 2378 "y.tab.c"
    break;

  case 113:
#line 476 "parser.y"
                        {	(yyval.node) = makeConstantNode(findTypeTableEntry("string"), 0, (yyvsp[0].string));		}
#line 2384 "y.tab.c"
    break;

  case 114:
#line 477 "parser.y"
                                        {   (yyval.node) = makeConstantNode(findTypeTableEntry("void"), 0, NULL);				}
#line 2390 "y.tab.c"
    break;

  case 115:
#line 481 "parser.y"
                                        {	(yyval.node) = makeVariableNode((yyvsp[-3].string), (yyvsp[-1].node));	}
#line 2396 "y.tab.c"
    break;

  case 116:
#line 482 "parser.y"
                                                                {	(yyval.node) = makeVariableNode((yyvsp[0].string), makeConstantNode(findTypeTableEntry("int"), 0, NULL)); }
#line 2402 "y.tab.c"
    break;

  case 117:
#line 483 "parser.y"
                                                        { 	(yyval.node) = makeFieldNode((yyvsp[0].fieldnode), makeConstantNode(findTypeTableEntry("int"), 0, NULL)); }
#line 2408 "y.tab.c"
    break;

  case 118:
#line 487 "parser.y"
                                                {	(yyval.fieldnode) = makeVariableChain((yyvsp[-2].string), NULL, (yyvsp[0].fieldnode)); 			}
#line 2414 "y.tab.c"
    break;

  case 119:
#line 488 "parser.y"
                                                {	(yyval.fieldnode) = makeVariableChain((yyvsp[-2].string), (yyvsp[0].string), NULL); 	}
#line 2420 "y.tab.c"
    break;

  case 120:
#line 489 "parser.y"
                                        {	(yyval.fieldnode) = makeVariableChain("SELF", (yyvsp[0].string), NULL);	}
#line 2426 "y.tab.c"
    break;

  case 121:
#line 490 "parser.y"
                                        { 	(yyval.fieldnode) = makeVariableChain("SELF", NULL, (yyvsp[0].fieldnode));	}
#line 2432 "y.tab.c"
    break;

  case 122:
#line 494 "parser.y"
                                        { (yyval.node) = makeConnectorNode((yyvsp[-2].node), (yyvsp[0].node));	}
#line 2438 "y.tab.c"
    break;

  case 123:
#line 495 "parser.y"
                                                        { (yyval.node) = makeConnectorNode(NULL, (yyvsp[0].node));  		}
#line 2444 "y.tab.c"
    break;

  case 124:
#line 496 "parser.y"
                        {	(yyval.node) = NULL;	}
#line 2450 "y.tab.c"
    break;


#line 2454 "y.tab.c"

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
#line 498 "parser.y"


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
