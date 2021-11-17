// NZ Blood Bank System.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Introduction Screen

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


string rNameTemp, rPAddTemp, rEAddTemp, rNumTemp, rUNameTemp, rPWordTemp, recipValidTemp;
string dFNameTemp, dLNameTemp, dDOBTemp, dDOBDay, dDOBMonth, dDOBYear, dNatTemp, dEthnicTemp, dGenderTemp, dUndCondTemp, dBloodTemp, dNumTemp, dEAddTemp, dPAddTemp, dLastDonateTemp, dUnameTemp, dPwordTemp;
string recipientFilePath = "RecipientInfo.csv"; // TODO MAKE SURE THIS IS RECIPIENT 
string donorFilePath = "DonorInfo.csv";
fstream file1, file2;


enum donor_data_type{ 
    First_Name,
    last_name,
    DOB,
    nationality,
    ethnicity,
    gender,
    underlying_condition,
    blood_group,
    contact_no,
    email,
    physical_address,
    last_date_of_donation,
    donor_username,
    donor_password };


enum recip_data_type{

    recipient_name,
    physAddr,
    emailAddr,
    contactNum,
    recip_username,
    recip_passord };

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
void menuFunc();

//Simple Function to write a line of variable length, with any character
void lineFunc(int length, string type) {
    for (int i = 0; i < length; i++)
        cout << type;
}

// for string delimiter                                                      <---- copied from stack overflow https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
vector<string> split(string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}


//
bool InfoExists(std::string target_info, string file_to_open, int where_to_look) {

    ifstream file;
    std::string line;
    bool isHeader = true;

    file.open(file_to_open, std::ios::in);
    while (std::getline(file, line)) {
        // this is the CSV header so skip it      
        if (isHeader) {
            isHeader = false;
            continue;
        }
        // split the CSV line into an array
        vector<string> values = split(line, ",");
        // the name is at index[1]            
        string info = values[where_to_look]; // the enum is one less then the column number
        // check info against the correct column
        if (info == target_info) {
            // if we find the info in the right place, clean up our resources
            // and return early
            file.close();
            return true;
        }
    }
    // otherwise we didn't find the user,
    // clean up our resources and return
    file.close();
    return false;
}






//Extract Donor Information from CSV File into struct
//donorInfo Get_donor_info(int data_row_num, string file_to_open) { //TODO put a line from the csv into a struct and returning that struct
//
//    ifstream file;
//    std::string line;
//    bool isHeader = true;
//    int row_counter = 0;
//
//    donorInfo info_to_return = {};
//
//    file.open(file_to_open, std::ios::in);
//    while (std::getline(file, line)) {
//        // this is the CSV header so skip it      
//        if (isHeader) {
//            isHeader = false;
//            continue;
//        }
//        row_counter++; // make sure we are only looking at the desired row
//
//        if (data_row_num == row_counter) {
//
//
//            // split the CSV line into an array
//            // assign the values in the vector to the correct parts of the struct
//            vector<string> values = split(line, ",");
//            info_to_return.firstName = values[0];
//            info_to_return.lastName = values[1];
//            info_to_return.dob = values[2];
//            info_to_return.nationality = values[3];
//            info_to_return.ethnicity = values[4];
//            info_to_return.gender = values[5];
//            info_to_return.underlyCond = values[6];
//            info_to_return.bloodGroup = values[7];
//            info_to_return.contactNum = values[8];
//            info_to_return.emailAddr = values[9];
//            info_to_return.physAddr = values[10];
//            info_to_return.lastDonation = values[11];
//            info_to_return.username = values[12];
//            info_to_return.password = values[13];
//
//            //close the file
//            file.close();
//
//            //once its full with the info return it
//            return info_to_return;
//        }
//
//    } file.close();
//    return info_to_return;
//
//
//}

