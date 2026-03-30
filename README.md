# Phase 1: Lexical Analyzer (Scanner)

## Overview
This branch (`feat/scanner`) contains the implementation of the Lexical Analyzer for our custom procedural language compiler. The scanner is generated using **Lex (Flex)** and serves as the very first step in the compilation pipeline.

Its primary responsibility is to read the raw source code characters, group them into meaningful lexemes, and output a stream of **Tokens** to be consumed by the Yacc-generated Parser.

## Scanner Responsibilities & Features

### 1. Token Recognition
The scanner employs Regular Expressions to accurately identify and categorize the following language components:
* [cite_start]**Keywords:** `bool`, `char`, `int`, `real`, `string`, `if`, `else`, `while`, `for`, `var`, `func`, `proc`, `return`, `null`[cite: 7, 8, 9, 10, 11, 15, 16, 17, 18, 19, 20, 21, 22, 23].
* [cite_start]**Identifiers:** Strings starting with an alphabetic character, optionally followed by alphanumeric characters or underscores `_`[cite: 69, 70].
* **Literals:**
    * [cite_start]**Booleans:** `true` or `false`[cite: 38].
    * [cite_start]**Integers:** Decimal numbers and Hexadecimal values (starting with `0x` or `0X`)[cite: 47, 50, 51].
    * [cite_start]**Reals:** Floating-point numbers, including scientific notation (e.g., `3.14`, `-4E+2101`, `+.2E4`)[cite: 53, 54].
    * [cite_start]**Characters:** Single printable characters enclosed in single quotes (e.g., `'a'`)[cite: 39, 41].
    * **Strings:** Sequences of characters enclosed in double quotes. [cite_start]The scanner handles basic escape sequences (like `\n`) and ensures double quotes aren't allowed inside the string itself[cite: 55, 57, 62].

### 2. Operators & Punctuation
[cite_start]The scanner correctly tokenizes arithmetic (`+`, `-`, `*`, `/`), relational (`==`, `>`, `>=`, `<`, `<=`, `!=`), logical (`&&`, `||`, `!`), and pointer-specific operators (`^`, `&`)[cite: 26, 27, 28, 29, 30, 31, 32, 33, 74, 76]. Note: the logical OR operator is represented by `+` in our regular expressions configuration, replacing the standard `|`. [cite_start]It also captures brackets, braces, commas, and semicolons necessary for parsing[cite: 105].

### 3. Whitespace & Comment Handling
* **Whitespace:** Spaces, tabs, and newlines are recognized and safely ignored, as they do not affect the logic of the target language.
* [cite_start]**Comments:** The scanner detects C-style block comments formatted as `/% comment block %/` and discards them entirely, preventing them from reaching the syntax analyzer[cite: 109].

### 4. Line Tracking
The scanner internally tracks line numbers (`yylineno`). [cite_start]This is critical for generating precise and helpful syntax error messages later in the parser phase[cite: 450].
