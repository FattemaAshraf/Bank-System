// Bank System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Validation.h"
#include "Client.h"
#include "Parser.h"
#include "FilesHelper.h"
#include "FileManager.h"
#include "EmployeeManager.h"
#include "ClientManager.cpp"
#include "Screen.h"
using namespace std;



int main() {
    //_____Phase 3______
    int id;
    string password;
    cout << "Id: ";
    cin >> id;
    cout << "password: ";
    cin >> password;
    EmployeeManager empManger;
    empManger.login(id,password);
    //____Phase 2_____
    /*cout << "=== Bank System - Admin Testing.... login  ===\n\n";
    Admin admin(1, "Fatma", "789", 600);
    Client clnt(2, "Fatma", "789", 6000);
    Employee emp(3, "Fatma", "789", 600);

    admin.addClient(clnt);
    admin.addClient(clnt);

    admin.addEmployee(emp);
    admin.addEmployee(emp);

    admin.listClients();
    admin.listEmployees();
    cout << "=== Bank System -   Testing FileManger....   ===\n\n";
    FileManager fileManager;
    fileManager.addClient(clnt);
    fileManager.addEmployee(emp);*/
    //           ======testing the client manager login======
    //            ======= phase 3 =======             
    int id;
    string password;

    cout << "===== Client Login =====" << endl;
    cout << "Enter your ID: ";
    cin >> id;
    cout << "Enter your password: ";
    cin >> password;

    Client* loggedClient = ClientManager::login(id, password);
    if (loggedClient) {
        ClientManager::clientOptions(loggedClient);
    }

    return 0;
}



