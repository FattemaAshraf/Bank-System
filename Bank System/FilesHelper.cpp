#include "FilesHelper.h"
#include "Parser.h"
#include "FileManager.h"

#include <fstream>
#include <iostream>

using namespace std;

 void FilesHelper::saveLast(string fileName, int id) {
    clearLastIdFile(fileName);
    ofstream file(fileName, ios::app);
    if (!file.is_open()) {
        cerr << "Error: Could not open " << fileName << endl;
        return;
    }
    file << id << endl;
    file.close();
}

 int FilesHelper::getLast(string fileName) {
    ifstream file(fileName, ios::in);
    if (!file.is_open()) {
        cerr << "Error: Could not open " << fileName << endl;
        return 0;
    }
    int id;
    file >> id;
    file.close();
    return id;
}

 void FilesHelper::saveClient(Client c) {
    ofstream file("Clients.txt", ios::app);
    if (!file.is_open()) {
        cerr << "Error: Could not open Clients.txt" << endl;
        return;
    }
    // Format: id:value,name:value,password:value,balance:value
    file << "id:" << c.getId() << ",name:" << c.getName()
        << ",password:" << c.getPassword() << ",balance:" << c.getBalance() << endl;
    saveLast(CLIENT_LAST_ID_FILE, c.getId());
    file.close();
}

 void FilesHelper::saveEmployee(Employee e) {
    ofstream file("Employees.txt", ios::app);
    if (!file.is_open()) {
        cerr << "Error: Could not open Employees.txt" << endl;
        return;
    }
    // Format: id:value,name:value,password:value,salary:value
    file << "id:" << e.getId() << ",name:" << e.getName()
        << ",password:" << e.getPassword() << ",salary:" << e.getSalary() << endl;
    saveLast(EMPLOYEE_LAST_ID_FILE,  e.getId());

    file.close();
}

 void FilesHelper::saveAdmin(Admin a) {
    ofstream file("Admins.txt", ios::app);
    if (!file.is_open()) {
        cerr << "Error: Could not open Admins.txt" << endl;
        return;
    }
    file << "id:" << a.getId() << ",name:" << a.getName()
        << ",password:" << a.getPassword() << ",salary:" << a.getSalary() << endl;
    saveLast(ADMIN_LAST_ID_FILE, a.getId());

    file.close();
}

 vector<Client> FilesHelper::getClients() {
    vector<Client> clients;
    ifstream file("Clients.txt");
    if (!file.is_open()) {
        cerr << "Error: Could not open Clients.txt" << endl;
        return clients;
    }
    string line;
    while (getline(file, line)) {
        clients.push_back(Parser::parseToClient(line));
    }
    file.close();
    return clients;
}

 vector<Employee> FilesHelper::getEmployees() {
    vector<Employee> employees;
    ifstream file("Employees.txt");
    if (!file.is_open()) {
        cerr << "Error: Could not open Employees.txt" << endl;
        return employees;
    }
    string line;
    while (getline(file, line)) {
        employees.push_back(Parser::parseToEmployee(line));
    }
    file.close();
    return employees;
}

 vector<Admin> FilesHelper::getAdmins() {
    vector<Admin> admins;
    ifstream file("Admins.txt");
    if (!file.is_open()) {
        cerr << "Error: Could not open Admins.txt" << endl;
        return admins;
    }
    string line;
    while (getline(file, line)) {
        admins.push_back(Parser::parseToAdmin(line));
    }
    file.close();
    return admins;
}

 void FilesHelper::clearFile(string fileName, string lastIdFile) {
    ofstream file(fileName, ios::out);
    if (!file.is_open()) {
        cerr << "Error: Could not clear " << fileName << endl;
        return;
    }
    file.close();

    ofstream lastFile(lastIdFile, ios::out);
    if (!lastFile.is_open()) {
        cerr << "Error: Could not reset " << lastIdFile << endl;
        return;
    }
    lastFile << "0";
    lastFile.close();

    cout << "Cleared files: " << fileName << " and reset: " << lastIdFile << endl;
}
 void FilesHelper::clearLastIdFile(string lastIdFile) {
    

     ofstream lastFile(lastIdFile, ios::out);
     if (!lastFile.is_open()) {
         cerr << "Error: Could not reset " << lastIdFile << endl;
         return;
     }
     lastFile << "0";
     lastFile.close();

     //cout << "Cleared files: " << fileName << " and reset: " << lastIdFile << endl;
 }

 void FilesHelper::updateClientInFile(Client* client) {
     if (!client) {
         cerr << "Error: Invalid client pointer" << endl;
         return;
     }

      vector<Client> clients = getClients();
     bool found = false;

      for (int i = 0; i < clients.size(); i++) {
         if (clients[i].getId() == client->getId()) {
             clients[i] = *client;   
             found = true;
             break;
         }
     }

     if (!found) {
         cerr << "Error: Client with ID " << client->getId() << " not found" << endl;
         return;
     }

      ofstream file("Clients.txt", ios::out);
     if (!file.is_open()) {
         cerr << "Error: Could not open Clients.txt for writing" << endl;
         return;
     }
     file.close();

      for (int i = 0; i < clients.size(); i++) {
         ofstream appendFile("Clients.txt", ios::app);
         if (!appendFile.is_open()) {
             cerr << "Error: Could not open Clients.txt for appending" << endl;
             return;
         }
         appendFile << "id:" << clients[i].getId()
             << ",name:" << clients[i].getName()
             << ",password:" << clients[i].getPassword()
             << ",balance:" << clients[i].getBalance() << endl;
         appendFile.close();
     }

  }

 void FilesHelper::updateAdminInFile(Admin* admin) {
     if (!admin) {
         cerr << "Error: Invalid admin pointer" << endl;
         return;
     }

      vector<Admin> admins = getAdmins();
     bool found = false;

     // Find and update the specific admin
     for (int i = 0; i < admins.size(); i++) {
         if (admins[i].getId() == admin->getId()) {
             admins[i] = *admin;  // Update the admin in the vector
             found = true;
             break;
         }
     }

     if (!found) {
         cerr << "Error: Admin with ID " << admin->getId() << " not found" << endl;
         return;
     }

      ofstream file("Admins.txt", ios::out);
     if (!file.is_open()) {
         cerr << "Error: Could not open Admins.txt for writing" << endl;
         return;
     }
     file.close();

     // Rewrite all admins
     for (int i = 0; i < admins.size(); i++) {
         ofstream appendFile("Admins.txt", ios::app);
         if (!appendFile.is_open()) {
             cerr << "Error: Could not open Admins.txt for appending" << endl;
             return;
         }
         appendFile << "id:" << admins[i].getId()
             << ",name:" << admins[i].getName()
             << ",password:" << admins[i].getPassword()
             << ",salary:" << admins[i].getSalary() << endl;
         appendFile.close();
     }

  }