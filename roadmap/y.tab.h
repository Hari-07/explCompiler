/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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

#line 165 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
