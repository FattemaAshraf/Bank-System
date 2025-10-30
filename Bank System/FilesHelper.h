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
};
 