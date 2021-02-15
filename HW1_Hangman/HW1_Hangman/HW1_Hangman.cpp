// HW1_Hangman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "hangman.h"
#include <string>

int main()
{
    char correctWord[10] = "mountain";
    char word[10] = "________";
    char wrongLetters[27] = "";
    char correctLetters[10]="";
    char guessed[5]="";
    char check[2]="";
    int correctLetterChecker = 0;

    std::cout << "Welcome to hangman!\nThe word has 8 leters in it!\n\n";

    showGallows(strlen(wrongLetters));
    std::cout << "Wrong Letters: " << wrongLetters<<"\n";
    showSolved(word, correctLetters);
    std::cout << "Word To solve: " << word<<"\n";


    do
    {
        std::cout << "Your have "<<8-strlen(wrongLetters)<<" guesses left.\nWhat letter will you guess?";
        std::cin.getline(guessed, 2);
        for (char letter : correctWord)
        {
            
            check[0] = letter;
            correctLetterChecker = strcmp(guessed, check);
            if (correctLetterChecker == 0)
            {
                strcat_s(correctLetters, guessed);
                break;
            }

            /*if (strcmp(guessed, check) == 0)
            {
                strcat_s(correctLetters, guessed);
                break;
            }
            else
            {
                strcat_s(wrongLetters, guessed);
                
            }*/
        }

        if (correctLetterChecker != 0)
        {
            strcat_s(wrongLetters, guessed);
        }

        showGallows(strlen(wrongLetters));
        std::cout << "Wrong Letters: " << wrongLetters<<"\n";
        showSolved(word, correctLetters);
        std::cout << "Word To solve: " << word << "\n";

        if (strlen(correctLetters) == 7)
        {
            break;
        }
        std::cout << "\n\n\n\n\n\n\n";
    } while (strlen(wrongLetters) < 8);
    if (strlen(wrongLetters) == 8)
    {
        std::cout << "Sorry, but you lose, try again nest time";
    }
    else
    {
        std::cout << "Great Job you won!";
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
