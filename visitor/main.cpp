#include "visitor.h"

int main(int argc, char** argv)
{
    Employees* empolyees = new Employees();
    empolyees->attach(new Employee("Jack", 35000.0, 14));
    empolyees->attach(new Employee("Sam", 45000.0, 15));

    empolyees->accept(new IncomeVisitor());
    empolyees->accept(new VacationVisitor());

    return 0;
}