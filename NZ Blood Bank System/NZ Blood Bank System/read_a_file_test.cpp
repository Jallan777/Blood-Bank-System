
#include <iostream>

using namespace std;


#include <iostream>
#include <fstream>
#include <string>


// order of info for patient  First name, last name, dob, nationality, ethnicity, gender, underlying condition, blood group
// contact no, email, physical address, last date of donation(optional), username  and password.


int read_a_csv() {

    string filePath = "C:\\Users\\ainsley2\\Desktop\\ainsley josh folder\\NZ Blood Bank System\\NZ Blood Bank System\\Patient info.csv";
fstream file;

file.open(filePath, ios::in);

string line;

while (std::getline(file, line)){

    cout << line << endl;

}

file.close();


return 0;









}

