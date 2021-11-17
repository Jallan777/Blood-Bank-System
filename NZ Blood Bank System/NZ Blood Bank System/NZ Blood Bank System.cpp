// NZ Blood Bank System.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Introduction Screen

#include <iostream>
#include <fstream>
#include <string>
#include "Global functions.h" 
using namespace std;


string rNameTemp, rPAddTemp, rEAddTemp, rNumTemp, rUNameTemp, rPWordTemp, recipValidTemp;
string dFNameTemp, dLNameTemp, dDOBTemp, dDOBDay, dDOBMonth, dDOBYear, dNatTemp, dEthnicTemp, dGenderTemp, dUndCondTemp, dBloodTemp, dNumTemp, dEAddTemp, dPAddTemp, dLastDonateTemp, dUnameTemp, dPwordTemp;
string recipientFilePath = "RecipientInfo.csv";
string donorFilePath = "DonorInfo.csv";
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
    string validated = recipValidTemp;
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
R1:    cout << endl << "Full Recipient Name\t: "; getline(cin, rNameTemp); if (rNameTemp == "" || rNameTemp == " ") { cout << endl << "Text Field is Empty!" << endl; goto R1; }
    cout << "Physical Address";
R2:    cout << endl << "\t(Street)\t\t: "; getline(cin, rStreet); if (rStreet == "" || rStreet == " ") { cout << endl << "Text Field is Empty!" << endl; goto R2; }
R3:    cout << "\t(Suburb/Town)\t\t: "; getline(cin, rSuburb); if (rSuburb == "" || rSuburb == " ") { cout << endl << "Text Field is Empty!" << endl; goto R3; }
R4:    cout << "\t(City)\t\t\t: "; getline(cin, rCity); if (rCity == "" || rCity == " ") { cout << endl << "Text Field is Empty!" << endl; goto R4; }
    rPAddTemp = rStreet + "/" + rSuburb + "/" + rCity + "/" + rCountry;
R5:    cout << "Email Address\t\t: "; getline(cin, rEAddTemp); if (rEAddTemp == "" || rEAddTemp == " ") { cout << endl << "Text Field is Empty!" << endl; goto R5; }
R6:    cout << "Contact Number\t\t: "; getline(cin, rNumTemp); if (rNumTemp == "" || rNumTemp == " ") { cout << endl << "Text Field is Empty!" << endl; goto R6; }
R7:    cout << "Username\t\t: "; getline(cin, rUNameTemp); if (rUNameTemp == "" || rUNameTemp == " ") { cout << endl << "Text Field is Empty!" << endl; goto R7; }
R8:    cout << "Password\t\t: "; getline(cin, rPWordTemp); if (rPWordTemp == "" || rPWordTemp == " ") { cout << endl << "Text Field is Empty!" << endl; goto R8; }           //(Below)Quickly checks fields aren't empty and triggers validation if all fields filled
    if (rNameTemp == "" || rNameTemp == " " && rPAddTemp == "" || rPAddTemp == " " && rEAddTemp == "" || rEAddTemp == " " && rNumTemp == "" || rNumTemp == " " && rUNameTemp == "" || rUNameTemp == " " && rPWordTemp == "" || rPWordTemp == " ") {
        recipValidTemp = "No";
    }
    else {
        recipValidTemp = "Yes";
    }
    cout << endl << endl;
    recipientWriteFunc();
    cout << "Thanks for Registering!" << endl;
    cout << endl << "Returning to Menu..." << endl;
}

bool recip_username_exists(string userName) { // TODO

    // username exists = false
    bool userExists = false;
    
    string filePath = "C:\\Users\\ainsley2\\Desktop\\ainsley josh folder\\NZ Blood Bank System\\NZ Blood Bank System\\Patient info.csv";
    // for each line in file
        // check relevent colum in this line
        // if this line matches
            //username exists = true
            // stop looping
        // else 
            //keep looping



}


void recipientLoginFunc() {           
    
    //TODO check that the username and password exist and are correct - exception handle if not
    //TODO figure out how to not make an infinite ask for password loop


    //formatting
    cout << endl << endl;
    cout << "\tRecipient Login" << endl;
    lineFunc(31, "*");
    cout << endl << "Log In as a Blood Recipient" << endl << endl;

    // ask for username
    string temp_user;
    cout << endl << "\tUsername: "; getline(cin, temp_user);
    
    // check username exists in the csv by calling recip_username_exists()
    bool username_exists = recip_username_exists(temp_user);
    
    
    if (username_exists) {

        //load recip into a struct TODO
        
  
    PassReAsk: 
        string temp_pass;
        int loginCounter = 0;
        cout << endl << "\tPassword: "; getline(cin, temp_pass);
        cout << endl << endl;
        
        // check that it applies to this user name TODO
        
        if (applies) {

            // log the user in as recipient ( maybe toggle a bool) TODO
            
            
            //return out of recipientLoginFunc TODO
        }
        else {
            if (loginCounter <= 3) {
                cout << endl << "\tToo Many Login Attempts" << endl << endl << "Returning to Menu...";
                menuFunc();
            }
            else {
                // tell user invalid password! 
                cout << endl << "\tInvalid Password!, please try again ";
                loginCounter++;
                goto PassReAsk;
            }

        }
    }   

    else {
        //tell user "username" isnt registered! 
        cout << endl << "\tThe username " <<  temp_user  << " is not registered as a recipient!";
        
        
        //return out of recipientLoginFunc //TODO

    }
    
}


