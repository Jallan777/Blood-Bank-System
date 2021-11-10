// NZ Blood Bank System.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Introduction Screen

#include <iostream>
using namespace std;
int bloodBankRepeat;

void lineFunc(int length, string type) {
    for (int i = 0; i < length; i++)
        cout << type;
}

void menuFunc() {
    string menuInput;
MenuRestart:
    cout << endl << "[1] Information" << endl;
    cout << "[2] Contact Details" << endl;
    cout << "[3] Log In" << endl;
    cout << "[4] Register" << endl;
    cout << "[5] Exit" << endl;
    cout << endl << "Please enter a selection: "; cin >> menuInput;
    cin.ignore();
    if (menuInput == "1") {
        cout << endl << "\tNZ Blood Bank Information" << endl;
        lineFunc(52, "*");
        cout << endl << endl;
        cout << "Regular weekly donations ensure blood and plasma are available for those in need." << endl;
        cout << "The gift of blood can only be given from one person to another, and there is no substitute." << endl;
        cout << "So it's nice to know New Zealand can rely on everyday heroes' generosity to keep the flow of blood and plasma going." << endl;
        cout << "However, the need for blood and plasma is constant, so we're looking for more lifesavers." << endl;
        cout << "By putting aside a small part of your day you can make a life-changing difference, you can become a lifesaver too!" << endl;
        cout << endl << "Press Enter to return to the Menu..." << endl;
        cin.ignore();
        goto MenuRestart;
    }
    else if (menuInput == "2") {
        cout << endl << "\tNZ Blood Bank Contact Details" << endl;
        lineFunc(52, "*");
        cout << endl << endl << "Email Us:\t contact@nzblood.co.nz" << endl;
        cout << "Call Us:\t 0800 448 325" << endl;
        cout << "Or come into any NZ Blood Donation center if you need more information" << endl;
        cout << endl << "Press Enter to return to the Menu..." << endl;
        cin.ignore();
        goto MenuRestart;

    }
    else if (menuInput == "3") {
        string loginChoice;
    LoginRestart:
        cout << endl << "\tLog In" << endl;
        lineFunc(52, "*");
        cout << endl << endl << "[1] Donor Login" << endl;
        cout << "[2] Recipient Login" << endl;
        cout << "[3] Admin Login" << endl;
        cout << endl << endl << "[4] Return to Menu" << endl;
        cout << endl << "Please select a valid option: "; cin >> loginChoice;
        if (loginChoice == "1") {
            cout << "DONOR LOGIN PORTAL" << endl;       //Portal to attach Donor Login
            goto MenuRestart;
        }
        else if (loginChoice == "2") {
            cout << "RECIPIENT LOGIN PORTAL" << endl;   //Portal to attach Recipient Login
            goto MenuRestart;
        }
        else if (loginChoice == "4") {
            goto MenuRestart;
        }
        else if (loginChoice == "5") {
            cout << endl << "Returning to Menu..." << endl;
            goto MenuRestart;
        }
        else {
            cout << endl << "Please select a valid option"; 
            goto LoginRestart;
        }
    }
    else if (menuInput == "4") {
        string regChoice;
RegisterRestart:
        cout << "\tRegistration" << endl;
        lineFunc(52, "*");
        cout << endl << endl << "Welcome to the NZ Blood Bank!\nPlease choose which type of account you wish to create: " << endl;
        cout << endl << "[1] Register as a Donor" << endl;
        cout << "[2] Register as a Recipient" << endl;
        cout << endl << endl << "[3] Return to Menu" << endl;
        cout << endl << "Please select a valid option: "; cin >> regChoice;
        if (regChoice == "1") {
            cout << "DONOR REGISTRATION PORTAL" << endl;
            goto MenuRestart;
        }
        else if (regChoice == "2") {
            cout << "RECIPIENT REGISTRATION PORTAL" << endl;
            goto MenuRestart;
        }
        else if (regChoice == "3") {
            cout << endl << "Returning to Menu..." << endl;
            goto MenuRestart;
        }
        else {
            cout << endl << "Please select a valid option";
            goto RegisterRestart;
        }
    }
    else if (menuInput == "5") {
        cout << endl << "Exiting..." << endl;
        exit(1);
    }
    else {
        cout << endl << "Please select a valid option" << endl;
        goto MenuRestart;
    }
}

int main()
{

    cout << endl << "\tWelcome to the NZ Blood Bank System!" << endl;
    lineFunc(52,"*");
    menuFunc();
}

