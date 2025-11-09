#pragma once
#include "DataSourceInterface.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "FilesHelper.h"
#include <iostream>
#include <vector>
using namespace std;

#define CLIENTS_FILE "Clients.txt"
#define EMPLOYEES_FILE "Employees.txt"
#define ADMINS_FILE "Admins.txt"
#define CLIENT_LAST_ID_FILE "Client_Last_ID.txt"
#define EMPLOYEE_LAST_ID_FILE "Employee_Last_ID.txt"
#define ADMIN_LAST_ID_FILE "Admin_Last_ID.txt"

class FileManager :public DataSourceInterface {
public:
    void addClient(Client &obj) override {
        FilesHelper::saveClient(obj);
    }

    void addEmployee(Employee &obj) override {
        FilesHelper::saveEmployee(obj);
    }

    void addAdmin(Admin &obj) override {
        FilesHelper::saveAdmin(obj);
    }

     vector<Client> getAllClients() override {
        return FilesHelper::getClients();
    }


    
    vector<Employee> getAllEmployees()override {
        vector<Employee> employees = FilesHelper::getEmployees();
        return employees;
    }
  

   vector<Admin> getAllAdmins()override {
       vector<Admin> admins = FilesHelper::getAdmins();
 
        return admins;
    }

    void removeAllClients() {
      FilesHelper::clearFile(CLIENTS_FILE, CLIENT_LAST_ID_FILE);
    }

    void removeAllEmployees() {
        FilesHelper::clearFile(EMPLOYEES_FILE, EMPLOYEE_LAST_ID_FILE);
    }

    void removeAllAdmins()  {
       FilesHelper::clearFile(ADMINS_FILE, ADMIN_LAST_ID_FILE);
    }
};
class DataInitializer {
public:
    static void initializeData() {
        FileManager fileManager;
         vector<Client> clients = fileManager.getAllClients();
        for (auto& client : clients) {
            Employee::addClient(client);
        }
        Employee::listClients();
         vector<Employee> employees = fileManager.getAllEmployees();
        for (auto& emp : employees) {
            Admin::addEmployee(emp);
        }
        Admin::listEmployees();

    }
};