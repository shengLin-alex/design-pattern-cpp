#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <string>

// define a class and save expression for interpreting
class Context
{
    public:
        Context(std::string);
        std::string getExpression();

    private:
        std::string _expression;
};

// define a interface for interpret
class Interpreter
{
    public:
        virtual int interpret(std::string) = 0;
};

// for interpret first character is lowercase
class LowercaseInterpreterImpl : public Interpreter
{
    public:
        int interpret(std::string);
};

// for interpret first character is uppercase
class UppercaseInterpreterImpl : public Interpreter
{
    public:
        int interpret(std::string);
};

#endif