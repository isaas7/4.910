#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>

enum class TokenType {

};

struct Token {
    TokenType type;
    std::string lexeme;
};

class Lexer {
public:
    Lexer(const std::string& sourceCode);
    std::vector<Token> tokenize();
private:
    Token scanToken();
};

#endif //LEXER_H