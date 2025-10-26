#pragma once
#include "Person.h"
class Employee :
    public Person
{
    double salary;
public:
    void setSalary(double s) {
        if (salary >= 5000) {
            salary = s;
        }

    }double getSalary() {
        return salary;
    }
    void displayEmp() {
        cout << "Name: " << getName() << endl;
        cout << "ID: " << getId() << endl;
        cout << "Password: " << getPassword() << endl;
        cout << "Salary: " << getSalary() << endl;
    }
};

