#ifndef COBALT_FRONTEND_SEMANTIC_AST_BASENODE_HPP_
#define COBALT_FRONTEND_SEMANTIC_AST_BASENODE_HPP_


#include <ostream>
#include <vector>

namespace Cobalt::AST {

typedef enum {
    NK_ASTRoot,

    NK_Type,
    NK_SimpleType,
    NK_FuncType,
    NK_ComplexType,
    NK_END_Type,

    NK_StructDef,
    NK_AliasDef,

    NK_Expr,
    NK_Assign,
    NK_BinaryOp,
    NK_UnaryOp,
    NK_Cast,
    NK_Condition,
    NK_ConstExpr,
    NK_FuncCall,
    NK_END_Expr,

    NK_Stmt,
    NK_If,
    NK_While,
    NK_For,
    NK_Return,
    NK_Break,
    NK_Continue,
    NK_Block,
    NK_VariableDef,
    NK_FuncDef,
    NK_END_Stmt
} NodeKind;

typedef enum {
    AST_AddOp,
    AST_SubOp,
    AST_TimesOp,
    AST_DivOp,
    AST_ModOp,
    AST_GEQOp,
    AST_GreaterOp,
    AST_LEQOp,
    AST_LessOp,
    AST_EqualOp,
    AST_NEqualOp,
    AST_BitAndOp,
    AST_BitOrOp,
    AST_BitXorOp,
    AST_LShiftOp,
    AST_RShiftOp,
    AST_LogicalAndOp,
    AST_LogicalOrOp,
} BinaryOpType;

typedef enum {
    AST_BitNotOp,
    AST_LogicalNotOp,
    AST_AddressOp,
} UnaryOpType;

struct BaseNode {
    [[nodiscard]] virtual NodeKind kind() const = 0;
    virtual void dump(std::ostream& os) const = 0;
    virtual ~BaseNode();
};

struct ASTRootNode : public BaseNode {
    [[nodiscard]] NodeKind kind() const override { return NK_ASTRoot; };
    std::vector<BaseNode*> children;
    ~ASTRootNode() override
    {
        for (auto ptr : children)
            delete ptr;
    }
};

struct TypeNode;
struct SimpleTypeNode;
struct FuncTypeNode;
struct ComplexTypeNode;

struct StructDefNode;
struct AliasDefNode;

struct ExprNode;
struct AssignNode;
struct BinaryOpNode;
struct UnaryOpNode;
struct CaseNode;
struct ConditionNode;
struct FuncCallNode;

struct StmtNode;
struct IfNode;
struct WhileNode;
struct ForNode;
struct ReturnNode;
struct BreakNode;
struct ContinueNode;
struct BlockNode;
struct VariableDefNode;
struct FuncDefNode;
}

#endif