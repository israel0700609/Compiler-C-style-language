# Compiler-C-style-language
# Custom Procedural Language Compiler

## Project Overview
This repository contains the full implementation of a custom compiler for a statically-typed procedural programming language. The compiler translates source code written in this specific language into Three-Address Code (3AC) through a multi-phase compilation pipeline.

The project is structured into three main phases, ensuring modularity, clear separation of concerns, and robust error handling.

## Compiler Architecture & Phases

### Phase 1: Front-End (Lexical & Syntax Analysis)
* **Scanner (Lexical Analyzer):** Built with **Lex/Flex**. Reads the source code and converts sequences of characters into a stream of tokens (e.g., keywords, identifiers, literals, operators). It strips out whitespace and block comments formatted as `/% comments %/`.
* **Parser (Syntax Analyzer):** Built with **Yacc/Bison**. Validates the grammatical structure of the token stream against the language's formal grammar rules. 
* **AST Construction:** Upon successful parsing, the compiler dynamically allocates and builds an Abstract Syntax Tree (AST) in memory. The tree represents the logical structure of the program and is printed in a strict **preorder traversal** with proper indentation and parentheses to reflect nesting. Detailed syntax error messages are generated if the code is invalid.

### Phase 2: Semantic Analysis (Upcoming)
* Traverses the AST to enforce semantic rules that cannot be caught by the parser.
* **Type Checking:** Validates type compatibility in assignments, expressions, and function calls.
* **Scope Resolution:** Enforces declaration-before-use rules and manages variable scoping using Symbol Tables.

### Phase 3: Back-End (Intermediate Code Generation - Upcoming)
* Converts the semantically validated AST into **Three-Address Code (3AC)**.
* Prepares the code for final target-machine assembly generation or execution via a virtual machine.

## The Language
The target language is a C-like procedural language featuring:
* **Subroutines:** Supports both value-returning functions (`func`) and non-returning procedures (`proc`). A `Main()` procedure is mandatory.
* **Data Types:** `int`, `real`, `char`, `bool`, `string` (character arrays), and strict pointer types (`int*`, `char*`, `real*`).
* **Control Flow:** `if`, `if-else`, `while`, and `for` statements.
* **Memory & Pointers:** Supports dereferencing (`^`), address-of (`&`), and the `null` keyword.

## Git Workflow
This repository follows a structured branching strategy:
* `main`: Stable, fully integrated, and tested compiler releases.
* `dev`: Integration branch for merging completed features.
* `feat/*`: Feature branches for specific components (e.g., `feat/scanner`, `feat/parser`, `feat/ast`).

## Team & Collaboration
This compiler is a joint academic project developed by a team of three Software Engineering students as part of our Compilation course. We simulate a real-world development environment by collaborating closely and dividing responsibilities.

Our collaborative workflow includes:
* **Task Distribution:** Splitting the workload logically across the compilation pipeline (e.g., separating Lex rules, Yacc grammar, and AST logic).
* **Version Control (Git):** Utilizing feature branches, peer code reviews, and structured merges into a central `dev` branch to prevent conflicts and ensure code stability.
* **Problem Solving:** Tackling complex shift/reduce conflicts and architectural decisions as a team.
