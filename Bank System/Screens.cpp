#include "Screens.h"
#include "clientManager.h"
#include "EmployeeManager.h"
#include "AdminManager.h"
#include <limits>

void Screens::bankName() {
    cout << "\n========================================================" << endl;
    cout << "                   BANK MANAGEMENT SYSTEM               " << endl;
    cout << "========================================================" << endl;
}

void Screens::welcome() {
    cout << "\n         Welcome to Our Banking System!" << endl;
    cout << "         Your trusted financial partner" << endl;
    cout << "\n========================================================\n" << endl;
}

void Screens::loginOptions() {
    cout << "\n==================== Login Menu =======================" << endl;
    cout << "  [1] Login as Client" << endl;
    cout << "  [2] Login as Employee" << endl;
    cout << "  [3] Login as Admin" << endl;
    cout << "  [0] Exit" << endl;
    cout << "========================================================" << endl;
}

int Screens::loginAs() {
    int choice;
    cout << ">> Enter your choice: ";
    cin >> choice;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return -1;
    }

    return choice;
}

void Screens::invalid(int c) {
    cout << "\n[ERROR] Invalid choice: " << c << endl;
    cout << "Please select a valid option (0-3)." << endl;
}

void Screens::logout() {
    cout << "\n========================================================" << endl;
    cout << "          Thank you for using our services!" << endl;
    cout << "                   Goodbye!" << endl;
    cout << "========================================================\n" << endl;
}

void Screens::loginScreen(int c) {
    int id;
    string password;

    if (c < 1 || c > 3) {
        invalid(c);
        return;
    }

    cout << "\n>> Enter ID: ";
    cin >> id;
    cout << ">> Enter Password: ";
    cin >> password;

    if (c == 1) {
        Client* client = ClientManager::login(id, password);
        if (client) {
            ClientManager::clientOptions(client);
            delete client;
        }
    }
    else if (c == 2) {
        Employee* employee = EmployeeManager::login(id, password);
        if (employee) {
            EmployeeManager::employeeOptions(employee);
            delete employee;
        }
    }
    else if (c == 3) {
        Admin* admin = AdminManager::login(id, password);
        if (admin) {
            AdminManager::AdminOptions(admin);
            delete admin;
        }
    }
}

void Screens::runApp() {
    bankName();
    welcome();

    bool running = true;
    while (running) {
        loginOptions();
        int choice = loginAs();

        if (choice == 0) {
            running = false;
            logout();
        } else {
            loginScreen(choice);
        }
    }
}