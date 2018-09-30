#ifndef BUILDER_H
#define BUILDER_H

#include <vector>
#include <cstring>
#include <iostream>
#include <stdexcept>

// define a product class, set some property to product.
class FoodSet
{
    public:
        FoodSet();
        void add(std::string, int);
        void show();

    private:
        std::vector<std::string> _foodName;
        std::vector<int> _price;
};

// define a interface for build food set.
class Builder
{
    public:
        virtual void BuildCoolDish() = 0;
        virtual void BuildDrink() = 0;
        virtual void BuildMainDish() = 0;
        virtual FoodSet* GetFoodSet() = 0;
};

// define a food set builder for build chinese food set
class ChineseSetBuilder : public Builder
{
    public:
        ChineseSetBuilder();
        ~ChineseSetBuilder();
        void BuildCoolDish();
        void BuildDrink();
        void BuildMainDish();
        FoodSet *GetFoodSet();

    private:
        FoodSet* _foodSet;
};

// define a food set builder for build japanese food set
class JapaneseSetBuilder : public Builder
{
    public:
        JapaneseSetBuilder();
        ~JapaneseSetBuilder();
        void BuildCoolDish();
        void BuildDrink();
        void BuildMainDish();
        FoodSet *GetFoodSet();

    private:
        FoodSet *_foodSet;
};

// define a class for manage which builder be used.
class FoodSetManager
{
    public:
        FoodSetManager();
        ~FoodSetManager();
        FoodSet* BuildFoodSet(char choice);

    private:
        Builder* _builder;
};

#endif