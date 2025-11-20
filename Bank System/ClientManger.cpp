#include "ClientManger.h"
#include "Admin.h"
#include "Client.h"
#include "Employee.h"
#include "ClientManger.h"
#include "FileManager.h"
Client* ClientManger::loginClient = nullptr;

ClientManger::ClientManger() {
    loginClient = nullptr;
}

ClientManger::~ClientManger() {
    delete loginClient;
}

void ClientManger::printClientMenu() {
    cout << "\n===================================================================================================================" << endl;
    cout << "                                                CLIENT DASHBOARD                                                  " << endl;
    cout << "====================================================================================================================" << endl;
    cout << endl;
    cout << "  +------------------------+  +--------------------------+  +----------------------------+  +------------------------+ " << endl;
    cout << "  |  [1]   Your Balance    |  |  [2]  Deposit            |  |  [3]  Withdraw             |  |    [4]  Transfer To    | " << endl;
    cout << "  +------------------------+  +--------------------------+  +----------------------------+  +------------------------+ " << endl;
    cout << endl;
    cout << "  +------------------------+  +--------------------------+  +----------------------------+" << endl;
    cout << "  |   [5]  Display My Info |  |  [6]  Update My Password |  |   [7]  Logout              |" << endl;
    cout << "  +------------------------+  +--------------------------+  +----------------------------+" << endl;
    cout << endl;
    cout << "====================================================================================================================" << endl;
    cout << ">> Enter your choice: ";
}


void ClientManger::updatePassword() {
    string newPassword;
    cout << "new password: ";
    cin >> newPassword;
    loginClient->updatePassword(loginClient->getId(), loginClient->getPassword(), newPassword);
}
 
