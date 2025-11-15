#pragma once
#include "Client.h"
#include "Employee.h"

class EmployeeManager
{
    Employee loginEmployee;
public:
    static void printEmployeeMenu() {
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
    static bool employeeOptions(Employee* employee) {
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
             employee->display();
            break;
        case 6:
            updatePassword();
            break;
        case 7:
            cout << "\nLogging out... Goodbye!" << endl;
            return false; // Return false to logout
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }

        return true; // Return true to continue
    }
    static void newClient();
    static void searchForClient();
    static void listAllClients();
    static void editClientInfo();
    static void updatePassword();
    // i need to make id==> email

    static Employee* login(int id, string password) { 
        vector<Employee>& allEmployees = Admin::getAllEmployees();

        for (int i = 0; i < allEmployees.size(); i++) {
            if (allEmployees[i].getId() == id && allEmployees[i].getPassword() == password) {
                cout << "\nWelcome: " << allEmployees[i].getName() << endl;
                return &allEmployees[i];
            }
        }

        cout << "\nInvalid ID or password." << endl;
        return nullptr;

    };

};

