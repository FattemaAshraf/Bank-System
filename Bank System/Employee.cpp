#include "Employee.h"

vector<Employee> Employee::allEmployees;

void Employee::addEmployee(const Employee& employee) {
    allEmployees.push_back(employee);
}

Employee* Employee::getEmpById(int id) {
    for (int i = 0; i < allEmployees.size(); i++) {
        if (allEmployees[i].getId() == id) {
            return &allEmployees[i];
        }
    }
    return nullptr;
}

vector<Employee>& Employee::getAllEmployees() {
    return allEmployees;
}
