#include "clientManager.h"

//c.static Client* login(int id, string password)
// Login a client by ID and password
Client* ClientManager::login(int id, string password) {
    vector<Client> clients = FilesHelper::getClients();

    for (int i = 0; i < clients.size(); i++) {
        if (clients[i].getId() == id && clients[i].getPassword() == password) {

            cout << "\n-----Login successful! Welcome, " << clients[i].getName() << "!----" << endl;

            return new Client(clients[i].getId(), clients[i].getName(),
                clients[i].getPassword(), clients[i].getBalance());
        }
    }
    cout << "Invalid ID or password." << endl;
    return nullptr;
}


//d.static bool clientOptions(Client* client)
// Handle client options menu
bool ClientManager::clientOptions(Client* client) {
    if (!client) return false;

    int choice;
    do {
        cout << "\n===== Client Menu =====\n";
        cout << "1. Deposit\n2. Withdraw\n3. Transfer\n4. Check Balance\n5. Update Password\n6. Display Info\n0. Logout\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            double amount;
            cout << "Enter amount to deposit: ";
            cin >> amount;
            client->deposit(amount);
            FilesHelper::updateClientInFile(client);
            cout << "New balance: " << client->checkBalance() << endl;
            break;
        }
        case 2: {
            double amount;
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            client->withdraw(amount);
            FilesHelper::updateClientInFile(client);
            cout << "New balance: " << client->checkBalance() << endl;
            break;
        }
        case 3: { // Transfer
            int recipientId;
            double transferAmount;
            cout << "Enter recipient ID: ";
            cin >> recipientId;
            cout << "Enter amount to transfer: ";
            cin >> transferAmount;

            // Get all clients
            vector<Client> clients = FilesHelper::getClients();
            Client* recipient = nullptr;

            for (Client& c : clients) {
                if (c.getId() == recipientId) {
                    recipient = new Client(c.getId(), c.getName(), c.getPassword(), c.getBalance());
                    break;
                }
            }

            if (recipient) {
                client->transferTo(transferAmount, *recipient);

                // Save both clients permanently
                FilesHelper::updateClientInFile(client);
                FilesHelper::updateClientInFile(recipient);

                delete recipient; 
            }
            else {
                cout << "Recipient not found!" << endl;
            }
            break;
        }
        case 4:
            cout << "\n<<<<<<Current balance: " << client->checkBalance() << " >>>>>>>>" << endl;
            break;
        case 5: {
            string newPass;
            cout << "Enter new password: ";
            cin >> newPass;
            client->setPassword(newPass);
            cout << "Password updated successfully!" << endl;
            break;
        }
        case 6:
            client->display();
            break;
        case 0:
            cout << "Logging out..." << endl;
            return false;
        default:
            cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 0);

    return false;
}
