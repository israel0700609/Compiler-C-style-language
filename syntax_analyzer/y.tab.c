/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast/ast.h"

extern int yylineno;
extern char* yytext;
extern Node* root;

int yylex();
void yyerror(const char* s);


#line 86 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    BOOL = 258,                    /* BOOL  */
    CHAR = 259,                    /* CHAR  */
    INT = 260,                     /* INT  */
    REAL = 261,                    /* REAL  */
    STRING = 262,                  /* STRING  */
    INTPTR = 263,                  /* INTPTR  */
    CHARPTR = 264,                 /* CHARPTR  */
    REALPTR = 265,                 /* REALPTR  */
    IF = 266,                      /* IF  */
    ELSE = 267,                    /* ELSE  */
    WHILE = 268,                   /* WHILE  */
    FOR = 269,                     /* FOR  */
    VAR = 270,                     /* VAR  */
    FUNC = 271,                    /* FUNC  */
    PROC = 272,                    /* PROC  */
    RETURN = 273,                  /* RETURN  */
    NULL_TOK = 274,                /* NULL_TOK  */
    TRUE_LITERAL = 275,            /* TRUE_LITERAL  */
    FALSE_LITERAL = 276,           /* FALSE_LITERAL  */
    INT_LITERAL = 277,             /* INT_LITERAL  */
    REAL_LITERAL = 278,            /* REAL_LITERAL  */
    STRING_LITERAL = 279,          /* STRING_LITERAL  */
    CHAR_LITERAL = 280,            /* CHAR_LITERAL  */
    IDENTIFIER = 281,              /* IDENTIFIER  */
    EQ = 282,                      /* EQ  */
    NEQ = 283,                     /* NEQ  */
    GTE = 284,                     /* GTE  */
    LTE = 285,                     /* LTE  */
    AND = 286,                     /* AND  */
    OR = 287                       /* OR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define BOOL 258
#define CHAR 259
#define INT 260
#define REAL 261
#define STRING 262
#define INTPTR 263
#define CHARPTR 264
#define REALPTR 265
#define IF 266
#define ELSE 267
#define WHILE 268
#define FOR 269
#define VAR 270
#define FUNC 271
#define PROC 272
#define RETURN 273
#define NULL_TOK 274
#define TRUE_LITERAL 275
#define FALSE_LITERAL 276
#define INT_LITERAL 277
#define REAL_LITERAL 278
#define STRING_LITERAL 279
#define CHAR_LITERAL 280
#define IDENTIFIER 281
#define EQ 282
#define NEQ 283
#define GTE 284
#define LTE 285
#define AND 286
#define OR 287

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "parser.y"

    Node* node_val;
    int int_val;
    double real_val;
    char char_val;
    char* str_val;

#line 211 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_BOOL = 3,                       /* BOOL  */
  YYSYMBOL_CHAR = 4,                       /* CHAR  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_REAL = 6,                       /* REAL  */
  YYSYMBOL_STRING = 7,                     /* STRING  */
  YYSYMBOL_INTPTR = 8,                     /* INTPTR  */
  YYSYMBOL_CHARPTR = 9,                    /* CHARPTR  */
  YYSYMBOL_REALPTR = 10,                   /* REALPTR  */
  YYSYMBOL_IF = 11,                        /* IF  */
  YYSYMBOL_ELSE = 12,                      /* ELSE  */
  YYSYMBOL_WHILE = 13,                     /* WHILE  */
  YYSYMBOL_FOR = 14,                       /* FOR  */
  YYSYMBOL_VAR = 15,                       /* VAR  */
  YYSYMBOL_FUNC = 16,                      /* FUNC  */
  YYSYMBOL_PROC = 17,                      /* PROC  */
  YYSYMBOL_RETURN = 18,                    /* RETURN  */
  YYSYMBOL_NULL_TOK = 19,                  /* NULL_TOK  */
  YYSYMBOL_TRUE_LITERAL = 20,              /* TRUE_LITERAL  */
  YYSYMBOL_FALSE_LITERAL = 21,             /* FALSE_LITERAL  */
  YYSYMBOL_INT_LITERAL = 22,               /* INT_LITERAL  */
  YYSYMBOL_REAL_LITERAL = 23,              /* REAL_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 24,            /* STRING_LITERAL  */
  YYSYMBOL_CHAR_LITERAL = 25,              /* CHAR_LITERAL  */
  YYSYMBOL_IDENTIFIER = 26,                /* IDENTIFIER  */
  YYSYMBOL_EQ = 27,                        /* EQ  */
  YYSYMBOL_NEQ = 28,                       /* NEQ  */
  YYSYMBOL_GTE = 29,                       /* GTE  */
  YYSYMBOL_LTE = 30,                       /* LTE  */
  YYSYMBOL_AND = 31,                       /* AND  */
  YYSYMBOL_OR = 32,                        /* OR  */
  YYSYMBOL_33_ = 33,                       /* '>'  */
  YYSYMBOL_34_ = 34,                       /* '<'  */
  YYSYMBOL_35_ = 35,                       /* '+'  */
  YYSYMBOL_36_ = 36,                       /* '-'  */
  YYSYMBOL_37_ = 37,                       /* '*'  */
  YYSYMBOL_38_ = 38,                       /* '/'  */
  YYSYMBOL_39_ = 39,                       /* '!'  */
  YYSYMBOL_40_ = 40,                       /* '^'  */
  YYSYMBOL_41_ = 41,                       /* '&'  */
  YYSYMBOL_42_ = 42,                       /* '('  */
  YYSYMBOL_43_ = 43,                       /* ')'  */
  YYSYMBOL_44_ = 44,                       /* '{'  */
  YYSYMBOL_45_ = 45,                       /* '}'  */
  YYSYMBOL_46_ = 46,                       /* ','  */
  YYSYMBOL_47_ = 47,                       /* ':'  */
  YYSYMBOL_48_ = 48,                       /* ';'  */
  YYSYMBOL_49_ = 49,                       /* '='  */
  YYSYMBOL_50_ = 50,                       /* '['  */
  YYSYMBOL_51_ = 51,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 52,                  /* $accept  */
  YYSYMBOL_program = 53,                   /* program  */
  YYSYMBOL_functions = 54,                 /* functions  */
  YYSYMBOL_function = 55,                  /* function  */
  YYSYMBOL_proc = 56,                      /* proc  */
  YYSYMBOL_parameter_list = 57,            /* parameter_list  */
  YYSYMBOL_non_empty_param_list = 58,      /* non_empty_param_list  */
  YYSYMBOL_type = 59,                      /* type  */
  YYSYMBOL_body_with_return = 60,          /* body_with_return  */
  YYSYMBOL_body = 61,                      /* body  */
  YYSYMBOL_declarations = 62,              /* declarations  */
  YYSYMBOL_statements = 63,                /* statements  */
  YYSYMBOL_statement = 64,                 /* statement  */
  YYSYMBOL_assign_sttmnt = 65,             /* assign_sttmnt  */
  YYSYMBOL_lhs = 66,                       /* lhs  */
  YYSYMBOL_rhs = 67,                       /* rhs  */
  YYSYMBOL_expression = 68,                /* expression  */
  YYSYMBOL_decl_sttmnt = 69,               /* decl_sttmnt  */
  YYSYMBOL_var_decl_list = 70,             /* var_decl_list  */
  YYSYMBOL_call_sttmnt = 71,               /* call_sttmnt  */
  YYSYMBOL_arguments = 72,                 /* arguments  */
  YYSYMBOL_non_empty_arguments_list = 73,  /* non_empty_arguments_list  */
  YYSYMBOL_if_sttmnt = 74,                 /* if_sttmnt  */
  YYSYMBOL_if_else_sttmnt = 75,            /* if_else_sttmnt  */
  YYSYMBOL_for_sttmnt = 76,                /* for_sttmnt  */
  YYSYMBOL_while_sttmnt = 77,              /* while_sttmnt  */
  YYSYMBOL_block_sttmnt = 78,              /* block_sttmnt  */
  YYSYMBOL_return_sttmnt = 79              /* return_sttmnt  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   339

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  166

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   287


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,     2,     2,     2,    41,     2,
      42,    43,    37,    35,    46,    36,     2,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    47,    48,
      34,    49,    33,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    50,     2,    51,    40,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    56,    56,    65,    70,    75,    78,    84,    94,   106,
     107,   111,   123,   134,   146,   147,   148,   149,   150,   152,
     153,   154,   157,   162,   167,   172,   173,   174,   178,   183,
     187,   193,   198,   199,   200,   201,   202,   203,   204,   205,
     209,   217,   220,   225,   232,   235,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   270,   276,   288,   301,   312,   313,   316,   322,   330,
     338,   349,   374,   381,   385,   391
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "BOOL", "CHAR", "INT",
  "REAL", "STRING", "INTPTR", "CHARPTR", "REALPTR", "IF", "ELSE", "WHILE",
  "FOR", "VAR", "FUNC", "PROC", "RETURN", "NULL_TOK", "TRUE_LITERAL",
  "FALSE_LITERAL", "INT_LITERAL", "REAL_LITERAL", "STRING_LITERAL",
  "CHAR_LITERAL", "IDENTIFIER", "EQ", "NEQ", "GTE", "LTE", "AND", "OR",
  "'>'", "'<'", "'+'", "'-'", "'*'", "'/'", "'!'", "'^'", "'&'", "'('",
  "')'", "'{'", "'}'", "','", "':'", "';'", "'='", "'['", "']'", "$accept",
  "program", "functions", "function", "proc", "parameter_list",
  "non_empty_param_list", "type", "body_with_return", "body",
  "declarations", "statements", "statement", "assign_sttmnt", "lhs", "rhs",
  "expression", "decl_sttmnt", "var_decl_list", "call_sttmnt", "arguments",
  "non_empty_arguments_list", "if_sttmnt", "if_else_sttmnt", "for_sttmnt",
  "while_sttmnt", "block_sttmnt", "return_sttmnt", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-122)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-24)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -10,   -21,   -15,    17,  -122,   -10,   -10,   -18,     9,  -122,
    -122,  -122,    29,    29,    -3,    18,  -122,    32,    29,   160,
      39,    55,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,
    -122,    50,   160,     5,    29,    57,    62,    63,    66,    83,
     136,    67,    90,     5,    99,     5,    14,  -122,  -122,    96,
    -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,     5,
     136,   136,   -11,     1,    98,  -122,  -122,  -122,  -122,  -122,
    -122,    97,   136,   136,   136,   123,   136,   152,   136,  -122,
     105,  -122,    14,  -122,  -122,    71,   115,   153,   128,   216,
     233,   125,    83,   160,  -122,   136,  -122,  -122,  -122,  -122,
     250,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,  -122,    51,  -122,  -122,   -38,   143,   267,
    -122,  -122,    14,    14,   112,  -122,  -122,    92,  -122,   301,
     301,   104,   104,   291,   279,   104,   104,    15,    15,  -122,
    -122,  -122,   136,  -122,  -122,   180,  -122,   145,  -122,   196,
     151,  -122,    14,   136,   136,   147,  -122,   174,  -122,  -122,
     -11,   148,   112,   155,    14,  -122
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     2,     5,     6,     0,     0,     1,
       3,     4,    10,    10,     0,     0,     9,     0,     0,     0,
       0,     0,    11,    15,    17,    14,    16,    18,    19,    20,
      21,    13,     0,    27,     0,     0,     0,     0,     0,     0,
       0,    41,     0,    27,     0,    25,    26,    31,    32,     0,
      29,    33,    34,    35,    37,    38,    36,    39,    12,     0,
       0,     0,     0,     0,     0,    70,    68,    69,    65,    66,
      67,    64,     0,     0,     0,     0,     0,     0,     0,    43,
       0,     8,    24,    28,    30,     0,     0,     0,    39,     0,
       0,     0,     0,     0,    71,     0,    59,    58,    60,    61,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    85,     0,    83,    45,    64,     0,    44,
       7,    22,     0,     0,     0,    72,    73,     0,    62,    48,
      49,    52,    53,    47,    46,    50,    51,    54,    55,    56,
      57,    42,    76,    40,    84,    36,    36,     0,    63,    78,
       0,    75,     0,     0,     0,     0,    36,     0,    77,    74,
       0,     0,     0,     0,     0,    36
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -122,  -122,    54,  -122,  -122,   183,    -8,   -19,  -122,   -13,
    -122,   154,   -46,  -122,   -60,  -121,   -39,   168,   122,  -122,
    -122,    61,  -122,  -122,  -122,  -122,  -114,   -45
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,     5,     6,    15,    16,    31,    86,    44,
      45,    46,    47,    48,    49,   118,   119,    50,    64,    51,
     150,   151,    52,    53,    54,    55,    56,    57
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      84,    77,    91,   147,   142,     7,     1,     2,   145,   146,
      22,     8,    95,    35,    88,    41,    36,     9,    37,    38,
      39,    89,    90,    40,    12,    36,    58,    37,    38,    42,
      80,    41,    40,    96,    97,    98,    84,   100,   156,   114,
      41,   163,   121,    18,    19,    42,    87,    92,    93,    43,
     165,    13,   111,   112,    42,    14,   127,    32,    43,    10,
      11,    20,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   126,    21,   144,   144,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
      65,    66,    67,    68,    69,   116,    70,   117,    34,    33,
     161,    59,   141,   149,    60,    61,   144,    72,    62,    63,
      73,    74,    75,    76,   157,   149,    79,    78,   144,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,    65,    66,    67,    68,    69,   116,    70,    71,   109,
     110,   111,   112,   148,    81,    85,    94,    95,    72,    99,
     115,    73,    74,    75,    76,    65,    66,    67,    68,    69,
     120,    70,    71,    23,    24,    25,    26,    27,    28,    29,
      30,    40,    72,   -23,   124,    73,    74,    75,    76,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   143,   152,   153,   155,   159,    17,   162,   164,    82,
     113,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,    83,   125,   158,     0,     0,     0,     0,
       0,     0,   160,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,     0,     0,     0,     0,     0,
       0,     0,   154,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,     0,     0,     0,     0,   122,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,     0,     0,     0,     0,   123,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,     0,
       0,     0,     0,   128,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   101,   102,   103,   104,
     105,     0,   107,   108,   109,   110,   111,   112,   101,   102,
     103,   104,     0,     0,   107,   108,   109,   110,   111,   112,
     103,   104,     0,     0,   107,   108,   109,   110,   111,   112
};

static const yytype_int16 yycheck[] =
{
      46,    40,    62,   124,    42,    26,    16,    17,   122,   123,
      18,    26,    50,    32,    59,    26,    11,     0,    13,    14,
      15,    60,    61,    18,    42,    11,    34,    13,    14,    40,
      43,    26,    18,    72,    73,    74,    82,    76,   152,    78,
      26,   162,    87,    46,    47,    40,    59,    46,    47,    44,
     164,    42,    37,    38,    40,    26,    95,    18,    44,     5,
       6,    43,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,    93,    43,   122,   123,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      19,    20,    21,    22,    23,    24,    25,    26,    48,    44,
     160,    44,    51,   142,    42,    42,   152,    36,    42,    26,
      39,    40,    41,    42,   153,   154,    26,    50,   164,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    19,    20,    21,    22,    23,    24,    25,    26,    35,
      36,    37,    38,    51,    45,    49,    48,    50,    36,    26,
      45,    39,    40,    41,    42,    19,    20,    21,    22,    23,
      45,    25,    26,     3,     4,     5,     6,     7,     8,     9,
      10,    18,    36,    45,    49,    39,    40,    41,    42,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    48,    12,    48,    43,    48,    13,    49,    43,    45,
      48,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    45,    92,   154,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    43,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    43,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    43,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    27,    28,    29,    30,
      31,    -1,    33,    34,    35,    36,    37,    38,    27,    28,
      29,    30,    -1,    -1,    33,    34,    35,    36,    37,    38,
      29,    30,    -1,    -1,    33,    34,    35,    36,    37,    38
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    16,    17,    53,    54,    55,    56,    26,    26,     0,
      54,    54,    42,    42,    26,    57,    58,    57,    46,    47,
      43,    43,    58,     3,     4,     5,     6,     7,     8,     9,
      10,    59,    18,    44,    48,    59,    11,    13,    14,    15,
      18,    26,    40,    44,    61,    62,    63,    64,    65,    66,
      69,    71,    74,    75,    76,    77,    78,    79,    58,    44,
      42,    42,    42,    26,    70,    19,    20,    21,    22,    23,
      25,    26,    36,    39,    40,    41,    42,    68,    50,    26,
      61,    45,    63,    69,    64,    49,    60,    61,    79,    68,
      68,    66,    46,    47,    48,    50,    68,    68,    68,    26,
      68,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    48,    68,    45,    24,    26,    67,    68,
      45,    79,    43,    43,    49,    70,    59,    68,    43,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    51,    42,    48,    64,    78,    78,    67,    51,    68,
      72,    73,    12,    48,    46,    43,    78,    68,    73,    48,
      48,    66,    49,    67,    43,    78
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    52,    53,    54,    54,    54,    54,    55,    56,    57,
      57,    58,    58,    58,    59,    59,    59,    59,    59,    59,
      59,    59,    60,    60,    61,    61,    61,    61,    62,    62,
      63,    63,    64,    64,    64,    64,    64,    64,    64,    64,
      65,    66,    66,    66,    67,    67,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    69,    70,    70,    71,    72,    72,    73,    73,    74,
      75,    76,    77,    78,    78,    79
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     1,    10,     8,     1,
       0,     3,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     2,     1,     1,     0,     2,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     1,     4,     2,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     2,     3,     4,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     7,     1,     0,     3,     1,     5,
       7,    13,     5,     3,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* program: functions  */
