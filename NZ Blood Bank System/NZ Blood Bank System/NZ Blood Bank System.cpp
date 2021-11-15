// NZ Blood Bank System.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Introduction Screen

#include <iostream>
#include <fstream>
#include <string>
#include "read_a_file_test.h"
using namespace std;

string rNameTemp, rPAddTemp, rEAddTemp, rNumTemp, rUNameTemp, rPWordTemp;
string dFNameTemp, dLNameTemp, dDOBTemp, dNatTemp, dEthnicTemp, dGenderTemp, dUndCondTemp, dBloodTemp, dNumTemp, dEAddTemp, dPAddTemp, dLastDonateTemp, dUnameTemp, dPwordTemp;
string recipientFilePath = "C:/Users/jacob/OneDrive/Documents/GitHub/Blood-Bank-System/NZ Blood Bank System/NZ Blood Bank System/RecipientInfo.csv";
string donorFilePath = "C:/Users/jacob/OneDrive/Documents/GitHub/Blood-Bank-System/NZ Blood Bank System/NZ Blood Bank System/DonorInfo.csv";
fstream file1, file2;



// Struct to hold Donor Information and eventually transfer it to the CSV file
struct donorInfo {
    string firstName = dFNameTemp;
    string lastName = dLNameTemp;
    string dob = dDOBTemp;
    string nationality = dNatTemp;
    string ethnicity = dEthnicTemp;
    string gender = dGenderTemp;
    string underlyCond = dUndCondTemp;
    string bloodGroup = dBloodTemp;
    string contactNum = dNumTemp;
    string emailAddr = dEAddTemp;
    string physAddr = dPAddTemp;
    string lastDonation = dLastDonateTemp;
    string username = dUnameTemp;
    string password = dPwordTemp;

    void donorRegFunc();
};

// Struct to hold Recipient Information and eventually transfer it to the CSV file
struct recipientInfo {
    string recipientName = rNameTemp;
    string physAddr = rPAddTemp;
    string emailAddr = rEAddTemp;
    string contactNum = rNumTemp;
    string username = rUNameTemp;
    string password = rPWordTemp;
};

void recipientWriteFunc();
void donorWriteFunc();

 //Simple Function to write a line of variable length, with any character
void lineFunc(int length, string type) {
    for (int i = 0; i < length; i++)
        cout << type;
}

//Recipient Registration Function
void recipientRegFunc() {           
    struct recipientInfo recipient;     //Declares the relevant struct in the function to be able to fill struct with data
    string rStreet, rSuburb, rCity, rCountry;
    cout << endl << endl;
    cout << "\tRecipient Registration" << endl;
    lineFunc(38, "*");
    cout << endl << "Register an account as a Blood Recipient" << endl << endl;
    cin.ignore();
    cout << "Please input your information: ";  //Takes user input and adds to struct
    cout << endl << "Full Recipient Name\t: "; getline(cin, rNameTemp);
    cout << "Physical Address\t\t:";
    cout << endl << "\t(Street)\t\t: "; getline(cin, rStreet); //dPAddTemp
    cout << "\t(Suburb)\t\t: "; getline(cin, rSuburb);
    cout << "\t(City)\t\t\t: "; getline(cin, rCity);
    cout << "\t(Country)\t\t: "; getline(cin, rCountry);
    rPAddTemp = rStreet + "/" + rSuburb + "/" + rCity + "/" + rCountry;
    cout << "Email Address\t\t: "; getline(cin, rEAddTemp);
    cout << "Contact Number\t\t: "; getline(cin, rNumTemp);
    cout << "Username\t\t: "; getline(cin, rUNameTemp);
    cout << "Password\t\t: "; getline(cin, rPWordTemp);
    cout << endl << endl;
    recipientWriteFunc();
    cout << "Thanks for Registering!" << endl;
    cout << endl << "Returning to Menu..." << endl;
}

void recipientLoginFunc() {           //TODO check that the username and password exist and are correct - exception handle if not
    cout << endl << endl;
    cout << "\tRecipient Login" << endl;
    lineFunc(31, "*");
    cout << endl << "Log In as a Blood Recipient" << endl << endl;
    cout << endl << "\tUsername: ";
    cout << endl << "\tPassword: ";
    cout << endl << endl;
}


