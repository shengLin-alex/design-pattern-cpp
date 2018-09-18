#include "builder.h"

FoodSet::FoodSet()
{
}

void FoodSet::add(std::string name, int price)
{
    this->_foodName.push_back(name);
    this->_price.push_back(price);
}

void FoodSet::show()
{
    std::cout << "food list:" << std::endl;
    for(int i = 0; i < this->_foodName.size(); i++)
    {
        std::cout << this->_foodName[i] << ";" << this->_price[i] << std::endl;
    }
}

ChineseSetBuilder::ChineseSetBuilder()
{
    this->_foodSet = new FoodSet();
}

ChineseSetBuilder::~ChineseSetBuilder()
{
    if (this->_foodSet != nullptr)
    {
        delete this->_foodSet;
    }
}

void ChineseSetBuilder::BuildCoolDish()
{
    this->_foodSet->add("Chinese CoolDish", 35);
}

void ChineseSetBuilder::BuildDrink()
{
    this->_foodSet->add("Green tea", 20);
}

void ChineseSetBuilder::BuildMainDish()
{
    this->_foodSet->add("Fried rice", 90);
}

FoodSet* ChineseSetBuilder::GetFoodSet()
{
    return this->_foodSet;
}

JapaneseSetBuilder::JapaneseSetBuilder()
{
    this->_foodSet = new FoodSet();
}

JapaneseSetBuilder::~JapaneseSetBuilder()
{
    if (this->_foodSet != nullptr)
    {
        delete this->_foodSet;
    }
}

void JapaneseSetBuilder::BuildCoolDish()
{
    this->_foodSet->add("Japanese CoolDish", 35);
}

void JapaneseSetBuilder::BuildDrink()
{
    this->_foodSet->add("Japanese Sake", 50);
}

void JapaneseSetBuilder::BuildMainDish()
{
    this->_foodSet->add("Ramen", 100);
}

FoodSet *JapaneseSetBuilder::GetFoodSet()
{
    return this->_foodSet;
}

FoodSetManager::FoodSetManager()
{
    this->_builder = nullptr;
}

FoodSetManager::~FoodSetManager()
{
    if (this->_builder != nullptr)
    {
        delete _builder;
    }
}

FoodSet* FoodSetManager::BuildFoodSet(char choice)
{
    // decide which builder to use.
    if (choice == 'A')
    {
        this->_builder = new ChineseSetBuilder();
    }
    else if (choice == 'B')
    {
        this->_builder = new JapaneseSetBuilder();
    }

    // build food set
    this->_builder->BuildCoolDish();
    this->_builder->BuildDrink();
    this->_builder->BuildMainDish();

    return this->_builder->GetFoodSet();
}