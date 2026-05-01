# Syntax Analyzer

## Overview
This folder contains the syntax-analysis stage of the compiler for the custom C-style language.
It is split into two generated components that work together as a pipeline:

- `Scanner.l` is the Flex lexer. It reads raw source text and converts it into tokens.
- `parser.y` is the Bison parser. It consumes those tokens, validates them against the grammar, and builds an abstract syntax tree (AST).

The flow is always:

1. The scanner reads characters from the input program.
2. The scanner classifies each lexeme as a keyword, identifier, literal, operator, or delimiter.
3. The scanner attaches semantic values when needed, such as string text or numeric values.
4. The parser receives the token stream and matches it against the grammar rules.
5. The parser creates AST nodes to represent the program structure.

## Architecture

### Scanner responsibilities
The scanner is responsible for lexical analysis only. It does not understand program structure; it only recognizes individual pieces of text.

It currently handles:

- language keywords such as `bool`, `char`, `int`, `real`, `string`, `if`, `else`, `while`, `for`, `var`, `func`, `proc`, `return`, and `null`
- identifiers for names of variables, functions, procedures, and parameters
- literals including booleans, integers, reals, strings, and characters
- operators such as `==`, `!=`, `>=`, `<=`, `&&`, `||`, `+`, `-`, `*`, `/`, `^`, `&`, `!`, `=`, `>`, and `<`
- punctuation symbols such as parentheses, braces, brackets, commas, semicolons, and colons
- block comments written in the `/% ... %/` style
- whitespace and newline skipping
- line-number tracking through `yylineno`

The scanner also fills `yylval` for tokens that carry extra data:

- `IDENTIFIER` carries a copied string value
- `STRING_LITERAL` carries the string contents
- `INT_LITERAL` carries an integer value
- `REAL_LITERAL` carries a floating-point value
- `CHAR_LITERAL` carries a character value
- `TRUE_LITERAL` and `FALSE_LITERAL` carry boolean values as integers

### Parser responsibilities
The parser is responsible for syntax and structure. It does not just check whether tokens exist; it checks that they appear in a valid order according to the language grammar.

The parser currently builds the high-level structure of the language:

- the program root
- lists of functions and procedures
- function definitions
- procedure definitions
- parameter lists
- typed parameters
- primitive and pointer types
- blocks of statements
- assignments
- variable declarations
- function call statements
- while statements
- return statements

The parser stores the final result in `root` when the full program parses successfully.

## AST Model

This parser is AST-driven. That means grammar rules do not just check syntax; they create tree nodes that describe the program.

The parser uses helper functions such as:

- `createNode`
- `addLeftChild`
- `addRightChild`

Each grammar rule can create one AST node and connect child nodes beneath it. This gives a tree representation that later compiler phases can walk.

Examples of node kinds used in the current parser:

- `PROGRAM`
- `FUNCTION_LIST`
- `PROC_LIST`
- `FUNCTION`
- `PROC`
- `PARAM_LIST`
- `PARAM`
- `TYPE`
- `BODY`
- `STATEMENTS`
- `ASSIGN_STTMNT`
- `DECL_STTMNT`
- `VAR_LIST`
- `CALL_STTMNT`
- `ARGUMENTS_LIST`
- `WHILE_STTMNT`
- `RETURN_STTMNT`

## Parser Structure

### Program entry
The top-level rule expects a sequence of functions and procedures. Once parsing succeeds, the parser creates a `PROGRAM` node and stores it as the root of the AST.

### Function and procedure definitions
The grammar distinguishes between:

- `function`, which has a `RETURN TYPE` and uses `body_with_return`
- `proc`, which has no return type and uses `body`

Both forms capture the name, parameter list, and body structure.

### Parameters
Parameters can be parsed as:

- a name followed by a type, like `x : int`
- a recursive parameter list, allowing comma-separated or semicolon-separated continuations depending on the grammar form used

The parser builds a `PARAM_LIST` chain so parameter order is preserved.

### Types
The parser supports primitive and pointer-style type names:

- `int`
- `bool`
- `real`
- `char`
- `string`
- `int*`
- `char*`
- `real*`

### Statements
The statement layer is organized as recursive lists so a block can contain multiple ordered statements.

The parser currently supports statement forms for:

- assignment
- declaration
- function call assignment
- while loop
- return
- nested block statements

## Recent Work In This File

The recent updates in `parser.y` were focused on making the parser more practical for AST construction and safer to integrate with the scanner.

### 1. Added typed semantic values
The parser now declares a `Node*` semantic value in the Bison `%union` and assigns AST-producing nonterminals to that value type with `%type`.

That allows grammar actions to use `$$` and `$n` as AST nodes instead of only primitive token data.

### 2. Connected function metadata into the AST
The function rule now attaches the parameter list and return type into the function node instead of leaving that information detached in a temporary local variable.

### 3. Aligned token and value handling with the scanner
The parser is written to work with the scanner’s token types and semantic payloads, including identifiers, strings, numbers, and booleans.

## What I Changed Overall

These are the main outcomes of the current work in the syntax analyzer:

- added AST-aware semantic typing to the parser
- made parser actions produce tree nodes consistently
- fixed function AST wiring so parameters and return type are preserved
- updated the scanner so identifier strings are safely copied
- updated boolean literals so they carry explicit values

## Implementation Notes

- The parser is meant to be used with a generated Flex header from the scanner.
- Identifier text must be owned memory because AST nodes may keep it after scanning.
- The parser still depends on the missing expression and conditional grammar pieces from the broader project work.
- The current file is focused on structure and AST assembly, not evaluation.

