#include "builder.h"

int main(int argc, char** argv)
{
    FoodSetManager* manager = new FoodSetManager();
    char choice;

    std::cin >> choice;
    manager->BuildFoodSet(choice)->show();

    delete manager;
    
    return 0;
}