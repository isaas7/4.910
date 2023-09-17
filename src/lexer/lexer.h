#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>

enum class TokenType {
    IDENTIFIER,
    INTEGER,
    PLUS, 
    MINUS,
    SEMICOLON,
    END_OF_FILE,
    // ...
};

struct Token {
    TokenType type;
    std::string lexeme;

    Token(TokenType t, const std::string& l) : type(t), lexeme(l) {}
};

class Lexer {
public:
    Lexer(const std::string& sourceCode);
    std::vector<Token> tokenize();
private:
    Token scanToken();
    char advance();
    char peek();
    bool isAtEnd();

    std::string source;
    std::vector<Token> tokens;
    int start = 0;
    int current = 0;
    int line = 1;
};

#endif //LEXER_H