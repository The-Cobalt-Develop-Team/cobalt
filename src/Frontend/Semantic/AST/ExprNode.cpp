#include "AST/ExprNode.hpp"
#include "AST/StmtNode.hpp"
#include "AST/TypeNode.hpp"

namespace Cobalt::AST {

AssignNode::~AssignNode()
{
    delete lhs;
    delete rhs;
}

BinaryOpNode::~BinaryOpNode()
{
    delete lhs;
    delete rhs;
}

UnaryOpNode::~UnaryOpNode()
{
    delete expr;
}

CastNode::~CastNode()
{
    delete type;
    delete expr;
}

ConditionNode::~ConditionNode()
{
    delete cond;
    delete state1;
    delete state2;
}

FuncCallNode::~FuncCallNode()
{
    for (auto ptr : params)
        delete ptr;
}

}
