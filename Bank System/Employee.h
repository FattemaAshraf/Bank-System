#pragma once
#include "Person.h"
#include "Client.h"  
#include <vector>
#include <string>

using namespace std;

class Employee :
    public Person
{
protected:
    double salary;
    static vector<Client> allClients;

public:
    Employee();
    Employee(int id, string name, string password, double salary);
    virtual ~Employee();

    void setSalary(double s);
    double getSalary();

    virtual void display();
    void displayEmp();

    Client& addClient( Client& client);
    Client* getClientById(int id);
    vector<Client>& getAllClients();
    void listClients();
    void editClient(int id, string name, string password, double balance);
    void updatePassword(Employee& employee, string& newPassword);
};

