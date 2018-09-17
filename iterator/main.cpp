#include <iostream>
#include "iterator.h"

int main(int argc, char** argv)
{
    Aggregate<int>* aggr = new ConcreteAggregate<int>();
    Iterator<int>* itr = aggr->createIterator();

    for(itr->first(); !itr->isDone(); itr->next())
    {
        std::cout << *(itr->currentItem()) << std::endl;
    }

    delete itr;
    delete aggr;

    return 0;
}