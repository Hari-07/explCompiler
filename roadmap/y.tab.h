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

#line 152 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
