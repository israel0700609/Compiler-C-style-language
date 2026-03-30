# Phase 1: Lexical Analyzer (Scanner)

## Overview
This branch (`feat/scanner`) contains the implementation of the Lexical Analyzer for our custom procedural language compiler. The scanner is generated using **Lex (Flex)** and serves as the very first step in the compilation pipeline.

Its primary responsibility is to read the raw source code characters, group them into meaningful lexemes, and output a stream of **Tokens** to be consumed by the Yacc-generated Parser.

## Scanner Responsibilities & Features

### 1. Token Recognition
The scanner employs Regular Expressions to accurately identify and categorize the following language components:
* **Keywords:** `bool`, `char`, `int`, `real`, `string`, `if`, `else`, `while`, `for`, `var`, `func`, `proc`, `return`, `null`.
* **Identifiers:** Strings starting with an alphabetic character, optionally followed by alphanumeric characters or underscores `_`.
* **Literals:**
    * **Booleans:** `true` or `false`.
    * **Integers:** Decimal numbers and Hexadecimal values (starting with `0x` or `0X`).
    * **Reals:** Floating-point numbers, including scientific notation (e.g., `3.14`, `-4E+2101`, `+.2E4`).
    * **Characters:** Single printable characters enclosed in single quotes (e.g., `'a'`).
    * **Strings:** Sequences of characters enclosed in double quotes. The scanner handles basic escape sequences (like `\n`) and ensures double quotes aren't allowed inside the string itself.

### 2. Operators & Punctuation
The scanner correctly tokenizes arithmetic (`+`, `-`, `*`, `/`), relational (`==`, `>`, `>=`, `<`, `<=`, `!=`), logical (`&&`, `||`, `!`), and pointer-specific operators (`^`, `&`). It also captures brackets, braces, commas, and semicolons necessary for parsing.

### 3. Whitespace & Comment Handling
* **Whitespace:** Spaces, tabs, and newlines are recognized and safely ignored, as they do not affect the logic of the target language.
* **Comments:** The scanner detects C-style block comments formatted as `/% comment block %/` and discards them entirely, preventing them from reaching the syntax analyzer.

### 4. Line Tracking
The scanner internally tracks line numbers (`yylineno`). This is critical for generating precise and helpful syntax error messages later in the parser phase.
