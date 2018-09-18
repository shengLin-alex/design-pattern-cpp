#include "interpreter.h"

Context::Context(std::string expression) : _expression(expression)
{
}

std::string Context::getExpression()
{
    return this->_expression;
}

int LowercaseInterpreterImpl::interpret(std::string expression)
{
    std::string target = expression.substr(1);
    int parse = std::stoi(target);

    return parse * 2;
}

int UppercaseInterpreterImpl::interpret(std::string expression)
{
    std::string target = expression.substr(1);
    int parse = std::stoi(target);

    return parse / 2;
}