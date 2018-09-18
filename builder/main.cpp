#include "builder.h"

int main(int argc, char** argv)
{
    FoodSetManager* manager = new FoodSetManager();
    char choice;

    std::cin >> choice;
    try
    {
        manager->BuildFoodSet(choice)->show();
    }
    catch (const std::exception* exception)
    {
        std::cout << exception->what() << std::endl;
    }

    delete manager;
    
    return 0;
}