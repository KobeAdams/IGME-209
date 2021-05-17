// DSACoin.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <thread>
#include <mutex>
#include <chrono>
#include "Coin.h"
#include "Wallet.h"
using namespace std;

/// <summary>
/// global variables
/// </summary>
std::chrono::high_resolution_clock clockTimer; 
std::chrono::high_resolution_clock::time_point start_time;
ifstream cryptoFile("cryptoFile.txt");;
ofstream walletFile("walletFile.txt");;
std::mutex mtx;

/// <summary>
/// Generates an 80 charater long string with random numbers in each such as
/// "01234567890123456789012345678901234567890123456789012345678901234567890123456789"
/// but with random numbers for each one
/// </summary>
/// <returns></returns>
string mineKey()
{
	//std::lock_guard<std::mutex> lck(mtx);
	
	
	string key;
	int adder;
	// TODO DSA1
	for (int i = 0; i < 80; i++)
	{
		adder = rand() % 10;
		key += to_string(adder);
	}
	return key;
	
}

/// <summary>
/// reads the next crypto key from the keybank file
/// </summary>
/// <returns>returns new crypto to use or "" if the file was completely read</returns>
string readNextCrypto()
{
	//lock_guard<mutex> lxk(mtx);
	string crypto = "";

	// TODO DSA1
	
	if (cryptoFile.is_open())
	{
		getline(cryptoFile, crypto);
	}
	return crypto;
}

double calculateValue()
{
	//lock_guard<mutex> lck(mtx);
	using namespace std::chrono;
	double coinValue = 0.0;
	high_resolution_clock::time_point cut_time = clockTimer.now();
	// TODO DSA1
	duration<double> timeSpan = duration_cast<duration<double>>(cut_time - start_time);
	coinValue = (300 - timeSpan.count()) * 100;
	if (coinValue <= 0)
		coinValue = 0;
	return coinValue;
}

void loop(Wallet& myWallet, int& cn)
{
	string crypto = readNextCrypto();
	string key = "";
	bool found = false;
	int cnt = cn;
	int place = 0;


	while (crypto != "")
	{
		while (found == false)
		{
			key = mineKey();

			cnt++;
			place = key.find(crypto);
			if (place == -1)
			{
				found = false;
			}
			else
			{
				found = true;

			}


		}
		myWallet.AddCoin(new Coin(key, calculateValue()));
		crypto = readNextCrypto();

	}
}

void checker(string crypto, Wallet& myWallet,int& cnt)
{
	lock_guard<mutex> lck(mtx);
	bool found=false;
	string key;
	int place;
	double value;
	while (found == false)
	{
		key = mineKey();
		cnt++;
		place = key.find(crypto);
		if (place == -1)
		{
			found = false;
		}
		else
		{
			value = calculateValue();
			found = true;
			
		}
		

	}
	cout << "found a code \n";
	myWallet.AddCoin(new Coin(key, value));

}

int main()
{
	start_time = clockTimer.now();
	srand(2021);
	Wallet myWallet;
	int cnt = 0;
	
	// TODO DSA1
	// write the main loop
	// mine the keys, check to see if the crypto is in the key
	// create a coin for the good keys and add it to your wallet
	// write out the keys to the walletFile
	vector<string> cryptos;
	for (int i = 0; i < 20; i++)
	{
		cryptos.push_back(readNextCrypto());
	}

	thread c1(checker,cryptos[0],std::ref(myWallet),std::ref(cnt));
	thread c2(checker, cryptos[1], std::ref(myWallet), std::ref(cnt));
	thread c3(checker, cryptos[2], std::ref(myWallet), std::ref(cnt));
	thread c4(checker, cryptos[3], std::ref(myWallet), std::ref(cnt));
	thread c5(checker, cryptos[4], std::ref(myWallet), std::ref(cnt));
	thread c6(checker, cryptos[5], std::ref(myWallet), std::ref(cnt));
	thread c7(checker, cryptos[6], std::ref(myWallet), std::ref(cnt));
	thread c8(checker, cryptos[7], std::ref(myWallet), std::ref(cnt));
	thread c9(checker, cryptos[8], std::ref(myWallet), std::ref(cnt));
	thread c10(checker, cryptos[9], std::ref(myWallet), std::ref(cnt));
	thread c11(checker, cryptos[10], std::ref(myWallet), std::ref(cnt));
	thread c12(checker, cryptos[11], std::ref(myWallet), std::ref(cnt));
	thread c13(checker, cryptos[12], std::ref(myWallet), std::ref(cnt));
	thread c14(checker, cryptos[13], std::ref(myWallet), std::ref(cnt));
	thread c15(checker, cryptos[14], std::ref(myWallet), std::ref(cnt));
	thread c16(checker, cryptos[15], std::ref(myWallet), std::ref(cnt));
	thread c17(checker, cryptos[16], std::ref(myWallet), std::ref(cnt));
	thread c18(checker, cryptos[17], std::ref(myWallet), std::ref(cnt));
	thread c19(checker, cryptos[18], std::ref(myWallet), std::ref(cnt));
	thread c20(checker, cryptos[19], std::ref(myWallet), std::ref(cnt));
	
	
	
	
	
	
	
	/*while (crypto != "")
	{
		while (found == false)
		{
			key = mineKey();
			
			cnt++;
			place = key.find(crypto);
			if (place==-1)
			{
				found = false;
			}
			else
			{
				found = true;
				
			}
			
			
		}
		myWallet.AddCoin(new Coin(key, calculateValue()));
		crypto = readNextCrypto();
		
	}*/

	c1.join();
	c2.join();
	c3.join();
	c4.join();
	c5.join();
	c6.join();
	c7.join();
	c8.join();
	c9.join();
	c10.join();
	c11.join();
	c12.join();
	c13.join();
	c14.join();
	c15.join();
	c16.join();
	c18.join();
	c19.join();
	c20.join();

	cout << "keys searched: " << cnt << endl;
	cout << "Wallet value: " << myWallet.GetValue() << endl;
	
	/*c3.join();
	c4.join();
	c5.join();*/

}

