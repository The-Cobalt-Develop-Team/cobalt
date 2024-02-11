#include "Resolver/Scope.hpp"

#include "AST/BaseNode.hpp"

namespace Cobalt::Semantic {

AST::BaseNode* Scope::find(const std::string& name)
{
    auto res = this->map_.find(name);
    if (res == this->map_.end())
        return nullptr;
    return res->second;
}

void Scope::insert(const std::string& name, AST::BaseNode* node)
{
    this->map_.emplace(name, node);
}

}
