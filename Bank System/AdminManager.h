#pragma once
#include "Admin.h"
#include "FilesHelper.h"
#include <iostream>
#include <limits>
using namespace std;

class AdminManager
{
public:
    static void printEmployeeMenu();
    static Admin* login(int id, string password);
    static bool AdminOptions(Admin* admin);
};