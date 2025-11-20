#include "Parser.h"
using namespace std;
vector<string> Parser::split(string line, char delimiter) {
    vector<string> tokens;
    stringstream ss(line);
    string token;

    while (getline(ss, token, delimiter)) {
        size_t start = token.find_first_not_of(" \t\r\n");
        size_t end = token.find_last_not_of(" \t\r\n");
        tokens.push_back(token.substr(start, end - start + 1));
    }

    return tokens;
}

Client Parser::parseToClient(string line) {
    vector<string> pairs = split(line, ',');

    int id = 0;
    string name = "";
    string password = "";
    double balance = 0.0;

    for (const string& pair : pairs) {
        //cout << pair << endl; //remove this line bec, it prints every key-value for every client
        vector<string> keyValue = split(pair, ':');

        if (keyValue.size() != 2) {
            throw invalid_argument("Invalid key-value pair format");
        }

        string key = keyValue[0];
        string value = keyValue[1];

        if (key == "id") {
            id = stoi(value);
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

Employee Parser::parseToEmployee(string line) {
    vector<string> pairs = split(line, ',');

    int id = 0;
    string name = "";
    string password = "";
    double salary = 0.0;

    for (const string& pair : pairs) {
        cout << pair << endl;
        vector<string> keyValue = split(pair, ':');

        if (keyValue.size() != 2) {
            throw invalid_argument("Invalid key-value pair format");
        }

        string key = keyValue[0];
        string value = keyValue[1];

        if (key == "id") {
            id = stoi(value);
        }
        else if (key == "name") {
            name = value;
        }
        else if (key == "password") {
            password = value;
        }
        else if (key == "salary") {
            salary = stod(value);
        }
    }

    return Employee(id, name, password, salary);
}

Admin Parser::parseToAdmin(string line) {
    vector<string> pairs = split(line, ',');

    int id = 0;
    string name = "";
    string password = "";
    double salary = 0.0;

    for (const string& pair : pairs) {
        cout << pair << endl;
        vector<string> keyValue = split(pair, ':');

        if (keyValue.size() != 2) {
            throw invalid_argument("Invalid key-value pair format");
        }

        string key = keyValue[0];
        string value = keyValue[1];

        if (key == "id") {
            id = stoi(value);
        }
        else if (key == "name") {
            name = value;
        }
        else if (key == "password") {
            password = value;
        }
        else if (key == "salary") {
            salary = stod(value);
        }
    }

    return Admin(id, name, password, salary);
}
