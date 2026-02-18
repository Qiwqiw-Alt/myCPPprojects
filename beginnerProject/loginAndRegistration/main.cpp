#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct User {
    string username;
    string password;
};

vector<User> users;

void registration();
void login();
void homeView();
void readData();
void writeData(string username, string password);
bool checkUsername(string username);
bool checkPassword(string username, string password);

int main() {
    readData();

    int userChoice;
    bool userChoiceisCorrect = false;

    do {
        cout << "\n=== Welcome to Our Application :) ===\n";
        cout << "(1) Registration \n";
        cout << "(2) Login \n";
        cout << "Enter your choice: "; cin >> userChoice;

        if (userChoice == 1) {
            registration();
            userChoiceisCorrect = true;
        } else if (userChoice == 2) {
            login();
            userChoiceisCorrect = true;
        } else {
            cout << "Please select the available choice!" << endl;
        }
    } while (!userChoiceisCorrect);

    return 0;
}

void registration() {
    string username;
    string password;
    string passwordConfirm;
    bool passwordDifferent = false;
    bool usernameIsAlreadyRegistered;

    cout << "\n=== Welcome to Registration Menu ===\n";

    do {
        cout << "Enter username: "; cin >> username;
        usernameIsAlreadyRegistered = checkUsername(username);

        if (usernameIsAlreadyRegistered) {
            cout << "\nUsername already registered! Please choose a different username!" << endl;
        }
    } while (usernameIsAlreadyRegistered);

    cout << "Enter password: "; cin >> password;
    do {
        cout << "Confirm your password: "; cin >> passwordConfirm;
        if (password != passwordConfirm) {
            cout << "Password dont match !" << endl;
            passwordDifferent = true;
        } else {
            cout << "Registration Success!!" << endl;
            passwordDifferent = false;
        }
    } while (passwordDifferent);

    users.push_back({username, password});
    writeData(username, password);

    login();
}

void login() {
    string username;
    string password;
    bool usernameIsAlreadyRegistered;
    bool passwordIsCorrect;

    cout << "\n=== Welcome to Login Menu ===\n";

    do {
        cout << "Enter username: "; cin >> username;
        usernameIsAlreadyRegistered = checkUsername(username);

        if (!usernameIsAlreadyRegistered) {
            cout << "\nUsername not found! Please write the correct username!" << endl;
        }
    } while (!usernameIsAlreadyRegistered);

    do {
        cout << "Enter password: "; cin >> password;
        passwordIsCorrect = checkPassword(username, password);

        if (passwordIsCorrect) {
            homeView();
        } else {
            cout << "Your password is wrong!, Please enter the correct password!" << endl;
        }
    } while (!passwordIsCorrect);
}

void readData() {
    users.clear();

    ifstream myFile("dataExample.txt");
    string line, username, password;

    if (myFile.is_open()) {
        while (getline(myFile, username, '|')) {
            getline(myFile, password);

            users.push_back({username, password});
        }
        myFile.close();
    }
}

void writeData(string username, string password) {
    ofstream myFile("dataExample.txt", ios::app);

    if (myFile.is_open()) {
        myFile << username << "|" << password << "\n";
        myFile.close();
    }
}

bool checkUsername(string username) {
    bool usernameFound = false;
    if (users.empty()) {
        return usernameFound;
    } else {
        for (int i = 0; i < users.size(); i++) {
            if (users[i].username == username) {
                usernameFound = true;
                break;
            }
        }
    }

    return usernameFound;
}

bool checkPassword(string username, string password) {
    bool usernameFound = checkUsername(username);
    bool passwordIsCorrect = false;

    if (usernameFound) {
        for (int i = 0; i < users.size(); i++) {
            if (users[i]. username == username && users[i].password == password) {
                passwordIsCorrect = true;
                break;
            }
        }
    }

    return passwordIsCorrect;
}

void homeView() {
    cout << "\n\n ===================================================================" << endl;
    cout << "=                                                                 =" << endl;
    cout << "=                           Hello there:)                         =" << endl;
    cout << "=                                                                 =" << endl;
    cout << "===================================================================" << endl;
}