#pragma once
#include "Employee.h"
class Admin : public Employee {
public:

    Admin() : Employee() {}

    Admin(int id, string name, string password, double salary)
        : Employee(id, name, password, salary) {}


    void display() override {
        cout << "========== Admin Information ==========" << endl;
        cout << "ID: " << getId() << endl;
        cout << "Name: " << getName() << endl;
        cout << "Password: " << getPassword() << endl;
        cout << "Salary: " << getSalary() << " EGP" << endl;
        cout << "=======================================" << endl;
    }
};