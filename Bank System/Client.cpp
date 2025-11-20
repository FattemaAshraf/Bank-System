#include "Client.h"
#include "FileManager.h"
#include "Client.h"
#include "Validation.h"
 
 Client::Client() : Person() {
    balance = 1500.0;
}

 Client::Client(int id, string name, string password, double balance)
    : Person(id, name, password) {
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

 double Client::getBalance() {
    return balance;
}

 void Client::setBalance(double balance) {
    try {
        Validation::validateBalance(balance);
        this->balance = balance;
    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }
}

 void Client::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        cout << "Deposited " << amount << " EGP successfully." << endl;
    }
    else {
        cout << "Invalid amount. Deposit must be positive." << endl;
    }
}

 void Client::withdraw(double amount) {
    if (amount <= 0) {
        cout << "Invalid amount. Withdrawal must be positive." << endl;
        return;
    }

    if (balance >= amount) {
        balance -= amount;
        cout << "Withdrew " << amount << " EGP successfully." << endl;
    }
    else {
        cout << "You don't have enough balance to withdraw." << endl;
    }
}

 void Client::transferTo(double amount, Client& recipient) {
    if (amount <= 0) {
        cout << "Invalid amount. Transfer must be positive." << endl;
        cout << "==== Transfer failed ====" << endl;
        return;
    }

    if (balance >= amount) {
        balance -= amount;
        recipient.deposit(amount);
        cout << "===== Transferred successfully =====" << endl;
    }
    else {
        cout << "Insufficient balance." << endl;
        cout << "==== Transfer failed ====" << endl;
    }
}

 double Client::checkBalance() {
    return balance;
}

 void Client::display() {
    cout << "\n========== Client Information ==========" << endl;
    cout << "Client ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Balance: " << balance << " EGP" << endl;
    cout << "========================================\n" << endl;
}

 
void Client::updatePassword(int id, string oldPassword, string newPassword) {
    FileManager fileManager;
    vector<Client> allClients = fileManager.getAllClients();
    Client* client = nullptr;

    for (int i = 0; i < allClients.size(); i++) {
        if (allClients[i].getId() == id && allClients[i].getPassword() == oldPassword) {
            client = &allClients[i];
            break;
        }
    }

    if (client == nullptr) {
        cout << "client not found." << endl;
        return;
    }
    if (oldPassword == newPassword) {
        cout << "same password." << endl;
        return;
    }
    try {
        Validation::validatePassword(newPassword);
        client->setPassword(newPassword);
        cout << "client password updated successfully." << endl;
        fileManager.removeAllClients();
        for (int i = 0; i < allClients.size(); i++) {
            fileManager.addClient(allClients[i]);
        }

    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }
}