#line 56 "parser.y"
              {
        (yyval.node_val) = createNode("PROGRAM", NULL);
        addLeftChild((yyval.node_val), (yyvsp[0].node_val));
        root = (yyval.node_val);                       
        printf("Parsed program successfully!\n");
    }
#line 1416 "y.tab.c"
    break;

  case 3: /* functions: function functions  */
#line 65 "parser.y"
                       {
        (yyval.node_val) = createNode("FUNCTION_LIST", NULL); 
        addLeftChild((yyval.node_val), (yyvsp[-1].node_val));
        addRightChild((yyval.node_val), (yyvsp[0].node_val));
    }
#line 1426 "y.tab.c"
    break;

  case 4: /* functions: proc functions  */
#line 70 "parser.y"
                       {
        (yyval.node_val) = createNode("PROC_LIST",NULL);
        addLeftChild((yyval.node_val), (yyvsp[-1].node_val));
        addRightChild((yyval.node_val), (yyvsp[0].node_val));
   }
#line 1436 "y.tab.c"
    break;

  case 5: /* functions: function  */
#line 75 "parser.y"
                       {
        (yyval.node_val) = (yyvsp[0].node_val);
   }
#line 1444 "y.tab.c"
    break;

  case 6: /* functions: proc  */
#line 78 "parser.y"
                       {
        (yyval.node_val) = (yyvsp[0].node_val);
   }
