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
