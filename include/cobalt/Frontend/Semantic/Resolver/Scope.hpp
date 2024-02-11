#ifndef COBALT_FRONTEND_SEMANTIC_RESOLVER_SCOPE_HPP_
#define COBALT_FRONTEND_SEMANTIC_RESOLVER_SCOPE_HPP_

#include "AST/BaseNode.hpp"

#include <map>
#include <string>

namespace Cobalt::Semantic {

class Scope {
public:
    AST::BaseNode* find(const std::string& name);
    void insert(const std::string& name, AST::BaseNode* node);

private:
    std::map<std::string, AST::BaseNode*> map_;
};

}

#endif