#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include "Validation.h"
using namespace std;

class Person {
protected:
    int id;
    string name;
    string password;

public:
    Person() {
        id = 0;
        name = "";
        password = "";
    }
    Person(int id, string name, string password) {
        this->id = id;
        this->name = name;
        this->password = password;
    }
    int getId() {
        return id;
    }
    string getName() {
        return name;
    }
    string getPassword() {
        return password;
    }
    void setId(int id) {
        this->id = id;
    }
    bool setName(const string& name) {
        try {
            Validation::validateName(name);
            this->name = name;
            return true;
        }
        catch (const invalid_argument& e) {
            cout << "Error: " << e.what() << endl;
            return false;
        }
    }
    bool setPassword(const string& password) {
        try {
            Validation::validatePassword(password);
            this->password = password;
            return true;
        }
        catch (const invalid_argument& e) {
            cout << "Error: " << e.what() << endl;
            return false;
        }
    }
};



