#include "clientManager.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "FileManager.h"
Client* ClientManager::loginClient = nullptr;

ClientManager::ClientManager() {
    loginClient = nullptr;
}
 
ClientManager::~ClientManager() {
    delete loginClient;
}
//c.static Client* login(int id, string password)
// Login a client by ID and password
Client* ClientManager::login(int id, string password) {
    vector<Client> clients = FilesHelper::getClients();

    for (int i = 0; i < clients.size(); i++) {
        if (clients[i].getId() == id && clients[i].getPassword() == password) {

            cout << "\n-----Login successful! Welcome, " << clients[i].getName() << "!----" << endl;
            Client* client = new Client(clients[i].getId(), clients[i].getName(),
                clients[i].getPassword(), clients[i].getBalance());
            setLoginClient(client);

            return client;
            
        }
    }
     return nullptr;
}


//d.static bool clientOptions(Client* client)
// Handle client options menu
bool ClientManager::clientOptions(Client* client) {
    if (!client) return false;

    int choice;
    
        printClientMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: Invalid input. Please enter a number." << endl;
            return true;
        }
        switch (choice) {
        case 1:
            cout << "\n<<<<<<Current balance: " << client->checkBalance() << " >>>>>>>>" << endl;
            break;
        case 2: {
            double amount;
            cout << "Enter amount to deposit: ";
            cin >> amount;
            client->deposit(amount);
            //FilesHelper::updateClientInFile(client);
            cout << "New balance: " << client->checkBalance() << endl;
            break;
        }
        case 3: {
            double amount;
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            client->withdraw(amount);
            //FilesHelper::updateClientInFile(client);
            cout << "New balance: " << client->checkBalance() << endl;
            break;
        }
        case 4: { // Transfer
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

                 FilesHelper::updateClientInFile(recipient);

                delete recipient; 
            }
            else {
                cout << "Recipient not found!" << endl;
            }
            break;
        }
        
        case 6: {
            string newPass;
            cout << "Enter new password: ";
            cin >> newPass;
            client->setPassword(newPass);
            cout << "Password updated successfully!" << endl;
            break;
        }
        case 5:
            client->display();
            break;
        case 7:
            logOut();
            return false;
        default:
            cout << "Invalid choice. Try again." << endl;
        }

     

    return true;
}


void ClientManager::printClientMenu() {
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

void ClientManager::logOut() {
    FilesHelper::updateClientInFile(loginClient);

    cout << "\nLogging out ... Goodbye!" << loginClient->getName() << endl;
}
void ClientManager::updatePassword() {
    string newPassword;
    cout << "new password: ";
    cin >> newPassword;
    loginClient->updatePassword(loginClient->getId(), loginClient->getPassword(), newPassword);
}
void ClientManager::setLoginClient(Client* cl) {
    loginClient = cl;
    
}
