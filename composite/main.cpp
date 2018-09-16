#include "composite.h"

/**
 * This is a type safety composite pattern demo.
 */
int main(int argc, char** argv)
{
    Composite* root = new Composite("ComRoot");
    root->add(new Leaf("Leaf_of_Root"));

    Composite* com = new Composite("ComChild");
    Leaf* leafA = new Leaf("Leaf_of_Com_A");
    Leaf* leafB = new Leaf("Leaf_of_Com_B");

    com->add(leafA);
    com->add(leafB);

    root->add(com);
    root->operation();

    com->remove(leafA);
    root->operation();

    delete root;

    return 0;
}