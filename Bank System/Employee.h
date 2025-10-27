#pragma once
#include "Person.h"
class Employee :
    public Person
{
protected:
    double salary;
public:
    Employee() : Person() {
        salary = 5000.0;
    }

    Employee(int id, string name, string password, double salary) : Person(id, name, password) {
        try {
            Validation::validateSalary(salary);
            this->salary = salary;
        }
        catch (const invalid_argument& e) {
            cout << "Error in constructor: " << e.what() << endl;
            cout << "Setting salary to minimum (5000 EGP)" << endl;
            this->salary = 5000.0;
        }
    }

    void setSalary(double s) {
        try {
            Validation::validateSalary(s);
            salary = s;
        }
        catch (const invalid_argument& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    double getSalary() {
        return salary;
    }

    void display() {
        cout << "========== Employee Information ==========" << endl;
        cout << "ID: " << getId() << endl;
        cout << "Name: " << getName() << endl;
        cout << "Password: " << getPassword() << endl;
        cout << "Salary: " << getSalary() << " EGP" << endl;
        cout << "==========================================" << endl;
    }

    void displayEmp() {
        display();
    }
};