#line 1452 "y.tab.c"
    break;

  case 7: /* function: FUNC IDENTIFIER '(' parameter_list ')' RETURN type '{' body_with_return '}'  */
#line 84 "parser.y"
                                                                                {
        (yyval.node_val) = createNode("FUNCTION", NULL);
        Node* idNode = createNode("IDENTIFIER", (yyvsp[-8].str_val));
        addLeftChild(idNode, (yyvsp[-6].node_val));
        addRightChild(idNode, (yyvsp[-3].node_val));
        addLeftChild((yyval.node_val), idNode);
        addRightChild((yyval.node_val), (yyvsp[-1].node_val)); 
    }
#line 1465 "y.tab.c"
    break;

  case 8: /* proc: PROC IDENTIFIER '(' parameter_list ')' '{' body '}'  */
#line 94 "parser.y"
                                                        {
        (yyval.node_val) = createNode("PROC",NULL);
        Node* idNode = createNode("IDENTIFIER",(yyvsp[-6].str_val));

        addLeftChild(idNode,(yyvsp[-4].node_val));

        addLeftChild((yyval.node_val),idNode);
        addRightChild((yyval.node_val),(yyvsp[-1].node_val));
     }
#line 1479 "y.tab.c"
    break;

  case 9: /* parameter_list: non_empty_param_list  */
