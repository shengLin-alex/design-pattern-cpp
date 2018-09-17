#ifndef COMPOSITE_H
#define COMPOSITE_H

#include <vector>
#include <string>
#include <iostream>

/**
 * Abstract base class, Component
 */
class Component
{
    public:

        // interface, no implemention
        virtual void operation() = 0;

        // virtual void, implemention is "do nothing"
        virtual void add(Component*);
        virtual void remove(Component*);
        virtual Component* getChild(int index);
        virtual ~Component();

        std::string getName();

    protected:
        Component(std::string);
        std::string _name;
};

/**
 * Leaf, a component that doesn't contain child components.
 */
class Leaf : public Component
{
    public:

        // A Leaf only implement operation.
        virtual void operation();
        Leaf(std::string);
        ~Leaf();
};

/**
 * Composite is component that can contain child.
 */
class Composite : public Component
{
    public:
        
        // implement all functions.
        void operation();
        void add(Component*);
        void remove(Component*);
        Component* getChild(int index);
        Composite(std::string);
        ~Composite();

    private:
        std::vector<Component*> _components;
};

#endif // COMPOSITE_H