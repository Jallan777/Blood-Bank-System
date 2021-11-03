// NZ Blood Bank System.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Introduction Screen

#include <iostream>
using namespace std;
int bloodBankRepeat;

void lineFunc(int length, string type) {
    for (int i = 0; i < length; i++)
        cout << type;
}

int main()
{

    cout << endl << "\tWelcome to the NZ Blood Bank System!" << endl;
    lineFunc(52,"*");
    cout << endl << endl;
    cout << "Regular weekly donations ensure blood and plasma are available for those in need." << endl;
    cout << "The gift of blood can only be given from one person to another, and there is no substitute." << endl;
    cout << "So it's nice to know New Zealand can rely on everyday heroes' generosity to keep the flow of blood and plasma going." << endl;
    cout << "However, the need for blood and plasma is constant, so we're looking for more lifesavers." << endl;
    cout << "By putting aside a small part of your day you can make a life-changing difference, you can become a lifesaver too!" << endl;
}