#line 106 "parser.y"
                         { (yyval.node_val) = (yyvsp[0].node_val); }
#line 1485 "y.tab.c"
    break;

  case 10: /* parameter_list: %empty  */
#line 107 "parser.y"
      { (yyval.node_val) = NULL; }
#line 1491 "y.tab.c"
    break;

  case 11: /* non_empty_param_list: IDENTIFIER ',' non_empty_param_list  */
#line 111 "parser.y"
                                        {
        Node* type = (yyvsp[0].node_val)->left->right;
        Node* param = createNode("PARAM", NULL);

        addLeftChild(param, createNode("IDENTIFIER", (yyvsp[-2].str_val)));
        addRightChild(param, type);

        (yyval.node_val) = createNode("PARAM_LIST", NULL);
        addLeftChild((yyval.node_val), param);
        addRightChild((yyval.node_val), (yyvsp[0].node_val));
    }
#line 1507 "y.tab.c"
    break;

  case 12: /* non_empty_param_list: IDENTIFIER ':' type ';' non_empty_param_list  */
#line 123 "parser.y"
                                                 {
        Node* param = createNode("PARAM", NULL);
        
        addLeftChild(param, createNode("IDENTIFIER", (yyvsp[-4].str_val)));
        addRightChild(param, (yyvsp[-2].node_val));

        (yyval.node_val) = createNode("PARAM_LIST", NULL);
        addLeftChild((yyval.node_val), param);
        addRightChild((yyval.node_val), (yyvsp[0].node_val));
    }
#line 1522 "y.tab.c"
    break;

  case 13: /* non_empty_param_list: IDENTIFIER ':' type  */
#line 134 "parser.y"
                        {
        Node* param = createNode("PARAM", NULL);
        
        addLeftChild(param, createNode("IDENTIFIER", (yyvsp[-2].str_val)));
        addRightChild(param, (yyvsp[0].node_val));

        (yyval.node_val) = createNode("PARAM_LIST", NULL);
        addLeftChild((yyval.node_val), param);
        addRightChild((yyval.node_val), NULL);
    }
