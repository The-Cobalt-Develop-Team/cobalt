#include "Resolver/Resolver.hpp"

#include "AST/BaseNode.hpp"
#include <type_traits>

namespace Cobalt::Semantic {

Resolver::~Resolver()
{
    while (!this->scopes_.empty()) {
        delete scopes_.back();
        scopes_.pop_back();
    }
}

void Resolver::pushScope()
{
    scopes_.emplace_back();
}

void Resolver::popScope()
{
    delete scopes_.back();
    scopes_.pop_back();
}

AST::BaseNode* Resolver::resolve(const std::string& name)
{
    AST::BaseNode* res = nullptr;
    for (auto it = this->scopes_.back(); it != this->scopes_.front(); --it) {
        res = it->find(name);
        if (res != nullptr)
            return res;
    }
    return nullptr;
}

void Resolver::insert(const std::string& name, AST::BaseNode* node)
{
    this->scopes_.back()->insert(name, node);
}

}