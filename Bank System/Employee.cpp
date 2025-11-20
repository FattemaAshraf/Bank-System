#include "Admin.h"
#include "Client.h"
#include "Employee.h"
#include "Validation.h"
#include "Person.h"
#include "FileManager.h"
vector<Client> Employee::allClients;

Employee::Employee() : Person() {
    salary = 5000.0;
}

 Employee::Employee(int id, string name, string password, double salary)
    : Person(id, name, password) {
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

 void Employee::setSalary(double s) {
    try {
        Validation::validateSalary(s);
        salary = s;
    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }
}

 double Employee::getSalary() {
    return salary;
}

 void Employee::display() {
    cout << "========== Employee Information ==========" << endl;
    cout << "ID: " << getId() << endl;
    cout << "Name: " << getName() << endl;
    cout << "Password: " << getPassword() << endl;
    cout << "Salary: " << getSalary() << " EGP" << endl;
    cout << "==========================================" << endl;
}

 void Employee::displayEmp() {
    display();
}

void Employee::addClient(const Client& client) {
     
    allClients.push_back(client);
}

Client* Employee::getClientById(int id) {
    for (int i = 0; i < allClients.size(); i++) {
        if (allClients[i].getId() == id) {
            return &allClients[i];
        }
    }
    return nullptr;
}

vector<Client>& Employee::getAllClients() {
    return allClients;
}

void Employee::listClients() {
    if (allClients.size() == 0) {
        cout << "No clients found." << endl;
        return;
    }

    cout << "\n===== All Clients =====" << endl;
    for (int i = 0; i < allClients.size(); i++) {
        allClients[i].display();
        cout << "----------------------" << endl;
    }
}

void Employee::editClient(int id, string name, string password, double balance) {
    Client* client = getClientById(id);

    if (client == nullptr) {
        cout << "Client not found." << endl;
        return;
    }

    try {
        Validation::validateName(name);
        Validation::validatePassword(password);
        Validation::validateBalance(balance);

        client->setName(name);
        client->setPassword(password);
        client->setBalance(balance);

        cout << "Client updated successfully." << endl;
    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }
}
void Employee::updatePassword(int id, string oldPassword, string newPassword) {
    FileManager fileManager;
    vector<Employee> allEmployees = fileManager.getAllEmployees();
    Employee* employee = nullptr;   

    for (int i = 0; i < allEmployees.size(); i++) {
        if (allEmployees[i].getId() == id && allEmployees[i].getPassword() == oldPassword) {  
            employee = &allEmployees[i];
            break;  
        }
    }

    if (employee == nullptr) {
        cout << "Employee not found." << endl;
        return;
    }
    if (oldPassword == newPassword) {
        cout << "same password." << endl;
        return;
    }
    try {
        Validation::validatePassword(newPassword);
        employee->setPassword(newPassword);  
        cout << "Employee password updated successfully." << endl;
        fileManager.removeAllEmployees();
        for (int i = 0; i < allEmployees.size(); i++) {
            fileManager.addEmployee(allEmployees[i]);
        }

    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }
}