// Bank System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Validation.h"
using namespace std;

int main() {
    cout << "=== Bank System - Validation Testing ===\n\n";

    // Test 1: Validate names
    string name1 = "John";
    string name2 = "AB"; // Too short
    string name3 = "John123"; // Contains numbers
    string name4 = "ThisIsAVeryLongNameExceedingLimit"; // Too long

    cout << "Testing names:\n";

    // Test valid name
    try {
        Validation::validateName(name1);
        cout << "'" << name1 << "' is VALID" << endl;
    } catch (const invalid_argument& e) {
        cout << "'" << name1 << "' is INVALID - " << e.what() << endl;
    }

    // Test short name
    try {
        Validation::validateName(name2);
        cout << "'" << name2 << "' is VALID" << endl;
    } catch (const invalid_argument& e) {
        cout << "'" << name2 << "' is INVALID - " << e.what() << endl;
    }

    // Test name with numbers
    try {
        Validation::validateName(name3);
        cout << "'" << name3 << "' is VALID" << endl;
    } catch (const invalid_argument& e) {
        cout << "'" << name3 << "' is INVALID - " << e.what() << endl;
    }

    // Test long name
    try {
        Validation::validateName(name4);
        cout << "'" << name4 << "' is VALID" << endl;
    } catch (const invalid_argument& e) {
        cout << "'" << name4 << "' is INVALID - " << e.what() << endl;
    }
    cout << endl;

    // Test 2: Validate passwords
    string pass1 = "SecurePass123";
    string pass2 = "short"; // Too short
    string pass3 = "has spaces"; // Contains spaces
    string pass4 = "ThisPasswordIsWayTooLongForTheSystem"; // Too long

    cout << "Testing passwords:\n";

    // Test valid password
    try {
        Validation::validatePassword(pass1);
        cout << "'" << pass1 << "' is VALID" << endl;
    } catch (const invalid_argument& e) {
        cout << "'" << pass1 << "' is INVALID - " << e.what() << endl;
    }

    // Test short password
    try {
        Validation::validatePassword(pass2);
        cout << "'" << pass2 << "' is VALID" << endl;
    } catch (const invalid_argument& e) {
        cout << "'" << pass2 << "' is INVALID - " << e.what() << endl;
    }

    // Test password with spaces
    try {
        Validation::validatePassword(pass3);
        cout << "'" << pass3 << "' is VALID" << endl;
    } catch (const invalid_argument& e) {
        cout << "'" << pass3 << "' is INVALID - " << e.what() << endl;
    }

    // Test long password
    try {
        Validation::validatePassword(pass4);
        cout << "'" << pass4 << "' is VALID" << endl;
    } catch (const invalid_argument& e) {
        cout << "'" << pass4 << "' is INVALID - " << e.what() << endl;
    }
    cout << endl;

    // Test 3: Validate balance
    double balance1 = 2000.0;
    double balance2 = 1000.0; // Too low
    double balance3 = 1500.0; // Minimum valid

    cout << "Testing balance:\n";

    // Test valid balance
    try {
        Validation::validateBalance(balance1);
        cout << balance1 << " EGP is VALID" << endl;
    } catch (const invalid_argument& e) {
        cout << balance1 << " EGP is INVALID - " << e.what() << endl;
    }

    // Test low balance
    try {
        Validation::validateBalance(balance2);
        cout << balance2 << " EGP is VALID" << endl;
    } catch (const invalid_argument& e) {
        cout << balance2 << " EGP is INVALID - " << e.what() << endl;
    }

    // Test minimum balance
    try {
        Validation::validateBalance(balance3);
        cout << balance3 << " EGP is VALID" << endl;
    } catch (const invalid_argument& e) {
        cout << balance3 << " EGP is INVALID - " << e.what() << endl;
    }
    cout << endl;

    // Test 4: Validate salary
    double salary1 = 6000.0;
    double salary2 = 3000.0; // Too low
    double salary3 = 5000.0; // Minimum valid

    cout << "Testing salary:\n";

    // Test valid salary
    try {
        Validation::validateSalary(salary1);
        cout << salary1 << " EGP is VALID" << endl;
    } catch (const invalid_argument& e) {
        cout << salary1 << " EGP is INVALID - " << e.what() << endl;
    }

    // Test low salary
    try {
        Validation::validateSalary(salary2);
        cout << salary2 << " EGP is VALID" << endl;
    } catch (const invalid_argument& e) {
        cout << salary2 << " EGP is INVALID - " << e.what() << endl;
    }

    // Test minimum salary
    try {
        Validation::validateSalary(salary3);
        cout << salary3 << " EGP is VALID" << endl;
    } catch (const invalid_argument& e) {
        cout << salary3 << " EGP is INVALID - " << e.what() << endl;
    }

    cout << "\n=== All validation tests completed ===\n";

    return 0;
}
