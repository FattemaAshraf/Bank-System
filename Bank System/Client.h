#pragma once
#include "Person.h"
#include <vector>

class Client : public Person {
    double balance;
public:
    Client() {
        balance = 1500.0;
    }
    Client(int id, string name, string password, double balance) :Person(id, name, password) {
        try {
            Validation::validateBalance(balance);
            this->balance = balance;
        }
        catch (const invalid_argument& e) {
            cout << "Error in constructor: " << e.what() << endl;
            cout << "Setting balance to minimum (1500 EGP)" << endl;
            this->balance = 1500.0;
        }
    }
    double getBalance() {
        return balance;
    }
    void setBalance(double balance) {
        try {
            Validation::validateBalance(balance);
            this->balance = balance;
        }
        catch (const invalid_argument& e) {
            cout << "Error: " << e.what() << endl;
        }
    }
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
        else {
            cout << "invalid amount" << endl;
        }
    }
    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
        }
        else {
            cout << "you don't have enough balance to withdraw" << endl;
        }
    }
    void transferTo(double amount, Client& recipient) {
        if (balance >= amount) {
            balance -= amount;
            recipient.deposit(amount);
            cout << "=====transfered successfuly=====\n" << endl;
        }
        else {
            cout << "====transfer failed====\n" << endl;
        }
    }
    double checkBalance() {
        return balance;
    }
    void display() {
        cout << "Client ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }
 
};



