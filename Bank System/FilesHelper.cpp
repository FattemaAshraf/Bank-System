#include "FilesHelper.h"
#include "Parser.h"
#include <fstream>
#include <iostream>

using namespace std;

 void FilesHelper::saveLast(string fileName, int id) {
    ofstream file(fileName, ios::app);
    if (!file.is_open()) {
        cerr << "Error: Could not open " << fileName << endl;
        return;
    }
    file << "id:" << id << endl;
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