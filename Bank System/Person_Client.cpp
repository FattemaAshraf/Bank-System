#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    int id;
    string name;
    string password;

public:
    Person() {
        id = 0;
        name = "";
        password = "";
    }
    Person(int id, string name, string password) {
        this->id = id;
        this->name = name;
        this->password = password;
    }
    int getId() {
        return id;
    }
    string getNname() {
        return name;
    }
    string getPassword() {
        return password;
    }
    void setId(int id) {
        this->id = id;
    }
    void setName(string name) {
        this->name = name;
    }
    void setPassword(string password) {
        this->password = password;
    }
};
class Client : public Person {
    double balance;
public:
    Client() {
        balance = 1500.0;
    }
    Client(int id,string name, string password, double balance):Person(id, name, password), balance(balance){}
    double getBalance() {
        return balance;
    }
    void setBalance(double balance) {
        this->balance = balance;
    }
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
        else {
            cout << "invalid amount" << endl;
        }
    }
    void withdraw(double amount) {
        if (balance > amount) {
            balance -= amount;
        }
        else {
            cout << "you don't have enough balance to withdraw" << endl;
        }
    }
    void transferTo(double amount, Client& recipient) {
        if (balance > amount) {
            balance -= amount;
            recipient.deposit(amount);
            cout << "=====transfered successfuly=====\n" << endl;
        }
        else {
            cout << "====transfer failed====\n" << endl;
        }
    }
    double checkBalance(){
        return balance;
    }
    void display() {
        cout << "Client ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }
};


int main()
{
    Client a1(2, "Ali", "123", 200);
    Client a2(3, "Sama", "111", 100);

    a1.deposit(300);//500
    a1.withdraw(200);//300
    a1.transferTo(50, a2);//a1-> 250, a1-> 150

    cout << "=======Ali's account: =========" << endl;
    a1.display();

    cout << "\n=======Sama's account: =========" << endl;
    a2.display();
}