recipientInfo Get_recipient_info(int data_row_num, string file_to_open) {

    ifstream file;
    std::string line;
    bool isHeader = true;
    int row_counter = 0;

    recipientInfo info_to_return = {};

    file.open(file_to_open, std::ios::in);
    while (std::getline(file, line)) {
        // this is the CSV header so skip it      
        if (isHeader) {
            isHeader = false;
            continue;
        }
        row_counter++; // make sure we are only looking at the desired row

        if (data_row_num == row_counter) {


            // split the CSV line into an array
            // assign the values in the vector to the correct parts of the struct
            vector<string> values = split(line, ",");
            info_to_return.recipientName = values[0];
            info_to_return.physAddr = values[1];
            info_to_return.emailAddr = values[2];
            info_to_return.contactNum = values[3];
            info_to_return.username = values[4];
            info_to_return.password = values[5];
            info_to_return.validated = values[6];

            file.close();
            return info_to_return;
        }
    } file.close();
    return info_to_return;
}

//get_recip_info() TODO

// get admin info() TODO


//Donor Post-Login Screen
void donorFrontPage() {             //Landing page after Donor has logged in
    string moreInfo, moreInfo2;
    string donorMenuChoice;
    //Formatting
    cout << endl << "\tWelcome [NAME]" << endl;     //TODO get Name of donor from csv and display
    lineFunc(30, "*");
    cout << endl << endl;
    cout << "[1] Blood Donation Procedure" << endl;
    cout << "[2] Benefits of Donating Blood" << endl;
    cout << "[3] Book A Visit!" << endl;
    cout << "[4] Manage my Account" << endl << endl;
    cout << "[5] Logout & Return to Menu" << endl << endl;
    cout << "Please Select an Option: "; getline(cin, donorMenuChoice);
    //Take user input to navigate menu
    if (donorMenuChoice == "1") {
        cout << endl << endl;
        cout << "\tThe Blood Donation Procedure" << endl;           //Blood Donation Procedure, broken up into chunks to avoid wall of text
        lineFunc(50, "*");
        cout << endl;
        cout << "\tUpon Your Arrival..." << endl << endl;
        cout << "When you first arrive to donate blood, you will need to have with you a suitable form of ID. " << endl
            << "(This can include your Birth Certificate, Drivers License, Passport, or a School or University ID) " << endl
            << "Once checked-in, you will need to read a few mandatory pamphlets and complete a Health Questionnaire. " << endl
            << "After this, you will need to sign a declaration confirming that the information you gave was accurate " << endl
            << "to the best of your knowledge, and giving consent to test your blood once donated. Finally, you will " << endl
            << "have a confidential interview, and a finger prick test to determine your Haemoglobin level. During this " << endl
            << "process, you can feel free to ask any questions you may still have." << endl << endl;
    M1Ask:                                                          //Asks user if they want to continue
        cout << "More? [Y]/[N]"; cin >> moreInfo;
        if (moreInfo == "Y" || moreInfo == "y") {
            cout << endl;
            cout << "\tYour Donation..." << endl << endl;
            cout << "After you've successfully completed the interview, you will be seated comfortably on one of our " << endl
                << "donation chairs. Your arm will then be cleaned on the inside of your elbow, and we will use a sterile, " << endl
                << "single use needle and insert it into the inside of your elbow. You may feel some discomfort, but we'll " << endl
                << "do our best to minimise it. A blood donation can take up to 60 minutes, and a unit (around 470ml) of " << endl
                << "blood will be collected. The needle is then removed and a bandage is applied." << endl << endl;
        M2Ask:                                                      //Asks user if they want to continue again
            cout << "More? [Y]/[N]"; cin >> moreInfo2;
            if (moreInfo2 == "Y" || moreInfo2 == "y") {
                cout << endl;
                cout << "\tBefore You Leave..." << endl << endl;
                cout << "After your donation is complete, you will be asked to rest on the chair for up to 10 minutes. When " << endl
                    << "you feel ready, you can head into the recovery area for some refreshments, as its important to " << endl
                    << "replenish your energy after you donate blood. We'd like to keep an eye on you for another 10-15 " << endl
                    << "minutes to make sure you feel fine before you leave. After that, you're welcome to head home. " << endl
                    << "If you are able to, we and our Blood Recipients would appreciate it if you'd book your next blood " << endl
                    << "donation visit. Donating blood regularly saves more lives than you think!" << endl << endl;
                cin.ignore();
                donorFrontPage();

            }
            else if (moreInfo2 == "N" || moreInfo2 == "n") {        //If user doesn't want to continue then return to Donor Landing Page
                cin.ignore();
                donorFrontPage();
            }
            else {
                cout << endl << "Please Input a Valid Option" << endl;  //Exception handling for user input
                goto M2Ask;
            }
        }
        else if (moreInfo == "N" || moreInfo == "n") {
            cin.ignore();                                           //If user doesn't want to continue then return to Donor Landing Page
            donorFrontPage();
        }
        else {
            cout << endl << "Please Input a Valid Option" << endl;      //Exception handling for user input
            goto M1Ask;
        }
    }
    else if (donorMenuChoice == "2") {
        cout << "\tBenefits of Donating Blood" << endl;                 //Benefits of donating blood
        lineFunc(40, "*");
        cout << endl << endl;
        cout << "Aside from potentially saving thousands of lives, donating blood comes with a few extra benefits." << endl
            << "Here are a few health benefits linked to donating blood:" << endl << endl
            << endl << "1. Donating Blood Can Reveal Potential Health Problems" << endl
            << "\t- Although not the same as going to the doctor, donating blood can be another way to keep an eye on your " << endl
            << "\t  cardiovascular health." << endl
            << "\t- While donating, somebody will check your pulse, blood pressure, body temperature, hemoglobin and more." << endl
            << "\t- They will also inform you of any other blood issues they notice or if anything seems unusual." << endl << endl;
        cout << "Press Enter to Continue..."; cin.ignore();                 //Breaks up information into 5 chunks, with a button press function to continue
        cout << endl << "2. Giving Blood Can Reduce Harmful Iron Stores" << endl
            << "\t- Hemochromatosis is a disease that causes an iron overload, and it affects 1 in every 200 " << endl
            << "\t  New Zealanders." << endl
            << "\t- The CDC says the removal of red blood cells by donating blood is the preferred treatment for " << endl
            << "\t  patients with excess iron in their blood." << endl << endl;
        cout << "Press Enter to Continue..."; cin.ignore();
        cout << endl << "3. Giving Blood May Lower Risk Of Suffering A Heart Attack" << endl
            << "\t- High levels of iron in the blood constrict your blood vessels and create more risk of a heart attack." << endl
            << "\t- Depleting those extra iron deposits by donating blood gives your vessels more room to operate." << endl
            << "\t- Donating blood at least once a year could reduce your risk of a heart attack by 88 percent, according " << endl
            << "\t  to a study conducted by the American Journal of Epidemiology" << endl << endl;
        cout << "Press Enter to Continue..."; cin.ignore();
        cout << endl << "4. Giving Blood Can Help Your Liver Stay Healthy" << endl
            << "\t- Another danger of iron overload is the health of your liver." << endl
            << "\t- Research has linked too much iron with NAFLD (Non-Alcoholic Fatty Liver Disease, Hepatitis C and " << endl
            << "\t- other liver issues." << endl
            << "\t- Though there are many other factors, donating blood can help relieve some of those iron stores " << endl
            << "\t  and avoid extra issues in your liver." << endl << endl;
        cout << "Press Enter to Continue..."; cin.ignore();
        cout << endl << "5. Giving Blood Can Help Your Mental State" << endl
            << "\t- While there are several physical benefits to donating blood, the most powerful health benefit is " << endl
            << "\t  arguably in the psychological realm. Donating blood means that someone, somewhere will be " << endl
            << "\t  getting the help they desperately need." << endl
            << "\t- Donating blood, especially on a regular basis, can be similar to volunteer work. You give of your " << endl
            << "\t  time to help strangers in need. If you go to the same donation place each time, you’ll get to know " << endl
            << "\t  some of the staff who are also dedicating themselves to the cause of saving lives." << endl
            << "\t- Volunteering has been shown to have positive effects on happiness. In people over 65-years-old, " << endl
            << "\t  volunteering also reduces the risk of depression and loneliness." << endl << endl;
        cout << "Press Enter to Continue..."; cin.ignore();
        donorFrontPage();               //Return to Donor Landing Page
    }
    else if (donorMenuChoice == "3") {
        //Book a visit TODO
        cout << endl << "Book Your Blood Donation" << endl;
        cout << "Press Enter to Return" << endl; cin.ignore();
        donorFrontPage();
    }
    else if (donorMenuChoice == "4") {
        string dManageChoice;
    dManageAsk:
        cout << "\tAccount Management" << endl;
        lineFunc(30, "*");
        cout << endl << endl;
        cout << "[1] Manage Booking" << endl;
        cout << "[2] Edit Your Info" << endl << endl;
        cout << "[3] Return to Donor Menu" << endl;
        cout << "Please Select an Option: "; cin >> dManageChoice;
        if (dManageChoice == "1") {
            //TODO Manage Booking - requires booking system first. would guess each patient is tagged with a unique random number to identify?
            cout << endl << "Manage Booking" << endl;
            cout << "Press Enter to Return" << endl; cin.ignore();
            donorFrontPage();
        }
        else if (dManageChoice == "2") {
            //TODO Edit Info - needs to access file, display current details for user and provide option to change details
            //-needs working find in csv func 
            cout << endl << "Edit Your Information" << endl;
            cout << "Press Enter to Return" << endl; cin.ignore();
            donorFrontPage();
        }
        else if (dManageChoice == "3") {
            cout << endl << "Press Enter to Return" << endl; cin.ignore();
            donorFrontPage();
        }
        else {
            cout << endl << "Please Input a Valid Option" << endl;      //Exception handling for user input
            goto dManageAsk;
        }
    }
    else if (donorMenuChoice == "5") {
        cout << endl << "Logging out..." << endl;
        menuFunc();
    }
    else {
        cout << endl << "Please Input a Valid Option" << endl;      //Exception handling for user input
        cout << "Press Enter to Return" << endl; cin.ignore();
        donorFrontPage();
    }

}

