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
        cout << endl << "Press any button to return to the Menu..." << endl;
        cin.ignore();
        goto MenuRestart;
    }
    else if (menuInput == "2") {
        cout << endl << "\tNZ Blood Bank Contact Details" << endl;
        lineFunc(52, "*");
        cout << endl << "Email Us: contact@nzblood.co.nz" << endl;
        cout << "Give Us a Call: 0800 448 325" << endl;
        cout << endl << "Press any button to return to the Menu..." << endl;
        cin.ignore();
        goto MenuRestart;

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

