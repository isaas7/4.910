#include <gtest/gtest.h>
#include "../../src/lexer/lexer.h"

TEST(LexerTests, TokenizeSimpleCode) {
    Lexer lexer("int main() { return 0; }");
    std::vector<Token> tokens = lexer.tokenize();
    ASSERT_EQ(tokens.size(), 15);
}