//Recipient Post-Login Screen
void recipFrontPage() {
    string recipMenuChoice, bloodOnlySearch, locationBloodSearch;
    //TODO menu with options to:
    //-see donor info by blood group (read csv and find n amount of people based if blood group the same)
    //-access donors by location and blood group (same as above, but including location too)
    //-find potential donor contact details by giving full name (again, look for specific name in csv and display corresponding details)

    //Formatting
    cout << endl << "\tWelcome [NAME]" << endl;     //TODO get Name of recipient from csv and display
    lineFunc(30, "*");
    cout << endl << endl;
    cout << "[1] See Donors by Blood Group" << endl;
    cout << "[2] See Donors by Location & Blood Group" << endl;
    cout << "[3] Donor Name Search" << endl << endl;
    cout << "[4] Logout & Return to Menu" << endl << endl;
    cout << "Please Select an Option: "; getline(cin, recipMenuChoice);
    if (recipMenuChoice == "1") {
        //See donors by blood group TODO
        // -needs csv searcher
    BloodSearchRestart:
        cout << endl << "\tDonors by Blood Type" << endl;
        lineFunc(36, "*");
        cout << endl << "\tSelect Blood Group: " << endl << endl;
        cout << "\t[1] Type A" << "\t[3]Type AB" << endl << "\t[2]Type B" << "\t [4]Type O" << endl << endl;
        cout << "Please Select an Option: "; getline(cin, bloodOnlySearch);
        if (bloodOnlySearch == "1") {
            bloodOnlySearch = "A";
            //Find any donors that match blood type, display their full name and blood group TODO
        }
        else if (bloodOnlySearch == "2") {
            bloodOnlySearch = "B";
            //Find any donors that match blood type, display their full name and blood group
        }
        else if (bloodOnlySearch == "3") {
            bloodOnlySearch = "A";
            //Find any donors that match blood type, display their full name and blood group
        }
        else if (bloodOnlySearch == "4") {
            bloodOnlySearch = "O";
            //Find any donors that match blood type, display their full name and blood group
        }
        else {
            cout << endl << "Please Select a Valid Option" << endl;
            goto BloodSearchRestart;
        }
        cout << endl << "Press Enter to Return" << endl; cin.ignore();
        recipFrontPage();
    }
    else if (recipMenuChoice == "2") {
        //See donors by location and blood group TODO
        // -needs csv searcher
        cout << endl << "Donors by Location & Blood Type" << endl;
        cout << "Press Enter to Return" << endl; cin.ignore();
        recipFrontPage();
    }
    else if (recipMenuChoice == "3") {
        //search donors Full Name and recieve contact details for that donor TODO
        // -needs csv searcher
        cout << endl << "Search Donors by Full Name" << endl;
        cout << "Press Enter to Return" << endl; cin.ignore();
        recipFrontPage();
    }
    else if (recipMenuChoice == "4") {
        cout << endl << "Logging out..." << endl;
        menuFunc();
    }
    else {
        cout << endl << "Please Input a Valid Option" << endl;      //Exception handling for user input
        cout << "Press Enter to Return" << endl; cin.ignore();
        recipFrontPage();
    }
}

