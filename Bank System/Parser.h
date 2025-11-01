#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
using namespace std;

class Parser
{
public:
    static vector<string> split(string line, char delimiter);
    static Client parseToClient(string line);
    static Employee parseToEmployee(string line);
    static Admin parseToAdmin(string line);
};
