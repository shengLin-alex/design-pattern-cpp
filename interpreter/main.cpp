#include <regex>
#include <iostream>
#include "interpreter.h"

int main(int argc, char** argv)
{
    std::regex reg("^[a-z][1-9][0-9]*$");
    std::string input;
    Interpreter* interpreter = nullptr;
    std::getline(std::cin, input);

    if (std::regex_match(input, reg))
    {
        interpreter = new LowercaseInterpreterImpl();
    }
    else
    {
        interpreter = new UppercaseInterpreterImpl();
    }

    std::cout << interpreter->interpret(input) << std::endl;

    delete interpreter;

    return 0;
}