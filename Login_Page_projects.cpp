#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Temp {
    string userName, Email, Password;
    string searchName, searchPass, searchEmail;
    fstream file;
public:
    void login();
    void signUP();
    void forgot();
};

void Temp::signUP() {
    cout << "\nEnter your User Name: ";
    getline(cin, userName);
    cout << "Enter your Email Address: ";
    getline(cin, Email);
    cout << "Enter your Password: ";
    getline(cin, Password);

    file.open("logginData.txt", ios::out | ios::app);
    if (file.is_open()) {
        file << userName << "*" << Email << "*" << Password << endl;
        file.close();
        cout << "Sign-up successful!" << endl;
    } else {
        cout << "Error opening file for writing!" << endl;
    }
}

void Temp::login() {
    cout << "-----------LOGIN----------" << endl;
    cout << "Enter your User Name: ";
    getline(cin, searchName);
    cout << "Enter your Password: ";
    getline(cin, searchPass);

    file.open("logginData.txt", ios::in);
    if (file.is_open()) {
        bool userFound = false;
        while (getline(file, userName, '*')) {
            getline(file, Email, '*');
            getline(file, Password, '\n');
            if (userName == searchName) {
                userFound = true;
                if (Password == searchPass) {
                    cout << "\nAccount Login Successful!" << endl;
                    cout << "UserName: " << userName << endl;
                    cout << "Email: " << Email << endl;
                } else {
                    cout << "Password is Incorrect" << endl;
                }
                break;
            }
        }
        if (!userFound) {
            cout << "User not found!" << endl;
        }
        file.close();
    } else {
        cout << "Error opening file for reading!" << endl;
    }
}

void Temp::forgot() {
    cout << "\nEnter your User Name: ";
    getline(cin, searchName);
    cout << "Enter your Email Address: ";
    getline(cin, searchEmail);

    file.open("logginData.txt", ios::in);
    if (file.is_open()) {
        bool accountFound = false;
        while (getline(file, userName, '*')) {
            getline(file, Email, '*');
            getline(file, Password, '\n');
            if (userName == searchName && Email == searchEmail) {
                accountFound = true;
                cout << "\nAccount Found!" << endl;
                cout << "Your Password: " << Password << endl;
                break;
            }
        }
        if (!accountFound) {
            cout << "\nAccount not found!" << endl;
        }
        file.close();
    } else {
        cout << "Error opening file for reading!" << endl;
    }
}

int main() {
    Temp obj;
    char choice;

    do {
        cout << "\n1- Login";
        cout << "\n2- Sign-Up";
        cout << "\n3- Forgot Password";
        cout << "\n4- Exit";
        cout << "\nEnter your Choice: ";
        
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case '1':
                obj.login();
                break;
            case '2':
                obj.signUP();
                break;
            case '3':
                obj.forgot();
                break;
            case '4':
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid selection! Please enter a number between 1 and 4." << endl;
        }
    } while (choice != '4');

    return 0;
}
