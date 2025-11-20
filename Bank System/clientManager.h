#pragma once
#include <iostream>
#include <limits>
#include "Client.h"
#include "FilesHelper.h"
using namespace std;

class ClientManager {
    static Client* loginClient;
public:
    ClientManager();
    ~ClientManager();

public:
    static Client* login(int id, string password);
    static bool clientOptions(Client* c);
  
    static void printClientMenu();
    static void updatePassword();
};
