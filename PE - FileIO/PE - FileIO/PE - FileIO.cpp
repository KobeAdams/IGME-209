// PE - FileIO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream newFile;
    
    newFile.open("data.txt");

    if (newFile.is_open())
    {
        newFile << "ICE!\n";
        newFile << "Off the juice!\n";
        newFile << "Homework Got me Trippin\n";
        newFile.close();
    }

    ifstream readFile;
    readFile.open("data.txt", ios::binary);
    if (readFile.is_open())
    {
        readFile.seekg(0, ios::end);
        int length = (int)readFile.tellg();
        readFile.seekg(0, ios::beg);
        char* content = new char[length + 1];
        readFile.read(content, length);
        content[length] = 0;
        cout << content;
        readFile.close();
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
