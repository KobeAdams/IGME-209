// HW_Classes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Player.h"
#include "Fighter.h"
using namespace std;

int main()
{
    const char* name = "Bob";
    const char* name2 = "Zepher";

    cout << "The 9th great player war begins!\n\n";

    //Fighter p1 = Fighter();
    
    //Player p2 = Player(name, 20, 18, 6);
   // Player* p3 = new Player();
    Fighter* p4 = new Fighter(name2, 20, 17, 17,17);

    Player* battlers[10];
    battlers[9] = p4;
    int size = 10;
    int loop = 10;

    for (int i = 0; i < 9; i++)
    {
        int x = rand() % 2-1;
        if (x == 1)
            battlers[i] = new Player();
        else
            battlers[i] = new Fighter();
    }

    while (size > 1)
    {
        loop = size;
        for (int i = 0; i < loop; i++)
        {
            if (i - 1 > 0 && battlers[i] != nullptr)
            {
                battlers[i]->Attack(battlers[i - 1]);
                delete battlers[i - 1];
                battlers[i - 1] = nullptr;
                size--;
            }
            
        }
    }
    
    

    for (int i = 0; i < 10; i++)
    {
        if (battlers[i] != nullptr)
        {
            delete battlers[i];
        }
        
    }
    delete[] battlers;

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
