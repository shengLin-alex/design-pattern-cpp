#ifndef FACADE_H
#define FACADE_H

#include <iostream>
#include <cstring>

// define some computer unit
class Cpu
{
    public:
        void freeze();
        void execute();
};

class HardDrive
{
    public:
        void read();
};

class Memory
{
    public:
        void load();
};

// define a facade class, a computer
class Computer
{
    public:
        Computer();
        ~Computer();
        void startComputer();

    private:
        Cpu* _cpu;
        HardDrive* _hardDrive;
        Memory* _memory;
};

#endif