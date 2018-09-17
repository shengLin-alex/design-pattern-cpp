#include "visitor.h"

Employee::Employee(std::string name, double income, int vacationDays) : _name(name), _income(income), _vacationDays(vacationDays)
{
}

void Employee::accept(Visitor *visitor)
{
    visitor->visit(this);
}

std::string Employee::getName()
{
    return this->_name;
}

double Employee::getIncome()
{
    return this->_income;
}

int Employee::getVacationDays()
{
    return this->_vacationDays;
}

void Employee::setIncome(double newIncome)
{
    this->_income = newIncome;
}

void Employee::setVacationDays(int newVacationDays)
{
    this->_vacationDays = newVacationDays;
}

void IncomeVisitor::visit(Element* element)
{
    Employee* employee = dynamic_cast<Employee*>(element);
    employee->setIncome(employee->getIncome() * 1.10);
    std::cout << employee->getName() << "'s new income: " << employee->getIncome() << std::endl;
}

void VacationVisitor::visit(Element* element)
{
    Employee* employee = dynamic_cast<Employee*>(element);
    employee->setVacationDays(employee->getVacationDays() + 3);
    std::cout << employee->getName() << "'s new vacation days:" << employee->getVacationDays() << std::endl;
}

Employees::~Employees()
{
    for(Employee* employee : this->_employees)
    {
        delete employee;
    }
}

void Employees::attach(Employee* employee)
{
    this->_employees.push_back(employee);
}

void Employees::detach(Employee* employee)
{
    this->_employees.remove(employee);
}

void Employees::accept(Visitor* visitor)
{
    for(Employee* employee : this->_employees)
    {
        employee->accept(visitor);
    }
}