#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Temp
{
    string userName, Email, Password;
    string searchName, searchPass, searchEmail;
    fstream file;
    public:
    void login();
    void signUP();
    void forgot();
};

int main()
{
    Temp obj;
    char choice;
    cout << "\n1- Login";
    cout << "\n2- Sign-Up";
    cout << "\n3- Forgot Password";
    cout << "\n4- Exit";
    cout << "\nEnter your Choice: ";
    
    cin >> choice;
    cin.ignore(); // To clear the newline character from the buffer after cin

    // Using Switch case
    switch (choice)
    {
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
            return 0;
        default:
            cout << "Invalid selection ......!";
    }
}

// Class definition

void Temp::signUP()
{
    cout << "\nEnter your User Name: ";
    getline(cin, userName);
    cout << "\nEnter your Email Address: ";
    getline(cin, Email);
    cout << "Enter your Password: ";
    getline(cin, Password);

    file.open("logginData.txt", ios::out | ios::app);
    if (file.is_open()) {
        file << userName << "*" << Email << "*" << Password << endl;
        file.close();
        cout << "Sign-up successful!" << endl;
    } else {
        cout << "Error opening file!" << endl;
    }
}

void Temp::login()
{
    cout << "-----------LOGIN----------" << endl;
    cout << "Enter your User Name: ";
    getline(cin, searchName);
    cout << "Enter your Password: ";
    getline(cin, searchPass);

    file.open("logginData.txt", ios::in);
    if (file.is_open()) {
        while (getline(file, userName, '*')) {
            getline(file, Email, '*');
            getline(file, Password, '\n');
            if (userName == searchName) {
                if (Password == searchPass) {
                    cout << "\nAccount Login Successful...!";
                    cout << "\nUserName: " << userName << endl;
                    cout << "Email: " << Email << endl;
                    file.close();
                    return;
                } else {
                    cout << "Password is Incorrect" << endl;
                    cout << "Please enter the valid password" << endl;
                    file.close();
                    return;
                }
            }
        }
        cout << "User not found!" << endl;
        file.close();
    } else {
        cout << "Error opening file!" << endl;
    }
}

void Temp::forgot()
{
    cout << "\nEnter your User Name: ";
    getline(cin, searchName);
    cout << "Enter your Email Address: ";
    getline(cin, searchEmail);

    file.open("logginData.txt", ios::in);
    if (file.is_open()) {
        while (getline(file, userName, '*')) {
            getline(file, Email, '*');
            getline(file, Password, '\n');
            if (userName == searchName && Email == searchEmail) {
                cout << "\nAccount Found!";
                cout << "Your Password: " << Password << endl;
                file.close();
                return;
            }
        }
        cout << "\nAccount not found!" << endl;
        file.close();
    } else {
        cout << "Error opening file!" << endl;
    }
}

