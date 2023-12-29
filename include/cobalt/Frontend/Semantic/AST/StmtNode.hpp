#ifndef COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_NODE_STMTNODE_HPP_
#define COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_NODE_STMTNODE_HPP_

#include "AST/BaseNode.hpp"
#include "AST/TypeNode.hpp"

#include <string>
#include <utility>
#include <vector>

namespace Cobalt::AST {

// TODO: Cobalt::AST::StmtNode

struct StmtNode : public BaseNode { };

struct IfNode : public StmtNode {
    IfNode(ExprNode* cond_, StmtNode* body_)
        : condition(cond_)
        , body(body_)
    {
    }
    [[nodiscard]] NodeKind kind() const override { return NK_If; }
    ~IfNode() override;
    ExprNode* condition;
    StmtNode* body;
};

struct WhileNode : public StmtNode {
    WhileNode(ExprNode* cond_, StmtNode* body_)
        : condition(cond_)
        , body(body_)
    {
    }
    [[nodiscard]] NodeKind kind() const override { return NK_While; }
    ~WhileNode() override;
    ExprNode* condition;
    StmtNode* body;
};

// TODO: AST::ForNode
struct ForNode : public StmtNode { };

struct ReturnNode : public StmtNode {
    explicit ReturnNode(ExprNode* expr_)
        : expr(expr_)
    {
    }
    ~ReturnNode() override;
    [[nodiscard]] NodeKind kind() const override { return NK_Return; }
    ExprNode* expr;
};

struct BreakNode : public StmtNode {
    BreakNode() = default;
    ~BreakNode() override = default;
    [[nodiscard]] NodeKind kind() const override { return NK_Break; }
};

struct ContinueNode : public StmtNode {
    ContinueNode() = default;
    ~ContinueNode() override = default;
    [[nodiscard]] NodeKind kind() const override { return NK_Continue; }
};

// TODO: Block Node
struct BlockNode : public StmtNode {
    BlockNode() = default;
    ~BlockNode() override;
    [[nodiscard]] NodeKind kind() const override { return NK_Block; }
    std::vector<StmtNode*> stmts;
};

struct VariableDefNode : public StmtNode {
    VariableDefNode(TypeNode* tpnode, std::string name_)
        : var_type(tpnode)
        , name { std::move(name_) }
    {
    }
    ~VariableDefNode() override;
    [[nodiscard]] NodeKind kind() const override { return NK_VariableDef; }
    TypeNode* var_type;
    const std::string name;
};

struct FuncDefNode : public StmtNode {
    FuncDefNode(TypeNode* tpnode, std::string name_)
        : ret_type(tpnode)
        , name { std::move(name_) }
    {
    }
    ~FuncDefNode() override;
    [[nodiscard]] NodeKind kind() const override { return NK_FuncDef; }
    TypeNode* ret_type;
    const std::string name;
    std::vector<std::pair<std::string, TypeNode*>> params;
};
}

#endif