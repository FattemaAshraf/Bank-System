#include "Client.h"
#include "FileManager.h"

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