#line 1537 "y.tab.c"
    break;

  case 14: /* type: INT  */
#line 146 "parser.y"
              { (yyval.node_val) = createNode("TYPE", "int"); }
#line 1543 "y.tab.c"
    break;

  case 15: /* type: BOOL  */
#line 147 "parser.y"
              { (yyval.node_val) = createNode("TYPE", "bool"); }
#line 1549 "y.tab.c"
    break;

  case 16: /* type: REAL  */
#line 148 "parser.y"
              { (yyval.node_val) = createNode("TYPE", "real"); }
#line 1555 "y.tab.c"
    break;

  case 17: /* type: CHAR  */
#line 149 "parser.y"
              { (yyval.node_val) = createNode("TYPE", "char"); }
#line 1561 "y.tab.c"
    break;

  case 18: /* type: STRING  */
#line 150 "parser.y"
              { (yyval.node_val) = createNode("TYPE", "string"); }
#line 1567 "y.tab.c"
    break;

  case 19: /* type: INTPTR  */
#line 152 "parser.y"
              { (yyval.node_val) = createNode("TYPE", "int*"); }
#line 1573 "y.tab.c"
    break;

  case 20: /* type: CHARPTR  */
#line 153 "parser.y"
              { (yyval.node_val) = createNode("TYPE", "char*"); }
#line 1579 "y.tab.c"
    break;

  case 21: /* type: REALPTR  */
#line 154 "parser.y"
              { (yyval.node_val) = createNode("TYPE", "real*"); }
#line 1585 "y.tab.c"
    break;

  case 22: /* body_with_return: body return_sttmnt  */
#line 157 "parser.y"
                       {
        (yyval.node_val) = createNode("BODY", NULL);
        addLeftChild((yyval.node_val), (yyvsp[-1].node_val)); 
        addRightChild((yyval.node_val), (yyvsp[0].node_val)); 
    }
#line 1595 "y.tab.c"
    break;

  case 23: /* body_with_return: return_sttmnt  */
#line 162 "parser.y"
                    {
        (yyval.node_val) = (yyvsp[0].node_val);
    }
#line 1603 "y.tab.c"
    break;

  case 24: /* body: declarations statements  */
#line 167 "parser.y"
                            {
        (yyval.node_val) = createNode("BODY", NULL);
        addLeftChild((yyval.node_val), (yyvsp[-1].node_val));
        addRightChild((yyval.node_val), (yyvsp[0].node_val));
    }
#line 1613 "y.tab.c"
    break;

  case 25: /* body: declarations  */
#line 172 "parser.y"
                   { (yyval.node_val) = (yyvsp[0].node_val); }
#line 1619 "y.tab.c"
    break;

  case 26: /* body: statements  */
#line 173 "parser.y"
                   { (yyval.node_val) = (yyvsp[0].node_val); }
#line 1625 "y.tab.c"
    break;

  case 27: /* body: %empty  */
#line 174 "parser.y"
      {(yyval.node_val) = NULL;}
#line 1631 "y.tab.c"
    break;

  case 28: /* declarations: declarations decl_sttmnt  */
#line 178 "parser.y"
                             {
        (yyval.node_val) = createNode("DECLARATIONS", NULL);
        addLeftChild((yyval.node_val), (yyvsp[-1].node_val));
        addRightChild((yyval.node_val), (yyvsp[0].node_val));
    }
#line 1641 "y.tab.c"
    break;

  case 29: /* declarations: decl_sttmnt  */
#line 183 "parser.y"
                  { (yyval.node_val) = (yyvsp[0].node_val); }
#line 1647 "y.tab.c"
    break;

  case 30: /* statements: statements statement  */
#line 187 "parser.y"
                         {
        (yyval.node_val) = createNode("STATEMENTS",NULL);
        addLeftChild((yyval.node_val),(yyvsp[-1].node_val));
        addRightChild((yyval.node_val),(yyvsp[0].node_val));
    }
#line 1657 "y.tab.c"
    break;

  case 31: /* statements: statement  */
#line 193 "parser.y"
              {
        (yyval.node_val) = (yyvsp[0].node_val);
    }
#line 1665 "y.tab.c"
    break;

  case 32: /* statement: assign_sttmnt  */
#line 198 "parser.y"
                  {(yyval.node_val) = (yyvsp[0].node_val);}
#line 1671 "y.tab.c"
    break;

  case 33: /* statement: call_sttmnt  */
#line 199 "parser.y"
                  {(yyval.node_val) = (yyvsp[0].node_val);}
#line 1677 "y.tab.c"
    break;

  case 34: /* statement: if_sttmnt  */
#line 200 "parser.y"
                {(yyval.node_val) = (yyvsp[0].node_val);}
#line 1683 "y.tab.c"
    break;

  case 35: /* statement: if_else_sttmnt  */
#line 201 "parser.y"
                     {(yyval.node_val) = (yyvsp[0].node_val);}
#line 1689 "y.tab.c"
    break;

  case 36: /* statement: block_sttmnt  */
#line 202 "parser.y"
                   {(yyval.node_val) = (yyvsp[0].node_val);}
#line 1695 "y.tab.c"
    break;

  case 37: /* statement: for_sttmnt  */
#line 203 "parser.y"
                 {(yyval.node_val) = (yyvsp[0].node_val);}
#line 1701 "y.tab.c"
    break;

  case 38: /* statement: while_sttmnt  */
#line 204 "parser.y"
                   {(yyval.node_val) = (yyvsp[0].node_val);}
