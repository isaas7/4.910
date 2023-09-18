# Lexer Design

This document outlines the design of the Lexer component for the Compilator C++ Compiler project. The Lexer is responsible for tokenizing the source code, breaking it down into individual units called tokens, which can be further processed by the parser.

## Table of Contents

- [Overview](#overview)
- [Token Types](#token-types)
- [Lexer Class](#lexer-class)
  - [Constructor](#constructor)
  - [Public Method: tokenize()](#public-method-tokenize)
- [Token Recognition](#token-recognition)
  - [scanToken()](#scantoken)
  - [scanIdentifier()](#scanidentifier)
- [Lexer State](#lexer-state)
- [Usage](#usage)

## Overview

The Lexer is an essential component of the Compilator C++ Compiler. It is responsible for taking the source code as input and converting it into a stream of tokens. Each token represents a meaningful unit in the source code, such as keywords, identifiers, literals, operators, and punctuation.

## Token Types

The lexer recognizes various token types, which are represented using the `enum class TokenType`. These token types include:

- `IDENTIFIER`: Represents user-defined names like variable names and function names.
- `INTEGER`: Represents integer literals.
- `PLUS`, `MINUS`, `SEMICOLON`: Represents specific operators and punctuation.
- `EQUAL`: Represents the equality operator (e.g., `=`).
- `END_OF_FILE`: Indicates the end of the input source code.
- `LEFT_PAREN`: Represents a left parenthesis, `(`.
- `RIGHT_PAREN`: Represents a right parenthesis, `)`.
- `LEFT_BRACE`: Represents a left brace, `{`.
- `RIGHT_BRACE`: Represents a right brace, `}`.
- (Additional token types can be added as needed to support the language being compiled.)

## Lexer Class

The Lexer is implemented as a C++ class named `Lexer`. It provides the following functionalities:

### Constructor

- **Constructor**: Accepts the source code as a string and initializes the lexer's internal state.

### Public Method: tokenize()

- **tokenize()**: Tokenizes the source code and returns a vector of tokens.

## Token Recognition

Token recognition is the process of identifying and categorizing parts of the source code into tokens. The lexer uses two primary functions for token recognition:

### scanToken()

- **scanToken()**: Scans the source code character by character, recognizing tokens based on specific characters or patterns. It returns a token object.

### scanIdentifier()

- **scanIdentifier()**: A helper function used by `scanToken()` to recognize identifiers (e.g., variable and function names). It identifies sequences of alphanumeric characters.

## Lexer State

The lexer maintains its state using private variables, including:

- `source`: The source code string.
- `tokens`: A vector to store recognized tokens.
- `start`, `current`: Pointers indicating the current position in the source code.
- `line`: Keeps track of the current line number.

## Usage

The lexer can be used by creating an instance of the `Lexer` class with the source code as input and calling the `tokenize()` method. The resulting vector of tokens can then be used as input for the parser and subsequent phases of the compiler.

This design provides a foundation for the lexer component, and additional functionality and token recognition rules can be added to support the language being compiled.
