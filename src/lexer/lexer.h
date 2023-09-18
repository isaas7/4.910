#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>
#include <stdexcept>

enum class TokenType {
    IDENTIFIER,
    INTEGER,
    PLUS, 
    MINUS,
    STAR,
    SLASH,
    SEMICOLON,
    END_OF_FILE,
    ERROR,
    WHITESPACE,
    EQUAL,
    LEFT_PAREN,
    RIGHT_PAREN,
    LEFT_BRACE,
    RIGHT_BRACE, 
    DOUBLE_COLON,
    STRING,
    CHARACTER,
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
    Token scanIdentifier();
    Token scanNumber();
    Token scanString();
    Token scanCharacterLiteral();
    char advance();
    char peek();
    bool isAtEnd();
    bool isComment();

    std::string source;
    std::vector<Token> tokens;
    int start = 0;
    int current = 0;
    int line = 1;
};

#endif //LEXER_H