#line 1707 "y.tab.c"
    break;

  case 39: /* statement: return_sttmnt  */
#line 205 "parser.y"
                    {(yyval.node_val) = (yyvsp[0].node_val);}
#line 1713 "y.tab.c"
    break;

  case 40: /* assign_sttmnt: lhs '=' rhs ';'  */
#line 209 "parser.y"
                   {
        (yyval.node_val) = createNode("ASSIGN_STTMNT",NULL);
        addLeftChild((yyval.node_val),(yyvsp[-3].node_val));
        addRightChild((yyval.node_val),(yyvsp[-1].node_val));
    }
#line 1723 "y.tab.c"
    break;

  case 41: /* lhs: IDENTIFIER  */
#line 217 "parser.y"
                {
        (yyval.node_val) = createNode("IDENTIFIER", (yyvsp[0].str_val));
        }
#line 1731 "y.tab.c"
    break;

  case 42: /* lhs: IDENTIFIER '[' expression ']'  */
#line 220 "parser.y"
                                    {
        (yyval.node_val) = createNode("ARRAY_ACCESS",NULL);
        addLeftChild((yyval.node_val),createNode("IDENTIFIER",(yyvsp[-3].str_val)));
        addRightChild((yyval.node_val),(yyvsp[-1].node_val));
        }
#line 1741 "y.tab.c"
    break;

  case 43: /* lhs: '^' IDENTIFIER  */
#line 225 "parser.y"
                     {
        (yyval.node_val) = createNode("DEREF",NULL);
        addLeftChild((yyval.node_val), createNode("IDENTIFIER", (yyvsp[0].str_val)));
        addRightChild((yyval.node_val),NULL);
    }
#line 1751 "y.tab.c"
    break;

  case 44: /* rhs: expression  */
#line 232 "parser.y"
               {
        (yyval.node_val) = (yyvsp[0].node_val);
    }
#line 1759 "y.tab.c"
    break;

  case 45: /* rhs: STRING_LITERAL  */
#line 235 "parser.y"
                     {
        (yyval.node_val) = createNode("STRING_LITERAL", (yyvsp[0].str_val));
    }
#line 1767 "y.tab.c"
    break;

  case 46: /* expression: expression OR expression  */
#line 241 "parser.y"
                             { (yyval.node_val) = createNode("OR",  NULL); addLeftChild((yyval.node_val),(yyvsp[-2].node_val)); addRightChild((yyval.node_val),(yyvsp[0].node_val)); }
#line 1773 "y.tab.c"
    break;

  case 47: /* expression: expression AND expression  */
#line 242 "parser.y"
                                { (yyval.node_val) = createNode("AND", NULL); addLeftChild((yyval.node_val),(yyvsp[-2].node_val)); addRightChild((yyval.node_val),(yyvsp[0].node_val)); }
#line 1779 "y.tab.c"
    break;

  case 48: /* expression: expression EQ expression  */
#line 243 "parser.y"
                                { (yyval.node_val) = createNode("EQ",  NULL); addLeftChild((yyval.node_val),(yyvsp[-2].node_val)); addRightChild((yyval.node_val),(yyvsp[0].node_val)); }
#line 1785 "y.tab.c"
    break;

  case 49: /* expression: expression NEQ expression  */
#line 244 "parser.y"
                                { (yyval.node_val) = createNode("NEQ", NULL); addLeftChild((yyval.node_val),(yyvsp[-2].node_val)); addRightChild((yyval.node_val),(yyvsp[0].node_val)); }
#line 1791 "y.tab.c"
    break;

  case 50: /* expression: expression '>' expression  */
#line 245 "parser.y"
                                { (yyval.node_val) = createNode("GT",  NULL); addLeftChild((yyval.node_val),(yyvsp[-2].node_val)); addRightChild((yyval.node_val),(yyvsp[0].node_val)); }
#line 1797 "y.tab.c"
    break;

  case 51: /* expression: expression '<' expression  */
#line 246 "parser.y"
                                { (yyval.node_val) = createNode("LT",  NULL); addLeftChild((yyval.node_val),(yyvsp[-2].node_val)); addRightChild((yyval.node_val),(yyvsp[0].node_val)); }
#line 1803 "y.tab.c"
    break;

  case 52: /* expression: expression GTE expression  */
#line 247 "parser.y"
                                { (yyval.node_val) = createNode("GTE", NULL); addLeftChild((yyval.node_val),(yyvsp[-2].node_val)); addRightChild((yyval.node_val),(yyvsp[0].node_val)); }
#line 1809 "y.tab.c"
    break;

  case 53: /* expression: expression LTE expression  */
#line 248 "parser.y"
                                { (yyval.node_val) = createNode("LTE", NULL); addLeftChild((yyval.node_val),(yyvsp[-2].node_val)); addRightChild((yyval.node_val),(yyvsp[0].node_val)); }
#line 1815 "y.tab.c"
    break;

  case 54: /* expression: expression '+' expression  */
#line 249 "parser.y"
                                { (yyval.node_val) = createNode("ADD", NULL); addLeftChild((yyval.node_val),(yyvsp[-2].node_val)); addRightChild((yyval.node_val),(yyvsp[0].node_val)); }
#line 1821 "y.tab.c"
    break;

  case 55: /* expression: expression '-' expression  */
#line 250 "parser.y"
                                { (yyval.node_val) = createNode("SUB", NULL); addLeftChild((yyval.node_val),(yyvsp[-2].node_val)); addRightChild((yyval.node_val),(yyvsp[0].node_val)); }
#line 1827 "y.tab.c"
    break;

  case 56: /* expression: expression '*' expression  */
