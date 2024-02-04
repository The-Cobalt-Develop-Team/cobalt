#ifndef COBALT_FRONTEND_SEMANTIC_AST_ASTTRAVELLER_HPP_
#define COBALT_FRONTEND_SEMANTIC_AST_ASTTRAVELLER_HPP_

#include "AST/ASTRootNode.hpp"
#include "AST/BaseNode.hpp"
#include "AST/ExprNode.hpp"
#include "AST/StmtNode.hpp"
#include "AST/TypeNode.hpp"

namespace Cobalt::AST {

template <typename TravellerImpl>
class BaseASTTraveller {
public:
    template <typename NodeType>
    void visit(NodeType* node)
    {
        static_cast<TravellerImpl*>(this)->beforeVisit(node);
        static_cast<TravellerImpl*>(this)->visitImpl(node);
        static_cast<TravellerImpl*>(this)->afterVisit(node);
    }
    template <>
    void visit(BaseNode* ptr)
    {
        switch (ptr->kind()) {
#define REG_NODE(x)                              \
    case NK_##x: {                               \
        this->visit(static_cast<x##Node*>(ptr)); \
        break;                                   \
    }
#include "ASTNodeList.inc"
        default: {
            break;
        }
        }
    }
    template <typename NodeType>
    void beforeVisit(NodeType*) { }
    template <typename NodeType>
    void visitImpl(NodeType*) { }
    template <typename NodeType>
    void afterVisit(NodeType*) { }

protected:
};

}

#endif