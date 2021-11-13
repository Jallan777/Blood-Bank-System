
#include <iostream>

using namespace std;


#include <iostream>
#include <fstream>
#include <string>


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


