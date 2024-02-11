#ifndef COBALT_FRONTEND_SEMANTIC_RESOLVER_RESOLVER_HPP_
#define COBALT_FRONTEND_SEMANTIC_RESOLVER_RESOLVER_HPP_

#include "Resolver/Scope.hpp"

#include "AST/BaseNode.hpp"

#include <deque>

namespace Cobalt::Semantic {

class Resolver {
public:
    ~Resolver();
    AST::BaseNode* resolve(const std::string& name);
    void insert(const std::string& name, AST::BaseNode* node);
    void pushScope();
    void popScope();

private:
    std::deque<Scope*> scopes_;
};

}

#endif