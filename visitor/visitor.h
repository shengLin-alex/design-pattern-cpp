#ifndef VISITOR_H
#define VISITOR_H

#include <iostream>
#include <string>
#include <list>

// pre-defination
class Element;

// abstract visitor
class Visitor
{
    public:
        virtual void visit(Element*) = 0;
};

// abstract element
class Element
{
    public:
        virtual void accept(Visitor*) = 0;
};

// concrete element
class Employee : public Element
{
    public:
        Employee(std::string, double, int);
        std::string getName();
        double getIncome();
        int getVacationDays();
        void setIncome(double);
        void setVacationDays(int);
        void accept(Visitor*);

      private:
        std::string _name;
        double _income;
        int _vacationDays;
};

// concrete visitor
class IncomeVisitor : public Visitor
{
    public:
        void visit(Element*);
};

// concrete visitor
class VacationVisitor: public Visitor
{
    public:
        void visit(Element *);
};

// object structure(a list or a array of element)
class Employees
{
    public:
        void attach(Employee*);
        void detach(Employee*);
        void accept(Visitor*);
        ~Employees();

    private:
        std::list<Employee*> _employees;
};

#endif