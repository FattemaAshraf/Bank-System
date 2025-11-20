#pragma once
#include "Employee.h"
#include <iostream>  
using namespace std;

class Admin : public Employee {
    static vector<Employee> allEmployees;

public:

    Admin() : Employee() {}

    Admin(int id, string name, string password, double salary)
        : Employee(id, name, password, salary) {}

    virtual ~Admin();


    static void addEmployee(const Employee& employee);
    static Employee* getEmpById(int id);
    static vector<Employee>& getAllEmployees();
    static void listEmployees();
    static void editEmployee(int id, string name, string password, double salary);

};