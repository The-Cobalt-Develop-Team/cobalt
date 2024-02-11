#ifndef COBALT_FRONTEND_SEMANTIC_AST_ASTROOTNODE_HPP_
#define COBALT_FRONTEND_SEMANTIC_AST_ASTROOTNODE_HPP_

#include "AST/BaseNode.hpp"
#include <ostream>

namespace Cobalt::AST {
struct ASTRootNode : public BaseNode{
    [[nodiscard]] NodeKind kind() const override { return NK_ASTRoot; };
    void dump(std::ostream&) const override;
    std::vector<BaseNode*> children;
    ~ASTRootNode() override
    {
        for (auto ptr : children)
            delete ptr;
    }
    template <typename TravellerType>
    void visitNext(TravellerType* t)
    {
        for (auto ptr : children) {
            t->visit(ptr);
        }
    }
};
}

#endif