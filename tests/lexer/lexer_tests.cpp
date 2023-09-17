#include <gtest/gtest.h>
#include "../../src/lexer/lexer.h"

TEST(LexerTests, TokenizeSimpleCode) {
    Lexer lexer("int main() { return 0; }");
    std::vector<Token> tokens = lexer.tokenize();
    std::cout << "Actual tokens:\n";
    for (const Token& token : tokens) {
        std::cout << "Type: " << static_cast<int>(token.type) << ", Lexeme: " << token.lexeme << "\n";
    }
    ASSERT_EQ(tokens.size(), 10);
}

// TEST(LexerTests, TokenizeBasicTypes) {
//     Lexer lexer("int x = 42;");
//     std::vector<Token> tokens = lexer.tokenize();
//     ASSERT_EQ(tokens.size(), 9);
//     ASSERT_EQ(tokens[0].type, TokenType::INTEGER);
//     ASSERT_EQ(tokens[1].type, TokenType::IDENTIFIER);
//     //ASSERT_EQ(tokens[2].type, TokenType::EQUAL);
//     ASSERT_EQ(tokens[3].type, TokenType::INTEGER);
// }

TEST(LexerTests, TokenizeWithWhitespace) {
    Lexer lexer("  int  x   =  42  ;  ");
    std::vector<Token> tokens = lexer.tokenize();
    std::cout << "Actual tokens:\n";
    for (const Token& token : tokens) {
        std::cout << "Type: " << static_cast<int>(token.type) << ", Lexeme: " << token.lexeme << "\n";
    }
    ASSERT_EQ(tokens.size(), 4);
    // Ensure no whitespace tokens are generated
    for (const auto& token : tokens) {
        ASSERT_NE(token.type, TokenType::WHITESPACE);
    }
}

// TEST(LexerTests, TokenizeInvalidInput) {
//     Lexer lexer("@$%&");
//     std::vector<Token> tokens = lexer.tokenize();
//     // Ensure that no valid tokens are generated for invalid input
//     ASSERT_EQ(tokens.size(), 0);
// }
