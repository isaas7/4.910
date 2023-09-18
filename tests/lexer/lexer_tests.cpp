#include <gtest/gtest.h>
#include "../../src/lexer/lexer.h"

TEST(LexerTests, TokenizeSimpleCode) {
    Lexer lexer("int main() { return 0; }");
    std::vector<Token> tokens = lexer.tokenize();
    ASSERT_EQ(tokens.size(), 10);
}

TEST(LexerTests, TokenizeBasicTypes) {
    Lexer lexer("int x = 42;");
    std::vector<Token> tokens = lexer.tokenize();
    ASSERT_EQ(tokens.size(), 6);
    ASSERT_EQ(tokens[0].type, TokenType::IDENTIFIER);
    ASSERT_EQ(tokens[1].type, TokenType::IDENTIFIER);
    ASSERT_EQ(tokens[2].type, TokenType::EQUAL);
    ASSERT_EQ(tokens[3].type, TokenType::INTEGER);
}

TEST(LexerTests, TokenizeWithWhitespace) {
    Lexer lexer("  int  x   =  42  ;  ");
    std::vector<Token> tokens = lexer.tokenize();
    ASSERT_EQ(tokens.size(), 6);
    for (const auto& token : tokens) {
        ASSERT_NE(token.type, TokenType::WHITESPACE);
    }
}

TEST(LexerTests, TokenizeInvalidInput) {
    EXPECT_THROW({
        Lexer lexer("@$%&");
        std::vector<Token> tokens = lexer.tokenize();
    }, std::runtime_error);
}
/* additional lexer test cases */
TEST(LexerTests, MultiplicativeOperators) {
    Lexer lexer("int result = x * y - z / 2;");
    std::vector<Token> tokens = lexer.tokenize();
    ASSERT_EQ(tokens.size(), 12);
}

TEST(LexerTests, CppKeywords) {
    Lexer lexer("if (condition) { return 42; }");
    std::vector<Token> tokens = lexer.tokenize();
    ASSERT_EQ(tokens.size(), 10);
}

TEST(LexerTests, String) {
    Lexer lexer("std::string greeting = \"Hello World\";");
    std::vector<Token> tokens = lexer.tokenize();
    ASSERT_EQ(tokens.size(), 8);
}

TEST(LexerTests, CharLiterals) {
    Lexer lexer("char ch = \'A\';");
    std::vector<Token> tokens = lexer.tokenize();
    ASSERT_EQ(tokens.size(), 6);
}

TEST(LexerTests, StringCharLiterals) {
    Lexer lexer("std::string greeting = \"Hello World\"; char ch = \'A\';");
    std::vector<Token> tokens = lexer.tokenize();
    ASSERT_EQ(tokens.size(), 13);
}

TEST(LexerTests, IdentifierDigits) {
    Lexer lexer("cpp var123 = x42 + a1b2c3;");
    std::vector<Token> tokens = lexer.tokenize();
    ASSERT_EQ(tokens.size(), 8);
}

TEST(LexerTests, TokenizeSpecialCharacters) {
    EXPECT_THROW({
        Lexer lexer("@variable $amount %value &name");
        std::vector<Token> tokens = lexer.tokenize();
    }, std::runtime_error);
}

TEST(LexerTests, EmptyString) {
    Lexer lexer("");
    std::vector<Token> tokens = lexer.tokenize();
    ASSERT_EQ(tokens.size(), 1);
}

TEST(LexerTests, TokenizeNonASCII) {
    EXPECT_THROW({
        Lexer lexer("你好, 世界\nαβγδε");
        std::vector<Token> tokens = lexer.tokenize();
    }, std::runtime_error);
}

TEST(LexerTests, LineEndings) {
    Lexer lexer("Line 1\r\nLine 2\nLine 3");
    std::vector<Token> tokens = lexer.tokenize();
    ASSERT_EQ(tokens.size(), 7);
}

TEST(LexerTests, BigNumber) {
    Lexer lexer("int bigNumber = 12345678901234567890;");
    std::vector<Token> tokens = lexer.tokenize();
    ASSERT_EQ(tokens.size(), 6);
}

TEST(LexerTests, EscapedCharacters) {
    Lexer lexer("std::string message = \"Hello\nWorld\";");
    std::vector<Token> tokens = lexer.tokenize();
    ASSERT_EQ(tokens.size(), 8);
}