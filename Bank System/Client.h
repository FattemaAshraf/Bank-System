#pragma once
#include "Person.h"
#include <vector>
#include <string>

using namespace std;

class Client : public Person {
    double balance;

public:
    Client();
    Client(int id, string name, string password, double balance);

    double getBalance();
    void setBalance(double balance);
    void deposit(double amount);
    void withdraw(double amount);
    void transferTo(double amount, Client& recipient);
    double checkBalance();
    void display();
    void updatePassword(int id, string oldPassword, string newPassword);
};