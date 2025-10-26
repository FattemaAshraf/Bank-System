#pragma once
#include "Employee.h"
class Admin : public Employee {
public:
   
    Admin() : Employee() {}

    Admin(int id, string name, string password, double salary)
        : Employee(id, name, password, salary) {}

    
    void display() override {
        cout << "========== Admin Information ==========" << endl;
        Person::display();
        cout << "Salary: " << salary << " EGP" << endl;
        cout << "=======================================" << endl;
    }
};