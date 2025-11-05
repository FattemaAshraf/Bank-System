#include "Client.h"

vector<Client> Client::allClients;

void Client::addClient(const Client& client) {
    allClients.push_back(client);
}

Client* Client::getClientById(int id) {
    for (int i = 0; i < allClients.size(); i++) {
        if (allClients[i].getId() == id) {
            return &allClients[i];
        }
    }
    return nullptr;
}

vector<Client>& Client::getAllClients() {
    return allClients;
}

void Client::listClients() {
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

void Client::editClient(int id, string name, string password, double balance) {
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
