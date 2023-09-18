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

class VariableDeclarationNodeEdgeTest : public ::testing::Test {
};

TEST_F(VariableDeclarationNodeEdgeTest, EmptyIdentifier) {
    ASSERT_THROW({
        VariableDeclarationNode node("", 42);
    }, std::runtime_error);
}


TEST_F(VariableDeclarationNodeEdgeTest, NegativeValue) {
    VariableDeclarationNode node("x", -123);
    EXPECT_EQ(node.getType(), NodeType::VariableDeclaration);
    EXPECT_EQ(node.getIdentifier(), "x");
    EXPECT_EQ(node.getValue(), -123);
}

TEST_F(VariableDeclarationNodeEdgeTest, LongIdentifier) {
    // Test with a very long identifier
    std::string longIdentifier(10000, 'a'); // 10,000 'a' characters
    VariableDeclarationNode node(longIdentifier, 42);
    EXPECT_EQ(node.getType(), NodeType::VariableDeclaration);
    EXPECT_EQ(node.getIdentifier(), longIdentifier);
    EXPECT_EQ(node.getValue(), 42);
}

// Test fixture for AssignmentNode
class AssignmentNodeEdgeTest : public ::testing::Test {
};

TEST_F(AssignmentNodeEdgeTest, NullExpression) {
    EXPECT_THROW({
        ASTNode* nullExpression = nullptr;
        AssignmentNode node("x", nullExpression);
    }, std::runtime_error);
}

TEST_F(AssignmentNodeEdgeTest, EmptyIdentifier) {
    ASTNode* expression = new VariableDeclarationNode("y", 123);
    ASSERT_THROW({
        AssignmentNode node("", expression);
    }, std::runtime_error);
}

class VariableDeclarationNodeNegativeTest : public ::testing::Test {
};

TEST_F(VariableDeclarationNodeNegativeTest, EmptyIdentifier) {
    // Attempt to create a VariableDeclarationNode with an empty identifier (should not be allowed)
    EXPECT_THROW({
        VariableDeclarationNode node("", 42);
    }, std::runtime_error);
}

TEST_F(VariableDeclarationNodeNegativeTest, NegativeValue) {
    // Attempt to create a VariableDeclarationNode with a negative value (may or may not be allowed, depending on your language's rules)
    EXPECT_NO_THROW({
        VariableDeclarationNode node("x", -123);
    });
}

// Add more negative test cases as needed

// Test fixture for AssignmentNode
class AssignmentNodeNegativeTest : public ::testing::Test {
};

TEST_F(AssignmentNodeNegativeTest, NullExpression) {
    // Attempt to create an AssignmentNode with a null expression (should not be allowed)
    EXPECT_THROW({
        ASTNode* nullExpression = nullptr;
        AssignmentNode node("x", nullExpression);
    }, std::runtime_error);
}

TEST_F(AssignmentNodeNegativeTest, EmptyIdentifier) {
    // Attempt to create an AssignmentNode with an empty identifier (may or may not be allowed, depending on your language's rules)
    EXPECT_THROW({
        ASTNode* expression = new VariableDeclarationNode("y", 123);
        AssignmentNode node("", expression);
    }, std::runtime_error);
}