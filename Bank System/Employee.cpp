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

void Employee::listEmployees() {
    if (allEmployees.size() == 0) {
        cout << "No employees found." << endl;
        return;
    }

    cout << "\n===== All Employees =====" << endl;
    for (int i = 0; i < allEmployees.size(); i++) {
        allEmployees[i].display();
        cout << "----------------------" << endl;
    }
}

void Employee::editEmployee(int id, string name, string password, double salary) {
    Employee* employee = getEmpById(id);

    if (employee == nullptr) {
        cout << "Employee not found." << endl;
        return;
    }

    try {
        Validation::validateName(name);
        Validation::validatePassword(password);
        Validation::validateSalary(salary);

        employee->setName(name);
        employee->setPassword(password);
        employee->setSalary(salary);

        cout << "Employee updated successfully." << endl;
    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }
}
