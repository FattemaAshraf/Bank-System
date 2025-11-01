#pragma once
#include <string>
#include "Client.h"
#include <fstream>
#include <iostream>
#include "Employee.h"
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
		ifstream  file(fileName, ios::app);
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

	// methods e, f, g, h >>

	static void getClients() {
		ifstream file("Clients.txt");
		if (!file.is_open()) {
			cerr << "error: could not open Clients.txt" << endl;
			return;
		}
		string line;
		cout << "\n--- Clients List ---\n";
		while (getline(file, line)) {
			cout << line << endl;
		}
		file.close();
		cout << "--------------------\n";
	}

	static void getEmployees() {
		ifstream file("Employees.txt");
		if (!file.is_open()) {
			cerr << "error: could not open Employees.txt" << endl;
			return;
		}
		string line;
		cout << "\n--- Employees List ---\n";
		while (getline(file, line)) {
			cout << line << endl;
		}
		file.close();
		cout << "----------------------\n";
	}

	static void getAdmins() {
		ifstream file("Admins.txt");
		if (!file.is_open()) {
			cerr << "error: Could not open Admins.txt" << endl;
			return;
		}
		string line;
		cout << "\n--- Admins List ---\n";
		while (getline(file, line)) {
			cout << line << endl;
		}
		file.close();
		cout << "-------------------\n";
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
 