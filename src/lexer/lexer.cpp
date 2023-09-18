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
    while (current < source.length() && (source[current] == ' ' || source[current] == '\t' || source[current] == '\n' || source[current] == '\r' || isComment())) {
        if (source[current] == '/') {
            if (current + 1 < source.length() && source[current + 1] == '/') {
                while (current < source.length() && source[current] != '\n') {
                    current++;
                }
            } else if (current + 1 < source.length() && source[current + 1] == '*') {
                current += 2;
                while (current < source.length() - 1 && !(source[current] == '*' && source[current + 1] == '/')) {
                    current++;
                }
                if (current < source.length() - 1) {
                    current += 2;
                } else {
                    throw std::runtime_error("Lexer Error: Unterminated multi-line comment");
                }
            }
        }
        current++;
    }

    if (isAtEnd()) {
        return Token(TokenType::END_OF_FILE, "");
    }

    char c = source[current++];

    switch(c) {
        case '\'':
            return scanCharacterLiteral();
        case '"':
            return scanString();
        case '+':
            return Token(TokenType::PLUS, "+");
        case '-':
            return Token(TokenType::MINUS, "-");
        case '*':
            return Token(TokenType::STAR, "*");
        case '/':
            return Token(TokenType::SLASH, "/");
        case ';':
            return Token(TokenType::SEMICOLON, ";");
        case '=':
            return Token(TokenType::EQUAL, "=");
        case '(':
            return Token(TokenType::LEFT_PAREN, "(");
        case ')':
            return Token(TokenType::RIGHT_PAREN, ")");
        case '{':
            return Token(TokenType::LEFT_BRACE, "{");
        case '}':
            return Token(TokenType::RIGHT_BRACE, "}");
        case ':':
            if (peek() == ':') {
                current++;
                return Token(TokenType::DOUBLE_COLON, "::");
            } else {
                throw std::runtime_error("Lexer Error: Unrecognized character '" + std::string(1, c) + "'");
            }
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

bool Lexer::isComment() {
    return (source[current] == '/' && (current + 1 < source.length() && (source[current + 1] == '/' || source[current + 1] == '*')));
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

Token Lexer::scanString() {
    int stringStart = current - 1; // Remember the starting position of the string

    while (peek() != '"' && !isAtEnd()) {
        if (peek() == '\\') {
            current++;
            if (isAtEnd()) {
                throw std::runtime_error("Lexer Error: Unterminated string literal");
            }
            current++;
        } else {
            current++;
        }
    }

    if (isAtEnd()) {
        throw std::runtime_error("Lexer Error: Unterminated string literal");
    }

    current++;
    std::string lexeme = source.substr(stringStart, current - stringStart);
    return Token(TokenType::STRING, lexeme);
}

Token Lexer::scanCharacterLiteral() {
    char c = advance();
    if (c == '\\') {
        c = advance();
    }
    if (peek() != '\'') {
        throw std::runtime_error("Lexer Error: Invalid character literal");
    }
    advance();
    return Token(TokenType::CHARACTER, std::string(1, c));
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