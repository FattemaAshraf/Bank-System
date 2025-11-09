#include "Employee.h"

vector<Client> Employee::allClients;

void Employee::addClient(const Client& client) {
     
    allClients.push_back(client);
}

Client* Employee::getClientById(int id) {
    for (int i = 0; i < allClients.size(); i++) {
        if (allClients[i].getId() == id) {
            return &allClients[i];
        }
    }
    return nullptr;
}

vector<Client>& Employee::getAllClients() {
    return allClients;
}

void Employee::listClients() {
    if (allClients.size() == 0) {
        cout << "No clients found." << endl;
        return;
    }

    cout << "\n===== All Clients =====" << endl;
    for (int i = 0; i < allClients.size(); i++) {
        allClients[i].display();
        cout << "----------------------" << endl;
    }
}

void Employee::editClient(int id, string name, string password, double balance) {
    Client* client = getClientById(id);

    if (client == nullptr) {
        cout << "Client not found." << endl;
        return;
    }

    try {
        Validation::validateName(name);
        Validation::validatePassword(password);
        Validation::validateBalance(balance);

        client->setName(name);
        client->setPassword(password);
        client->setBalance(balance);

        cout << "Client updated successfully." << endl;
    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }
}
