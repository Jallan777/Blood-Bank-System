// NZ Blood Bank System.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Introduction Screen

#pragma warning(disable : 4996)
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <chrono>
#include <regex>
#include <cstdio>
using namespace std;

bool dateAvailable = false, isBooked = false;
int lineFoundOn, unameLine, pwordLine, sameLineCheck;
string rNameTemp, rPAddTemp, rEAddTemp, rNumTemp, rUNameTemp, rPWordTemp, recipValidTemp, passwordCorrect, infoReplace, infoNew, nameCheck;
string dFNameTemp, dLNameTemp, dDOBTemp, dDOBDay, dDOBMonth, dDOBYear, dNatTemp, dEthnicTemp, dGenderTemp, dUndCondTemp, dBloodTemp, dNumTemp, dEAddTemp, dPAddTemp, dLastDonateTemp, dUnameTemp, dPwordTemp;
string recipientFilePath = "RecipientInfo.csv";
string donorFilePath = "DonorInfo.csv";
string adminFilePath = "AdminInfo.csv";
fstream file1, file2;

enum donor_data_type {
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
	donor_password
};

enum recip_data_type {

	recipient_name,
	physAddr,
	emailAddr,
	contactNum,
	recip_username,
	recip_password,
	recip_validated
};

enum admin_data_type {
	admin_username,
	admin_password
};

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
	void donorEditInfo();
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
bool InfoExists(std::string target_info, string file_to_open, int where_to_look);
void donorEditFunc(donorInfo& donorEdit);
void BookFunction(int lineNum, int lineLimit);

//Simple Function to write a line of variable length, with any character
void lineFunc(int length, string type) {
	for (int i = 0; i < length; i++)
		cout << type;
}

void findAndReplace(string& data, string toSearch, string replaceWith) {
	size_t pos = data.find(toSearch);
	while (pos != std::string::npos) {
		// Replace this occurrence of Sub String
		data.replace(pos, toSearch.size(), replaceWith);
		// Get the next occurrence from the current position
		pos = data.find(toSearch, pos + replaceWith.size());
	}
}

void copyDataBasic(string srcFile, string dstFile) {
	std::ifstream  sourceFile(srcFile, std::ios::binary);
	std::ofstream  destinationFile(dstFile, std::ios::binary);

	destinationFile << sourceFile.rdbuf();
}

void quickReplaceFunc(string source, string dest) {

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

//Get recipient info from csv and place into struct
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



			info_to_return.recipientName = values[recipient_name];
			info_to_return.physAddr = values[physAddr];
			info_to_return.emailAddr = values[emailAddr];
			info_to_return.contactNum = values[contactNum];
			info_to_return.username = values[recip_username];
			info_to_return.password = values[recip_password];
			info_to_return.validated = values[recip_validated];

			file.close();
			return info_to_return;
		}

	} file.close();

	return info_to_return;
}

//Get Donor info from csv and place into struct
donorInfo Get_donor_info(int data_row_num, string file_to_open) {

	ifstream file;
	std::string line;
	bool isHeader = true;
	int row_counter = 0;

	donorInfo info_to_return = {};

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



			info_to_return.firstName = values[First_Name]; //cout << values[recipient_name];
			info_to_return.lastName = values[last_name]; //cout << values[physAddr];
			info_to_return.dob = values[DOB]; //cout << values[emailAddr];
			info_to_return.nationality = values[nationality]; //cout << values[contactNum];
			info_to_return.ethnicity = values[ethnicity]; //cout << values[recip_username];
			info_to_return.gender = values[gender]; //cout << values[recip_password];
			info_to_return.underlyCond = values[underlying_condition]; //cout << values[recip_validated];
			info_to_return.bloodGroup = values[blood_group];
			info_to_return.contactNum = values[contact_no];
			info_to_return.emailAddr = values[email];
			info_to_return.physAddr = values[physical_address];
			info_to_return.lastDonation = values[last_date_of_donation];
			info_to_return.username = values[donor_username];
			info_to_return.password = values[donor_password];

			file.close();
			return info_to_return;
		}

	} file.close();

	return info_to_return;
}




