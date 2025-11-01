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
        FilesHelper::saveEmployee(obj);
    }

     vector<Client> getClients() override {
        return FilesHelper::getClients();
    }


    
    vector<Employee> getEmployees() {
        vector<Employee> employees = FilesHelper::getEmployees();
        return employees;
    }
  

   vector<Admin> getAdmins()override {
    
        return admins;
    }

    void removeAllClients() {
   /*     FilesHelper::clearFile(CLIENTS_FILE, CLIENT_LAST_ID_FILE);*/
    }

    void removeAllEmployees() {
        //F/*ilesHelper::clearFile(EMPLOYEES_FILE, EMPLOYEE_LAST_ID_FILE);*/
    }

    void removeAllAdmins()  {
      /*  FilesHelper::clearFile(ADMINS_FILE, ADMIN_LAST_ID_FILE);*/
    }
};
