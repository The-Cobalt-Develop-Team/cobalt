#ifndef COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_NODE_EXPRNODE_HPP_
#define COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_NODE_EXPRNODE_HPP_

#include "BaseNode.hpp"

#include <string>

namespace Cobalt::AST {

struct ExprNode : public BaseNode {
};

struct AssignNode : public ExprNode {
    [[nodiscard]] NodeKind kind() const override { return NK_Assign; }
    AssignNode(ExprNode* lhs_, ExprNode* rhs_)
        : lhs(lhs_)
        , rhs(rhs_)
    {
    }
    ~AssignNode() override;
    ExprNode *lhs, *rhs;
};

struct BinaryOpNode : public ExprNode {
    [[nodiscard]] NodeKind kind() const override { return NK_BinaryOp; }
    BinaryOpNode(ExprNode* lhs_, BinaryOpType op_, ExprNode* rhs_)
        : lhs(lhs_)
        , rhs(rhs_)
        , op(op_)
    {
    }
    ~BinaryOpNode() override;
    ExprNode *lhs, *rhs;
    BinaryOpType op;
};

struct UnaryOpNode : public ExprNode {
    [[nodiscard]] NodeKind kind() const override { return NK_UnaryOp; }
    UnaryOpNode(UnaryOpType op_, ExprNode* expr_)
        : op(op_)
        , expr(expr_)

    {
    }
    ~UnaryOpNode() override;
    UnaryOpType op;
    ExprNode* expr;
};

struct CastNode : public ExprNode {
    [[nodiscard]] NodeKind kind() const override { return NK_Cast; }
    CastNode(TypeNode* type_, ExprNode* expr_)
        : type(type_)
        , expr(expr_)
    {
    }
    ~CastNode() override;
    TypeNode* type;
    ExprNode* expr;
};

struct ConditionNode : public ExprNode {
    [[nodiscard]] NodeKind kind() const override { return NK_Condition; }
    ConditionNode(ExprNode* cond_, ExprNode* state1_, ExprNode* state2_)
        : cond(cond_)
        , state1(state1_)
        , state2(state2_)
    {
    }
    ~ConditionNode() override;
    ExprNode *cond, *state1, *state2;
};

// TODO: ConstExprNode
struct ConstExprNode : public ExprNode { };

struct FuncCallNode : public ExprNode {
    [[nodiscard]] NodeKind kind() const override { return NK_FuncCall; }
    explicit FuncCallNode(std::string func_)
        : func { std::move(func_) }
    {
    }
    ~FuncCallNode() override;
    const std::string func;
    std::vector<ExprNode*> params;
};

}

#endif