#include "ast.h"
#include <iostream> // For debugging purposes

ASTNode::ASTNode(NodeType type) : type(type) {}

ASTNode::~ASTNode() {}

NodeType ASTNode::getType() const {
    return type;
}

VariableDeclarationNode::VariableDeclarationNode(const std::string& identifier, int value)
    : ASTNode(NodeType::VariableDeclaration), identifier(identifier), value(value) {
    if (identifier.empty()) {
        throw std::runtime_error("VariableDeclarationNode Error: Identifier cannot be empty");
    }
}

void VariableDeclarationNode::print(int indent) const {
    for (int i = 0; i < indent; i++) {
        std::cout << "  "; // Adjust the indentation as needed
    }
    std::cout << "VariableDeclarationNode: " << identifier << " = " << value << std::endl;
}

int VariableDeclarationNode::getValue() const {
    return value;
}

const std::string& VariableDeclarationNode::getIdentifier() const {
    return identifier;
}

AssignmentNode::AssignmentNode(const std::string& identifier, ASTNode* expression)
    : ASTNode(NodeType::Assignment), identifier(identifier), expression(expression) {
    if (identifier.empty() || expression == nullptr) {
            throw std::runtime_error("AssignmentNode Error: Identifier or Expression cannot be empty or nullptr");
    }
}

AssignmentNode::~AssignmentNode() {
    delete expression;
}

void AssignmentNode::print(int indent) const {
    for (int i = 0; i < indent; i++) {
        std::cout << "  "; // Adjust the indentation as needed
    }
    std::cout << "AssignmentNode: " << identifier << " = " << std::endl;
    expression->print(indent + 1);
}

ASTNode* AssignmentNode::getExpression() const {
    return expression;
}

const std::string& AssignmentNode::getIdentifier() const {
    return identifier;
}



// Implement additional derived classes as needed
