#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class EmployeeManager
{
    static Employee* loginEmployee;

public:
    EmployeeManager();
    ~EmployeeManager();

    static void printEmployeeMenu();
    static bool employeeOptions(Employee* employee);
    static void newClient();
    static void searchForClient();
    static void listAllClients();
    static void editClientInfo();
    static void updatePassword();
    static Employee* login(int id, string password);
    static void setLoginEmp(Employee* emp);
};

