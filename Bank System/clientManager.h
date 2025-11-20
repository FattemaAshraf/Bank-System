#pragma once
#include <iostream>
#include <limits>
#include "Client.h"
#include "FilesHelper.h"
using namespace std;

class ClientManager {
public:
    static Client* login(int id, string password);
    static bool clientOptions(Client* c);
};
