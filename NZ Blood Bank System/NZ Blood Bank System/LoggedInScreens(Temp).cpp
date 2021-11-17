#include <iostream>
#include <fstream>
#include <string>
#include "Global functions.h"
using namespace std;

void variableLineFunc(int length, string type) {
    for (int i = 0; i < length; i++)
        cout << type;
}

//Logged In screen functions


void donorFrontPage() {             //Landing page after Donor has logged in
    string moreInfo, moreInfo2;     
    string donorMenuChoice;
    //Formatting
	cout << endl << "\tWelcome [NAME]" << endl;     //TODO get Name of donor from csv and display
    variableLineFunc(30, "*");
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
        variableLineFunc(50, "*");
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
        variableLineFunc(40, "*");
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
    }
    else if (donorMenuChoice == "4") {
        string dManageChoice;
    dManageAsk:
        cout << "\tAccount Management" << endl;
        variableLineFunc(30, "*");
        cout << endl << endl;
        cout << "[1] Manage Booking" << endl;
        cout << "[2] Edit Your Info" << endl << endl;
        cout << "[3] Return to Donor Menu" << endl;
        cout << "Please Select an Option: "; cin >> dManageChoice;
        if (dManageChoice == "1") {
            //TODO Manage Booking - requires booking system first. would guess each patient is tagged with a unique random number to identify?
        }
        else if (dManageChoice == "2") {
            //TODO Edit Info - needs to access file, display current details for user and provide option to change details
            //-needs working find in csv func 
        }
        else if (dManageChoice == "3") {
            cin.ignore();
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
    cin.ignore();
    donorFrontPage();
}

}

void recipFrontPage() {
    string recipMenuChoice, bloodOnlySearch, locationBloodSearch;
    //TODO menu with options to:
    //-see donor info by blood group (read csv and find n amount of people based if blood group the same)
    //-access donors by location and blood group (same as above, but including location too)
    //-find potential donor contact details by giving full name (again, look for specific name in csv and display corresponding details)

    //Formatting
    cout << endl << "\tWelcome [NAME]" << endl;     //TODO get Name of recipient from csv and display
    variableLineFunc(30, "*");
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
        variableLineFunc(36, "*");
        cout << endl << "\tSelect Blood Group: " << endl << endl;
        cout << "\tA" << endl << "\tB" << endl << "\tAB" << endl << "\tO" << endl;
        cout << "Please Select an Option: "; getline(cin, bloodOnlySearch);
        if (bloodOnlySearch == "A" || bloodOnlySearch == "a") {
            bloodOnlySearch == "A";
            //Find any donors that match blood type, display their full name and blood group TODO
        }
        else if (bloodOnlySearch == "B" || bloodOnlySearch == "b") {
            bloodOnlySearch = "B";
            //Find any donors that match blood type, display their full name and blood group
        }
        else if (bloodOnlySearch == "AB" || bloodOnlySearch == "ab" || bloodOnlySearch == "Ab" || bloodOnlySearch == "aB") {
            bloodOnlySearch = "AB";
            //Find any donors that match blood type, display their full name and blood group
        }
        else if (bloodOnlySearch == "O" || bloodOnlySearch == "o") {
            bloodOnlySearch = "O";
            //Find any donors that match blood type, display their full name and blood group
        }
        else {
            cout << endl << "Please Select a Valid Option" << endl;
            goto BloodSearchRestart;
        }

    }
    else if (recipMenuChoice == "2") {
        //See donors by location and blood group TODO
        // -needs csv searcher
        cout << endl << "Donors by Location & Blood Type";
    }
    else if (recipMenuChoice == "3") {
        //search donors Full Name and recieve contact details for that donor TODO
        // -needs csv searcher
        cout << endl << "Search Donors by Full Name";
    }
    else if (recipMenuChoice == "4") {
        cout << endl << "Logging out..." << endl;
        menuFunc();
    }
    else {
        cout << endl << "Please Input a Valid Option" << endl;      //Exception handling for user input
        cin.ignore();
        recipFrontPage();
    }
}

