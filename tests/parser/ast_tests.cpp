#include <gtest/gtest.h>
#include "../../src/parser/ast.h"

// Test fixture for VariableDeclarationNode
class VariableDeclarationNodeTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Initialize a VariableDeclarationNode for testing
        variableDeclarationNode = new VariableDeclarationNode("x", 42);
    }

    void TearDown() override {
        delete variableDeclarationNode;
    }

    VariableDeclarationNode* variableDeclarationNode;
};

TEST_F(VariableDeclarationNodeTest, GetType) {
    EXPECT_EQ(variableDeclarationNode->getType(), NodeType::VariableDeclaration);
}

TEST_F(VariableDeclarationNodeTest, IdentifierAndValue) {
    EXPECT_EQ(variableDeclarationNode->getIdentifier(), "x");
    EXPECT_EQ(variableDeclarationNode->getValue(), 42);
}

// Test fixture for AssignmentNode
class AssignmentNodeTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Initialize an AssignmentNode for testing
        ASTNode* expression = new VariableDeclarationNode("y", 123);
        assignmentNode = new AssignmentNode("x", expression);
    }

    void TearDown() override {
        delete assignmentNode;
    }

    AssignmentNode* assignmentNode;
};

TEST_F(AssignmentNodeTest, GetType) {
    EXPECT_EQ(assignmentNode->getType(), NodeType::Assignment);
}

TEST_F(AssignmentNodeTest, IdentifierAndExpression) {
    EXPECT_EQ(assignmentNode->getIdentifier(), "x");

    ASTNode* expression = assignmentNode->getExpression();
    EXPECT_EQ(expression->getType(), NodeType::VariableDeclaration);
    VariableDeclarationNode* varDeclNode = dynamic_cast<VariableDeclarationNode*>(expression);
    EXPECT_NE(varDeclNode, nullptr);
    if (varDeclNode) {
        EXPECT_EQ(varDeclNode->getIdentifier(), "y");
        EXPECT_EQ(varDeclNode->getValue(), 123);
    }
}