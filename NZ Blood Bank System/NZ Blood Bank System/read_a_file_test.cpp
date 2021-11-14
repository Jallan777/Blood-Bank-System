
#include <iostream>
#include <fstream>
#include <string>

using namespace std;






int read_a_csv() {

    string filePath = "C:/Users/jacob/OneDrive/Documents/GitHub/Blood-Bank-System/NZ Blood Bank System/NZ Blood Bank System/Patient info.csv";
    //Ainsley Address "C:\\Users\\ainsley2\\Desktop\\ainsley josh folder\\NZ Blood Bank System\\NZ Blood Bank System\\Patient info.csv";
fstream file;

file.open(filePath, ios::in);

string line;

while (std::getline(file, line)){

    cout << line << endl;

}

file.close();


return 0;









}