//==============================================================================
//int main() {
//    //____Phase 2_____
//    cout << "=== Bank System - Admin Testing.... login  ===\n\n";
//    Admin admin(1, "Fatma", "789", 600);
//    Client clnt(2, "Fatma", "789", 6000);
//    Employee emp(3, "Fatma", "789", 600);
//
//    admin.addClient(clnt);
//    admin.addClient(clnt);
//
//    admin.addEmployee(emp);
//    admin.addEmployee(emp);
//
//    admin.listClients();
//    admin.listEmployees();
//    cout << "=== Bank System -   Testing FileManger....   ===\n\n";
//    FileManager fileManager;
//    fileManager.addClient(clnt);
//    fileManager.addEmployee(emp);
//
//    DataInitializer::initializeData();

 
    //___Phase 1_____
    //cout << "=== Bank System - Validation Testing ===\n\n";

    //// Test 1: Validate names
    //string name1 = "John";
    //string name2 = "AB"; // Too short
    //string name3 = "John123"; // Contains numbers
    //string name4 = "ThisIsAVeryLongNameExceedingLimit"; // Too long

    //cout << "Testing names:\n";

    //// Test valid name
    //try {
    //    Validation::validateName(name1);
    //    cout << "'" << name1 << "' is VALID" << endl;
    //} catch (const invalid_argument& e) {
    //    cout << "'" << name1 << "' is INVALID - " << e.what() << endl;
    //}

    //// Test short name
    //try {
    //    Validation::validateName(name2);
    //    cout << "'" << name2 << "' is VALID" << endl;
    //} catch (const invalid_argument& e) {
    //    cout << "'" << name2 << "' is INVALID - " << e.what() << endl;
    //}

    //// Test name with numbers
    //try {
    //    Validation::validateName(name3);
    //    cout << "'" << name3 << "' is VALID" << endl;
    //} catch (const invalid_argument& e) {
    //    cout << "'" << name3 << "' is INVALID - " << e.what() << endl;
    //}

    //// Test long name
    //try {
    //    Validation::validateName(name4);
    //    cout << "'" << name4 << "' is VALID" << endl;
    //} catch (const invalid_argument& e) {
    //    cout << "'" << name4 << "' is INVALID - " << e.what() << endl;
    //}
    //cout << endl;

    //// Test 2: Validate passwords
    //string pass1 = "SecurePass123";
    //string pass2 = "short"; // Too short
    //string pass3 = "has spaces"; // Contains spaces
    //string pass4 = "ThisPasswordIsWayTooLongForTheSystem"; // Too long

    //cout << "Testing passwords:\n";

    //// Test valid password
    //try {
    //    Validation::validatePassword(pass1);
    //    cout << "'" << pass1 << "' is VALID" << endl;
    //} catch (const invalid_argument& e) {
    //    cout << "'" << pass1 << "' is INVALID - " << e.what() << endl;
    //}

    //// Test short password
    //try {
    //    Validation::validatePassword(pass2);
    //    cout << "'" << pass2 << "' is VALID" << endl;
    //} catch (const invalid_argument& e) {
    //    cout << "'" << pass2 << "' is INVALID - " << e.what() << endl;
    //}

    //// Test password with spaces
    //try {
    //    Validation::validatePassword(pass3);
    //    cout << "'" << pass3 << "' is VALID" << endl;
    //} catch (const invalid_argument& e) {
    //    cout << "'" << pass3 << "' is INVALID - " << e.what() << endl;
    //}

    //// Test long password
    //try {
    //    Validation::validatePassword(pass4);
    //    cout << "'" << pass4 << "' is VALID" << endl;
    //} catch (const invalid_argument& e) {
    //    cout << "'" << pass4 << "' is INVALID - " << e.what() << endl;
    //}
    //cout << endl;

    //// Test 3: Validate balance
    //double balance1 = 2000.0;
    //double balance2 = 1000.0; // Too low
    //double balance3 = 1500.0; // Minimum valid

    //cout << "Testing balance:\n";

    //// Test valid balance
    //try {
    //    Validation::validateBalance(balance1);
    //    cout << balance1 << " EGP is VALID" << endl;
    //} catch (const invalid_argument& e) {
    //    cout << balance1 << " EGP is INVALID - " << e.what() << endl;
    //}

    //// Test low balance
    //try {
    //    Validation::validateBalance(balance2);
    //    cout << balance2 << " EGP is VALID" << endl;
    //} catch (const invalid_argument& e) {
    //    cout << balance2 << " EGP is INVALID - " << e.what() << endl;
    //}

    //// Test minimum balance
    //try {
    //    Validation::validateBalance(balance3);
    //    cout << balance3 << " EGP is VALID" << endl;
    //} catch (const invalid_argument& e) {
    //    cout << balance3 << " EGP is INVALID - " << e.what() << endl;
    //}
    //cout << endl;

    //// Test 4: Validate salary
    //double salary1 = 6000.0;
    //double salary2 = 3000.0; // Too low
    //double salary3 = 5000.0; // Minimum valid

    //cout << "Testing salary:\n";

    //// Test valid salary
    //try {
    //    Validation::validateSalary(salary1);
    //    cout << salary1 << " EGP is VALID" << endl;
    //} catch (const invalid_argument& e) {
    //    cout << salary1 << " EGP is INVALID - " << e.what() << endl;
    //}

    //// Test low salary
    //try {
    //    Validation::validateSalary(salary2);
    //    cout << salary2 << " EGP is VALID" << endl;
    //} catch (const invalid_argument& e) {
    //    cout << salary2 << " EGP is INVALID - " << e.what() << endl;
    //}

    //// Test minimum salary
    //try {
    //    Validation::validateSalary(salary3);
    //    cout << salary3 << " EGP is VALID" << endl;
    //} catch (const invalid_argument& e) {
    //    cout << salary3 << " EGP is INVALID - " << e.what() << endl;
    //}

    //cout << "\n=== All validation tests completed ===\n";

    //string clientData = "id:12234,name:fatma ashraf,password:223128,balance:8290";
    //try {
    //    Client client = Parser::parseToClient(clientData);
    //    cout << "Parsed Client:" << endl;
    //    client.display();
    //    FilesHelper::saveClient(client);
    //}
    //catch (const exception& e) {
    //    cout << "Error: " << e.what() << endl;
    //}
    return 0;
}
