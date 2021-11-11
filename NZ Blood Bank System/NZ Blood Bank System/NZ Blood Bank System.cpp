// NZ Blood Bank System.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Introduction Screen

#include <iostream>
using namespace std;


void lineFunc(int length, string type) {
    for (int i = 0; i < length; i++)
        cout << type;
}

void recipientRegFunc() {           //Styled to have naturally placed input
    cout << endl << endl;
    cout << "\tRecipient Registration" << endl;
    lineFunc(38, "*");
    cout << endl << "Register an account as a Blood Recipient" << endl << endl;
    cout << "Please input your information: ";
    cout << endl << "Recipient Name:\t";
    cout << endl << "Physical Address:\t";
    cout << endl << "Email Address:\t";
    cout << endl << "Contact Number:\t";
    cout << endl << "Username:\t";
    cout << endl << "Password:\t";
    cout << endl << endl;
}

void recipientLoginFunc() {
    cout << endl << endl;
    cout << "\tRecipient Login" << endl;
    lineFunc(31, "*");
    cout << endl << "Log In as a Blood Recipient" << endl << endl;
    cout << endl << "\tUsername: ";
    cout << endl << "\tPassword: ";
    cout << endl << endl;
}


void donorRegFunc() {               //Styled to have inputs all start on the same column
    cout << endl << endl;
    cout << "\tDonor Registration" << endl;
    lineFunc(34,"*");
    cout << endl << "Register an account as a Blood Donor" << endl << endl;
    cout << "Please input your information: ";
    cout << endl << "First Name\t\t\t:";
    cout << endl << "Last Name\t\t\t:";
    cout << endl << "Date of Birth\t\t\t:";
    cout << endl << "Nationality\t\t\t:";
    cout << endl << "Ethnicity\t\t\t:";
    cout << endl << "Gender\t\t\t\t:";
    cout << endl << "Known Underlying Conditions\t:";
    //Blood Group
    cout << endl << "Contact Number\t\t\t:";
    cout << endl << "Email Address\t\t\t:";
    cout << endl << "Physical Address\t\t:";
    cout << endl << "(Optional) Date of Last Donation:";
    cout << endl << "Username\t\t\t:";
    cout << endl << "Password\t\t\t:";
    cout << endl << endl;
}

void donorLoginFunc() {
    cout << endl << endl;
    cout << "\tDonor Login" << endl;
    lineFunc(28, "*");
    cout << endl << "Log In as a Blood Donor" << endl << endl;
    cout << endl << "\tUsername: ";
    cout << endl << "\tPassword: ";
    cout << endl << endl;
}

void adminLoginFunc() {
    cout << endl << endl;
    cout << "\tAdministrator Login" << endl;
    lineFunc(35, "*");
    cout << endl << "Log In as Administrator" << endl << endl;
    cout << endl << "\tUsername: ";
    cout << endl << "\tPassword: ";
    cout << endl << endl;
}

void menuFunc() {
    string menuInput;
MenuRestart:
    cout << endl << "\tWelcome to the NZ Blood Bank System!" << endl;
    lineFunc(54, "*");
    cout << endl << "[1] Information" << endl;
    cout << "[2] Contact Details" << endl;
    cout << "[3] Log In" << endl;
    cout << "[4] Register" << endl;
    cout << "[5] Exit" << endl;
    cout << endl << "Please enter a selection: "; cin >> menuInput;
    cin.ignore();
    if (menuInput == "1") {
        cout << endl << "\tNZ Blood Bank Information" << endl;
        lineFunc(43, "*");
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
        lineFunc(45, "*");
        cout << endl << endl << "Email Us:\t contact@nzblood.co.nz" << endl;
        cout << "Call Us:\t 0800 448 325" << endl << endl;
        cout << "Or come into any NZ Blood Donation center for more information" << endl;
        cout << endl << "Press Enter to return to the Menu..." << endl;
        cin.ignore();
        goto MenuRestart;

    }
    else if (menuInput == "3") {
        string loginChoice;
    LoginRestart:
        cout << endl << "\tLog In" << endl;
        lineFunc(22, "*");
        cout << endl << endl << "[1] Donor Login" << endl;
        cout << "[2] Recipient Login" << endl;
        cout << "[3] Admin Login" << endl;
        cout << endl << endl << "[4] Return to Menu" << endl;
        cout << endl << "Please select a valid option: "; cin >> loginChoice;
        if (loginChoice == "1") {
            donorLoginFunc();       //Portal to attach Donor Login
            system("pause");
            goto MenuRestart;
        }
        else if (loginChoice == "2") {
            recipientLoginFunc();   //Portal to attach Recipient Login
            system("pause");
            goto MenuRestart;
        }
        else if (loginChoice == "3") {
            adminLoginFunc();       //Portal to attach Admin Login (assuming we have a pre-made Admin User)
            system("pause");
            goto MenuRestart;
        }
        else if (loginChoice == "4") {
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
        lineFunc(28, "*");
        cout << endl << endl << "Welcome to the NZ Blood Bank!\nPlease choose which type of account you wish to create: " << endl;
        cout << endl << "[1] Register as a Donor" << endl;
        cout << "[2] Register as a Recipient" << endl;
        cout << endl << endl << "[3] Return to Menu" << endl;
        cout << endl << "Please select a valid option: "; cin >> regChoice;
        if (regChoice == "1") {
            
            donorRegFunc();
            system("pause");
            goto MenuRestart;
        }
        else if (regChoice == "2") {
            
            recipientRegFunc();
            system("pause");
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


    menuFunc();
}

