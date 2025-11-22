 #include "AdminManager.h"
#include "Client.h"
#include "FileManager.h"

void AdminManager::printEmployeeMenu() {
    cout << "\n========== Admin Menu ==========" << endl;
    cout << "1. Add New Client" << endl;
    cout << "2. List All Clients" << endl;
    cout << "3. Search for Client" << endl;
    cout << "4. Edit Client Info" << endl;
    cout << "5. Add New Employee" << endl;
    cout << "6. List All Employees" << endl;
    cout << "7. Search for Employee" << endl;
    cout << "8. Edit Employee Info" << endl;
    cout << "9. Display My Info" << endl;
    cout << "10. Update My Password" << endl;
    cout << "0. Logout" << endl;
    cout << "================================" << endl;
    cout << "Enter your choice: ";
}

Admin* AdminManager::login(int id, string password) {
    vector<Admin> admins = FilesHelper::getAdmins();

    for (int i = 0; i < admins.size(); i++) {
        if (admins[i].getId() == id && admins[i].getPassword() == password) {
            cout << "Login successful! Welcome " << admins[i].getName() << endl;
            Admin* admin = new Admin(admins[i].getId(), admins[i].getName(),
                admins[i].getPassword(), admins[i].getSalary());
            setLoginAdmin(admin);
            return admin;
        }
    }

    cout << "Invalid ID or password." << endl;
    return nullptr;
}

bool AdminManager::AdminOptions(Admin* admin) {
    int choice;
    printEmployeeMenu();
    cin >> choice;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number." << endl;
        return true;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  
    switch (choice) {
        case 1: {
            int id = FilesHelper::getLast(CLIENT_LAST_ID_FILE) + 1;
            double  balance;
            string name, password;
 
            cout << "\n--- Add New Client ---" << endl;
            cout << "Id: " << id << " [read Only]";

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter Name: ";
            getline(cin, name);

            cout << "Enter Password: ";
            getline(cin, password);

            cout << "Enter Balance: ";
            cin >> balance;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            try {
                Client newClient(id, name, password, balance);
                admin->addClient(newClient);
                FilesHelper::saveClient(newClient);
                cout << "Client added successfully!" << endl;
            }
            catch (const invalid_argument& e) {
                cout << "Error: " << e.what() << endl;
            }
            break;
        }

        case 2: {
           
            admin->listClients();
            break;
        }

        case 3: {
            int searchId;
            cout << "\nEnter Client ID to search: ";
            cin >> searchId;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            Client* client = admin->getClientById(searchId);
            if (client != nullptr) {
                client->display();
            } else {
                cout << "Client not found." << endl;
            }
            break;
        }

        case 4: {
            int editId;
            string name, password;
            double balance;

            cout << "\n--- Edit Client Info ---" << endl;
            cout << "Enter Client ID: ";
            cin >> editId;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter New Name: ";
            getline(cin, name);

            cout << "Enter New Password: ";
            getline(cin, password);

            cout << "Enter New Balance: ";
            cin >> balance;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            admin->editClient(editId, name, password, balance);
            break;
        }

        case 5: {
            int id = FilesHelper::getLast(EMPLOYEE_LAST_ID_FILE) + 1;

            string name, password;
            double salary;

            cout << "\n--- Add New Employee ---" << endl;
            cout << "Id: " << id << " [read Only]";


            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter Name: ";
            getline(cin, name);

            cout << "Enter Password: ";
            getline(cin, password);

            cout << "Enter Salary: ";
            cin >> salary;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            try {
                Employee newEmployee(id, name, password, salary);
                admin->addEmployee(newEmployee);
                FilesHelper::saveEmployee(newEmployee);
                cout << "Employee added successfully!" << endl;
            }
            catch (const invalid_argument& e) {
                cout << "Error: " << e.what() << endl;
            }
            break;
        }

        case 6: {
            admin->listEmployees();
            break;
        }

        case 7: {
            int searchId;
            cout << "\nEnter Employee ID to search: ";
            cin >> searchId;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            Employee* employee = admin->getEmpById(searchId);
            if (employee != nullptr) {
                employee->display();
            } else {
                cout << "Employee not found." << endl;
            }
            break;
        }

        case 8: {
            int editId;
            string name, password;
            double salary;

            cout << "\n--- Edit Employee Info ---" << endl;
            cout << "Enter Employee ID: ";
            cin >> editId;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter New Name: ";
            getline(cin, name);

            cout << "Enter New Password: ";
            getline(cin, password);

            cout << "Enter New Salary: ";
            cin >> salary;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            admin->editEmployee(editId, name, password, salary);
            break;
        }

        case 9: {
            admin->display();
            break;
        }

        case 10: {
            string newPassword;
            cout << "\nEnter New Password: ";
            getline(cin, newPassword);

            try {
                admin->setPassword(newPassword);
                cout << "Password updated successfully!" << endl;
                FilesHelper::updateAdminInFile(admin);
            }
            catch (const invalid_argument& e) {
                cout << "Error: " << e.what() << endl;
            }
            break;
        }

        case 0: {
            logOut(admin);
            return false;
        }

        default: {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }

    return true;
}

void AdminManager::logOut(Admin* admin) {
    FileManager fileManger;
    fileManger.removeAllClients();
    for (int i = 0; i < admin->getAllClients().size(); i++) {
        fileManger.addClient(admin->getAllClients()[i]);
    }
    fileManger.removeAllEmployees();
    for (int i = 0; i < admin->getAllEmployees().size(); i++) {
        fileManger.addEmployee(admin->getAllEmployees()[i]);
    }
    cout << "\nLogging out ... Goodbye!" << admin->getName() << endl;
}

void AdminManager::setLoginAdmin(Admin* admin) {
    FileManager fileManager;
    vector<Client> clients = fileManager.getAllClients();
    for (Client& client : clients) {
        admin->addClient(client);
    }
    vector<Employee> emps = fileManager.getAllEmployees();
    for (Employee& Employee : emps) {
        admin->addEmployee(Employee);
    }
}