void donorInfo::donorRegFunc() {               //Styled to have inputs all start on the same column
    struct donorInfo donor;

    string bloodSelect, dStreet, dSuburb, dCity, dCountry;
    cout << endl << endl;

    //Formatting
    cout << "\tDonor Registration" << endl;
    lineFunc(34,"*");
    cout << endl << "Register an account as a Blood Donor" << endl << endl;
    cin.ignore();
    cout << "Please input your information: ";

    //Takes user input and stores in temp variable before moving into structure
R1:    cout << endl << "First Name\t\t\t: "; getline(cin, dFNameTemp); if (dFNameTemp == "" || dFNameTemp == " ") { cout << endl << "Text Field is Empty!" << endl; goto R1; }
R2:    cout << "Last Name\t\t\t: "; getline(cin, dLNameTemp); if (dLNameTemp== "" || dLNameTemp== " ") { cout << endl << "Text Field is Empty!" << endl; goto R2; }
    cout << "Date of Birth\t\t\t(DD/MM/YYYY)";
R3:    cout << endl << "\t\t\tDay\t: "; getline(cin, dDOBDay); if (dDOBDay == "" || dDOBDay == " ") { cout << endl << "Text Field is Empty!" << endl; goto R3; }
R4:    cout << "\t\t\tMonth\t: "; getline(cin, dDOBMonth); if (dDOBMonth == "" || dDOBMonth == " ") { cout << endl << "Text Field is Empty!" << endl; goto R4; }
R5:    cout << "\t\t\tYear\t: "; getline(cin, dDOBYear); if (dDOBYear == "" || dDOBYear == " ") { cout << endl << "Please input Year" << endl; goto R5; }
    dDOBTemp = dDOBDay + "/" + dDOBMonth + "/" + dDOBYear; //DOB split into different parts to try make sure the format is the same when put into struct
R6:    cout << "Nationality\t\t\t: "; getline(cin, dNatTemp); if (dNatTemp == "" || dNatTemp == " ") { cout << endl << "Text Field is Empty!" << endl; goto R6; }
R7:    cout << "Ethnicity\t\t\t: "; getline(cin, dEthnicTemp); if ( dEthnicTemp == "" || dEthnicTemp == " ") { cout << endl << "Text Field is Empty!" << endl; goto R7; }
R8:    cout << "Gender\t\t\t\t: "; getline(cin, dGenderTemp); if ( dGenderTemp == "" || dGenderTemp == " ") { cout << endl << "Text Field is Empty!" << endl; goto R8; }
R9:    cout << "Known Underlying Conditions\t: "; getline(cin, dUndCondTemp); if ( dUndCondTemp == "" || dUndCondTemp == " ") { cout << endl << "Text Field is Empty!" << endl; goto R9; }
    cout << "Please select your Blood Group\t:";            //Asks user to select their blood group from a list of selections
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
R10:    cout << endl << "Contact Number\t\t\t: "; getline(cin, dNumTemp); if ( dNumTemp == "" || dNumTemp == " ") { cout << endl << "Text Field is Empty!" << endl; goto R10; }
R11:    cout << "Email Address\t\t\t: "; getline(cin, dEAddTemp); if ( dEAddTemp == "" || dEAddTemp == " ") { cout << endl << "Text Field is Empty!" << endl; goto R11; }
    cout << "Physical Address\t\t:";                                        //Breaks down address into parts, so user doesn't try to use comma's to seperate values
R12:    cout << endl << "\t(Street)\t\t: "; getline(cin, dStreet); if ( dStreet == "" || dStreet == " ") { cout << endl << "Text Field is Empty!" << endl; goto R12; }
R13:    cout << "\t(Suburb/Town)\t\t: "; getline(cin, dSuburb); if ( dSuburb == "" || dSuburb == " ") { cout << endl << "Text Field is Empty!" << endl; goto R13; }
R14:    cout << "\t(City)\t\t\t: "; getline(cin, dCity); if ( dCity == "" || dCity == " ") { cout << endl << "Text Field is Empty!" << endl; goto R14; }
    dPAddTemp = dStreet + "/" + dSuburb + "/" + dCity + "/" + dCountry;     //Address parts combined into one string
    cout << "Date of Last Donation" << endl; 
    cout << "(Press Enter if Unknown)\t: "; getline(cin, dLastDonateTemp);
    if (dLastDonateTemp == "") {                                            //If statement allows user to press enter and move past this question, and fills data with "unknown"
        dLastDonateTemp = "Unknown";
    }
R15:    cout << "Username\t\t\t: "; getline(cin, dUnameTemp); if ( dUnameTemp == "" || dUnameTemp == " ") { cout << endl << "Text Field is Empty!" << endl; goto R15; }
R16:    cout << "Password\t\t\t: "; getline(cin, dPwordTemp); if (dPwordTemp == "" || dPwordTemp == " ") { cout << endl << "Text Field is Empty!" << endl; goto R16; }
    cout << endl << endl;
    donorWriteFunc();
    cout << "Thanks for Registering!" << endl;
    cout << endl << "Returning to Menu..." << endl;
    
}

void donorLoginFunc() { //TODO use very similar logic to recipientLoginFunc
    cout << endl << endl;
    cout << "\tDonor Login" << endl;
    lineFunc(28, "*");
    cout << endl << "Log In as a Blood Donor" << endl << endl;
    cout << endl << "\tUsername: ";
    cout << endl << "\tPassword: ";
    cout << endl << endl;
}

void adminLoginFunc() { //TODO use very similar logic to recipientLoginFunc
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
    file1 << "| " << recipient.emailAddr << ",";
    file1 << "| " << recipient.contactNum << ",";
    file1 << " " << recipient.username << ",";
    file1 << " " << recipient.password << ",";
    file1 << " " << recipient.validated << "\n";
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
            
            goto MenuRestart;
        }
        else if (regChoice == "2") {
            
            recipientRegFunc();
            
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
    else if (menuInput == "6") {
        donorFrontPage();
    }
    else if (menuInput == "7") {
        recipFrontPage();
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

