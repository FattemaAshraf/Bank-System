#include "Validation.h"
#include <cctype>
#include <stdexcept>


void Validation::validateName(string name) {
    if (name.size() < 3) {
        throw invalid_argument("Name is too short! Minimum length is 3 characters.");
    }

    if (name.size() > 20) {
        throw invalid_argument("Name is too long! Maximum length is 20 characters.");
    }

    for (int i = 0; i < name.size(); i++) {
        if (!isalpha(name[i])) {
            throw invalid_argument("Name must contain only alphabetic characters (no numbers, spaces, or symbols)!");
        }
    }
}

void Validation::validatePassword(string password) {
    if (password.size() < 8) {
        throw invalid_argument("Password is too short! Minimum length is 8 characters.");
    }

    if (password.size() > 20) {
        throw invalid_argument("Password is too long! Maximum length is 20 characters.");
    }

    for (int i = 0; i < password.size(); i++) {
        if (isspace(password[i])) {
            throw invalid_argument("Password cannot contain spaces!");
        }
    }
}

void Validation::validateBalance(double balance) {
    if (balance < 1500.0) {
        throw invalid_argument("Balance is below minimum! Minimum balance is 1500 EGP.");
    }
}

void Validation::validateSalary(double salary) {
    if (salary < 5000.0) {
        throw invalid_argument("Salary is below minimum! Minimum salary is 5000 EGP.");
    }
}