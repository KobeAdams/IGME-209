// StringStream.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>

int main()
{
    int month = 3;
    int today = 28;
    int days[12];
    days[0] = 31;
    days[1] = 28;
    days[2] = 31;
    days[3] = 30;
    days[4] = 31;
    days[5] = 30;
    days[6] = 31;
    days[7] = 31;
    days[8] = 30;
    days[9] = 31;
    days[10] = 30;
    days[11] = 31;
    char name[] = "Cameron Adams 5/07";//{'C','a','m','e','r','o','n',' ','A','d','a','m','s',' ','5','/','0','7'};
    //cameron adams 5/07;

    std::stringstream ss(name);
    std::string first, last;
    int birthMonth = 0, birthDay = 0;
    char slash;

    ss >>first>>last>>birthMonth>>slash>>birthDay;

    int daysTill = 0;

    while (month != birthMonth || today != birthDay)
    {

        today++;
        if (today > days[month])
        {
            month++;
            if (month > 12)
            {
                month = 1;
            }
            today = 1;
        }
        daysTill++;
    }

    std::cout << first << ", Your birthday is in " << daysTill << " days";

    

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
