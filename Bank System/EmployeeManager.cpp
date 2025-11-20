#include "Admin.h"
#include "Client.h"
#include "Employee.h"
#include "EmployeeManager.h"
 #include "FileManager.h"
Employee* EmployeeManager::loginEmployee = nullptr;

 EmployeeManager::EmployeeManager() {
    loginEmployee = nullptr;
}

 EmployeeManager::~EmployeeManager() {
    delete loginEmployee;
}

 void EmployeeManager::printEmployeeMenu() {
    cout << "\n===================================================================================================================" << endl;
    cout << "                                                EMPLOYEE DASHBOARD                                                  " << endl;
    cout << "====================================================================================================================" << endl;
    cout << endl;
    cout << "  +------------------------+  +--------------------------+  +----------------------------+  +------------------------+ " << endl;
    cout << "  |  [1]  Add New Client   |  |  [2]  Search for Client  |  |  [3]  List All Clients     |  |  [4]  Edit Client Info | " << endl;
    cout << "  +------------------------+  +--------------------------+  +----------------------------+  +------------------------+ " << endl;
    cout << endl;
    cout << "  +------------------------+  +--------------------------+  +----------------------------+" << endl;
    cout << "  |   [5]  Display My Info |  |  [6]  Update My Password |  |   [7]  Logout              |" << endl;
    cout << "  +------------------------+  +--------------------------+  +----------------------------+" << endl;
    cout << endl;
    cout << "====================================================================================================================" << endl;
    cout << ">> Enter your choice: ";
}

 bool EmployeeManager::employeeOptions(Employee* employee) {
    if (employee == nullptr) {
        cout << "Error: Invalid employee." << endl;
        return false;
    }

    int choice;
    printEmployeeMenu();
    cin >> choice;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Invalid input. Please enter a number." << endl;
        return true;
    }

    switch (choice) {
    case 1:
        newClient();
        break;
    case 2:
        searchForClient();
        break;
    case 3:
        listAllClients();
        break;
    case 4:
        editClientInfo();
        break;
    case 5:
        loginEmployee->display();
        break;
    case 6:
        updatePassword();
        break;
    case 7:
        cout << "\nLogging out... Goodbye!" << endl;
        return false;  
    default:
        cout << "Invalid choice. Please try again." << endl;
        break;
    }

    return true;  
}

 void EmployeeManager::newClient() {
    int id, balance;
    string name, password;
    cout << "Id: ";
    cin >> id;
    cout << "name: ";
    cin >> name;
    cout << "password: ";
    cin >> password;
    cout << "balance: ";
    cin >> balance;
    Client client(id, name, password, balance);
    loginEmployee->addClient(client);
}

 void EmployeeManager::searchForClient() {
    int id;
    cout << "Id: ";
    cin >> id;
    Client* client = loginEmployee->getClientById(id);
    if (client != nullptr) {
        client->display();
    }
    else {
        cout << "Client not found." << endl;
    }
}

 void EmployeeManager::listAllClients() {
    loginEmployee->listClients();
}

 void EmployeeManager::editClientInfo() {
    int id, balance;
    string name, password;
    cout << "Id: ";
    cin >> id;
    cout << "name: ";
    cin >> name;
    cout << "password: ";
    cin >> password;
    cout << "balance: ";
    cin >> balance;
    loginEmployee->editClient(id, name, password, balance);
}

 void EmployeeManager::updatePassword() {
    string newPassword;
    cout << "new password: ";
    cin >> newPassword;
    loginEmployee->updatePassword(loginEmployee->getId(), loginEmployee->getPassword(), newPassword);
}

 Employee* EmployeeManager::login(int id, string password) {
    FileManager fileManager;
    vector<Employee> allEmployees = fileManager.getAllEmployees();

    for (int i = 0; i < allEmployees.size(); i++) {
        if (allEmployees[i].getId() == id && allEmployees[i].getPassword() == password) {
            cout << "\nWelcome: " << allEmployees[i].getName() << endl;
            setLoginEmp(&allEmployees[i]);
            printEmployeeMenu();
            return &allEmployees[i];
        }
    }
    return nullptr;
}

 void EmployeeManager::setLoginEmp(Employee* emp) {
    loginEmployee = emp;
    FileManager fileManager;
    vector<Client> clients = fileManager.getAllClients();
    for (Client& client : clients) {
        loginEmployee->addClient(client);
    }
}