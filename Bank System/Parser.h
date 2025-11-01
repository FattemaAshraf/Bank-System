#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Client.h"
using namespace std;

class Parser
{
	 /*   static vector<string> split(string line). id,pass,name=> line => add => txt
		static Client parseToClient(string line).
		static Employee parseToEmployee(string line).
		static Admin parseToAdmin(string line).*/
public:
    static vector<string> split(string line, char delimiter) { // i send : once  or ,
        vector<string> tokens;
        stringstream ss(line);
        string token;

        while (getline(ss, token, delimiter)) {//"ID:1234"
             size_t start = token.find_first_not_of(" \t\r\n"); //Find the FIRST character that is NOT a space, tab, or newline                                               
            size_t end = token.find_last_not_of(" \t\r\n");//Find the LAST character that is NOT a space, tab, or newline

            tokens.push_back(token.substr(start, end - start + 1));
             
             
        }

        return tokens;
    }

    // Expected format: "id:12234,name:fatma ashraf,password:223128,balance:8290"
    static Client parseToClient(string line) {
        //first split by comma ===>  result:
        //["id:12234","name:fatma ashraf","password:223128","balance:8290"]
        vector<string> pairs = split(line, ',');

        //variables to get the result of vector str
        int id = 0;
        string name = "";
        string password = "";
        double balance = 0.0;

        //foreach on result above
        for (const string& pair : pairs) {
            cout << pair << endl;
            vector<string> keyValue = split(pair, ':');
            //id:1234
            if (keyValue.size() != 2) {
                throw invalid_argument("Invalid key-value pair format");
            }
            //id,name,password,balance
            string key = keyValue[0];
            //values
            string value = keyValue[1];

            if (key == "id") {
                id = stoi(value);//transforms text "123" into number 123
            }
            else if (key == "name") {
                name = value;
            }
            else if (key == "password") {
                password = value;
            }
            else if (key == "balance") {
                balance = stod(value);
            }
        }

        return Client(id, name, password, balance);
    }
};

