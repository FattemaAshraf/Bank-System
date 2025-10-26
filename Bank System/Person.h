#pragma once
#include <iostream>
#include <string>
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
        if (name.length() < 3 || name.length() > 20) {
            cout << "name must be between 3 and 20 characters" << endl;
            return false;
        }
        for (int i = 0; i < name.length(); i++) {
            char c = name[i];
            if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == ' '))) {
                cout << "write letters only" << endl;
                return false;
            }
        }
        this->name = name;
        return true;
    }
    bool setPassword(const string& password) {
        if (password.length() < 8 || password.length() > 20) {
            cout << "password must be 8 to 20 characters" << endl;
            return false;
        }
        for (int i = 0; i < password.length(); i++) {
            if (password[i] == ' ') {
                cout << "write password without spaces" << endl;
                return false;
            }
        }
        this->password = password;
        return true;
    }
};



