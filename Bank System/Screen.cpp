#include "Screen.h"
#include "ClientManager.h"
#include "AdminManager.h"
#include "EmployeeManager.h"

////d. e. f. g methods >> 

// LoginAs ---------------------
int Screen::loginAs() {
    int choice;
    cout << "Enter your choice: " << endl;
    cout << "\n1.Admin\n2.Employee\n3.Client" << endl;
    cin >> choice;
    return choice;
}

// Invalid choice ---------------------
void Screen::invalid(int c) {
    cout << "Invalid choice: " << c << ". Please try again.\n";
}

// --------------------- Logout ---------------------
void Screen::logout() {
    cout << "You have been logged out successfully.\n";
}

// --------------------- LoginScreen ---------------------
void Screen::loginScreen(int c) {
    switch (c) {
    case 1: { // Admin
        int id; 
        string password;
        cout << "===== Admin Login =====\n";
        cout << "Enter ID: "; cin>> id;
        cout << "Enter Password: ";  cin >> password;

        Admin* admin = AdminManager::login(id, password);
        if (admin) {
            AdminManager::AdminOptions(admin);
            delete admin;
        }
        break;
    }
    case 2: { // Employee
        int id; string password;
        cout << "===== Employee Login =====\n";
        cout << "Enter ID: ";  cin >> id;
        cout << "Enter Password: ";  cin >> password;

        Employee* emp = EmployeeManager::login(id, password);
        if (emp) {
            //EmployeeManager::employeeOptions(emp);
            delete emp;
        }
        break;
    }
    case 3: { // Client
        int id; 
        string password;
        cout << "===== Client Login =====\n";
        cout << "Enter ID: ";  cin >> id;
        cout << "Enter Password: ";  cin >> password;

        Client* client = ClientManager::login(id, password);
        if (client) {
            ClientManager::clientOptions(client);
            delete client;
        }
        break;
    }
    case 0:
        cout << "Exiting application...\n";
        break;
    default:
        invalid(c);
        break;
    }
}