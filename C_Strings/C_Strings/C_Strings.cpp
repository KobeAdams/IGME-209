// C_Strings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>


int main()
{
    char super[50] = "supercalifraglistic";
    std::cout << strlen(super);
    std::cout <<"\n";
    char exp[25] = "expialidocious";
    strcat_s(super, exp);
    std::cout << super;
    std:: cout << "\n";
    int iCount = 0;
    for (char letter: super)
    {
        if (letter == 'i')
        {
            iCount++;
        }
    }
    std::cout << iCount;
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
