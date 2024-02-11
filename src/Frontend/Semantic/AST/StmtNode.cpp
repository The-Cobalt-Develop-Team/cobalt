#include "AST/StmtNode.hpp"
#include "AST/ExprNode.hpp"
#include "AST/TypeNode.hpp"

namespace Cobalt::AST {

IfNode::~IfNode()
{
    delete condition;
    delete body;
}

WhileNode::~WhileNode()
{
    delete condition;
    delete body;
}

ReturnNode::~ReturnNode()
{
    delete expr;
}

BlockNode::~BlockNode()
{
    for (auto stmt : stmts)
        delete stmt;
}

VariableDefNode::~VariableDefNode()
{
    delete var_type;
}

FuncDefNode::~FuncDefNode()
{
    delete ret_type;
}

}