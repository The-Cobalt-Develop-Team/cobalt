#ifndef COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_NODE_TYPENODE_HPP_
#define COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_NODE_TYPENODE_HPP_

#include "BaseNode.hpp"

#include <string>
#include <utility>

namespace Cobalt::AST {

// TODO: Type System

struct TypeNode : public BaseNode {
};

struct SimpleTypeNode : public TypeNode {
    [[nodiscard]] NodeKind kind() const override { return NK_SimpleType; };
    ~SimpleTypeNode() override;
    explicit SimpleTypeNode(std::string name_)
        : name { std::move(name_) }
    {
    }
    const std::string name;
};

struct FuncTypeNode : public TypeNode {
    // TODO: Cobalt::AST::FuncTypeNode
};

struct ComplexTypeNode : public TypeNode {
    // TODO: Cobalt::AST::ComplexTypeNode
};

}

#endif