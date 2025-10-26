#pragma once
#include <string>
#include <stdexcept>
using namespace std;

class Validation {
public:

    static void validateName(string name);

    static void validatePassword(string password);

    static void validateBalance(double balance);

    static void validateSalary(double salary);
};
