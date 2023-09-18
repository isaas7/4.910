#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <stdexcept>
#include "../../src/lexer/lexer.h"

class ASTNode;

class Parser {
public:
    Parser(const std::vector<Token>& tokens);

    ASTNode* parseVariableDeclaration();
    ASTNode* parseAssignment();

private:
    const std::vector<Token>& tokens;
    size_t current;

    Token consume(TokenType type);
};

#endif // PARSER_H
