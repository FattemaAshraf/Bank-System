#pragma once
#include <string>
#include "Client.h"
#include <fstream>
#include <iostream>
#include "Employee.h"
#include "Parser.h"
using namespace std;
 

class FilesHelper
{
 
	  /*  static void saveLast(string fileName, int id)
		static int getLast(string fileName).
		static void saveClient(Client c).
		static void saveEmployee(string fileName, string lastIdFile, Employee e).
		static void getClients().
		static void getEmployees().
		static void getAdmins().
		static void clearFile(string fileName, string lastIdFile).*/
public:
	static void saveLast(string fileName, int id) {
		ofstream file(fileName, ios::app);
		if (!file.is_open()) {
			cerr << "Error: Could not open " << fileName << endl;
			return;
		}
  		file << "id:" << id  << endl;
		file.close();
	}
	static int getLast(string fileName) {
		ifstream  file(fileName, ios::in);
		if (!file.is_open()) {
			cerr << "Error: Could not open " << fileName << endl;
			return 0;
		}
		int id;
		file >> id;
		file.close();
		return id;
	}
	static void saveClient(Client c)   {
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
	static void saveEmployee(Employee e) {
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
	static void saveAdmin(Admin a) {
		ofstream file("Admins.txt", ios::app);
		if (!file.is_open()) {
			cerr << "Error: Could not open Admins.txt" << endl;
			return;
		}
		file << "id:" << a.getId() << ",name:" << a.getName()
			<< ",password:" << a.getPassword() << ",salary:" << a.getSalary() << endl;
		file.close();
	}
// methods (e, f, g, h) >> 

//client
static vector<Client> getClients() {
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

//employee
static vector<Employee> getEmployees() {
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

//admin
static vector<Admin> getAdmins() {
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
static void clearFile(string fileName, string lastIdFile) {
	ofstream file(fileName, ios::out);
	if (!file.is_open()) {
		cerr << "error: Could not clear " << fileName << endl;
		return;
	}
	file.close();

	ofstream lastFile(lastIdFile, ios::out);
	if (!lastFile.is_open()) {
		cerr << "error: Could not reset " << lastIdFile << endl;
		return;
	}
	lastFile << "0";
	lastFile.close();

	cout << "Cleared files: " << fileName << " and reset: " << lastIdFile << endl;
}
};
