#pragma once
#include <string>
#include <vector>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"

using namespace std;
class FilesHelper
{
public:
    static void saveLast(string fileName, int id);
    static int getLast(string fileName);

    static void saveClient(Client c);
    static void saveEmployee(Employee e);
    static void saveAdmin(Admin a);

    static vector<Client> getClients();
    static vector<Employee> getEmployees();
    static vector<Admin> getAdmins();

    static void clearFile(string fileName, string lastIdFile);
};