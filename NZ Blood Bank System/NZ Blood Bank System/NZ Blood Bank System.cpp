// NZ Blood Bank System.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Introduction Screen
// Ainsley wrote this

#include <iostream>
#include <string>
#include "read_a_file_test.h"
using namespace std;


struct donorInfo {
    string firstName;
    string lastName;
    string dob;
    string nationality;
    string ethnicity;
    string gender;
    string underlyCond;
    string bloodGroup;
    string contactNum;
    string emailAddr;
    string physAddr;
    string lastDonation = "";
    string username;
    string password;
};

struct recipientInfo {
    string recipientName;
    string physAddr;
    string emailAddr;
    string contactNum;
    string username;
    string password;
};

void lineFunc(int length, string type) {
    for (int i = 0; i < length; i++)
        cout << type;
}

void recipientRegFunc() {           //Styled to have naturally placed input
    struct recipientInfo recipient;
    cout << endl << endl;
    cout << "\tRecipient Registration" << endl;
    lineFunc(38, "*");
    cout << endl << "Register an account as a Blood Recipient" << endl << endl;
    cin.ignore();
    cout << "Please input your information: ";
    cout << endl << "Full Recipient Name\t: "; getline(cin, recipient.recipientName);
    cout << "Physical Address\t: "; getline(cin, recipient.physAddr);
    cout << "Email Address\t\t: "; getline(cin, recipient.emailAddr);
    cout << "Contact Number\t\t: "; getline(cin, recipient.contactNum);
    cout << "Username\t\t: "; getline(cin, recipient.username);
    cout << "Password\t\t: "; getline(cin, recipient.password);
    cout << endl << endl;
    cout << "Thanks for Registering!" << endl;
    cout << endl << "Returning to Menu..." << endl;
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
    struct donorInfo donor;

    string bloodSelect;
    cout << endl << endl;
    cout << "\tDonor Registration" << endl;
    lineFunc(34,"*");
    cout << endl << "Register an account as a Blood Donor" << endl << endl;
    cin.ignore();
    cout << "Please input your information: ";
    cout << endl << "First Name\t\t\t: "; getline(cin, donor.firstName);
    cout << "Last Name\t\t\t: "; getline(cin, donor.lastName);
    cout << "Date of Birth\t\t\t: "; getline(cin, donor.dob);
    cout << "Nationality\t\t\t: "; getline(cin, donor.nationality);
    cout << "Ethnicity\t\t\t: "; getline(cin, donor.ethnicity);
    cout << "Gender\t\t\t\t: "; getline(cin, donor.gender);
    cout << "Known Underlying Conditions\t: "; getline(cin, donor.underlyCond);
    cout << "Please select your Blood Group\t:";
    cout << endl << endl << "\t[1] A+/-\t[2] B+/-";
    cout << endl << "\t[3] AB+/-\t[4] O+/-" << endl << endl; 
BloodSelectAskAgain:
    cout << "Blood Group: "; cin >> bloodSelect;
    if (bloodSelect == "1") {
        bloodSelect = "A";
    }
    else if (bloodSelect == "2") {
        bloodSelect = "B";
    }
    else if (bloodSelect == "3") {
        bloodSelect = "AB";
    }
    else if (bloodSelect == "4") {
        bloodSelect = "O";
    }
    else {
        cout << endl << "Please select a valid option" << endl;
        goto BloodSelectAskAgain;
    }
    cin.ignore();
    donor.bloodGroup = bloodSelect;
    cout << endl << "Contact Number\t\t\t: "; getline(cin, donor.contactNum);
    cout << "Email Address\t\t\t: "; getline(cin, donor.emailAddr);
    cout << "Physical Address\t\t: "; getline(cin, donor.physAddr);
    cout << "(Optional) Date of Last Donation: "; getline(cin, donor.lastDonation);
    cout << "Username\t\t\t: "; getline(cin, donor.username);
    cout << "Password\t\t\t: "; getline(cin, donor.password);
    cout << endl << endl;
    cout << "Thanks for Registering!" << endl;
    cout << endl << "Returning to Menu..." << endl;
    
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
            //system("pause");
            goto MenuRestart;
        }
        else if (regChoice == "2") {
            
            recipientRegFunc();
            //system("pause");
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
    //read_a_csv();
    menuFunc();
}

