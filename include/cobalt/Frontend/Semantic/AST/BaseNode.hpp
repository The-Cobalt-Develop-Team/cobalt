#ifndef COBALT_FRONTEND_SEMANTIC_AST_BASENODE_HPP_
#define COBALT_FRONTEND_SEMANTIC_AST_BASENODE_HPP_

#include <ostream>
#include <vector>

namespace Cobalt::AST {

typedef enum {
#define REG_NODE(x) NK_##x,
#include "ASTNodeList.inc"
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

template <typename NodeType>
struct ASTVisitable : public BaseNode {
    template <typename TravellerType>
    void visit(TravellerType* t)
    {
        static_cast<NodeType*>(this)->beforeVisit(t);
        static_cast<NodeType*>(this)->visitNext(t);
        static_cast<NodeType*>(this)->afterVisit(t);
    }
    template <typename TravellerType>
    void beforeVisit(TravellerType*) { }
    template <typename TravellerType>
    void visitNext(TravellerType*) { }
    template <typename TravellerType>
    void afterVisit(TravellerType*) { }
};

#define REG_NODE(x) struct x##Node;
#include "ASTNodeList.inc"

}

#endif