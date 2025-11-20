#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

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

    void setSalary(double s);
    double getSalary();

    virtual void display();
    void displayEmp();

    void addClient(const Client& client);
    Client* getClientById(int id);
    vector<Client>& getAllClients();
    void listClients();
    void editClient(int id, string name, string password, double balance);
    void updatePassword(int id, string oldPassword, string newPassword);
};

