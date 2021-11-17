#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Global functions.h"
#include <string>
using std::ifstream;
using std::string;
using std::vector;

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
        string info = values[where_to_look + 1]; // the enum is one less then the column number
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

donorInfo Get_donor_info(int data_row_num, string file_to_open) { //TODO put a line from the csv into a struct and returning that struct

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
            info_to_return.firstName = values[0];
            info_to_return.lastName = values[1];
            info_to_return.dob = values[2];
            info_to_return.nationality = values[3];
            info_to_return.ethnicity = values[4];
            info_to_return.gender = values[5];
            info_to_return.underlyCond = values[6];
            info_to_return.bloodGroup = values[7];
            info_to_return.contactNum = values[8];
            info_to_return.emailAddr = values[9];
            info_to_return.physAddr = values[10];
            info_to_return.lastDonation = values[11];
            info_to_return.username = values[12];
            info_to_return.password = values[13];

            //close the file
            file.close();

            //once its full with the info return it
            return info_to_return;
        }

    } file.close();
    return info_to_return;


}



//get_recip_info() TODO

// get admin info() TODO