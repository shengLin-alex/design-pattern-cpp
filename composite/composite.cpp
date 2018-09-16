#include "composite.h"

/**
 * Abstract base class Component, no need for implemention.
 */
Component::Component(std::string name) : _name(name)
{
}

Component::~Component()
{
}

void Component::add(Component* component)
{
}

void Component::remove(Component* component)
{
}

std::string Component::getName()
{
    return this->_name;
}

Component* Component::getChild(int index)
{
    return nullptr;
}

Leaf::Leaf(std::string name) : Component(name)
{
}

Leaf::~Leaf()
{
}

void Leaf::operation()
{
    std::cout << "Leaf::" << this->_name << "::operation()" << std::endl;
}

Composite::Composite(std::string name) : Component(name)
{
}

Composite::~Composite()
{
    for(Component* component : this->_components)
    {
        std::cout << component->getName() << "::delete" << std::endl;
        delete component;
    }
}

void Composite::operation()
{
    std::cout << "Composite::" << this->_name << "::operation()" << std::endl;
    for(Component* component : this->_components)
    {
        component->operation();
    }
}

void Composite::add(Component* component)
{
    this->_components.push_back(component);
}

void Composite::remove(Component* component)
{
    std::vector<Component*>::iterator itr = this->_components.begin();
    while(itr != this->_components.end())
    {
        if (*itr == component)
        {
            this->_components.erase(itr);

            break;
        }
    }
}

Component* Composite::getChild(int index)
{
    if (index < 0 || index >= this->_components.size())
    {
        return nullptr;
    }

    return this->_components[index];
}