//Admin Post-Login Screen
void adminFrontPage() {
    string adminMenuChoice;
    cout << endl << "\tWelcome Admin" << endl;
    lineFunc(30, "*");
    cout << endl << endl;
    cout << "[1] View Patient Information" << endl;
    cout << "[2] Update Donor Blood Test Reports" << endl;
    cout << "[3] Donor Report" << endl;
    cout << "[4] Recipient Report" << endl;
    cout << "[5] Location Based Report" << endl;
    cout << "[6] Blood Group Based Report" << endl << endl;
    cout << "[7] Log Out and Return to Menu" << endl << endl;
    cout << "Please Select an Option: "; cin >> adminMenuChoice;
    if(adminMenuChoice == "1") {
    ViewInfoMenu:
        string adminInfoChoice;
        cout << endl << endl;
        cout << "Select Patient Group:" << endl << endl;
        cout << "\t[1] View Donor Information" << endl;
        cout << "\t[2] View Recipient Information" << endl << endl;
        cout << "\t[3] Return to Admin Menu" << endl << endl;
        cout << "Please Select an Option: "; cin >> adminInfoChoice;
        if (adminInfoChoice == "1") {
            //view donor information (read 1 by 1, and ask to contine?)
        }
        else if (adminInfoChoice == "2") {
            //view recipient information (1 by 1 again?)
        }
        else if (adminInfoChoice == "3") {
            cout << endl << "Press Enter to Return" << endl; cin.ignore();
            adminFrontPage();
        }
        else {
            cout << endl << "Please Input a Valid Option" << endl;      //Exception handling for user input
            goto ViewInfoMenu;
        }
    }
    else if(adminMenuChoice == "2") {
        //Update Donor Blood Test Reports
    }
    else if(adminMenuChoice == "3") { 
        //Donor Report
    }
    else if(adminMenuChoice == "4") { 
        //Recipient Report
    }
    else if(adminMenuChoice == "5") {
        //Location Based Report
    }
    else if (adminMenuChoice == "6") {
        //Location Based Report
    }
    else if (adminMenuChoice == "7") {
        cout << endl << "Logging out..." << endl;
        menuFunc();
    }
    else {
        cout << endl << "Please Input a Valid Option" << endl;      //Exception handling for user input
        //cout << "Press Enter to Return" << endl; cin.ignore();
        adminFrontPage();
    }
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

//Recipient Login Fucntion
void recipientLoginFunc() {           
    
    //TODO check that the password exist and are correct - exception handle if not
    //TODO figure out how to not make an infinite ask for password loop


    //formatting
    cout << endl << endl;
    cout << "\tRecipient Login" << endl;
    lineFunc(31, "*");
    cout << endl << "Log In as a Blood Recipient" << endl << endl;

    // ask for username
    string temp_user;
    
    cout << endl << "\tUsername: "; getline(cin, temp_user); // TODO not prompting the user here
    
    // check username exists in the csv by calling InfoExists() with hardcoded index and file to open
    bool username_exists = InfoExists(temp_user, recipientFilePath, recip_username);
    
    
    if (username_exists) {
        cout << "exists function is working";
        //load recip into a struct TODO
        
  
    PassReAsk: 
        string temp_pass;
        int loginCounter = 0;
        cout << endl << "\tPassword: "; getline(cin, temp_pass);
        cout << endl << endl;
        
        // check that it applies to this user name TODO
        
        if (true) {// TODO applies

            // log the user in as recipient ( maybe toggle a bool) TODO
            
            
            //return out of recipientLoginFunc TODO
            //return to recipFrontPage();
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
        string rLoginRetry;
        cout << endl << "\tThe username " <<  temp_user  << " is not registered as a recipient!" << endl; 
    rLoginRetryRestart:
        cout << endl << "\tDid you want to try again? [Y]/[N]" << endl << "\t"; cin >> rLoginRetry;
        cin.ignore();
        if (rLoginRetry == "Y" || rLoginRetry == "y") {
            recipientLoginFunc();
        }
        else if (rLoginRetry == "N" || rLoginRetry == "n") {
            cout << endl << "Returning to Menu..." << endl;
            menuFunc();
        }
        else {
            cout << endl << "Please Input a Valid Option" << endl;
            goto rLoginRetryRestart;
        }
        

    }
    
}

//Donor Registraion Function
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

//Donor Login Function
void donorLoginFunc() { //TODO use very similar logic to recipientLoginFunc
    cout << endl << endl;
    cout << "\tDonor Login" << endl;
    lineFunc(28, "*");
    cout << endl << "Log In as a Blood Donor" << endl << endl;
    cout << endl << "\tUsername: ";
    cout << endl << "\tPassword: ";
    cout << endl << endl << "Press Enter to Log In"; cin.ignore();
    donorFrontPage();
}

//Admin Login Function
void adminLoginFunc() { //TODO use very similar logic to recipientLoginFunc
    cout << endl << endl;
    cout << "\tAdministrator Login" << endl;
    lineFunc(35, "*");
    cout << endl << "Log In as Administrator" << endl << endl;
    cout << endl << "\tUsername: ";
    cout << endl << "\tPassword: ";
    cout << endl << endl << "Press Enter to Log In" << endl; cin.ignore();
    adminFrontPage();

}

//Recipient Write to CSV Function
void recipientWriteFunc() {

    
    file1.open(recipientFilePath, ios::app);
    struct recipientInfo recipient;
    file1 << recipient.recipientName << ",";
    file1 << recipient.physAddr << ",";
    file1 << recipient.emailAddr << ",";
    file1 << "|" << recipient.contactNum << ",";
    file1 << recipient.username << ",";
    file1 << recipient.password << ",";
    file1 << recipient.validated << "\n";
    file1.close();
}

//Donor Write to CSV Function
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
    file2 << "|" << donor.contactNum << ",";
    file2 << donor.emailAddr << ",";
    file2 << donor.physAddr << ",";
    file2 << donor.lastDonation << ",";
    file2 << donor.username << ",";
    file2 << donor.password << "\n";
    file2.close();
}



//Main Menu Function
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
        cin.ignore();
        if (loginChoice == "1") {
            donorLoginFunc();       //Portal to attach Donor Login
            
            goto MenuRestart;
        }
        else if (loginChoice == "2") {
            recipientLoginFunc();   //Portal to attach Recipient Login
            
            goto MenuRestart;
        }
        else if (loginChoice == "3") {
            adminLoginFunc();       //Portal to attach Admin Login (assuming we have a pre-made Admin User)
            
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
        cin.ignore();
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
    else if (menuInput == "8") {
        adminFrontPage();
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

