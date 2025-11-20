#include "Person.h"
#include "Validation.h"

 Person::Person() {
    id = 0;
    name = "";
    password = "";
}

 Person::Person(int id, string name, string password) {
    this->id = id;
    this->name = name;
    this->password = password;
}

 int Person::getId() {
    return id;
}

 string Person::getName() {
    return name;
}

 string Person::getPassword() {
    return password;
}

 void Person::setId(int id) {
    this->id = id;
}

 bool Person::setName(const string& name) {
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

 bool Person::setPassword(const string& password) {
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