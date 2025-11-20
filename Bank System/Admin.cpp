#include "Admin.h"
#include "Validation.h"


vector<Employee> Admin::allEmployees;

void Admin::addEmployee(const Employee& employee) {
    allEmployees.push_back(employee);
}

Employee* Admin::getEmpById(int id) {
    for (int i = 0; i < allEmployees.size(); i++) {
        if (allEmployees[i].getId() == id) {
            return &allEmployees[i];
        }
    }
    return nullptr;
}

vector<Employee>& Admin::getAllEmployees() {
    return allEmployees;
}

void Admin::listEmployees() {
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

void Admin::editEmployee(int id, string name, string password, double salary) {
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

