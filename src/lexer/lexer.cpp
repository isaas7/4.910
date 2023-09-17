#include "lexer.h"

Lexer::Lexer(const std::string& sourceCode) : source(sourceCode) {
}

std::vector<Token> Lexer::tokenize() {
    while(!isAtEnd()) {
        start = current;

        Token token = scanToken();

        if(!token.lexeme.empty()) {
            tokens.push_back(token);
        }
    }

    tokens.push_back(Token(TokenType::END_OF_FILE, ""));

    return tokens;
}

Token Lexer::scanToken() {
    char c = advance();

    while (c == ' ' || c == '\t' || c == '\n' || c == '\r') {
        c = advance();
    }

    switch(c) {
        case '+':
            return Token(TokenType::PLUS, "+");
        case '-':
            return Token(TokenType::PLUS, "+");
        case ';':
            return Token(TokenType::PLUS, "+");
        default:
            if(isalpha(c)) {
                return scanIdentifier();
            } else if (isdigit(c)) {
                return scanNumber();
            } else {
                // Handle unrecognized character or errors
                return Token(TokenType::INVALID, std::string(1, c));
            }
    }
}

Token Lexer::scanIdentifier() {
    while(isalnum(peek())) {
        advance();
    }

    return Token(TokenType::IDENTIFIER, source.substr(start, current - start));
}

Token Lexer::scanNumber() {
    while(isdigit(peek())) {
        advance();
    }

    return Token(TokenType::INTEGER, source.substr(start, current - start));
}

char Lexer::advance() {
    char currentChar = source[current];
    current++;

    if(currentChar == '\n') {
        line++;
    }

    return currentChar;
}

char Lexer::peek() {
    if(isAtEnd()) {
        return '\0';
    }

    return source[current];
}

bool Lexer::isAtEnd() {
    return current >= source.length();
}