#line 251 "parser.y"
                                { (yyval.node_val) = createNode("MUL", NULL); addLeftChild((yyval.node_val),(yyvsp[-2].node_val)); addRightChild((yyval.node_val),(yyvsp[0].node_val)); }
#line 1833 "y.tab.c"
    break;

  case 57: /* expression: expression '/' expression  */
#line 252 "parser.y"
                                { (yyval.node_val) = createNode("DIV", NULL); addLeftChild((yyval.node_val),(yyvsp[-2].node_val)); addRightChild((yyval.node_val),(yyvsp[0].node_val)); }
#line 1839 "y.tab.c"
    break;

  case 58: /* expression: '!' expression  */
#line 253 "parser.y"
                     { (yyval.node_val) = createNode("NOT",  NULL); addLeftChild((yyval.node_val),(yyvsp[0].node_val)); addRightChild((yyval.node_val),NULL); }
#line 1845 "y.tab.c"
    break;

  case 59: /* expression: '-' expression  */
#line 254 "parser.y"
                              { (yyval.node_val) = createNode("NEG",  NULL); addLeftChild((yyval.node_val),(yyvsp[0].node_val)); addRightChild((yyval.node_val),NULL); }
#line 1851 "y.tab.c"
    break;

  case 60: /* expression: '^' expression  */
#line 255 "parser.y"
                     { (yyval.node_val) = createNode("DEREF",NULL); addLeftChild((yyval.node_val),(yyvsp[0].node_val)); addRightChild((yyval.node_val),NULL); }
#line 1857 "y.tab.c"
    break;

  case 61: /* expression: '&' IDENTIFIER  */
#line 256 "parser.y"
                     { (yyval.node_val) = createNode("ADDR_OF",NULL); addLeftChild((yyval.node_val),createNode("IDENTIFIER",(yyvsp[0].str_val))); addRightChild((yyval.node_val),NULL); }
#line 1863 "y.tab.c"
    break;

  case 62: /* expression: '(' expression ')'  */
#line 257 "parser.y"
                         { (yyval.node_val) = (yyvsp[-1].node_val); }
#line 1869 "y.tab.c"
    break;

  case 63: /* expression: IDENTIFIER '[' expression ']'  */
#line 258 "parser.y"
                                   { (yyval.node_val) = createNode("ARRAY_ACCESS",NULL); addLeftChild((yyval.node_val),createNode("IDENTIFIER",(yyvsp[-3].str_val))); addRightChild((yyval.node_val),(yyvsp[-1].node_val)); }
#line 1875 "y.tab.c"
    break;

  case 64: /* expression: IDENTIFIER  */
#line 259 "parser.y"
                 { (yyval.node_val) = createNode("IDENTIFIER",(yyvsp[0].str_val)); }
#line 1881 "y.tab.c"
    break;

  case 65: /* expression: INT_LITERAL  */
#line 260 "parser.y"
                  { char buf[32]; sprintf(buf,"%d",(yyvsp[0].int_val));  (yyval.node_val) = createNode("INT_LITERAL",  buf); }
#line 1887 "y.tab.c"
    break;

  case 66: /* expression: REAL_LITERAL  */
#line 261 "parser.y"
                   { char buf[64]; sprintf(buf,"%g",(yyvsp[0].real_val));  (yyval.node_val) = createNode("REAL_LITERAL", buf); }
#line 1893 "y.tab.c"
    break;

  case 67: /* expression: CHAR_LITERAL  */
#line 262 "parser.y"
                   { char buf[4];  buf[0]=(yyvsp[0].char_val); buf[1]='\0'; (yyval.node_val) = createNode("CHAR_LITERAL",buf); }
#line 1899 "y.tab.c"
    break;

  case 68: /* expression: TRUE_LITERAL  */
#line 263 "parser.y"
                   { (yyval.node_val) = createNode("BOOL_LITERAL","true"); }
#line 1905 "y.tab.c"
    break;

  case 69: /* expression: FALSE_LITERAL  */
#line 264 "parser.y"
                    { (yyval.node_val) = createNode("BOOL_LITERAL","false"); }
#line 1911 "y.tab.c"
    break;

  case 70: /* expression: NULL_TOK  */
#line 265 "parser.y"
               { (yyval.node_val) = createNode("NULL",NULL); }
#line 1917 "y.tab.c"
    break;

  case 71: /* decl_sttmnt: VAR var_decl_list ';'  */
#line 270 "parser.y"
                          { 
        (yyval.node_val) = (yyvsp[-1].node_val); 
    }
#line 1925 "y.tab.c"
    break;

  case 72: /* var_decl_list: IDENTIFIER ',' var_decl_list  */
#line 276 "parser.y"
                                 {
        Node* type = (yyvsp[0].node_val)->left->right;
        Node* id = createNode("VAR_DECL", NULL);

        addLeftChild(id, createNode("IDENTIFIER", (yyvsp[-2].str_val)));
        addRightChild(id, type);

        (yyval.node_val) = createNode("VAR_LIST", NULL);
        addLeftChild((yyval.node_val), id);
        addRightChild((yyval.node_val), (yyvsp[0].node_val));
    }
#line 1941 "y.tab.c"
    break;

  case 73: /* var_decl_list: IDENTIFIER ':' type  */
#line 288 "parser.y"
                        {
        Node* id = createNode("VAR_DECL", NULL);
        
        addLeftChild(id, createNode("IDENTIFIER", (yyvsp[-2].str_val)));
        addRightChild(id, (yyvsp[0].node_val));

        (yyval.node_val) = createNode("VAR_LIST", NULL);
        addLeftChild((yyval.node_val), id);
        addRightChild((yyval.node_val), NULL);
    }
