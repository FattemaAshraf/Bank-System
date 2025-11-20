#pragma once
#include <string>
#include <iostream>

using namespace std;

  class Person {
protected:
    int id;
    string name;
    string password;

public:
    Person();
    Person(int id, string name, string password);
    virtual ~Person();

    int getId();
    string getName();
    string getPassword();

    void setId(int id);
    bool setName(const string& name);
    bool setPassword(const string& password);
};