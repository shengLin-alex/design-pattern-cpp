#include "facade.h"

void Cpu::freeze()
{
    std::cout << "CPU freeze" << std::endl;
}

void Cpu::execute()
{
    std::cout << "CPU execute" << std::endl;
}

void HardDrive::read()
{
    std::cout << "HardDrive read" << std::endl;
}

void Memory::load()
{
    std::cout << "Memory load" << std::endl;
}

Computer::Computer()
{
    this->_cpu = new Cpu();
    this->_hardDrive = new HardDrive();
    this->_memory = new Memory();
}

Computer::~Computer()
{
    delete this->_cpu, this->_hardDrive, this->_memory;
}

void Computer::startComputer()
{
    this->_cpu->freeze();
    this->_memory->load();
    this->_hardDrive->read();
    this->_cpu->execute();

    std::cout << "Computer is running now." << std::endl;
}