//Donor Post-Login Screen
void donorFrontPage() {             //Landing page after Donor has logged in
	string moreInfo, moreInfo2, bookingDay, bookingTime, bookingDate;
	string donorMenuChoice;
	donorInfo my_donor_info = Get_donor_info((lineFoundOn - 1), "DonorInfo.csv");
	//Formatting
	cout << endl << "\tWelcome " << my_donor_info.firstName << endl;     //TODO get Name of donor from csv and display
	lineFunc(40, "*");
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
			<< "\t  time to help strangers in need. If you go to the same donation place each time, you?ll get to know " << endl
			<< "\t  some of the staff who are also dedicating themselves to the cause of saving lives." << endl
			<< "\t- Volunteering has been shown to have positive effects on happiness. In people over 65-years-old, " << endl
			<< "\t  volunteering also reduces the risk of depression and loneliness." << endl << endl;
		cout << "Press Enter to Continue..."; cin.ignore();
		donorFrontPage();               //Return to Donor Landing Page
	}
	else if (donorMenuChoice == "3") {
		//Book a visit TODO
		string menuInput;
		cout << endl << "Book Your Blood Donation" << endl;

		cout << endl << "\tWhich day would you like to donate on?" << endl;
		lineFunc(54, "*");

		cout << endl << "[1] Monday" << endl;
		cout << "[2] Tuesday" << endl;
		cout << "[3] Wednesday" << endl;
		cout << "[4] Thursday" << endl;
		cout << "[5] Friday" << endl;
		cout << "[6] Saturday" << endl;
		cout << "[7] Sunday" << endl;

		cout << endl << "Please enter a selection: "; cin >> menuInput;
		cin.ignore();

		if (menuInput == "1") {
			string secondMenuInput;
			cout << endl << "\tWhich time would you like to come in?" << endl;
			lineFunc(54, "*");
			bookingDay = "Monday";
			cout << endl << "[1] 9:00am" << endl;
			cout << "[2] 10:00am" << endl;
			cout << "[3] 11:00am" << endl;
			cout << "[4] 12:00pm" << endl;
			cout << "[5] 1:00pm" << endl;
			cout << "[6] 2:00pm" << endl;
			cout << "[7] 3:00pm" << endl;

			cout << endl << "Please enter a selection: "; cin >> secondMenuInput;
			cin.ignore();
			if (secondMenuInput == "1") { bookingTime = "9:00am"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
			if (secondMenuInput == "2") { bookingTime = "10:00am"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
			if (secondMenuInput == "3") { bookingTime = "11:00am"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
			if (secondMenuInput == "4") { bookingTime = "12:00pm"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
			if (secondMenuInput == "5") { bookingTime = "1:00pm"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
			if (secondMenuInput == "6") { bookingTime = "2:00pm"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
			if (secondMenuInput == "7") { bookingTime = "3:00pm"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
		}
		if (menuInput == "2") {
			string secondMenuInput;
			cout << endl << "\tWhich time would you like to come in?" << endl;
			lineFunc(54, "*");
			bookingDay = "Tuesday";
			cout << endl << "[1] 9:00am" << endl;
			cout << "[2] 10:00am" << endl;
			cout << "[3] 11:00am" << endl;
			cout << "[4] 12:00pm" << endl;
			cout << "[5] 1:00pm" << endl;
			cout << "[6] 2:00pm" << endl;
			cout << "[7] 3:00pm" << endl;

			cout << endl << "Please enter a selection: "; cin >> secondMenuInput;
			cin.ignore();
			if (secondMenuInput == "1") { bookingTime = "9:00am"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
			if (secondMenuInput == "2") { bookingTime = "10:00am"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
			if (secondMenuInput == "3") { bookingTime = "11:00am"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
			if (secondMenuInput == "4") { bookingTime = "12:00pm"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
			if (secondMenuInput == "5") { bookingTime = "1:00pm"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
			if (secondMenuInput == "6") { bookingTime = "2:00pm"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
			if (secondMenuInput == "7") { bookingTime = "3:00pm"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
		}
		if (menuInput == "3") {
			string secondMenuInput;
			cout << endl << "\tWhich time would you like to come in?" << endl;
			lineFunc(54, "*");
			bookingDay = "Wednesday";
			cout << endl << "[1] 9:00am" << endl;
			cout << "[2] 10:00am" << endl;
			cout << "[3] 11:00am" << endl;
			cout << "[4] 12:00pm" << endl;
			cout << "[5] 1:00pm" << endl;
			cout << "[6] 2:00pm" << endl;
			cout << "[7] 3:00pm" << endl;

			cout << endl << "Please enter a selection: "; cin >> secondMenuInput;
			cin.ignore();
			if (secondMenuInput == "1") { bookingTime = "9:00am"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
			if (secondMenuInput == "2") { bookingTime = "10:00am"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
			if (secondMenuInput == "3") { bookingTime = "11:00am"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
			if (secondMenuInput == "4") { bookingTime = "12:00pm"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
			if (secondMenuInput == "5") { bookingTime = "1:00pm"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
			if (secondMenuInput == "6") { bookingTime = "2:00pm"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
			if (secondMenuInput == "7") { bookingTime = "3:00pm"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
		}
		if (menuInput == "4") {
			string secondMenuInput;
			cout << endl << "\tWhich time would you like to come in?" << endl;
			lineFunc(54, "*");
			bookingDay = "Thursday";
			cout << endl << "[1] 9:00am" << endl;
			cout << "[2] 10:00am" << endl;
			cout << "[3] 11:00am" << endl;
			cout << "[4] 12:00pm" << endl;
			cout << "[5] 1:00pm" << endl;
			cout << "[6] 2:00pm" << endl;
			cout << "[7] 3:00pm" << endl;

			cout << endl << "Please enter a selection: "; cin >> secondMenuInput;
			cin.ignore();
			if (secondMenuInput == "1") { bookingTime = "9:00am"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
			if (secondMenuInput == "2") { bookingTime = "10:00am"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
			if (secondMenuInput == "3") { bookingTime = "11:00am"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
			if (secondMenuInput == "4") { bookingTime = "12:00pm"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
			if (secondMenuInput == "5") { bookingTime = "1:00pm"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
			if (secondMenuInput == "6") { bookingTime = "2:00pm"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
			if (secondMenuInput == "7") { bookingTime = "3:00pm"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
		}
		if (menuInput == "5") {
			string secondMenuInput;
			cout << endl << "\tWhich time would you like to come in?" << endl;
			lineFunc(54, "*");
			bookingDay = "Friday";
			cout << endl << "[1] 9:00am" << endl;
			cout << "[2] 10:00am" << endl;
			cout << "[3] 11:00am" << endl;
			cout << "[4] 12:00pm" << endl;
			cout << "[5] 1:00pm" << endl;
			cout << "[6] 2:00pm" << endl;
			cout << "[7] 3:00pm" << endl;

			cout << endl << "Please enter a selection: "; cin >> secondMenuInput;
			cin.ignore();
			if (secondMenuInput == "1") { bookingTime = "9:00am"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
			if (secondMenuInput == "2") { bookingTime = "10:00am"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
			if (secondMenuInput == "3") { bookingTime = "11:00am"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
			if (secondMenuInput == "4") { bookingTime = "12:00pm"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
			if (secondMenuInput == "5") { bookingTime = "1:00pm"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
			if (secondMenuInput == "6") { bookingTime = "2:00pm"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
			if (secondMenuInput == "7") { bookingTime = "3:00pm"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
		}
		if (menuInput == "6") {
			string secondMenuInput;
			cout << endl << "\tWhich time would you like to come in?" << endl;
			lineFunc(54, "*");
			bookingDay = "Saturday";
			cout << endl << "[1] 9:00am" << endl;
			cout << "[2] 10:00am" << endl;
			cout << "[3] 11:00am" << endl;
			cout << "[4] 12:00pm" << endl;
			cout << "[5] 1:00pm" << endl;
			cout << "[6] 2:00pm" << endl;
			cout << "[7] 3:00pm" << endl;

			cout << endl << "Please enter a selection: "; cin >> secondMenuInput;
			cin.ignore();
			if (secondMenuInput == "1") { bookingTime = "9:00am"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
			if (secondMenuInput == "2") { bookingTime = "10:00am"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
			if (secondMenuInput == "3") { bookingTime = "11:00am"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
			if (secondMenuInput == "4") { bookingTime = "12:00pm"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
			if (secondMenuInput == "5") { bookingTime = "1:00pm"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
			if (secondMenuInput == "6") { bookingTime = "2:00pm"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
			if (secondMenuInput == "7") { bookingTime = "3:00pm"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
		}
		if (menuInput == "7") {
			string secondMenuInput;
			cout << endl << "\tWhich time would you like to come in?" << endl;
			lineFunc(54, "*");
			bookingDay = "Sunday";
			cout << endl << "[1] 9:00am" << endl;
			cout << "[2] 10:00am" << endl;
			cout << "[3] 11:00am" << endl;
			cout << "[4] 12:00pm" << endl;
			cout << "[5] 1:00pm" << endl;
			cout << "[6] 2:00pm" << endl;
			cout << "[7] 3:00pm" << endl;

			cout << endl << "Please enter a selection: "; cin >> secondMenuInput;
			cin.ignore();
			if (secondMenuInput == "1") { bookingTime = "9:00am"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
			if (secondMenuInput == "2") { bookingTime = "10:00am"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
			if (secondMenuInput == "3") { bookingTime = "11:00am"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
			if (secondMenuInput == "4") { bookingTime = "12:00pm"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
			if (secondMenuInput == "5") { bookingTime = "1:00pm"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
			if (secondMenuInput == "6") { bookingTime = "2:00pm"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
			if (secondMenuInput == "7") { bookingTime = "3:00pm"; bookingDate = bookingDay + " " + bookingTime; cout << endl << "You have been booked in for: " << bookingDate << endl; isBooked = true; }
		}




		cout << "Press Enter to Return" << endl; cin.ignore();
		donorFrontPage();
	}
	else if (donorMenuChoice == "4") {
		string dManageChoice;
	dManageAsk:
		cout << "\tAccount Management" << endl;
		lineFunc(30, "*");
		cout << endl << endl;

		cout << "[1] Edit Your Info" << endl << endl;
		cout << "[2] Return to Donor Menu" << endl;
		cout << "Please Select an Option: "; cin >> dManageChoice;
		if (dManageChoice == "1") {
			//TODO Edit Info - needs to access file, display current details for user and provide option to change details
			//-needs working find in csv func 
			donorInfo donorEdit;
			cout << endl << "Your Current Information" << endl;
			lineFunc(50, "*");
			cout << endl << endl;
			cout << "Full Name\t: " << my_donor_info.firstName << " " << my_donor_info.lastName << endl;
			nameCheck = my_donor_info.firstName;
			string physAddrTemp = my_donor_info.physAddr;
			findAndReplace(physAddrTemp, "/", ", ");
			cout << "Physical Address\t\t: " << physAddrTemp << endl << endl;

			cout << "Date of Birth\t\t\t: " << my_donor_info.dob << endl;
			cout << "Nationality\t\t\t: " << my_donor_info.nationality << endl;
			cout << "Ethnicity\t\t\t: " << my_donor_info.ethnicity << endl;
			cout << "Gender\t\t\t\t: " << my_donor_info.gender << endl << endl;

			cout << "Blood Group\t\t\t: " << my_donor_info.bloodGroup << endl;
			cout << "Known Underlying Conditions\t: " << my_donor_info.underlyCond << endl;
			cout << "Contact Number\t\t\t: " << my_donor_info.contactNum.erase(0, 1) << endl;
			cout << "Email Address\t\t\t: " << my_donor_info.emailAddr << endl << endl;

			cout << "Username\t\t\t: " << my_donor_info.username << endl;
			cout << "Password\t\t\t: " << my_donor_info.password << endl << endl;

			string infoChange;
		InfoChangeAsk:
			cout << "Would you like to change anything? [Y][N]" << endl; cin >> infoChange;
			if (infoChange == "Y" || infoChange == "y") {
				bool isCorrectLine = InfoExists(my_donor_info.firstName, donorFilePath, First_Name);
				int sameLineCheck = lineFoundOn;
				if (isCorrectLine) {
					cin.ignore();
					donorEdit.donorEditInfo();
					cout << endl << "Your information has been changed!" << endl;
					cout << endl << "Returning to Donor Menu" << endl;
					donorFrontPage();
				}
			}
			else if (infoChange == "N" || infoChange == "n") {
				cout << endl << "Saving Your Information..." << endl;
				donorFrontPage();
			}
			else {
				cout << endl << "Please Input a Valid Option..." << endl;
				goto InfoChangeAsk;
			}

		}
		else if (dManageChoice == "2") {
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
	recipientInfo my_recipient_info = Get_recipient_info((lineFoundOn - 1), "Recipientinfo.csv");
	//TODO -access donors by location and blood group (same as above, but including location too)


	//Formatting
	cout << endl << "\tWelcome " << my_recipient_info.recipientName << endl;
	lineFunc(40, "*");
	cout << endl << endl;
	cout << "[1] See Donors by Blood Group" << endl;
	cout << "[2] See Donors by Location & Blood Group" << endl;
	cout << "[3] Donor Name Search" << endl << endl;
	cout << "[4] Logout & Return to Menu" << endl << endl;
	cout << "Please Select an Option: "; getline(cin, recipMenuChoice);
	if (recipMenuChoice == "1") {

	BloodSearchRestart:

		cout << endl << "\tDonors by Blood Type" << endl;
		lineFunc(36, "*");
		cout << endl << "\tSelect Blood Group: " << endl << endl;
		cout << "\t[1] Type A" << "\t[2]Type B" << endl << "\t[3]Type AB" << "\t [4]Type O" << endl << endl;
		cout << "Please Select an Option: "; getline(cin, bloodOnlySearch);

		string bloodSearchKey;
		ifstream file;
		std::string line;
		if (bloodOnlySearch == "1") {
			bloodSearchKey = "A";

			int lineCounter = 0;
			file.open(donorFilePath, std::ios::in);
			while (std::getline(file, line)) {
				lineCounter++;
			}
			int donorOnLine = lineCounter;

			for (int i = 1; i < donorOnLine; i++) {
				if (i == donorOnLine - 1) {
					cout << endl << endl << "That is all the registered donors!" << endl;
					recipFrontPage();
				}
				donorInfo my_donor_info = Get_donor_info((i), "DonorInfo.csv");
				if (my_donor_info.bloodGroup == bloodSearchKey) {
					cout << "Donors with Blood Type " << bloodSearchKey << endl;
					lineFunc(40, "*");
					cout << endl << endl;
					cout << "Full Name\t: " << my_donor_info.firstName << " " << my_donor_info.lastName << endl;
					cout << "Date of Birth\t: " << my_donor_info.dob << endl;
					cout << "Blood Group\t: " << my_donor_info.bloodGroup << endl;
					cout << "Date of Last Donation: " << my_donor_info.lastDonation << endl;
					cout << "Known Underlying Conditions: " << my_donor_info.underlyCond << endl << endl;
					cout << "Gender\t\t: " << my_donor_info.gender << endl;
					cout << "Nationality\t: " << my_donor_info.nationality << endl;
					cout << "Ethnicity\t: " << my_donor_info.ethnicity << endl << endl;

					cout << endl << endl << "Press Enter to View Next Donor..."; cin.ignore();
				}

				file.close();
			}
		}
		else if (bloodOnlySearch == "2") {
			bloodSearchKey = "B";
			int lineCounter = 0;
			file.open(donorFilePath, std::ios::in);
			while (std::getline(file, line)) {
				lineCounter++;
			}
			int donorOnLine = lineCounter;

			for (int i = 1; i < donorOnLine; i++) {
				if (i == donorOnLine - 1) {
					cout << endl << endl << "That is all the registered donors!" << endl;
					recipFrontPage();
				}
				donorInfo my_donor_info = Get_donor_info((i), "DonorInfo.csv");
				if (my_donor_info.bloodGroup == bloodSearchKey) {
					cout << "Donors with Blood Type " << bloodSearchKey << endl;
					lineFunc(40, "*");
					cout << endl << endl;
					cout << "Full Name\t: " << my_donor_info.firstName << " " << my_donor_info.lastName << endl;
					cout << "Date of Birth\t: " << my_donor_info.dob << endl;
					cout << "Blood Group\t: " << my_donor_info.bloodGroup << endl;
					cout << "Date of Last Donation: " << my_donor_info.lastDonation << endl;
					cout << "Known Underlying Conditions: " << my_donor_info.underlyCond << endl << endl;
					cout << "Gender\t\t: " << my_donor_info.gender << endl;
					cout << "Nationality\t: " << my_donor_info.nationality << endl;
					cout << "Ethnicity\t: " << my_donor_info.ethnicity << endl << endl;

					cout << endl << endl << "Press Enter to View Next Donor..."; cin.ignore();
				}

				file.close();
			}
			//Find any donors that match blood type, display their full name and blood group
		}
		else if (bloodOnlySearch == "3") {
			bloodSearchKey = "AB";
			int lineCounter = 0;
			file.open(donorFilePath, std::ios::in);
			while (std::getline(file, line)) {
				lineCounter++;
			}
			int donorOnLine = lineCounter;

			for (int i = 1; i < donorOnLine; i++) {
				if (i == donorOnLine - 1) {
					cout << endl << endl << "That is all the registered donors!" << endl;
					recipFrontPage();
				}
				donorInfo my_donor_info = Get_donor_info((i), "DonorInfo.csv");
				if (my_donor_info.bloodGroup == bloodSearchKey) {
					cout << "Donors with Blood Type " << bloodSearchKey << endl;
					lineFunc(40, "*");
					cout << endl << endl;
					cout << "Full Name\t: " << my_donor_info.firstName << " " << my_donor_info.lastName << endl;
					cout << "Date of Birth\t: " << my_donor_info.dob << endl;
					cout << "Blood Group\t: " << my_donor_info.bloodGroup << endl;
					cout << "Date of Last Donation: " << my_donor_info.lastDonation << endl;
					cout << "Known Underlying Conditions: " << my_donor_info.underlyCond << endl << endl;
					cout << "Gender\t\t: " << my_donor_info.gender << endl;
					cout << "Nationality\t: " << my_donor_info.nationality << endl;
					cout << "Ethnicity\t: " << my_donor_info.ethnicity << endl << endl;

					cout << endl << endl << "Press Enter to View Next Donor..."; cin.ignore();
				}

				file.close();
			}
			//Find any donors that match blood type, display their full name and blood group
		}
		else if (bloodOnlySearch == "4") {
			bloodSearchKey = "O";
			int lineCounter = 0;
			file.open(donorFilePath, std::ios::in);
			while (std::getline(file, line)) {
				lineCounter++;
			}
			int donorOnLine = lineCounter;

			for (int i = 1; i < donorOnLine; i++) {
				if (i == donorOnLine - 1) {
					cout << endl << endl << "That is all the registered donors!" << endl;
					recipFrontPage();
				}
				donorInfo my_donor_info = Get_donor_info((i), "DonorInfo.csv");
				if (my_donor_info.bloodGroup == bloodSearchKey) {
					cout << "Donors with Blood Type " << bloodSearchKey << endl;
					lineFunc(40, "*");
					cout << endl << endl;
					cout << "Full Name\t: " << my_donor_info.firstName << " " << my_donor_info.lastName << endl;
					cout << "Date of Birth\t: " << my_donor_info.dob << endl;
					cout << "Blood Group\t: " << my_donor_info.bloodGroup << endl;
					cout << "Date of Last Donation: " << my_donor_info.lastDonation << endl;
					cout << "Known Underlying Conditions: " << my_donor_info.underlyCond << endl << endl;
					cout << "Gender\t\t: " << my_donor_info.gender << endl;
					cout << "Nationality\t: " << my_donor_info.nationality << endl;
					cout << "Ethnicity\t: " << my_donor_info.ethnicity << endl << endl;

					cout << endl << endl << "Press Enter to View Next Donor..."; cin.ignore();
				}

				file.close();
			}
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

		string locationKey, bloodKey, bloodSearchOption;
		cout << endl << "Donors by Location & Blood Type" << endl;
		lineFunc(40, "*");
		cout << endl << endl;
		cout << "Please input the Location you wish to search for" << endl;
		cout << "(Search a City Name for best results)" << endl << endl;
		cout << "\tLocation: "; cin >> locationKey; cin.ignore();
	BloodAskRestart:
		cout << endl << "\tSelect Blood Group: " << endl << endl;
		cout << "\t[1] Type A" << "\t[2]Type B" << endl << "\t[3]Type AB" << "\t [4]Type O" << endl << endl;
		cout << "Please Select an Option: "; getline(cin, bloodSearchOption);
		if (bloodSearchOption == "1") {
			bloodKey = "A";
		}
		else if (bloodSearchOption == "2") {
			bloodKey = "B";
		}
		else if (bloodSearchOption == "3") {
			bloodKey = "AB";
		}
		else if (bloodSearchOption == "4") {
			bloodKey = "O";
		}
		else {
			cout << endl << "Please Select a Valid Option" << endl;
			goto BloodAskRestart;
		}

		ifstream file;
		std::string line;
		int lineCounter = 0;
		file.open(donorFilePath, std::ios::in);
		bool foundLocation = false;
		while (std::getline(file, line)) {
			lineCounter++;
		}
		int donorOnLine = lineCounter;

		for (int i = 1; i < donorOnLine; i++) {
			if (i == donorOnLine) {
				cout << endl << endl << "That is all the registered donors!" << endl;
				recipFrontPage();
			}
			donorInfo my_donor_info = Get_donor_info((i), "DonorInfo.csv");

			if (my_donor_info.bloodGroup == bloodKey) {
				string tempAddress = my_donor_info.physAddr;
				findAndReplace(tempAddress, "/", " , ");
				//cout << endl << tempAddress;
				if (tempAddress.find(locationKey) != string::npos) {
					cout << endl << "Donors " << " with Blood Type " << bloodKey << " matching search: " << locationKey << endl;
					lineFunc(50, "*");
					cout << endl << endl;
					cout << "Full Name\t: " << my_donor_info.firstName << " " << my_donor_info.lastName << endl;
					cout << "Date of Birth\t: " << my_donor_info.dob << endl;
					cout << "Blood Group\t: " << my_donor_info.bloodGroup << endl;
					cout << "Date of Last Donation: " << my_donor_info.lastDonation << endl;
					cout << "Known Underlying Conditions: " << my_donor_info.underlyCond << endl << endl;
					cout << "Gender\t\t: " << my_donor_info.gender << endl;
					cout << "Nationality\t: " << my_donor_info.nationality << endl;
					cout << "Ethnicity\t: " << my_donor_info.ethnicity << endl << endl;
					string printAddress = my_donor_info.physAddr;
					findAndReplace(printAddress, "/", ", ");
					cout << "Physical Address: " << printAddress << endl << endl;
					lineFunc(50, "*");

					cout << endl << endl << "Press Enter to View Next Donor..."; cin.ignore();
				}




			}


		}

		cout << endl << endl << "There are no more Donors in Blood Group " << bloodKey << " matching search: " << locationKey;
		file.close();
		cout << endl << endl << "Press Enter to return to Recipient Menu..."; cin.ignore();
		recipFrontPage();

	}
	else if (recipMenuChoice == "3") {
		string firstNameSearch, lastNameSearch, firstLine, secondLine;
		cout << endl << "Search Donors by Full Name" << endl;
		lineFunc(30, "*");
	DonorSearchAgain:
		cout << endl << endl;
		cout << "Please Enter Donor Full Name (Case Sensitive!): " << endl;
		cout << "\tFirst Name: "; cin >> firstNameSearch;
		cout << "\tLast Name: "; cin >> lastNameSearch;
		bool firstNameExists = InfoExists(firstNameSearch, donorFilePath, First_Name);
		if (firstNameExists) {
			firstLine = lineFoundOn;
			bool lastNameExists = InfoExists(lastNameSearch, donorFilePath, last_name);
			secondLine = lineFoundOn;
			if (lastNameExists && firstLine == secondLine) {
				donorInfo my_donor_info = Get_donor_info((lineFoundOn - 1), "DonorInfo.csv");
				cout << endl;
				lineFunc(50, "*");
				cout << endl << endl;
				cout << "Donor Name: " << my_donor_info.firstName << " " << my_donor_info.lastName << endl;
				cout << "Contact Details:" << endl;
				cout << "\tContact Number: " << my_donor_info.contactNum.erase(0, 1) << endl;
				cout << "\tEmail Address: " << my_donor_info.emailAddr << endl << endl;
				lineFunc(50, "*");
				cout << endl << endl;
				string donorSearchAgain;
			DonorSearchAgainAsk:
				cout << "Would you like to search again? [Y]/[N]: "; cin >> donorSearchAgain;
				if (donorSearchAgain == "Y" || donorSearchAgain == "y") {
					goto DonorSearchAgain;
				}
				else if (donorSearchAgain == "N" || donorSearchAgain == "n") {
					cin.ignore();
					cout << endl << "Returning to Recipient Menu..." << endl;
					recipFrontPage();
				}
				else {
					cout << endl << "Please Input a Valid Option" << endl;
					goto DonorSearchAgainAsk;
				}
			}
		}
		else {
			//Tell user no donors are registered with this name
			string noDonorRetry;
			cout << endl << "No Donors are registered with this name!" << endl;
		NoDonorRetryAsk:
			cout << "Would you like to search again? [Y]/[N]: "; cin >> noDonorRetry;
			if (noDonorRetry == "Y" || noDonorRetry == "y") {
				goto DonorSearchAgain;
			}
			else if (noDonorRetry == "N" || noDonorRetry == "n") {
				cin.ignore();
				cout << endl << "Returning to Recipient Menu..." << endl;
				recipFrontPage();
			}
			else {
				cout << endl << "Please Input a Valid Option" << endl;
				goto NoDonorRetryAsk;
			}
		}

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
	if (adminMenuChoice == "1") {
	ViewInfoMenu:
		string adminInfoChoice;
		cout << endl << endl;
		cout << "Select Patient Group:" << endl << endl;
		cout << "\t[1] View Donor Information" << endl;
		cout << "\t[2] View Recipient Information" << endl << endl;
		cout << "\t[3] Return to Admin Menu" << endl << endl;
		cout << "Please Select an Option: "; cin >> adminInfoChoice;
		if (adminInfoChoice == "1") {
			cin.ignore();
			cout << endl << "Donor Information: " << endl << endl;

			ifstream file;
			std::string line;
			int lineCounter = 0;
			file.open(donorFilePath, std::ios::in);
			while (std::getline(file, line)) {
				lineCounter++;
			}
			int adViewCounter = lineCounter;

			for (int i = 1; i < adViewCounter; i++) {

				donorInfo my_donor_info = Get_donor_info((i), "DonorInfo.csv");
				cout << endl << my_donor_info.firstName << " " << my_donor_info.lastName << " Information" << endl;
				lineFunc(50, "*");
				cout << endl << endl;
				cout << "Full Name\t: " << my_donor_info.firstName << " " << my_donor_info.lastName << endl;
				string physAddrTemp = my_donor_info.physAddr;
				findAndReplace(physAddrTemp, "/", ", ");
				cout << "Physical Address\t\t: " << physAddrTemp << endl << endl;

				cout << "Date of Birth\t\t\t: " << my_donor_info.dob << endl;
				cout << "Nationality\t\t\t: " << my_donor_info.nationality << endl;
				cout << "Ethnicity\t\t\t: " << my_donor_info.ethnicity << endl;
				cout << "Gender\t\t\t\t: " << my_donor_info.gender << endl << endl;

				cout << "Blood Group\t\t\t: " << my_donor_info.bloodGroup << endl;
				cout << "Known Underlying Conditions\t: " << my_donor_info.underlyCond << endl;
				cout << "Date of Last Dontaion\t\t: " << my_donor_info.lastDonation << endl << endl;

				cout << "Contact Number\t\t\t: " << my_donor_info.contactNum.erase(0, 1) << endl;
				cout << "Email Address\t\t\t: " << my_donor_info.emailAddr << endl;
				cout << "Username\t\t\t: " << my_donor_info.username << endl;
				cout << "Password\t\t\t: " << my_donor_info.password << endl << endl;

				cout << endl << endl << "Press Enter to View Next Donor..."; cin.ignore();
			}
			cout << endl << endl << "That is all the registered donors!" << endl;
			file.close();
			cout << endl << "Press Enter to Return to Admin Menu..."; cin.ignore();
			adminFrontPage();
		}
		else if (adminInfoChoice == "2") {
			cin.ignore();
			cout << endl << "Recipient Information: " << endl << endl;

			ifstream file;
			std::string line;
			int lineCounter = 0;
			file.open(recipientFilePath, std::ios::in);
			while (std::getline(file, line)) {
				lineCounter++;
			}
			int adViewCounter = lineCounter;

			for (int i = 1; i < adViewCounter; i++) {

				recipientInfo my_recipient_info = Get_recipient_info((i), "RecipientInfo.csv");
				cout << endl << my_recipient_info.recipientName << " Information" << endl;
				lineFunc(50, "*");
				cout << endl << endl;
				cout << "Recipient Name\t: " << my_recipient_info.recipientName << endl;
				string physAddrTemp = my_recipient_info.physAddr;
				findAndReplace(physAddrTemp, "/", ", ");
				cout << "Physical Address\t\t: " << physAddrTemp << endl << endl;

				cout << "Contact Number\t\t\t: " << my_recipient_info.contactNum.erase(0, 1) << endl;
				cout << "Email Address\t\t\t: " << my_recipient_info.emailAddr << endl;
				cout << "Validated\t\t\t: " << my_recipient_info.validated << endl << endl;

				cout << "Username\t\t\t: " << my_recipient_info.username << endl;
				cout << "Password\t\t\t: " << my_recipient_info.password << endl << endl;

				cout << endl << endl << "Press Enter to View Next Recipient..."; cin.ignore();
			}
			cout << endl << "That is all the registered recipients!" << endl;
			file.close();
			cout << endl << "Press Enter to Return to Admin Menu..."; cin.ignore();
			adminFrontPage();
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
	else if (adminMenuChoice == "2") {
		//Update Donor Blood Test Reports TODO
	}
	else if (adminMenuChoice == "3") {
		//Donor Report
		cin.ignore();
		cout << endl << "Donor Summary: " << endl << endl;

		ifstream file;
		std::string line;
		int lineCounter = 0, donorAmount = 0, undCondNum = 0, numMales = 0, numFemales = 0;
		file.open(donorFilePath, std::ios::in);
		while (std::getline(file, line)) {
			lineCounter++;
		}
		int adViewCounter = lineCounter;

		for (int i = 1; i < adViewCounter; i++) {
			donorAmount++;

			donorInfo my_donor_info = Get_donor_info((i), "DonorInfo.csv");

			lineFunc(50, "*");
			cout << endl << "\tDonor: " << my_donor_info.firstName << " " << my_donor_info.lastName << endl;
			cout << "\tBlood Group: " << my_donor_info.bloodGroup << "\t\tLast Donation: " << my_donor_info.lastDonation << endl;
			cout << "\tGender: " << my_donor_info.gender << "\t\tDate of Birth: " << my_donor_info.dob << endl;
			lineFunc(50, "*");

			if (my_donor_info.underlyCond != "None") { undCondNum++; }
			if (my_donor_info.gender == "Male" || my_donor_info.gender == "M" || my_donor_info.gender == "m" || my_donor_info.gender == "male") { numMales++; }
			if (my_donor_info.gender == "Female" || my_donor_info.gender == "female" || my_donor_info.gender == "F" || my_donor_info.gender == "f") { numFemales++; }

			cout << endl << endl << "Press Enter to View Next Donor..."; cin.ignore();

		}
		file.close();
		lineFunc(50, "*");

		cout << endl << "\tDonor Report" << endl << endl;
		cout << "Number of Male Donors: " << numMales << endl;
		cout << "Number of Female Donors: " << numFemales << endl;
		cout << "Number of Donors with Known Underlying Conditions: " << undCondNum << endl << endl;
		cout << "Total Number of Donors: " << donorAmount << endl;

		cout << "That is all the registered donors!" << endl;
		cout << "(Scroll Up to Review Accounts)";
		cout << endl << endl;
		cout << "Press Enter to Return to Admin Menu..."; cin.ignore();


		adminFrontPage();
	}
	else if (adminMenuChoice == "4") {
		//Recipient Report 
		cin.ignore();
		cout << endl << "Recipient Summary: " << endl << endl;

		ifstream file;
		std::string line;
		int lineCounter = 0, recipCounter = 0, isValidated = 0;
		file.open(recipientFilePath, std::ios::in);
		while (std::getline(file, line)) {
			lineCounter++;
		}
		int adViewCounter = lineCounter;

		for (int i = 1; i < adViewCounter; i++) {
			recipCounter++;
			recipientInfo my_recipient_info = Get_recipient_info((i), "RecipientInfo.csv");
			cout << endl << endl;
			lineFunc(50, "*");
			cout << endl << "\tRecipient Name: " << my_recipient_info.recipientName << endl << endl;
			cout << "Validated: " << my_recipient_info.validated << endl;
			cout << "Contact Number: " << my_recipient_info.contactNum.erase(0, 1) << endl;
			if (my_recipient_info.validated != "No") { isValidated++; }
			lineFunc(50, "*");



		}

		cout << endl << "\tRecipient Report" << endl;
		lineFunc(50, "*");
		cout << endl << endl << "Number of Validated Recipients: " << isValidated << endl;
		cout << "Total Number of Recipients: " << recipCounter << endl;
		cout << endl << "That is all the registered recipients!" << endl;
		cout << "(Scroll Up Review Recipient Accounts)" << endl;
		file.close();
		cout << endl << "Press Enter to Return to Admin Menu..."; cin.ignore();
		adminFrontPage();
	}
	else if (adminMenuChoice == "5") {
		//Location Report
		string locationKey;
		cout << endl << "Location Based Report" << endl;
		lineFunc(40, "*");
		cout << endl << endl;
		cout << "Please input the Location you wish to search for" << endl;
		cout << "(Search a City Name for best results)" << endl << endl;
		cout << "\tLocation: "; cin >> locationKey; cin.ignore();

		ifstream file, fileSecond;
		string line, lineSecond;
		int lineCounter = 0, totalCounter = 0, donorCount = 0, recipCount = 0, undCondCount = 0, maleDonors = 0, femaleDonors = 0, isValid = 0;
		file.open(donorFilePath, std::ios::in);
		while (std::getline(file, line)) {
			lineCounter++;
		}
		int donorOnLine = lineCounter;

		for (int i = 1; i < donorOnLine; i++) {
			if (i == donorOnLine) {
				cout << endl << endl << "That is all the registered donors!" << endl;
				adminFrontPage();
			}
			donorInfo my_donor_info = Get_donor_info((i), "DonorInfo.csv");
			string tempAddress = my_donor_info.physAddr;
			findAndReplace(tempAddress, "/", " , ");
			//cout << endl << tempAddress;
			if (tempAddress.find(locationKey) != string::npos) {
				cout << endl << "Accounts matching:  " << locationKey << endl;
				lineFunc(50, "*");
				cout << endl << endl;
				cout << "Name\t: " << my_donor_info.firstName << " " << my_donor_info.lastName << endl << endl;
				cout << "Account Type: Donor" << endl;
				cout << "Contact Number\t: " << my_donor_info.contactNum.erase(0, 1) << endl;
				cout << "Email Address\t: " << my_donor_info.emailAddr << endl << endl;
				string printAddress = my_donor_info.physAddr;
				findAndReplace(printAddress, "/", ", ");
				cout << "Physical Address: " << printAddress << endl << endl;
				lineFunc(50, "*");
				donorCount++;
				if (my_donor_info.underlyCond != "None") { undCondCount++; }
				if (my_donor_info.gender == "Male" || my_donor_info.gender == "male" || my_donor_info.gender == "M" || my_donor_info.gender == "m") { maleDonors++; }
				if (my_donor_info.gender == "Female" || my_donor_info.gender == "female" || my_donor_info.gender == "F" || my_donor_info.gender == "f") { femaleDonors++; }
				cout << endl << "Press Enter for Next Account..."; cin.ignore();
			}
		}
		lineCounter = 0;
		fileSecond.open(recipientFilePath, std::ios::in);
		while (std::getline(fileSecond, lineSecond)) {
			lineCounter++;
		}
		int recipOnLine = lineCounter;

		for (int j = 1; j < recipOnLine; j++) {
			if (j == recipOnLine) {
				cout << endl << endl << "That is all the registered donors!" << endl;
				adminFrontPage();
			}
			recipientInfo my_recipient_info = Get_recipient_info((j), "RecipientInfo.csv");
			string tempAddress = my_recipient_info.physAddr;
			findAndReplace(tempAddress, "/", " , ");
			//cout << endl << tempAddress;
			if (tempAddress.find(locationKey) != string::npos) {
				cout << endl << "Accounts matching: '" << locationKey << "'" << endl;
				lineFunc(50, "*");
				cout << endl << endl;
				cout << "Full Name\t: " << my_recipient_info.recipientName << endl << endl;
				cout << "Account Type: Recipient" << endl;
				cout << "Contact Number\t: " << my_recipient_info.contactNum.erase(0, 1) << endl;
				cout << "Email Address\t: " << my_recipient_info.emailAddr << endl << endl;
				string printAddress = my_recipient_info.physAddr;
				findAndReplace(printAddress, "/", ", ");
				cout << "Physical Address: " << printAddress << endl << endl;
				lineFunc(50, "*");
				recipCount++;
				if (my_recipient_info.validated == "Yes") { isValid++; }
				cout << endl << "Press Enter for Next Account..."; cin.ignore();
			}

		}

		cout << endl << endl << "There are no more Accounts matching search: \"" << locationKey << "\"" << endl << endl;
		file.close();
		fileSecond.close();
		totalCounter = donorCount + recipCount;
		lineFunc(65, "*");
		cout << endl << endl;
		cout << "Number of Donor Accounts: " << donorCount << endl;
		cout << "Number of Donors with Underlying Conditions: " << undCondCount << endl;
		cout << "Number of Male Donors: " << maleDonors << endl;
		cout << "Number of Female Donors: " << femaleDonors << endl << endl;
		cout << "Number of Recipient Accounts: " << recipCount << endl;
		cout << "Number of Recipients Validated: " << isValid << endl << endl;
		cout << "Total Number of Accounts matching search: " << totalCounter << endl;
		lineFunc(65, "*");
		cout << endl << endl << "Press Enter to return to Admin Menu..."; cin.ignore();
		adminFrontPage();

	}
	else if (adminMenuChoice == "6") {
		cin.ignore();
		string bloodOnlySearch, bloodKey, viewAccounts;
		//Blood Group Based Report 
	BloodSearchRestart:

		cout << endl << "\tAccounts by Blood Type" << endl;
		lineFunc(36, "*");
		cout << endl << "\tSelect Blood Group: " << endl << endl;
		cout << "\t[1] Type A" << "\t[2] Type B" << endl << "\t[3] Type AB" << "\t[4] Type O" << endl << endl;
		cout << "Please Select an Option: "; getline(cin, bloodOnlySearch);
		if (bloodOnlySearch == "1") {
			bloodKey = "A";
			ifstream file;
			std::string line;
			int lineCounter = 0, accountCounter = 0, undCondNum = 0, numMales = 0, numFemales = 0;
			file.open(donorFilePath, std::ios::in);
			while (std::getline(file, line)) {
				lineCounter++;
			}
			int adViewCounter = lineCounter;

			for (int i = 1; i < adViewCounter; i++) {


				donorInfo my_donor_info = Get_donor_info((i), "DonorInfo.csv");

				if (my_donor_info.bloodGroup == bloodKey) {
					accountCounter++;
					cout << endl << my_donor_info.firstName << " " << my_donor_info.lastName << " Information" << endl;
					lineFunc(50, "*");
					cout << endl << endl;
					cout << "Full Name\t: " << my_donor_info.firstName << " " << my_donor_info.lastName << endl;
					string physAddrTemp = my_donor_info.physAddr;
					findAndReplace(physAddrTemp, "/", ", ");
					cout << "Physical Address\t\t: " << physAddrTemp << endl << endl;

					cout << "Date of Birth\t\t\t: " << my_donor_info.dob << endl;
					cout << "Nationality\t\t\t: " << my_donor_info.nationality << endl;
					cout << "Ethnicity\t\t\t: " << my_donor_info.ethnicity << endl;
					cout << "Gender\t\t\t\t: " << my_donor_info.gender << endl << endl;

					cout << "Blood Group\t\t\t: " << my_donor_info.bloodGroup << endl;
					cout << "Known Underlying Conditions\t: " << my_donor_info.underlyCond << endl;
					cout << "Date of Last Dontaion\t\t: " << my_donor_info.lastDonation << endl << endl;

					cout << "Contact Number\t\t\t: " << my_donor_info.contactNum.erase(0, 1) << endl;
					cout << "Email Address\t\t\t: " << my_donor_info.emailAddr << endl;
					cout << "Username\t\t\t: " << my_donor_info.username << endl;
					cout << "Password\t\t\t: " << my_donor_info.password << endl << endl;

					if (my_donor_info.underlyCond != "None") { undCondNum++; }
					if (my_donor_info.gender == "Male" || my_donor_info.gender == "M" || my_donor_info.gender == "m" || my_donor_info.gender == "male") { numMales++; }
					if (my_donor_info.gender == "Female" || my_donor_info.gender == "female" || my_donor_info.gender == "F" || my_donor_info.gender == "f") { numFemales++; }

					cout << "Press Enter for Next Account..."; cin.ignore();

				}


			}
			cout << endl << "Blood Group Based Report" << endl;
			lineFunc(55, "*");
			cout << endl;
			cout << "Number of Accounts with Known Underlying Conditions: " << undCondNum << endl;
			cout << "Number of Males: " << numMales << endl;
			cout << "Number of Females: " << numFemales << endl;
			cout << endl << "Total Number of Accounts in Blood Group " << bloodKey << ": " << accountCounter << endl;

			lineFunc(55, "*");
			cout << endl << endl << "Report Completed" << endl;
			cout << "(Scroll Up to Review Accounts)" << endl;
			cout << "Press Enter to Return to Admin Menu..."; cin.ignore();
			adminFrontPage();
		}
		else if (bloodOnlySearch == "2") {
			bloodKey = "B";
			ifstream file;
			std::string line;
			int lineCounter = 0, accountCounter = 0, undCondNum = 0, numMales = 0, numFemales = 0;
			file.open(donorFilePath, std::ios::in);
			while (std::getline(file, line)) {
				lineCounter++;
			}
			int adViewCounter = lineCounter;

			for (int i = 1; i < adViewCounter; i++) {


				donorInfo my_donor_info = Get_donor_info((i), "DonorInfo.csv");

				if (my_donor_info.bloodGroup == bloodKey) {
					accountCounter++;
					cout << endl << my_donor_info.firstName << " " << my_donor_info.lastName << " Information" << endl;
					lineFunc(50, "*");
					cout << endl << endl;
					cout << "Full Name\t: " << my_donor_info.firstName << " " << my_donor_info.lastName << endl;
					string physAddrTemp = my_donor_info.physAddr;
					findAndReplace(physAddrTemp, "/", ", ");
					cout << "Physical Address\t\t: " << physAddrTemp << endl << endl;

					cout << "Date of Birth\t\t\t: " << my_donor_info.dob << endl;
					cout << "Nationality\t\t\t: " << my_donor_info.nationality << endl;
					cout << "Ethnicity\t\t\t: " << my_donor_info.ethnicity << endl;
					cout << "Gender\t\t\t\t: " << my_donor_info.gender << endl << endl;

					cout << "Blood Group\t\t\t: " << my_donor_info.bloodGroup << endl;
					cout << "Known Underlying Conditions\t: " << my_donor_info.underlyCond << endl;
					cout << "Date of Last Dontaion\t\t: " << my_donor_info.lastDonation << endl << endl;

					cout << "Contact Number\t\t\t: " << my_donor_info.contactNum.erase(0, 1) << endl;
					cout << "Email Address\t\t\t: " << my_donor_info.emailAddr << endl;
					cout << "Username\t\t\t: " << my_donor_info.username << endl;
					cout << "Password\t\t\t: " << my_donor_info.password << endl << endl;

					if (my_donor_info.underlyCond != "None") { undCondNum++; }
					if (my_donor_info.gender == "Male" || my_donor_info.gender == "M" || my_donor_info.gender == "m" || my_donor_info.gender == "male") { numMales++; }
					if (my_donor_info.gender == "Female" || my_donor_info.gender == "female" || my_donor_info.gender == "F" || my_donor_info.gender == "f") { numFemales++; }

					cout << "Press Enter for Next Account..."; cin.ignore();

				}


			}
			cout << endl << "Blood Group Based Report" << endl;
			lineFunc(55, "*");
			cout << endl;
			cout << "Number of Accounts with Known Underlying Conditions: " << undCondNum << endl;
			cout << "Number of Males: " << numMales << endl;
			cout << "Number of Females: " << numFemales << endl;
			cout << endl << "Total Number of Accounts in Blood Group " << bloodKey << ": " << accountCounter << endl;

			lineFunc(55, "*");
			cout << endl << endl << "Report Completed" << endl;
			cout << "(Scroll Up to Review Accounts)" << endl;
			cout << "Press Enter to Return to Admin Menu..."; cin.ignore();
			adminFrontPage();
		}
		else if (bloodOnlySearch == "3") {
			bloodKey = "AB";
			ifstream file;
			std::string line;
			int lineCounter = 0, accountCounter = 0, undCondNum = 0, numMales = 0, numFemales = 0;
			file.open(donorFilePath, std::ios::in);
			while (std::getline(file, line)) {
				lineCounter++;
			}
			int adViewCounter = lineCounter;

			for (int i = 1; i < adViewCounter; i++) {


				donorInfo my_donor_info = Get_donor_info((i), "DonorInfo.csv");

				if (my_donor_info.bloodGroup == bloodKey) {
					accountCounter++;
					cout << endl << my_donor_info.firstName << " " << my_donor_info.lastName << " Information" << endl;
					lineFunc(50, "*");
					cout << endl << endl;
					cout << "Full Name\t: " << my_donor_info.firstName << " " << my_donor_info.lastName << endl;
					string physAddrTemp = my_donor_info.physAddr;
					findAndReplace(physAddrTemp, "/", ", ");
					cout << "Physical Address\t\t: " << physAddrTemp << endl << endl;

					cout << "Date of Birth\t\t\t: " << my_donor_info.dob << endl;
					cout << "Nationality\t\t\t: " << my_donor_info.nationality << endl;
					cout << "Ethnicity\t\t\t: " << my_donor_info.ethnicity << endl;
					cout << "Gender\t\t\t\t: " << my_donor_info.gender << endl << endl;

					cout << "Blood Group\t\t\t: " << my_donor_info.bloodGroup << endl;
					cout << "Known Underlying Conditions\t: " << my_donor_info.underlyCond << endl;
					cout << "Date of Last Dontaion\t\t: " << my_donor_info.lastDonation << endl << endl;

					cout << "Contact Number\t\t\t: " << my_donor_info.contactNum.erase(0, 1) << endl;
					cout << "Email Address\t\t\t: " << my_donor_info.emailAddr << endl;
					cout << "Username\t\t\t: " << my_donor_info.username << endl;
					cout << "Password\t\t\t: " << my_donor_info.password << endl << endl;

					if (my_donor_info.underlyCond != "None") { undCondNum++; }
					if (my_donor_info.gender == "Male" || my_donor_info.gender == "M" || my_donor_info.gender == "m" || my_donor_info.gender == "male") { numMales++; }
					if (my_donor_info.gender == "Female" || my_donor_info.gender == "female" || my_donor_info.gender == "F" || my_donor_info.gender == "f") { numFemales++; }

					cout << "Press Enter for Next Account..."; cin.ignore();

				}


			}
			cout << endl << "Blood Group Based Report" << endl;
			lineFunc(55, "*");
			cout << endl;
			cout << "Number of Accounts with Known Underlying Conditions: " << undCondNum << endl;
			cout << "Number of Males: " << numMales << endl;
			cout << "Number of Females: " << numFemales << endl;
			cout << endl << "Total Number of Accounts in Blood Group " << bloodKey << ": " << accountCounter << endl;

			lineFunc(55, "*");
			cout << endl << endl << "Report Completed" << endl;
			cout << "(Scroll Up to Review Accounts)" << endl;
			cout << "Press Enter to Return to Admin Menu..."; cin.ignore();
			adminFrontPage();
		}
		else if (bloodOnlySearch == "4") {
			bloodKey = "O";
			ifstream file;
			std::string line;
			int lineCounter = 0, accountCounter = 0, undCondNum = 0, numMales = 0, numFemales = 0;
			file.open(donorFilePath, std::ios::in);
			while (std::getline(file, line)) {
				lineCounter++;
			}
			int adViewCounter = lineCounter;

			for (int i = 1; i < adViewCounter; i++) {


				donorInfo my_donor_info = Get_donor_info((i), "DonorInfo.csv");

				if (my_donor_info.bloodGroup == bloodKey) {
					accountCounter++;
					cout << endl << my_donor_info.firstName << " " << my_donor_info.lastName << " Information" << endl;
					lineFunc(50, "*");
					cout << endl << endl;
					cout << "Full Name\t: " << my_donor_info.firstName << " " << my_donor_info.lastName << endl;
					string physAddrTemp = my_donor_info.physAddr;
					findAndReplace(physAddrTemp, "/", ", ");
					cout << "Physical Address\t\t: " << physAddrTemp << endl << endl;

					cout << "Date of Birth\t\t\t: " << my_donor_info.dob << endl;
					cout << "Nationality\t\t\t: " << my_donor_info.nationality << endl;
					cout << "Ethnicity\t\t\t: " << my_donor_info.ethnicity << endl;
					cout << "Gender\t\t\t\t: " << my_donor_info.gender << endl << endl;

					cout << "Blood Group\t\t\t: " << my_donor_info.bloodGroup << endl;
					cout << "Known Underlying Conditions\t: " << my_donor_info.underlyCond << endl;
					cout << "Date of Last Dontaion\t\t: " << my_donor_info.lastDonation << endl << endl;

					cout << "Contact Number\t\t\t: " << my_donor_info.contactNum.erase(0, 1) << endl;
					cout << "Email Address\t\t\t: " << my_donor_info.emailAddr << endl;
					cout << "Username\t\t\t: " << my_donor_info.username << endl;
					cout << "Password\t\t\t: " << my_donor_info.password << endl << endl;

					if (my_donor_info.underlyCond != "None") { undCondNum++; }
					if (my_donor_info.gender == "Male" || my_donor_info.gender == "M" || my_donor_info.gender == "m" || my_donor_info.gender == "male") { numMales++; }
					if (my_donor_info.gender == "Female" || my_donor_info.gender == "female" || my_donor_info.gender == "F" || my_donor_info.gender == "f") { numFemales++; }

					cout << "Press Enter for Next Account..."; cin.ignore();

				}


			}
			cout << endl << "Blood Group Based Report" << endl;
			lineFunc(55, "*");
			cout << endl;
			cout << "Number of Accounts with Known Underlying Conditions: " << undCondNum << endl;
			cout << "Number of Males: " << numMales << endl;
			cout << "Number of Females: " << numFemales << endl;
			cout << endl << "Total Number of Accounts in Blood Group " << bloodKey << ": " << accountCounter << endl;

			lineFunc(55, "*");
			cout << endl << endl << "Report Completed" << endl;
			cout << "(Scroll Up to Review Accounts)" << endl;
			cout << "Press Enter to Return to Admin Menu..."; cin.ignore();
			adminFrontPage();
		}
		else {
			cout << endl << "Please Input a Valid Selection..." << endl;
			goto BloodSearchRestart;
		}

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
	string rStreet, rSuburb, rCity;
	cout << endl << endl;
	cout << "\tRecipient Registration" << endl;
	lineFunc(38, "*");
	cout << endl << "Register an account as a Blood Recipient" << endl << endl;

	cout << "Please input your information: ";  //Takes user input and adds to struct
R1:    cout << endl << "Full Recipient Name\t: "; getline(cin, rNameTemp); if (rNameTemp == "" || rNameTemp == " ") { cout << endl << "Text Field is Empty!" << endl; goto R1; }
	cout << "Physical Address";
R2:    cout << endl << "\t(Street)\t\t: "; getline(cin, rStreet); if (rStreet == "" || rStreet == " ") { cout << endl << "Text Field is Empty!" << endl; goto R2; }
R3:    cout << "\t(Suburb/Town)\t\t: "; getline(cin, rSuburb); if (rSuburb == "" || rSuburb == " ") { cout << endl << "Text Field is Empty!" << endl; goto R3; }
R4:    cout << "\t(City)\t\t\t: "; getline(cin, rCity); if (rCity == "" || rCity == " ") { cout << endl << "Text Field is Empty!" << endl; goto R4; }
	rPAddTemp = rStreet + "/" + rSuburb + "/" + rCity;
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


	//Formatting
	cout << endl << endl;
	cout << "\tRecipient Login" << endl;
	lineFunc(31, "*");
	cout << endl << "Log In as a Blood Recipient" << endl << endl;

	//Ask for username
	string temp_user;

	cout << endl << "\tUsername: "; getline(cin, temp_user);

	//Check username exists in the csv by calling InfoExists() with hardcoded index and file to open
	bool username_exists = InfoExists(temp_user, recipientFilePath, recip_username);


	if (username_exists) {

		int loginCounter = 1;
		unameLine = lineFoundOn;        //Sets a variable to hold the number of the line the username was found on



	PassReAsk:
		string temp_pass;

		cout << endl << "\tPassword: "; getline(cin, temp_pass);
		cout << endl << endl;

		//Check password exists by calling InfoExists()
		bool password_exists = InfoExists(temp_pass, recipientFilePath, recip_password);
		pwordLine = lineFoundOn;        //Sets a differernt variable to hold number of line password is on
		if (password_exists && unameLine == pwordLine) {    //Makes sure password exists and is on the same line as the username, therefore meaning its the same account


			cout << endl << "Press Enter to Log In"; cin.ignore();
			recipFrontPage();       //If username and password are both correct and match the info stored upon same line in csv, then proceed



		}
		else {
			if (loginCounter > 3) {     //Tracks login attemps. Once attempted tries is more than 3, send user back to main menu
				cout << endl << "\tToo Many Login Attempts" << endl << endl << "Returning to Menu...";
				menuFunc();
			}
			else {
				// tell user invalid password! 
				cout << endl << "\tInvalid Password!, please try again ";
				loginCounter++;         //Adds to login attempt tracker
				goto PassReAsk;
			}

		}
	}
	else {
		//tell user "username" isnt registered! 
		string rLoginRetry;
		cout << endl << "\tThe username " << temp_user << " is not registered as a recipient!" << endl;
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

	string bloodSelect, dStreet, dSuburb, dCity;
	cout << endl << endl;

	//Formatting
	cout << "\tDonor Registration" << endl;
	lineFunc(34, "*");
	cout << endl << "Register an account as a Blood Donor" << endl << endl;
	cin.ignore();
	cout << "Please input your information: ";

	//Takes user input and stores in temp variable before moving into structure
R1:    cout << endl << "First Name\t\t\t: "; getline(cin, dFNameTemp); if (dFNameTemp == "" || dFNameTemp == " ") { cout << endl << "Text Field is Empty!" << endl; goto R1; }
R2:    cout << "Last Name\t\t\t: "; getline(cin, dLNameTemp); if (dLNameTemp == "" || dLNameTemp == " ") { cout << endl << "Text Field is Empty!" << endl; goto R2; }
	cout << "Date of Birth\t\t\t(DD/MM/YYYY)";
R3:    cout << endl << "\t\t\tDay\t: "; getline(cin, dDOBDay); if (dDOBDay == "" || dDOBDay == " ") { cout << endl << "Text Field is Empty!" << endl; goto R3; }
R4:    cout << "\t\t\tMonth\t: "; getline(cin, dDOBMonth); if (dDOBMonth == "" || dDOBMonth == " ") { cout << endl << "Text Field is Empty!" << endl; goto R4; }
R5:    cout << "\t\t\tYear\t: "; getline(cin, dDOBYear); if (dDOBYear == "" || dDOBYear == " ") { cout << endl << "Please input Year" << endl; goto R5; }
	dDOBTemp = dDOBDay + "/" + dDOBMonth + "/" + dDOBYear; //DOB split into different parts to try make sure the format is the same when put into struct
R6:    cout << "Nationality\t\t\t: "; getline(cin, dNatTemp); if (dNatTemp == "" || dNatTemp == " ") { cout << endl << "Text Field is Empty!" << endl; goto R6; }
R7:    cout << "Ethnicity\t\t\t: "; getline(cin, dEthnicTemp); if (dEthnicTemp == "" || dEthnicTemp == " ") { cout << endl << "Text Field is Empty!" << endl; goto R7; }
R8:    cout << "Gender\t\t\t\t: "; getline(cin, dGenderTemp); if (dGenderTemp == "" || dGenderTemp == " ") { cout << endl << "Text Field is Empty!" << endl; goto R8; }
R9:    cout << "Known Underlying Conditions\t: "; getline(cin, dUndCondTemp); if (dUndCondTemp == "" || dUndCondTemp == " ") { cout << endl << "Text Field is Empty!" << endl; goto R9; }
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
R10:    cout << endl << "Contact Number\t\t\t: "; getline(cin, dNumTemp); if (dNumTemp == "" || dNumTemp == " ") { cout << endl << "Text Field is Empty!" << endl; goto R10; }
R11:    cout << "Email Address\t\t\t: "; getline(cin, dEAddTemp); if (dEAddTemp == "" || dEAddTemp == " ") { cout << endl << "Text Field is Empty!" << endl; goto R11; }
	cout << "Physical Address\t\t:";                                        //Breaks down address into parts, so user doesn't try to use comma's to seperate values
R12:    cout << endl << "\t(Street)\t\t: "; getline(cin, dStreet); if (dStreet == "" || dStreet == " ") { cout << endl << "Text Field is Empty!" << endl; goto R12; }
R13:    cout << "\t(Suburb/Town)\t\t: "; getline(cin, dSuburb); if (dSuburb == "" || dSuburb == " ") { cout << endl << "Text Field is Empty!" << endl; goto R13; }
R14:    cout << "\t(City)\t\t\t: "; getline(cin, dCity); if (dCity == "" || dCity == " ") { cout << endl << "Text Field is Empty!" << endl; goto R14; }
	dPAddTemp = dStreet + "/" + dSuburb + "/" + dCity;     //Address parts combined into one string
	cout << "Date of Last Donation" << endl;
	cout << "(Press Enter if Unknown)\t: "; getline(cin, dLastDonateTemp);
	if (dLastDonateTemp == "") {                                            //If statement allows user to press enter and move past this question, and fills data with "unknown"
		dLastDonateTemp = "Unknown";
	}
R15:    cout << "Username\t\t\t: "; getline(cin, dUnameTemp); if (dUnameTemp == "" || dUnameTemp == " ") { cout << endl << "Text Field is Empty!" << endl; goto R15; }
R16:    cout << "Password\t\t\t: "; getline(cin, dPwordTemp); if (dPwordTemp == "" || dPwordTemp == " ") { cout << endl << "Text Field is Empty!" << endl; goto R16; }
	cout << endl << endl;
	donorWriteFunc();
	cout << "Thanks for Registering!" << endl;
	cout << endl << "Returning to Menu..." << endl;

}

void donorInfo::donorEditInfo() {
	string bloodSelect, dStreet, dSuburb, dCity;
	//donorInfo my_donor_info = Get_donor_info((lineFoundOn - 1), donorFilePath);
	donorInfo donorEdit;
	cout << "Please input your new information: ";

	//Takes user input and stores in temp variable before moving into structure
R1:    cout << endl << "First Name\t\t\t: "; getline(cin, donorEdit.firstName); if (donorEdit.firstName == "" || donorEdit.firstName == " ") { cout << endl << "Text Field is Empty!" << endl; goto R1; }

R2:    cout << "Last Name\t\t\t: "; getline(cin, donorEdit.lastName); if (donorEdit.lastName == "" || donorEdit.lastName == " ") { cout << endl << "Text Field is Empty!" << endl; goto R2; }

	cout << "Date of Birth\t\t\t(DD/MM/YYYY)";
R3:    cout << endl << "\t\t\tDay\t: "; getline(cin, dDOBDay); if (dDOBDay == "" || dDOBDay == " ") { cout << endl << "Text Field is Empty!" << endl; goto R3; }

R4:    cout << "\t\t\tMonth\t: "; getline(cin, dDOBMonth); if (dDOBMonth == "" || dDOBMonth == " ") { cout << endl << "Text Field is Empty!" << endl; goto R4; }

R5:    cout << "\t\t\tYear\t: "; getline(cin, dDOBYear); if (dDOBYear == "" || dDOBYear == " ") { cout << endl << "Please input Year" << endl; goto R5; }

	donorEdit.dob = dDOBDay + "/" + dDOBMonth + "/" + dDOBYear; //DOB split into different parts to try make sure the format is the same when put into struct
R6:    cout << "Nationality\t\t\t: "; getline(cin, donorEdit.nationality); if (donorEdit.nationality == "" || donorEdit.nationality == " ") { cout << endl << "Text Field is Empty!" << endl; goto R6; }

R7:    cout << "Ethnicity\t\t\t: "; getline(cin, donorEdit.ethnicity); if (donorEdit.ethnicity == "" || donorEdit.ethnicity == " ") { cout << endl << "Text Field is Empty!" << endl; goto R7; }

R8:    cout << "Gender\t\t\t\t: "; getline(cin, donorEdit.gender); if (donorEdit.gender == "" || donorEdit.gender == " ") { cout << endl << "Text Field is Empty!" << endl; goto R8; }

R9:    cout << "Known Underlying Conditions\t: "; getline(cin, donorEdit.underlyCond); if (donorEdit.underlyCond == "" || donorEdit.underlyCond == " ") { cout << endl << "Text Field is Empty!" << endl; goto R9; }

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
	donorEdit.bloodGroup = bloodSelect;

R10:    cout << endl << "Contact Number\t\t\t: "; getline(cin, donorEdit.contactNum); if (donorEdit.contactNum == "" || donorEdit.contactNum == " ") { cout << endl << "Text Field is Empty!" << endl; goto R10; }

R11:    cout << "Email Address\t\t\t: "; getline(cin, donorEdit.emailAddr); if (donorEdit.emailAddr == "" || donorEdit.emailAddr == " ") { cout << endl << "Text Field is Empty!" << endl; goto R11; }

	cout << "Physical Address\t\t:";                                        //Breaks down address into parts, so user doesn't try to use comma's to seperate values
R12:    cout << endl << "\t(Street)\t\t: "; getline(cin, dStreet); if (dStreet == "" || dStreet == " ") { cout << endl << "Text Field is Empty!" << endl; goto R12; }

R13:    cout << "\t(Suburb/Town)\t\t: "; getline(cin, dSuburb); if (dSuburb == "" || dSuburb == " ") { cout << endl << "Text Field is Empty!" << endl; goto R13; }

R14:    cout << "\t(City)\t\t\t: "; getline(cin, dCity); if (dCity == "" || dCity == " ") { cout << endl << "Text Field is Empty!" << endl; goto R14; }

	donorEdit.physAddr = dStreet + "/" + dSuburb + "/" + dCity;     //Address parts combined into one string
	cout << "Date of Last Donation" << endl;
	cout << "(Press Enter if Unknown)\t: "; getline(cin, donorEdit.lastDonation);
	if (donorEdit.lastDonation == "") {                                            //If statement allows user to press enter and move past this question, and fills data with "unknown"
		donorEdit.lastDonation = "Unknown";
	}
R15:    cout << "Username\t\t\t: "; getline(cin, donorEdit.username); if (donorEdit.username == "" || donorEdit.username == " ") { cout << endl << "Text Field is Empty!" << endl; goto R15; }

R16:    cout << "Password\t\t\t: "; getline(cin, donorEdit.password); if (donorEdit.password == "" || donorEdit.password == " ") { cout << endl << "Text Field is Empty!" << endl; goto R16; }

	cout << endl << endl;

	donorEditFunc(donorEdit);
}

//Donor Login Function
void donorLoginFunc() {
	//Formatting
	cout << endl << endl;
	cout << "\tDonor Login" << endl;
	lineFunc(31, "*");
	cout << endl << "Log In as a Blood Donor" << endl << endl;

	//Ask for username
	string temp_user;

	cout << endl << "\tUsername: "; getline(cin, temp_user);

	//Check username exists in the csv by calling InfoExists() with hardcoded index and file to open
	bool username_exists = InfoExists(temp_user, donorFilePath, donor_username);


	if (username_exists) {

		int loginCounter = 1;
		unameLine = lineFoundOn;        //Sets a variable to hold the number of the line the username was found on



	PassReAsk:
		string temp_pass;

		cout << endl << "\tPassword: "; getline(cin, temp_pass);
		cout << endl << endl;

		//Check password exists by calling InfoExists()
		bool password_exists = InfoExists(temp_pass, donorFilePath, donor_password);
		pwordLine = lineFoundOn;        //Sets a differernt variable to hold number of line password is on
		if (password_exists && unameLine == pwordLine) {    //Makes sure password exists and is on the same line as the username, therefore meaning its the same account


			cout << endl << "Press Enter to Log In"; cin.ignore();
			donorFrontPage();       //If username and password are both correct and match the info stored upon same line in csv, then proceed



		}
		else {
			if (loginCounter > 3) {     //Tracks login attemps. Once attempted tries is more than 3, send user back to main menu
				cout << endl << "\tToo Many Login Attempts" << endl << endl << "Returning to Menu...";
				menuFunc();
			}
			else {
				// tell user invalid password! 
				cout << endl << "\tInvalid Password!, please try again ";
				loginCounter++;         //Adds to login attempt tracker
				goto PassReAsk;
			}

		}
	}
	else {
		//tell user "username" isnt registered! 
		string dLoginRetry;
		cout << endl << "\tThe username " << temp_user << " is not registered as a donor!" << endl;
	rLoginRetryRestart:
		cout << endl << "\tDid you want to try again? [Y]/[N]" << endl << "\t"; cin >> dLoginRetry;
		cin.ignore();
		if (dLoginRetry == "Y" || dLoginRetry == "y") {
			donorLoginFunc();
		}
		else if (dLoginRetry == "N" || dLoginRetry == "n") {
			cout << endl << "Returning to Menu..." << endl;
			menuFunc();
		}
		else {
			cout << endl << "Please Input a Valid Option" << endl;
			goto rLoginRetryRestart;
		}


	}
}

//Admin Login Function
void adminLoginFunc() {
	//Formatting
	cout << endl << endl;
	cout << "\tAdmin Login" << endl;
	lineFunc(31, "*");
	cout << endl << "Log In as Admin" << endl << endl;

	//Ask for username
	string temp_user;

	cout << endl << "\tUsername: "; getline(cin, temp_user);

	//Check username exists in the csv by calling InfoExists() with hardcoded index and file to open
	bool username_exists = InfoExists(temp_user, adminFilePath, admin_username);


	if (username_exists) {

		int loginCounter = 1;
		unameLine = lineFoundOn;        //Sets a variable to hold the number of the line the username was found on



	PassReAsk:
		string temp_pass;

		cout << endl << "\tPassword: "; getline(cin, temp_pass);
		cout << endl << endl;

		//Check password exists by calling InfoExists()
		bool password_exists = InfoExists(temp_pass, adminFilePath, admin_password);
		pwordLine = lineFoundOn;        //Sets a differernt variable to hold number of line password is on
		if (password_exists && unameLine == pwordLine) {    //Makes sure password exists and is on the same line as the username, therefore meaning its the same account


			cout << endl << "Press Enter to Log In"; cin.ignore();
			adminFrontPage();       //If username and password are both correct and match the info stored upon same line in csv, then proceed



		}
		else {
			if (loginCounter > 3) {     //Tracks login attemps. Once attempted tries is more than 3, send user back to main menu
				cout << endl << "\tToo Many Login Attempts" << endl << endl << "Returning to Menu...";
				menuFunc();
			}
			else {
				// tell user invalid password! 
				cout << endl << "\tInvalid Password!, please try again ";
				loginCounter++;         //Adds to login attempt tracker
				goto PassReAsk;
			}

		}
	}
	else {
		//tell user "username" isnt registered! 
		string aLoginRetry;
		cout << endl << "\tThe username " << temp_user << " is not registered!" << endl;
	aLoginRetryRestart:
		cout << endl << "\tDid you want to try again? [Y]/[N]" << endl << "\t"; cin >> aLoginRetry;
		cin.ignore();
		if (aLoginRetry == "Y" || aLoginRetry == "y") {
			adminLoginFunc();
		}
		else if (aLoginRetry == "N" || aLoginRetry == "n") {
			cout << endl << "Returning to Menu..." << endl;
			menuFunc();
		}
		else {
			cout << endl << "Please Input a Valid Option" << endl;
			goto aLoginRetryRestart;
		}


	}

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



//Func to Edit info in donor csv
void donorEditFunc(donorInfo& donorEdit) {

	string line;
	donorInfo my_donor_info = Get_donor_info((lineFoundOn - 1), "DonorInfo.csv");


	fstream file;
	ofstream fileTemp;

	file.open(donorFilePath, ios::in | ios::out | ios::app);

	fileTemp.open("DonorInfoTemp.csv", ios::out);

	InfoExists(my_donor_info.firstName, donorFilePath, First_Name); int num1 = lineFoundOn;

	InfoExists(my_donor_info.username, donorFilePath, donor_username); int num3 = lineFoundOn;
	int lineCounter = 0;
	if (num1 == num3) {

		while (getline(file, line)) {


			lineCounter++;

			if (lineCounter == lineFoundOn) {

				cout << donorEdit.firstName;
				vector<string> values = split(line, ",");
				// the name is at index[0]            
				values[0] = donorEdit.firstName;
				values[1] = donorEdit.lastName;
				values[2] = donorEdit.dob;
				values[3] = donorEdit.nationality;
				values[4] = donorEdit.ethnicity;
				values[5] = donorEdit.gender;
				values[6] = donorEdit.underlyCond;
				values[7] = donorEdit.bloodGroup;
				values[8] = "|" + donorEdit.contactNum;
				values[9] = donorEdit.emailAddr;
				values[10] = donorEdit.physAddr;
				values[11] = donorEdit.lastDonation;
				values[12] = donorEdit.username;
				values[13] = donorEdit.password;



				donorInfo my_donor_info = Get_donor_info((lineCounter), "DonorInfo.csv");




				for (string lineValue : values) {
					fileTemp << lineValue << ",";
				}
				fileTemp << endl;



			}
			else {

				fileTemp << line << endl;

			}
		}
		file.close();
		fileTemp.close();
		fstream sourceFile;
		ofstream destFile;
		string line2;
		sourceFile.open("DonorInfoTemp.csv", ios::in | ios::out | ios::app);
		destFile.open(donorFilePath, ios::out);
		while (getline(sourceFile, line2)) {
			destFile << line2 << endl;
		}

		sourceFile.close();
		destFile.close();
		remove("DonorInfoTemp.csv");



	}
}

bool InfoExists(std::string target_info, string file_to_open, int where_to_look) {

	ifstream file;
	std::string line;
	bool isHeader = true;
	int lineCounter = 0;
	file.open(file_to_open, std::ios::in);
	while (std::getline(file, line)) {
		lineCounter++;
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

			lineFoundOn = lineCounter;
			file.close();
			return true;
		}
	}
	// otherwise we didn't find the info,
	// clean up our resources and return
	file.close();
	return false;
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

void getDate() {
	string tempYear, tempMonth, tempDay;
	time_t t = std::time(0);   // get time now
	tm* now = std::localtime(&t);

	cout << now->tm_mday << endl;


	if ((now->tm_mon + 1) == 1) { tempMonth = "January"; }
	if ((now->tm_mon + 1) == 2) { tempMonth = "February"; }
	if ((now->tm_mon + 1) == 3) { tempMonth = "March"; }
	if ((now->tm_mon + 1) == 4) { tempMonth = "April"; }
	if ((now->tm_mon + 1) == 5) { tempMonth = "May"; }
	if ((now->tm_mon + 1) == 6) { tempMonth = "June"; }
	if ((now->tm_mon + 1) == 7) { tempMonth = "July"; }
	if ((now->tm_mon + 1) == 8) { tempMonth = "August"; }
	if ((now->tm_mon + 1) == 9) { tempMonth = "September"; }
	if ((now->tm_mon + 1) == 10) { tempMonth = "October"; }
	if ((now->tm_mon + 1) == 11) { tempMonth = "November"; }
	if ((now->tm_mon + 1) == 12) { tempMonth = "December"; }
	cout << tempMonth;
	//cout << (now->tm_mon + 1) << endl;
	cout << (now->tm_year + 1900) << endl;
}

void getTime() {
	string tempHour, tempMin, tempSec;
	time_t t = std::time(0);   // get time now
	tm* now = std::localtime(&t);

	cout << (now->tm_hour - 12) << ":" << now->tm_min;
	if (now->tm_hour < 12) {
		cout << " am." << endl;
	}
	else {
		cout << " pm." << endl;
	}
}

void fullDateAndTime() {
	auto now = std::chrono::system_clock::now();


	std::time_t time_now = std::chrono::system_clock::to_time_t(now);

	std::cout << std::ctime(&time_now);
}

//booking functions

void is_slot_avavilable(int data_row_num) { // data row num will come from user input

	ifstream file;
	std::string line;
	bool isHeader = true;
	int row_counter = 0, lineCounter = 0;




	file.open("Bookings.csv", std::ios::in);
	while (std::getline(file, line)) {
		// this is the CSV header so skip it 
		if (isHeader) {
			isHeader = false;
			continue;
		}
		row_counter++; // make sure we are only looking at the desired row

		if (data_row_num == row_counter) {


			// split the CSV line into an array
			// check the availability column and if the slot is available return true. if its not return false
			vector<string> values = split(line, ",");


			file.close();

			if (values[2] == "yes") {
				
				dateAvailable = true;

			}
			else {
				
				dateAvailable = false;
			}



		}

	} file.close();


}


void book_slot_if_available(int data_row_num) {
	fstream file;
	ofstream tempFile;
	std::string line;
	bool isHeader = true;
	int row_counter = 0;



	file.open("Bookings.csv", ios::in | ios::out | ios::app); // TODO open in write mode and change the yes to a no
	tempFile.open("bookingsTemp.csv", ios::out);


	int lineCounter = 0;
	if (dateAvailable = true) {

		while (getline(file, line)) {

			
			lineCounter++;

			if (lineCounter == data_row_num) {
				if (isHeader) {
					isHeader = false;
					continue;
				}

				vector<string> values = split(line, ",");
				// the name is at index[0]        
				values[0] = values[0];
				values[1] = values[1];
				values[2] = "no";



				//donorInfo my_donor_info = Get_donor_info((lineCounter), "DonorInfo.csv");




				for (string lineValue : values) {
					tempFile << lineValue << ",";
				}
				tempFile << endl;



			}
			else {

				tempFile << line << endl;

			}
		}
		file.close();
		tempFile.close();
		fstream sourceFile;
		ofstream destFile;
		string line2;
		sourceFile.open("bookingsTemp.csv", ios::in | ios::out | ios::app);
		destFile.open("Bookings.csv", ios::out);
		while (getline(sourceFile, line2)) {
			destFile << line2 << endl;
		}

		sourceFile.close();
		destFile.close();
		remove("bookingsTemp.csv");



	}
	file.close(); //return false;
}



void BookFunction(int lineNum,int lineLimit) {
	int lineToSearch = lineNum;
	while (lineNum < lineLimit) {
	
		is_slot_avavilable(lineToSearch);
		if (dateAvailable = true) {
			string bookAsk;
		AskToBook:
			cout << endl << "Would you like to book this slot? [Y]/[N]:"; cin >> bookAsk;
			if (bookAsk == "Y" || bookAsk == "y") {
				book_slot_if_available(lineToSearch);
			}
			else {
				break;
			}
		}
	}
	//cout << "Please input the line to search: "; cin >> lineToSearch;
	


	
}









int main()
{
	//getDate();
	 //getTime();

	/*ofstream file("DonorInfoTemp.csv");
	file.clear();*/

	//donorEditFunc();
    menuFunc();
	
	//BookFunction();

}