#line 1956 "y.tab.c"
    break;

  case 74: /* call_sttmnt: lhs '=' IDENTIFIER '(' arguments ')' ';'  */
#line 301 "parser.y"
                                            {
        Node* rhss = createNode("RHS_CALL",NULL);
        addLeftChild(rhss,createNode("IDENTIFIER",(yyvsp[-4].str_val)));
        addRightChild(rhss,(yyvsp[-2].node_val));

        (yyval.node_val) = createNode("CALL_STTMNT",NULL);
        addLeftChild((yyval.node_val),(yyvsp[-6].node_val));
        addRightChild((yyval.node_val),rhss);
    }
#line 1970 "y.tab.c"
    break;

  case 75: /* arguments: non_empty_arguments_list  */
#line 312 "parser.y"
                             { (yyval.node_val) = (yyvsp[0].node_val);}
#line 1976 "y.tab.c"
    break;

  case 76: /* arguments: %empty  */
#line 313 "parser.y"
      {(yyval.node_val) = NULL;}
#line 1982 "y.tab.c"
    break;

  case 77: /* non_empty_arguments_list: expression ',' non_empty_arguments_list  */
#line 316 "parser.y"
                                            {
        (yyval.node_val) = createNode("ARGUMENTS_LIST",NULL);
        addLeftChild((yyval.node_val),(yyvsp[-2].node_val));
        addRightChild((yyval.node_val),(yyvsp[0].node_val));
        }
#line 1992 "y.tab.c"
    break;

  case 78: /* non_empty_arguments_list: expression  */
#line 322 "parser.y"
               {
        (yyval.node_val) = createNode("ARGUMENTS_LIST",NULL);
        addLeftChild((yyval.node_val),(yyvsp[0].node_val));
        addRightChild((yyval.node_val),NULL);
    }
#line 2002 "y.tab.c"
    break;

  case 79: /* if_sttmnt: IF '(' expression ')' block_sttmnt  */
#line 330 "parser.y"
                                       {
        (yyval.node_val) = createNode("IF_STTMNT",NULL);
        addLeftChild((yyval.node_val),(yyvsp[-2].node_val));
        addRightChild((yyval.node_val),(yyvsp[0].node_val));
    }
#line 2012 "y.tab.c"
    break;

  case 80: /* if_else_sttmnt: IF '(' expression ')' block_sttmnt ELSE block_sttmnt  */
#line 338 "parser.y"
                                                         {
        (yyval.node_val) = createNode("IF_ELSE_STTMNT",NULL);
        Node* branches = createNode("IF_BRANCHES",NULL);
        addLeftChild(branches,(yyvsp[-2].node_val));
        addRightChild(branches,(yyvsp[0].node_val));
        addLeftChild((yyval.node_val),(yyvsp[-4].node_val));
        addRightChild((yyval.node_val),branches);
    }
#line 2025 "y.tab.c"
    break;

  case 81: /* for_sttmnt: FOR '(' lhs '=' rhs ';' expression ';' lhs '=' rhs ')' block_sttmnt  */
#line 349 "parser.y"
                                                                        {
        (yyval.node_val) = createNode("FOR_STTMNT",NULL);

        Node* init = createNode("FOR_INIT",NULL);
        addLeftChild(init,(yyvsp[-10].node_val));
        addRightChild(init,(yyvsp[-8].node_val));

        Node* update = createNode("FOR_UPDATE",NULL);
        addLeftChild(update,(yyvsp[-4].node_val));
        addRightChild(update,(yyvsp[-2].node_val));

        Node* cond_update = createNode("FOR_COND_UPDATE",NULL);
        addLeftChild(cond_update,(yyvsp[-6].node_val));
        addRightChild(cond_update,update);

        Node* header = createNode("FOR_HEADER",NULL);
        addLeftChild(header,init);
        addRightChild(header,cond_update);

        addLeftChild((yyval.node_val),header);
        addRightChild((yyval.node_val),(yyvsp[0].node_val));
    }
#line 2052 "y.tab.c"
    break;

  case 82: /* while_sttmnt: WHILE '(' expression ')' block_sttmnt  */
#line 374 "parser.y"
                                          {
        (yyval.node_val) = createNode("WHILE_STTMNT",NULL);
        addLeftChild((yyval.node_val),(yyvsp[-2].node_val));
        addRightChild((yyval.node_val),(yyvsp[0].node_val));
    }
#line 2062 "y.tab.c"
    break;

  case 83: /* block_sttmnt: '{' body '}'  */
#line 381 "parser.y"
                 {
        (yyval.node_val) = (yyvsp[-1].node_val);
    }
#line 2070 "y.tab.c"
    break;

  case 84: /* block_sttmnt: statement  */
#line 385 "parser.y"
              {
        (yyval.node_val) = (yyvsp[0].node_val);
    }
#line 2078 "y.tab.c"
    break;

  case 85: /* return_sttmnt: RETURN expression ';'  */
#line 391 "parser.y"
                         {
        (yyval.node_val) = createNode("RETURN_STTMNT",NULL);
        addLeftChild((yyval.node_val),(yyvsp[-1].node_val));
        addRightChild((yyval.node_val),NULL);
    }
#line 2088 "y.tab.c"
    break;


#line 2092 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 400 "parser.y"
 

/* #include "lex.yy.c" */ 

int main() {
    printf("Starting Parser...\n");
    if (yyparse() == 0) {
        printf("Success!\n\n");
        printf("=== Abstract Syntax Tree ===\n");
        printTree(root);
        freeTree(root);
    } else {
        printf("Failed.\n");
    }
    return 0;
}

void yyerror(const char* s) {
    printf("Syntax Error on line %d: %s\n", yylineno, s);
}
