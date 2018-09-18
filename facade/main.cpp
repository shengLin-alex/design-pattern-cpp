#include "facade.h"

int main(int argc, char** argv)
{
    Computer* computer = new Computer();
    computer->startComputer();

    delete computer;

    return 0;
}