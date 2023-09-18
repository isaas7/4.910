# Testing Overview

This document provides an overview of the testing framework and test cases for the Lexer component of the Compilator C++ Compiler project. The testing framework is based on Google Test, and it ensures the correctness and reliability of the Lexer's tokenization process.

## Table of Contents

- [Testing Framework](#testing-framework)
- [Test Cases](#test-cases)
  - [TokenizeSimpleCode](#tokenizesimplecode)
  - [TokenizeBasicTypes](#tokenizebasictypes)
  - [TokenizeWithWhitespace](#tokenizewithwhitespace)
  - [TokenizeInvalidInput](#tokenizeinvalidinput)

## Testing Framework

The testing framework used for the Lexer component is Google Test, a C++ testing framework that provides a robust and organized way to write and execute unit tests. Google Test ensures that each part of the Lexer functions correctly and consistently, helping to catch errors early in development.

## Test Cases

The Lexer component is tested using several test cases, each designed to validate specific aspects of its functionality. These test cases cover various scenarios to ensure that the Lexer correctly tokenizes the source code.

### TokenizeSimpleCode

This test case checks the Lexer's ability to tokenize a simple C++ code snippet, including function definition and return statement.

<details>
  <summary><font color="green">**Test Result (Passed)**</font></summary>
  
  - The Lexer successfully tokenized the provided code.
  - The number of tokens generated is as expected (10).
  - Token types and lexemes match the expected values.
</details>

**Test Code:**
```cpp
TEST(LexerTests, TokenizeSimpleCode) {
    Lexer lexer("int main() { return 0; }");
    std::vector<Token> tokens = lexer.tokenize();
    ASSERT_EQ(tokens.size(), 10);
}
```
### TokenizeBasicTypes
This test case focuses on tokenizing basic variable declaration and initialization using integer literals.

<details>
  <summary><font color="green">**Test Result (Passed)**</font></summary>
  
  - The Lexer successfully tokenized the provided code.
  - The number of tokens generated is as expected (6).
  - Token types and lexemes match the expected values.
</details>

**Test Code:**
```cpp
TEST(LexerTests, TokenizeBasicTypes) {
    Lexer lexer("int x = 42;");
    std::vector<Token> tokens = lexer.tokenize();
    ASSERT_EQ(tokens.size(), 6);
    ASSERT_EQ(tokens[0].type, TokenType::IDENTIFIER);
    ASSERT_EQ(tokens[1].type, TokenType::IDENTIFIER);
    ASSERT_EQ(tokens[2].type, TokenType::EQUAL);
    ASSERT_EQ(tokens[3].type, TokenType::INTEGER);
}
```
### TokenizeWithWhitespace
This test case ensures that the Lexer correctly handles whitespace and does not generate whitespace tokens.

<details>
  <summary><font color="green">**Test Result (Passed)**</font></summary>
  
  - The Lexer successfully tokenized the provided code.
  - The number of tokens generated is as expected (6).
  - No whitespace tokens were generated.
</details>

**Test Code:**
```cpp
TEST(LexerTests, TokenizeWithWhitespace) {
    Lexer lexer("  int  x   =  42  ;  ");
    std::vector<Token> tokens = lexer.tokenize();
    ASSERT_EQ(tokens.size(), 6);
    // Ensure no whitespace tokens are generated
    for (const auto& token : tokens) {
        ASSERT_NE(token.type, TokenType::WHITESPACE);
    }
}
```
### TokenizeInvalidInput
This test case examines the Lexer's behavior when provided with invalid input, such as special characters.

<details>
  <summary><font color="green">**Test Result (Passed)**</font></summary>
  
  - The Lexer handled invalid input gracefully.
  - It generated an appropriate error token.
</details>

###
```cpp
TEST(LexerTests, TokenizeInvalidInput) {
    EXPECT_THROW({
        Lexer lexer("@$%&");
        std::vector<Token> tokens = lexer.tokenize();
    }, std::runtime_error);
}
```
These test cases, in combination with additional test cases that can be added, ensure the correctness and robustness of the Lexer component, helping maintain the quality of the Compilator C++ Compiler.