#ifndef AST_H
#define AST_H

#include <string>
#include <vector>

enum class NodeType {
    VariableDeclaration,
    Assignment,
};

class ASTNode {
public:
    ASTNode(NodeType type);
    virtual ~ASTNode();
    
    NodeType getType() const;

    virtual void print(int indent = 0) const = 0;
private:
    NodeType type;
};

class VariableDeclarationNode : public ASTNode {
public:
    VariableDeclarationNode(const std::string& identifier, int value);
    void print(int indent = 0) const override;
    int getValue() const;
    const std::string& getIdentifier() const;
private:
    std::string identifier;
    int value;
};

class AssignmentNode : public ASTNode {
public:
    AssignmentNode(const std::string& identifier, ASTNode* expression);
    ~AssignmentNode();
    void print(int indent = 0) const override;
    ASTNode* getExpression() const;
    const std::string& getIdentifier() const;
    
private:
    std::string identifier;
    ASTNode* expression;
};

#endif // AST_H