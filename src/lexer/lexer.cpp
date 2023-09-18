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
    // Skip leading whitespace
    while (current < source.length() && (source[current] == ' ' || source[current] == '\t' || source[current] == '\n' || source[current] == '\r')) {
        current++;
    }

    if (isAtEnd()) {
        return Token(TokenType::END_OF_FILE, "");
    }

    char c = source[current++];

    switch(c) {
        case '+':
            return Token(TokenType::PLUS, "+");
        case '-':
            return Token(TokenType::MINUS, "-");
        case ';':
            return Token(TokenType::SEMICOLON, ";");
        case '=':
            return Token(TokenType::EQUAL, "=");
        case '(':
            return Token(TokenType::LEFT_PAREN, "(");
        case ')':
            return Token(TokenType::RIGHT_PAREN, ")");
        case '{':
            return Token(TokenType::LEFT_BRACE, "{");  // Recognize left brace
        case '}':
            return Token(TokenType::RIGHT_BRACE, "}"); // Recognize right brace
        default:
            if(isalpha(c)) {
                return scanIdentifier();
            } else if (isdigit(c)) {
                return scanNumber();
            } else {
                throw std::runtime_error("Lexer Error: Unrecognized character '" + std::string(1, c) + "'");
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