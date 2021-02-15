#pragma once
void showGallows(int guessLimit)
{
	if (guessLimit == 0)
	{
		std::cout << " _______        \n|        \n|        \n|        \n|        \n|        \n|";
	}
	else if (guessLimit == 1)
	{
		std::cout << " _______        \n|   |        \n|        \n|        \n|        \n|        \n|";
	}
	else if (guessLimit == 2)
	{
		std::cout << " _______        \n|   |        \n|   O     \n|        \n|        \n|        \n|";
	}
	else if (guessLimit == 3)
	{
		std::cout << " _______        \n|   |        \n|   O     \n|   |     \n|        \n|        \n|";
	}
	else if (guessLimit == 4)
	{
		std::cout << " _______        \n|   |        \n|   O     \n|  /|     \n|        \n|        \n|";
	}
	else if (guessLimit == 5)
	{
		std::cout << " _______        \n|   |        \n|   O     \n|  /|\\     \n|        \n|        \n|";
	}
	else if (guessLimit == 6)
	{
		std::cout << " _______        \n|   |        \n|   O     \n|  /|\\     \n|   |     \n|        \n|";
	}
	else if (guessLimit == 7)
	{
		std::cout << " _______        \n|   |        \n|   O     \n|  /|\\     \n|   |    \n|  /      \n|";
	}
	else if (guessLimit == 8)
	{
		std::cout << " _______        \n|   |        \n|   O     \n|  /|\\     \n|   |    \n|  / \\     \n|";
	}
	std::cout << "\n";
}

void showSolved(char word[], char guesses[])
{
	//mountain
	char mountain[10] = "mountain";
	for (int i = 0; i < strlen(guesses); i++)
	{
		if (guesses[i] == mountain[0])
		{
			word[0]= mountain[0];
		}
		if (guesses[i] == mountain[1])
		{
			word[1] = mountain[1];
		}
		if (guesses[i] == mountain[2])
		{
			word[2] = mountain[2];
		}
		if (guesses[i] == mountain[3])
		{
			word[3] = mountain[3];
		}
		if (guesses[i] == mountain[4])
		{
			word[4] = mountain[4];
			word[9] = mountain[4];
		}
		if (guesses[i] == mountain[5])
		{
			word[5] = mountain[5];
		}
		if (guesses[i] == mountain[6])
		{
			word[6] = mountain[6];
		}
		if (guesses[i] == mountain[7])
		{
			word[7] = mountain[7];
		}
		if (guesses[i] == mountain[8])
		{
			word[8] = mountain[8];
		}
	}
}