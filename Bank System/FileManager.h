#pragma once
#include <iostream>
#include <vector>
#include "DataSourceInterface.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"

using namespace std;

#define CLIENTS_FILE "Clients.txt"
#define EMPLOYEES_FILE "Employees.txt"
#define ADMINS_FILE "Admins.txt"
#define CLIENT_LAST_ID_FILE "Client_Last_ID.txt"
#define EMPLOYEE_LAST_ID_FILE "Employee_Last_ID.txt"
#define ADMIN_LAST_ID_FILE "Admin_Last_ID.txt"

class FileManager : public DataSourceInterface {
public:
    void addClient(Client& obj) override;
    void addEmployee(Employee& obj) override;
    void addAdmin(Admin& obj) override;

    vector<Client> getAllClients() override;
    vector<Employee> getAllEmployees() override;
    vector<Admin> getAllAdmins() override;

    void removeAllClients();
    void removeAllEmployees();
    void removeAllAdmins();
};