void donorInfo::donorRegFunc() {               //Styled to have inputs all start on the same column
    struct donorInfo donor;

    string bloodSelect, dStreet, dSuburb, dCity, dCountry;
    cout << endl << endl;
    cout << "\tDonor Registration" << endl;
    lineFunc(34,"*");
    cout << endl << "Register an account as a Blood Donor" << endl << endl;
    cin.ignore();
    cout << "Please input your information: ";
    cout << endl << "First Name\t\t\t: "; getline(cin, dFNameTemp);
    cout << "Last Name\t\t\t: "; getline(cin, dLNameTemp);
    cout << "Date of Birth\t\t\t: "; getline(cin, dDOBTemp);
    cout << "Nationality\t\t\t: "; getline(cin, dNatTemp);
    cout << "Ethnicity\t\t\t: "; getline(cin, dEthnicTemp);
    cout << "Gender\t\t\t\t: "; getline(cin, dGenderTemp);
    cout << "Known Underlying Conditions\t: "; getline(cin, dUndCondTemp);
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
    dBloodTemp = bloodSelect;
    cout << endl << "Contact Number\t\t\t: "; getline(cin, dNumTemp);
    cout << "Email Address\t\t\t: "; getline(cin, dEAddTemp);
    cout << "Physical Address\t\t:";
    cout << endl << "\t(Street)\t\t: "; getline(cin, dStreet); //dPAddTemp
    cout << "\t(Suburb)\t\t: "; getline(cin, dSuburb);
    cout << "\t(City)\t\t\t: "; getline(cin, dCity);
    cout << "\t(Country)\t\t: "; getline(cin, dCountry);
    dPAddTemp = dStreet + "/" + dSuburb + "/" + dCity + "/" + dCountry;
    cout << "(Optional) Date of Last Donation: "; getline(cin, dLastDonateTemp);
    cout << "Username\t\t\t: "; getline(cin, dUnameTemp);
    cout << "Password\t\t\t: "; getline(cin, dPwordTemp);
    cout << endl << endl;
    cout << dPAddTemp;
    donorWriteFunc();
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

void recipientWriteFunc() {

    
    file1.open(recipientFilePath, ios::app);
    struct recipientInfo recipient;
    file1 << recipient.recipientName << ",";
    file1 << " " << recipient.physAddr << ",";
    file1 << " " << recipient.emailAddr << ",";
    file1 << " " << recipient.contactNum << ",";
    file1 << " " << recipient.username << ",";
    file1 << " " << recipient.password << "\n";
    file1.close();
}

void donorWriteFunc() {
    file2.open(donorFilePath, ios::app);
    struct donorInfo donor;
    file2 << donor.firstName << ",";
    file2 << donor.lastName << ",";
    file2 << donor.dob << ",";
    file2 << donor.nationality << ",";
    file2 << donor.ethnicity << ",";
    file2 << donor.gender << ",";
    file2 << donor.underlyCond << ",";
    file2 << donor.bloodGroup << ",";
    file2 << donor.contactNum << ",";
    file2 << donor.emailAddr << ",";
    file2 << donor.physAddr << ",";
    file2 << donor.lastDonation << ",";
    file2 << donor.username << ",";
    file2 << donor.password << "\n";
    file2.close();
}

void menuFunc() {
    donorInfo donor;
    recipientInfo recipient;
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
            
            donor.donorRegFunc();
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
    
    //file1.open(recipientFilePath, ios::out);
    //file1 << "Recipient Name,Physical Address,Email Address,Contact Number,Username,Password" << endl;
    //file1.close();
    //file2.open(donorFilePath, ios::out);
    //file2 << "First Name,Last Name,Date of Birth,Nationality,Ethnicity,Gender,Underlying Conditions,Blood Group,Contact Number,Email Address,Physical Address,Date of Last Donation,Username,Password" << endl;
    //file2.close();
    //read_a_csv();
    menuFunc();
}

