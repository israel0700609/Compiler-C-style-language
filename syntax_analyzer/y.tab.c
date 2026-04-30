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
#include "../ast/ast.h"

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
    OR = 287,                      /* OR  */
    IFX = 288                      /* IFX  */
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
#define IFX 288

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

#line 213 "y.tab.c"

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
  YYSYMBOL_IFX = 33,                       /* IFX  */
  YYSYMBOL_34_ = 34,                       /* '>'  */
  YYSYMBOL_35_ = 35,                       /* '<'  */
  YYSYMBOL_36_ = 36,                       /* '+'  */
  YYSYMBOL_37_ = 37,                       /* '-'  */
  YYSYMBOL_38_ = 38,                       /* '*'  */
  YYSYMBOL_39_ = 39,                       /* '/'  */
  YYSYMBOL_40_ = 40,                       /* '!'  */
  YYSYMBOL_41_ = 41,                       /* '^'  */
  YYSYMBOL_42_ = 42,                       /* '&'  */
  YYSYMBOL_43_ = 43,                       /* '('  */
  YYSYMBOL_44_ = 44,                       /* ')'  */
  YYSYMBOL_45_ = 45,                       /* '{'  */
  YYSYMBOL_46_ = 46,                       /* '}'  */
  YYSYMBOL_47_ = 47,                       /* ','  */
  YYSYMBOL_48_ = 48,                       /* ':'  */
  YYSYMBOL_49_ = 49,                       /* ';'  */
  YYSYMBOL_50_ = 50,                       /* '['  */
  YYSYMBOL_51_ = 51,                       /* ']'  */
  YYSYMBOL_52_ = 52,                       /* '='  */
  YYSYMBOL_53_ = 53,                       /* '|'  */
  YYSYMBOL_YYACCEPT = 54,                  /* $accept  */
  YYSYMBOL_program = 55,                   /* program  */
  YYSYMBOL_functions = 56,                 /* functions  */
  YYSYMBOL_function = 57,                  /* function  */
  YYSYMBOL_proc = 58,                      /* proc  */
  YYSYMBOL_parameter_list = 59,            /* parameter_list  */
  YYSYMBOL_non_empty_param_list = 60,      /* non_empty_param_list  */
  YYSYMBOL_type = 61,                      /* type  */
  YYSYMBOL_body = 62,                      /* body  */
  YYSYMBOL_declarations = 63,              /* declarations  */
  YYSYMBOL_statements = 64,                /* statements  */
  YYSYMBOL_statement = 65,                 /* statement  */
  YYSYMBOL_assign_sttmnt = 66,             /* assign_sttmnt  */
  YYSYMBOL_lhs = 67,                       /* lhs  */
  YYSYMBOL_rhs = 68,                       /* rhs  */
  YYSYMBOL_expression = 69,                /* expression  */
  YYSYMBOL_decl_sttmnt = 70,               /* decl_sttmnt  */
  YYSYMBOL_var_decl_list = 71,             /* var_decl_list  */
  YYSYMBOL_call_sttmnt = 72,               /* call_sttmnt  */
  YYSYMBOL_arguments = 73,                 /* arguments  */
  YYSYMBOL_non_empty_arguments_list = 74,  /* non_empty_arguments_list  */
  YYSYMBOL_if_sttmnt = 75,                 /* if_sttmnt  */
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
#define YYLAST   430

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  189

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   288


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
       2,     2,     2,    40,     2,     2,     2,     2,    42,     2,
      43,    44,    38,    36,    47,    37,     2,    39,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    48,    49,
      35,    52,    34,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    50,     2,    51,    41,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,    53,    46,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    62,    62,    71,    76,    81,    86,    94,   104,   116,
     117,   121,   134,   145,   157,   158,   159,   160,   161,   163,
     164,   165,   169,   174,   175,   176,   180,   185,   189,   195,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   211,
     219,   220,   225,   230,   238,   245,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   270,   277,   282,   283,   290,   292,   294,   295,
     296,   301,   302,   303,   304,   305,   307,   309,   312,   318,
     330,   343,   350,   351,   354,   360,   368,   376,   395,   420,
     427,   433
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
  "IFX", "'>'", "'<'", "'+'", "'-'", "'*'", "'/'", "'!'", "'^'", "'&'",
  "'('", "')'", "'{'", "'}'", "','", "':'", "';'", "'['", "']'", "'='",
  "'|'", "$accept", "program", "functions", "function", "proc",
  "parameter_list", "non_empty_param_list", "type", "body", "declarations",
  "statements", "statement", "assign_sttmnt", "lhs", "rhs", "expression",
  "decl_sttmnt", "var_decl_list", "call_sttmnt", "arguments",
  "non_empty_arguments_list", "if_sttmnt", "for_sttmnt", "while_sttmnt",
  "block_sttmnt", "return_sttmnt", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-136)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       2,   -19,    13,    47,  -136,     2,     2,     0,     6,  -136,
    -136,  -136,    25,    25,   -20,     9,  -136,    18,    25,   420,
      52,    45,  -136,  -136,  -136,  -136,  -136,    51,  -136,  -136,
    -136,    54,   420,    43,    85,    25,    64,    81,    87,    88,
     107,   -11,     5,   -10,    43,  -136,  -136,    89,    43,    82,
    -136,  -136,    84,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
      83,  -136,    43,   -11,   -11,   -21,    38,    90,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,    44,   -11,   -11,   -11,    -9,
     112,   -11,   -11,   221,   -11,   -11,    91,   -11,    94,  -136,
      82,  -136,  -136,   -11,  -136,    97,   267,   285,   101,   121,
     107,   420,  -136,   -11,   -11,  -136,  -136,  -136,   114,   -11,
     122,   303,   118,   -11,   -11,   -11,   -11,   -11,   -11,   -11,
     -11,   -11,   -11,   -11,   -11,  -136,   253,   130,  -136,   131,
     -11,   321,  -136,   126,   357,  -136,    82,    82,   -11,  -136,
    -136,   145,   149,   -11,   339,   -11,  -136,  -136,    76,    76,
      28,    28,   383,   370,    28,    28,    79,    79,  -136,  -136,
     -11,   141,  -136,   167,  -136,  -136,   179,  -136,   143,  -136,
    -136,   185,  -136,   203,  -136,  -136,  -136,    82,   -11,  -136,
    -136,  -136,   237,   -21,   155,   -11,   164,    82,  -136
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     2,     5,     6,     0,     0,     1,
       3,     4,    10,    10,     0,     0,     9,     0,     0,     0,
       0,     0,    11,    15,    17,    14,    16,     0,    19,    20,
      21,    13,     0,    25,     0,     0,     0,     0,     0,     0,
       0,     0,    40,     0,    25,    37,    38,     0,    23,    24,
      29,    30,     0,    27,    31,    32,    34,    35,    33,    36,
       0,    12,    25,     0,     0,     0,     0,     0,    77,    74,
      75,    71,    72,    76,    73,    69,     0,     0,     0,     0,
       0,     0,     0,     0,    83,     0,    42,     0,     0,     8,
      22,    26,    28,     0,    18,     0,     0,     0,    40,     0,
       0,     0,    78,    83,     0,    60,    59,    58,    61,     0,
      64,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    85,     0,    82,     0,
       0,     0,    90,     0,    45,     7,     0,     0,     0,    79,
      80,     0,     0,     0,     0,     0,    66,    67,    48,    49,
      52,    53,    47,    46,    50,    51,    54,    55,    56,    57,
       0,     0,    41,     0,    44,    39,    86,    89,     0,    70,
      68,     0,    63,     0,    84,    81,    43,     0,     0,    62,
      65,    87,     0,     0,     0,     0,     0,     0,    88
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -136,  -136,   123,   116,   120,   180,     3,   -30,   -38,  -136,
     161,   -45,  -136,   -64,  -135,   -41,   162,   111,  -136,   124,
      65,  -136,  -136,  -136,  -136,  -136
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,    45,    46,    15,    16,    31,    47,    48,
      49,    50,    51,    52,   133,   126,    53,    67,    54,   127,
     128,    55,    56,    57,    58,    59
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      83,    99,    36,   168,    92,    98,    88,     7,    68,    69,
      70,    71,    72,    73,    74,    75,    86,   108,     1,     2,
      43,    22,    96,    97,    95,    76,    77,    18,    19,    78,
      79,    80,    81,    87,   109,   105,   106,   107,    61,     8,
     111,   112,    82,    12,   129,    92,   131,     9,    84,    13,
     186,    14,   134,    20,    37,    85,    38,    39,    40,     1,
       2,    41,    21,   142,   121,   122,   123,   124,   144,    42,
      32,   140,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,    43,   100,   101,   103,    44,   163,
      33,   166,   167,    37,   104,    38,    39,   134,     1,     2,
      41,    34,   171,    35,   173,   115,   116,    60,    42,    62,
     119,   120,   121,   122,   123,   124,     5,   123,   124,   184,
       6,     5,     5,    43,    63,     6,     6,    44,    10,    11,
      64,    65,   181,    66,    94,    89,    93,   182,   110,   102,
     132,   130,   188,   135,   134,   113,   114,   115,   116,   117,
     118,    85,   119,   120,   121,   122,   123,   124,   113,   114,
     115,   116,   117,   118,   143,   119,   120,   121,   122,   123,
     124,   147,   145,   138,   161,   165,   113,   114,   115,   116,
     117,   118,   162,   119,   120,   121,   122,   123,   124,   169,
     175,   177,   178,    17,   113,   114,   115,   116,   117,   118,
     170,   119,   120,   121,   122,   123,   124,   185,   187,    90,
      91,   139,   113,   114,   115,   116,   117,   118,   176,   119,
     120,   121,   122,   123,   124,   174,     0,   141,     0,     0,
     113,   114,   115,   116,   117,   118,   179,   119,   120,   121,
     122,   123,   124,     0,     0,     0,     0,     0,   113,   114,
     115,   116,   117,   118,   180,   119,   120,   121,   122,   123,
     124,     0,     0,     0,   113,   114,   115,   116,   117,   118,
     125,   119,   120,   121,   122,   123,   124,     0,     0,     0,
     113,   114,   115,   116,   117,   118,   183,   119,   120,   121,
     122,   123,   124,     0,   113,   114,   115,   116,   117,   118,
     160,   119,   120,   121,   122,   123,   124,     0,     0,     0,
       0,   136,   113,   114,   115,   116,   117,   118,     0,   119,
     120,   121,   122,   123,   124,     0,     0,     0,     0,   137,
     113,   114,   115,   116,   117,   118,     0,   119,   120,   121,
     122,   123,   124,     0,     0,     0,     0,   146,   113,   114,
     115,   116,   117,   118,     0,   119,   120,   121,   122,   123,
     124,     0,     0,     0,     0,   164,   113,   114,   115,   116,
     117,   118,     0,   119,   120,   121,   122,   123,   124,     0,
       0,     0,     0,   172,   113,   114,   115,   116,   117,   118,
       0,   119,   120,   121,   122,   123,   124,   113,   114,   115,
     116,   117,     0,     0,   119,   120,   121,   122,   123,   124,
     113,   114,   115,   116,     0,     0,     0,   119,   120,   121,
     122,   123,   124,    23,    24,    25,    26,    27,    28,    29,
      30
};

