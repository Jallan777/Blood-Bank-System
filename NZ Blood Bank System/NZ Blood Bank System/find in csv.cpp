#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using std::ifstream;
using std::string;
using std::vector;

// fuck c++ idk how to read from a file
// i got a thing reading line by line and cout'ing it
//so i need to read each line but only the nth thing 



// splits a string based on a delimiter: ie ","  splits it and stores in a vector? yeah I just copy pasted this from google its a pretty common function built in to every other fucking language lmao 

// input : "a|b|c|d", delimiter="|"
// output: ["a", "b", "c", "d"]

// look down


// so if your CSV is something like
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

bool recip_username_exists(std::string userName) {

    ifstream file;
    std::string line;
    bool isHeader = true;

    file.open("./demo.csv", std::ios::in);
    while (std::getline(file, line)) {
        // this is the CSV header so skip it      
        if (isHeader) {
            isHeader = false;
            continue;
        }
        // split the CSV line into an array
        vector<string> values = split(line, ",");
        // the name is at index[1]            
        string name = values[1];
        // check name against username
        if (name == userName) {
            // if we find the user, clean up our resources
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

string getUsername() {
    return "ainsley";
}

int main() {
    bool result = recip_username_exists(getUsername());                //and the string can be passed from another function?
    if (result) {
        std::cout << "USERNAME EXISTS";
    }
    else {
        std::cout << "NOT EXISTS";
    }
} //this is fucking amazing thank you
// i find c++ so hard to understand when reading online so the comments explaining each bit are super handy