#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
class ClientManger
{
    static Client* loginClient;

public:
    ClientManger();
    ~ClientManger();

    static void printClientMenu();
     static void updatePassword();
 };