static const yytype_int16 yycheck[] =
{
      41,    65,    32,   138,    49,    26,    44,    26,    19,    20,
      21,    22,    23,    24,    25,    26,    26,    26,    16,    17,
      41,    18,    63,    64,    62,    36,    37,    47,    48,    40,
      41,    42,    43,    43,    43,    76,    77,    78,    35,    26,
      81,    82,    53,    43,    85,    90,    87,     0,    43,    43,
     185,    26,    93,    44,    11,    50,    13,    14,    15,    16,
      17,    18,    44,   104,    36,    37,    38,    39,   109,    26,
      18,   101,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    41,    47,    48,    43,    45,   130,
      45,   136,   137,    11,    50,    13,    14,   138,    16,    17,
      18,    50,   143,    49,   145,    29,    30,    22,    26,    45,
      34,    35,    36,    37,    38,    39,     0,    38,    39,   183,
       0,     5,     6,    41,    43,     5,     6,    45,     5,     6,
      43,    43,   177,    26,    51,    46,    52,   178,    26,    49,
      46,    50,   187,    46,   185,    27,    28,    29,    30,    31,
      32,    50,    34,    35,    36,    37,    38,    39,    27,    28,
      29,    30,    31,    32,    50,    34,    35,    36,    37,    38,
      39,    53,    50,    52,    44,    49,    27,    28,    29,    30,
      31,    32,    51,    34,    35,    36,    37,    38,    39,    44,
      49,    12,    49,    13,    27,    28,    29,    30,    31,    32,
      51,    34,    35,    36,    37,    38,    39,    52,    44,    48,
      48,   100,    27,    28,    29,    30,    31,    32,    51,    34,
      35,    36,    37,    38,    39,   160,    -1,   103,    -1,    -1,
      27,    28,    29,    30,    31,    32,    51,    34,    35,    36,
      37,    38,    39,    -1,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    51,    34,    35,    36,    37,    38,
      39,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      49,    34,    35,    36,    37,    38,    39,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    49,    34,    35,    36,
      37,    38,    39,    -1,    27,    28,    29,    30,    31,    32,
      47,    34,    35,    36,    37,    38,    39,    -1,    -1,    -1,
      -1,    44,    27,    28,    29,    30,    31,    32,    -1,    34,
      35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,    44,
      27,    28,    29,    30,    31,    32,    -1,    34,    35,    36,
      37,    38,    39,    -1,    -1,    -1,    -1,    44,    27,    28,
      29,    30,    31,    32,    -1,    34,    35,    36,    37,    38,
      39,    -1,    -1,    -1,    -1,    44,    27,    28,    29,    30,
      31,    32,    -1,    34,    35,    36,    37,    38,    39,    -1,
      -1,    -1,    -1,    44,    27,    28,    29,    30,    31,    32,
      -1,    34,    35,    36,    37,    38,    39,    27,    28,    29,
      30,    31,    -1,    -1,    34,    35,    36,    37,    38,    39,
      27,    28,    29,    30,    -1,    -1,    -1,    34,    35,    36,
      37,    38,    39,     3,     4,     5,     6,     7,     8,     9,
      10
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    16,    17,    55,    56,    57,    58,    26,    26,     0,
      56,    56,    43,    43,    26,    59,    60,    59,    47,    48,
      44,    44,    60,     3,     4,     5,     6,     7,     8,     9,
      10,    61,    18,    45,    50,    49,    61,    11,    13,    14,
      15,    18,    26,    41,    45,    57,    58,    62,    63,    64,
      65,    66,    67,    70,    72,    75,    76,    77,    78,    79,
      22,    60,    45,    43,    43,    43,    26,    71,    19,    20,
      21,    22,    23,    24,    25,    26,    36,    37,    40,    41,
      42,    43,    53,    69,    43,    50,    26,    43,    62,    46,
      64,    70,    65,    52,    51,    62,    69,    69,    26,    67,
      47,    48,    49,    43,    50,    69,    69,    69,    26,    43,
      26,    69,    69,    27,    28,    29,    30,    31,    32,    34,
      35,    36,    37,    38,    39,    49,    69,    73,    74,    69,
      50,    69,    46,    68,    69,    46,    44,    44,    52,    71,
      61,    73,    69,    50,    69,    50,    44,    53,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      47,    44,    51,    69,    44,    49,    65,    65,    68,    44,
      51,    69,    44,    69,    74,    49,    51,    12,    49,    51,
      51,    65,    69,    49,    67,    52,    68,    44,    65
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    56,    56,    56,    56,    57,    58,    59,
      59,    60,    60,    60,    61,    61,    61,    61,    61,    61,
      61,    61,    62,    62,    62,    62,    63,    63,    64,    64,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    66,
      67,    67,    67,    67,    67,    68,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    70,    71,
      71,    72,    73,    73,    74,    74,    75,    75,    76,    77,
      78,    79
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     1,    10,     8,     1,
       0,     3,     5,     3,     1,     1,     1,     1,     4,     1,
       1,     1,     2,     1,     1,     0,     2,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     4,     2,     5,     4,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     2,     5,     4,     2,     5,     3,     3,     4,     1,
       4,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     5,     1,     0,     3,     1,     5,     7,    13,     5,
       3,     3
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
#line 62 "parser.y"
              {
        (yyval.node_val) = createNode("PROGRAM", NULL);
        addLeftChild((yyval.node_val), (yyvsp[0].node_val));
        root = (yyval.node_val);                       
        printf("Parsed program successfully!\n");
    }
#line 1447 "y.tab.c"
    break;

  case 3: /* functions: function functions  */
#line 71 "parser.y"
                       {
        (yyval.node_val) = createNode("Top level", NULL);
        addLeftChild((yyval.node_val), (yyvsp[-1].node_val));
        addRightChild((yyval.node_val), (yyvsp[0].node_val));
    }
#line 1457 "y.tab.c"
    break;

  case 4: /* functions: proc functions  */
#line 76 "parser.y"
                       {
        (yyval.node_val) = createNode("Top level",NULL);
        addLeftChild((yyval.node_val), (yyvsp[-1].node_val));
        addRightChild((yyval.node_val), (yyvsp[0].node_val));
   }
#line 1467 "y.tab.c"
    break;

  case 5: /* functions: function  */
#line 81 "parser.y"
                       {
        (yyval.node_val) = createNode("Top level", NULL);
        addLeftChild((yyval.node_val), (yyvsp[0].node_val));
        addRightChild((yyval.node_val), NULL);
   }
#line 1477 "y.tab.c"
    break;

  case 6: /* functions: proc  */
#line 86 "parser.y"
                       {
        (yyval.node_val) = createNode("Top Level", NULL);
        addLeftChild((yyval.node_val), (yyvsp[0].node_val));
        addRightChild((yyval.node_val), NULL);
   }
#line 1487 "y.tab.c"
    break;

  case 7: /* function: FUNC IDENTIFIER '(' parameter_list ')' RETURN type '{' body '}'  */
#line 94 "parser.y"
                                                                    {
        (yyval.node_val) = createNode("FUNCTION", NULL);
        Node* idNode = createNode("IDENTIFIER", (yyvsp[-8].str_val));
        addLeftChild(idNode, (yyvsp[-6].node_val));
        addRightChild(idNode, (yyvsp[-3].node_val));
        addLeftChild((yyval.node_val), idNode);
        addRightChild((yyval.node_val), (yyvsp[-1].node_val)); 
    }
#line 1500 "y.tab.c"
    break;

  case 8: /* proc: PROC IDENTIFIER '(' parameter_list ')' '{' body '}'  */
#line 104 "parser.y"
                                                        {
        (yyval.node_val) = createNode("PROC",NULL);
        Node* idNode = createNode("IDENTIFIER",(yyvsp[-6].str_val));

        addLeftChild(idNode,(yyvsp[-4].node_val));

        addLeftChild((yyval.node_val),idNode);
        addRightChild((yyval.node_val),(yyvsp[-1].node_val));
     }
#line 1514 "y.tab.c"
    break;

  case 9: /* parameter_list: non_empty_param_list  */
#line 116 "parser.y"
                         { (yyval.node_val) = (yyvsp[0].node_val); }
#line 1520 "y.tab.c"
    break;

  case 10: /* parameter_list: %empty  */
#line 117 "parser.y"
      { (yyval.node_val) = NULL; }
#line 1526 "y.tab.c"
    break;

  case 11: /* non_empty_param_list: IDENTIFIER ',' non_empty_param_list  */
#line 121 "parser.y"
                                        {
        Node* original_type = (yyvsp[0].node_val)->left->right;
        Node* cloned_type = createNode(original_type->type, original_type->value);
        
        Node* param = createNode("PARAM", NULL);
        addLeftChild(param, createNode("IDENTIFIER", (yyvsp[-2].str_val)));
        addRightChild(param, cloned_type); /* משתמשים בשיבוט! */

        (yyval.node_val) = createNode("PARAM_LIST", NULL);
        addLeftChild((yyval.node_val), param);
        addRightChild((yyval.node_val), (yyvsp[0].node_val));
    }
#line 1543 "y.tab.c"
    break;

  case 12: /* non_empty_param_list: IDENTIFIER ':' type ';' non_empty_param_list  */
#line 134 "parser.y"
                                                 {
        Node* param = createNode("PARAM", NULL);
        
        addLeftChild(param, createNode("IDENTIFIER", (yyvsp[-4].str_val)));
        addRightChild(param, (yyvsp[-2].node_val));

        (yyval.node_val) = createNode("PARAM_LIST", NULL);
        addLeftChild((yyval.node_val), param);
        addRightChild((yyval.node_val), (yyvsp[0].node_val));
    }
#line 1558 "y.tab.c"
    break;

  case 13: /* non_empty_param_list: IDENTIFIER ':' type  */
#line 145 "parser.y"
                        {
        Node* param = createNode("PARAM", NULL);
        
        addLeftChild(param, createNode("IDENTIFIER", (yyvsp[-2].str_val)));
        addRightChild(param, (yyvsp[0].node_val));

        (yyval.node_val) = createNode("PARAM_LIST", NULL);
        addLeftChild((yyval.node_val), param);
        addRightChild((yyval.node_val), NULL);
    }
#line 1573 "y.tab.c"
    break;

  case 14: /* type: INT  */
#line 157 "parser.y"
              { (yyval.node_val) = createNode("TYPE", "int"); }
#line 1579 "y.tab.c"
    break;

  case 15: /* type: BOOL  */
#line 158 "parser.y"
              { (yyval.node_val) = createNode("TYPE", "bool"); }
#line 1585 "y.tab.c"
    break;

  case 16: /* type: REAL  */
#line 159 "parser.y"
              { (yyval.node_val) = createNode("TYPE", "real"); }
#line 1591 "y.tab.c"
    break;

  case 17: /* type: CHAR  */
#line 160 "parser.y"
              { (yyval.node_val) = createNode("TYPE", "char"); }
#line 1597 "y.tab.c"
    break;

  case 18: /* type: STRING '[' INT_LITERAL ']'  */
#line 161 "parser.y"
                                 { char buf[32]; sprintf(buf,"%d",(yyvsp[-1].int_val)); (yyval.node_val) = createNode("STRING_ARRAY_TYPE", buf);}
#line 1603 "y.tab.c"
    break;

  case 19: /* type: INTPTR  */
#line 163 "parser.y"
              { (yyval.node_val) = createNode("TYPE", "int*"); }
#line 1609 "y.tab.c"
    break;

  case 20: /* type: CHARPTR  */
#line 164 "parser.y"
              { (yyval.node_val) = createNode("TYPE", "char*"); }
#line 1615 "y.tab.c"
    break;

  case 21: /* type: REALPTR  */
#line 165 "parser.y"
              { (yyval.node_val) = createNode("TYPE", "real*"); }
#line 1621 "y.tab.c"
    break;

  case 22: /* body: declarations statements  */
#line 169 "parser.y"
                            {
        (yyval.node_val) = createNode("BODY", NULL);
        addLeftChild((yyval.node_val), (yyvsp[-1].node_val));
        addRightChild((yyval.node_val), (yyvsp[0].node_val));
    }
#line 1631 "y.tab.c"
    break;

  case 23: /* body: declarations  */
#line 174 "parser.y"
                   { (yyval.node_val) = (yyvsp[0].node_val); }
#line 1637 "y.tab.c"
    break;

  case 24: /* body: statements  */
#line 175 "parser.y"
                   { (yyval.node_val) = (yyvsp[0].node_val); }
#line 1643 "y.tab.c"
    break;

  case 25: /* body: %empty  */
#line 176 "parser.y"
      {(yyval.node_val) = NULL;}
#line 1649 "y.tab.c"
    break;

  case 26: /* declarations: declarations decl_sttmnt  */
#line 180 "parser.y"
                             {
        (yyval.node_val) = createNode("DECLARATIONS", NULL);
        addLeftChild((yyval.node_val), (yyvsp[-1].node_val));
        addRightChild((yyval.node_val), (yyvsp[0].node_val));
    }
#line 1659 "y.tab.c"
    break;

  case 27: /* declarations: decl_sttmnt  */
#line 185 "parser.y"
                  { (yyval.node_val) = (yyvsp[0].node_val); }
#line 1665 "y.tab.c"
    break;

  case 28: /* statements: statements statement  */
#line 189 "parser.y"
                         {
        (yyval.node_val) = createNode("STATEMENTS",NULL);
        addLeftChild((yyval.node_val),(yyvsp[-1].node_val));
        addRightChild((yyval.node_val),(yyvsp[0].node_val));
    }
#line 1675 "y.tab.c"
    break;

  case 29: /* statements: statement  */
#line 195 "parser.y"
              {
        (yyval.node_val) = (yyvsp[0].node_val);
    }
#line 1683 "y.tab.c"
    break;

  case 30: /* statement: assign_sttmnt  */
#line 200 "parser.y"
                  {(yyval.node_val) = (yyvsp[0].node_val);}
#line 1689 "y.tab.c"
    break;

  case 31: /* statement: call_sttmnt  */
#line 201 "parser.y"
                  {(yyval.node_val) = (yyvsp[0].node_val);}
#line 1695 "y.tab.c"
    break;

  case 32: /* statement: if_sttmnt  */
#line 202 "parser.y"
                {(yyval.node_val) = (yyvsp[0].node_val);}
#line 1701 "y.tab.c"
    break;

  case 33: /* statement: block_sttmnt  */
#line 203 "parser.y"
                   {(yyval.node_val) = (yyvsp[0].node_val);}
#line 1707 "y.tab.c"
    break;

  case 34: /* statement: for_sttmnt  */
#line 204 "parser.y"
                 {(yyval.node_val) = (yyvsp[0].node_val);}
#line 1713 "y.tab.c"
    break;

  case 35: /* statement: while_sttmnt  */
#line 205 "parser.y"
                   {(yyval.node_val) = (yyvsp[0].node_val);}
#line 1719 "y.tab.c"
    break;

  case 36: /* statement: return_sttmnt  */
#line 206 "parser.y"
                    {(yyval.node_val) = (yyvsp[0].node_val);}
#line 1725 "y.tab.c"
    break;

  case 37: /* statement: function  */
#line 207 "parser.y"
               {(yyval.node_val) = (yyvsp[0].node_val);}
#line 1731 "y.tab.c"
    break;

  case 38: /* statement: proc  */
#line 208 "parser.y"
           {(yyval.node_val) = (yyvsp[0].node_val);}
#line 1737 "y.tab.c"
    break;

  case 39: /* assign_sttmnt: lhs '=' rhs ';'  */
#line 211 "parser.y"
                   {
        (yyval.node_val) = createNode("ASSIGN_STTMNT",NULL);
        addLeftChild((yyval.node_val),(yyvsp[-3].node_val));
        addRightChild((yyval.node_val),(yyvsp[-1].node_val));
    }
#line 1747 "y.tab.c"
    break;

  case 40: /* lhs: IDENTIFIER  */
#line 219 "parser.y"
                { (yyval.node_val) = createNode("IDENTIFIER", (yyvsp[0].str_val)); }
#line 1753 "y.tab.c"
    break;

  case 41: /* lhs: IDENTIFIER '[' expression ']'  */
#line 220 "parser.y"
                                    {
        (yyval.node_val) = createNode("ARRAY_ACCESS", NULL);
        addLeftChild((yyval.node_val), createNode("IDENTIFIER", (yyvsp[-3].str_val)));
        addRightChild((yyval.node_val), (yyvsp[-1].node_val));
    }
#line 1763 "y.tab.c"
    break;

  case 42: /* lhs: '^' IDENTIFIER  */
#line 225 "parser.y"
                     { 
        (yyval.node_val) = createNode("DEREF", NULL); 
        addLeftChild((yyval.node_val), createNode("IDENTIFIER", (yyvsp[0].str_val))); 
        addRightChild((yyval.node_val), NULL); 
    }
#line 1773 "y.tab.c"
    break;

  case 43: /* lhs: '^' IDENTIFIER '[' expression ']'  */
#line 230 "parser.y"
                                        {
        Node* arr = createNode("ARRAY_ACCESS", NULL);
        addLeftChild(arr, createNode("IDENTIFIER", (yyvsp[-3].str_val)));
        addRightChild(arr, (yyvsp[-1].node_val));
        (yyval.node_val) = createNode("DEREF", NULL); 
        addLeftChild((yyval.node_val), arr);
        addRightChild((yyval.node_val), NULL);
    }
#line 1786 "y.tab.c"
    break;

  case 44: /* lhs: '^' '(' expression ')'  */
#line 238 "parser.y"
                             {
        (yyval.node_val) = createNode("DEREF", NULL); 
        addLeftChild((yyval.node_val), (yyvsp[-1].node_val)); 
        addRightChild((yyval.node_val), NULL); 
    }
#line 1796 "y.tab.c"
    break;

  case 45: /* rhs: expression  */
#line 245 "parser.y"
               {
        (yyval.node_val) = (yyvsp[0].node_val);
    }
#line 1804 "y.tab.c"
    break;

  case 46: /* expression: expression OR expression  */
#line 251 "parser.y"
                               { (yyval.node_val) = createNode("OR",  NULL); addLeftChild((yyval.node_val),(yyvsp[-2].node_val)); addRightChild((yyval.node_val),(yyvsp[0].node_val)); }
#line 1810 "y.tab.c"
    break;

  case 47: /* expression: expression AND expression  */
#line 252 "parser.y"
                                { (yyval.node_val) = createNode("AND", NULL); addLeftChild((yyval.node_val),(yyvsp[-2].node_val)); addRightChild((yyval.node_val),(yyvsp[0].node_val)); }
#line 1816 "y.tab.c"
    break;

  case 48: /* expression: expression EQ expression  */
#line 253 "parser.y"
                                { (yyval.node_val) = createNode("EQ",  NULL); addLeftChild((yyval.node_val),(yyvsp[-2].node_val)); addRightChild((yyval.node_val),(yyvsp[0].node_val)); }
#line 1822 "y.tab.c"
    break;

  case 49: /* expression: expression NEQ expression  */
#line 254 "parser.y"
                                { (yyval.node_val) = createNode("NEQ", NULL); addLeftChild((yyval.node_val),(yyvsp[-2].node_val)); addRightChild((yyval.node_val),(yyvsp[0].node_val)); }
#line 1828 "y.tab.c"
    break;

  case 50: /* expression: expression '>' expression  */
#line 255 "parser.y"
                                { (yyval.node_val) = createNode("GT",  NULL); addLeftChild((yyval.node_val),(yyvsp[-2].node_val)); addRightChild((yyval.node_val),(yyvsp[0].node_val)); }
#line 1834 "y.tab.c"
    break;

  case 51: /* expression: expression '<' expression  */
#line 256 "parser.y"
                                { (yyval.node_val) = createNode("LT",  NULL); addLeftChild((yyval.node_val),(yyvsp[-2].node_val)); addRightChild((yyval.node_val),(yyvsp[0].node_val)); }
#line 1840 "y.tab.c"
    break;

  case 52: /* expression: expression GTE expression  */
#line 257 "parser.y"
                                { (yyval.node_val) = createNode("GTE", NULL); addLeftChild((yyval.node_val),(yyvsp[-2].node_val)); addRightChild((yyval.node_val),(yyvsp[0].node_val)); }
#line 1846 "y.tab.c"
    break;

  case 53: /* expression: expression LTE expression  */
#line 258 "parser.y"
                                { (yyval.node_val) = createNode("LTE", NULL); addLeftChild((yyval.node_val),(yyvsp[-2].node_val)); addRightChild((yyval.node_val),(yyvsp[0].node_val)); }
#line 1852 "y.tab.c"
    break;

  case 54: /* expression: expression '+' expression  */
#line 259 "parser.y"
                                { (yyval.node_val) = createNode("ADD", NULL); addLeftChild((yyval.node_val),(yyvsp[-2].node_val)); addRightChild((yyval.node_val),(yyvsp[0].node_val)); }
#line 1858 "y.tab.c"
    break;

  case 55: /* expression: expression '-' expression  */
#line 260 "parser.y"
                                { (yyval.node_val) = createNode("SUB", NULL); addLeftChild((yyval.node_val),(yyvsp[-2].node_val)); addRightChild((yyval.node_val),(yyvsp[0].node_val)); }
#line 1864 "y.tab.c"
    break;

  case 56: /* expression: expression '*' expression  */
#line 261 "parser.y"
                                { (yyval.node_val) = createNode("MUL", NULL); addLeftChild((yyval.node_val),(yyvsp[-2].node_val)); addRightChild((yyval.node_val),(yyvsp[0].node_val)); }
#line 1870 "y.tab.c"
    break;

  case 57: /* expression: expression '/' expression  */
#line 262 "parser.y"
                                { (yyval.node_val) = createNode("DIV", NULL); addLeftChild((yyval.node_val),(yyvsp[-2].node_val)); addRightChild((yyval.node_val),(yyvsp[0].node_val)); }
#line 1876 "y.tab.c"
    break;

  case 58: /* expression: '!' expression  */
#line 263 "parser.y"
                     { (yyval.node_val) = createNode("NOT",  NULL); addLeftChild((yyval.node_val),(yyvsp[0].node_val)); addRightChild((yyval.node_val),NULL); }
#line 1882 "y.tab.c"
    break;

  case 59: /* expression: '-' expression  */
#line 264 "parser.y"
                               { (yyval.node_val) = createNode("NEG",  NULL); addLeftChild((yyval.node_val),(yyvsp[0].node_val)); addRightChild((yyval.node_val),NULL); }
#line 1888 "y.tab.c"
    break;

  case 60: /* expression: '+' expression  */
#line 265 "parser.y"
                               { (yyval.node_val) = createNode("POS",  NULL); addLeftChild((yyval.node_val),(yyvsp[0].node_val)); addRightChild((yyval.node_val),NULL); }
#line 1894 "y.tab.c"
    break;

  case 61: /* expression: '^' IDENTIFIER  */
#line 266 "parser.y"
                     { 
        (yyval.node_val) = createNode("DEREF", NULL); 
        addLeftChild((yyval.node_val), createNode("IDENTIFIER", (yyvsp[0].str_val))); 
    }
#line 1903 "y.tab.c"
    break;

  case 62: /* expression: '^' IDENTIFIER '[' expression ']'  */
#line 270 "parser.y"
                                        { 
        Node* arr = createNode("ARRAY_ACCESS", NULL);
        addLeftChild(arr, createNode("IDENTIFIER", (yyvsp[-3].str_val)));
        addRightChild(arr, (yyvsp[-1].node_val));
        (yyval.node_val) = createNode("DEREF", NULL); 
        addLeftChild((yyval.node_val), arr); 
    }
#line 1915 "y.tab.c"
    break;

  case 63: /* expression: '^' '(' expression ')'  */
#line 277 "parser.y"
                             { 
        (yyval.node_val) = createNode("DEREF", NULL); 
        addLeftChild((yyval.node_val), (yyvsp[-1].node_val)); 
    }
#line 1924 "y.tab.c"
    break;

  case 64: /* expression: '&' IDENTIFIER  */
#line 282 "parser.y"
                     { (yyval.node_val) = createNode("ADDR_OF",NULL); addLeftChild((yyval.node_val),createNode("IDENTIFIER",(yyvsp[0].str_val))); addRightChild((yyval.node_val),NULL); }
#line 1930 "y.tab.c"
    break;

  case 65: /* expression: '&' IDENTIFIER '[' expression ']'  */
#line 283 "parser.y"
                                        { 
        Node* arr = createNode("ARRAY_ACCESS", NULL);
        addLeftChild(arr, createNode("IDENTIFIER", (yyvsp[-3].str_val)));
        addRightChild(arr, (yyvsp[-1].node_val));
        (yyval.node_val) = createNode("ADDR_OF", NULL);
        addLeftChild((yyval.node_val), arr);
    }
#line 1942 "y.tab.c"
    break;

  case 66: /* expression: '(' expression ')'  */
#line 290 "parser.y"
                         { (yyval.node_val) = (yyvsp[-1].node_val); }
#line 1948 "y.tab.c"
    break;

  case 67: /* expression: '|' expression '|'  */
#line 292 "parser.y"
                         { (yyval.node_val) = createNode("STRLEN", NULL); addLeftChild((yyval.node_val), (yyvsp[-1].node_val)); }
#line 1954 "y.tab.c"
    break;

  case 68: /* expression: IDENTIFIER '[' expression ']'  */
#line 294 "parser.y"
                                   { (yyval.node_val) = createNode("ARRAY_ACCESS",NULL); addLeftChild((yyval.node_val),createNode("IDENTIFIER",(yyvsp[-3].str_val))); addRightChild((yyval.node_val),(yyvsp[-1].node_val)); }
#line 1960 "y.tab.c"
    break;

  case 69: /* expression: IDENTIFIER  */
#line 295 "parser.y"
                 { (yyval.node_val) = createNode("IDENTIFIER",(yyvsp[0].str_val)); }
#line 1966 "y.tab.c"
    break;

  case 70: /* expression: IDENTIFIER '(' arguments ')'  */
#line 296 "parser.y"
                                   { 
        (yyval.node_val) = createNode("FUNC_CALL", NULL); 
        addLeftChild((yyval.node_val), createNode("IDENTIFIER", (yyvsp[-3].str_val))); 
        addRightChild((yyval.node_val), (yyvsp[-1].node_val)); 
    }
#line 1976 "y.tab.c"
    break;

  case 71: /* expression: INT_LITERAL  */
#line 301 "parser.y"
                  { char buf[32]; sprintf(buf,"%d",(yyvsp[0].int_val));  (yyval.node_val) = createNode("INT_LITERAL",  buf); }
#line 1982 "y.tab.c"
    break;

  case 72: /* expression: REAL_LITERAL  */
#line 302 "parser.y"
                   { char buf[64]; sprintf(buf,"%g",(yyvsp[0].real_val));  (yyval.node_val) = createNode("REAL_LITERAL", buf); }
#line 1988 "y.tab.c"
    break;

  case 73: /* expression: CHAR_LITERAL  */
#line 303 "parser.y"
                   { char buf[4];  buf[0]=(yyvsp[0].char_val); buf[1]='\0'; (yyval.node_val) = createNode("CHAR_LITERAL",buf); }
#line 1994 "y.tab.c"
    break;

  case 74: /* expression: TRUE_LITERAL  */
#line 304 "parser.y"
                   { (yyval.node_val) = createNode("BOOL_LITERAL","true"); }
#line 2000 "y.tab.c"
    break;

  case 75: /* expression: FALSE_LITERAL  */
#line 305 "parser.y"
                    { (yyval.node_val) = createNode("BOOL_LITERAL","false"); }
#line 2006 "y.tab.c"
    break;

  case 76: /* expression: STRING_LITERAL  */
#line 307 "parser.y"
                     { (yyval.node_val) = createNode("STRING_LITERAL", (yyvsp[0].str_val)); }
#line 2012 "y.tab.c"
    break;

  case 77: /* expression: NULL_TOK  */
#line 309 "parser.y"
               { (yyval.node_val) = createNode("NULL",NULL); }
#line 2018 "y.tab.c"
    break;

  case 78: /* decl_sttmnt: VAR var_decl_list ';'  */
#line 312 "parser.y"
                          { 
        (yyval.node_val) = (yyvsp[-1].node_val); 
    }
#line 2026 "y.tab.c"
    break;

  case 79: /* var_decl_list: IDENTIFIER ',' var_decl_list  */
#line 318 "parser.y"
                                 {
        Node* original_type = (yyvsp[0].node_val)->left->right;
        Node* cloned_type = createNode(original_type->type, original_type->value);
        
        Node* id = createNode("VAR_DECL", NULL);
        addLeftChild(id, createNode("IDENTIFIER", (yyvsp[-2].str_val)));
        addRightChild(id, cloned_type); 

        (yyval.node_val) = createNode("VAR_LIST", NULL);
        addLeftChild((yyval.node_val), id);
        addRightChild((yyval.node_val), (yyvsp[0].node_val));
    }
#line 2043 "y.tab.c"
    break;

  case 80: /* var_decl_list: IDENTIFIER ':' type  */
#line 330 "parser.y"
                        {
        Node* id = createNode("VAR_DECL", NULL);
        
        addLeftChild(id, createNode("IDENTIFIER", (yyvsp[-2].str_val)));
        addRightChild(id, (yyvsp[0].node_val));

        (yyval.node_val) = createNode("VAR_LIST", NULL);
        addLeftChild((yyval.node_val), id);
        addRightChild((yyval.node_val), NULL);
    }
#line 2058 "y.tab.c"
    break;

  case 81: /* call_sttmnt: IDENTIFIER '(' arguments ')' ';'  */
#line 343 "parser.y"
                                     {
        (yyval.node_val) = createNode("CALL_STTMNT", NULL);
        addLeftChild((yyval.node_val), createNode("IDENTIFIER", (yyvsp[-4].str_val)));
        addRightChild((yyval.node_val), (yyvsp[-2].node_val));
    }
#line 2068 "y.tab.c"
    break;

  case 82: /* arguments: non_empty_arguments_list  */
#line 350 "parser.y"
                             { (yyval.node_val) = (yyvsp[0].node_val);}
#line 2074 "y.tab.c"
    break;

  case 83: /* arguments: %empty  */
#line 351 "parser.y"
      {(yyval.node_val) = NULL;}
#line 2080 "y.tab.c"
    break;

  case 84: /* non_empty_arguments_list: expression ',' non_empty_arguments_list  */
#line 354 "parser.y"
                                            {
        (yyval.node_val) = createNode("ARGUMENTS_LIST",NULL);
        addLeftChild((yyval.node_val),(yyvsp[-2].node_val));
        addRightChild((yyval.node_val),(yyvsp[0].node_val));
        }
#line 2090 "y.tab.c"
    break;

  case 85: /* non_empty_arguments_list: expression  */
#line 360 "parser.y"
               {
        (yyval.node_val) = createNode("ARGUMENTS_LIST",NULL);
        addLeftChild((yyval.node_val),(yyvsp[0].node_val));
        addRightChild((yyval.node_val),NULL);
    }
#line 2100 "y.tab.c"
    break;

  case 86: /* if_sttmnt: IF '(' expression ')' statement  */
#line 368 "parser.y"
                                              {
        (yyval.node_val) = createNode("IF_STTMNT", NULL);
        addLeftChild((yyval.node_val), (yyvsp[-2].node_val)); 
        
        Node* then_block = createNode("THEN", NULL);
        addLeftChild(then_block, (yyvsp[0].node_val));
        addRightChild((yyval.node_val), then_block);
    }
#line 2113 "y.tab.c"
    break;

  case 87: /* if_sttmnt: IF '(' expression ')' statement ELSE statement  */
#line 376 "parser.y"
                                                     {
        (yyval.node_val) = createNode("IF_ELSE_STTMNT", NULL);
        
        Node* then_block = createNode("THEN", NULL);
        addLeftChild(then_block, (yyvsp[-2].node_val));
        
        Node* else_block = createNode("ELSE", NULL);
        addLeftChild(else_block, (yyvsp[0].node_val));
        
        Node* branches = createNode("IF_BRANCHES", NULL);
        addLeftChild(branches, then_block);
        addRightChild(branches, else_block);
        
        addLeftChild((yyval.node_val), (yyvsp[-4].node_val));
        addRightChild((yyval.node_val), branches);
    }
#line 2134 "y.tab.c"
    break;

  case 88: /* for_sttmnt: FOR '(' lhs '=' rhs ';' expression ';' lhs '=' rhs ')' statement  */
#line 395 "parser.y"
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
#line 2161 "y.tab.c"
    break;

  case 89: /* while_sttmnt: WHILE '(' expression ')' statement  */
#line 420 "parser.y"
                                       {
        (yyval.node_val) = createNode("WHILE_STTMNT",NULL);
        addLeftChild((yyval.node_val),(yyvsp[-2].node_val));
        addRightChild((yyval.node_val),(yyvsp[0].node_val));
    }
#line 2171 "y.tab.c"
    break;

  case 90: /* block_sttmnt: '{' body '}'  */
#line 427 "parser.y"
                 {
        (yyval.node_val) = (yyvsp[-1].node_val);
    }
#line 2179 "y.tab.c"
    break;

  case 91: /* return_sttmnt: RETURN expression ';'  */
#line 433 "parser.y"
                         {
        (yyval.node_val) = createNode("RETURN_STTMNT",NULL);
        addLeftChild((yyval.node_val),(yyvsp[-1].node_val));
        addRightChild((yyval.node_val),NULL);
    }
#line 2189 "y.tab.c"
    break;


#line 2193 "y.tab.c"

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

#line 440 "parser.y"




/* #include "lex.yy.c" */ 

int main() {
    printf("Starting Parser...\n");
    if (yyparse() == 0) {
        printf("Success!\n\n");
        printf("=== Abstract Syntax Tree ===\n");
        printTree(root);
        freeTree(root);
    } 
    return 0;
}

void yyerror(const char* s) {
    printf("Syntax Error on line %d: %s: unexpected token '%s' \n ", yylineno, s,yytext);
}
