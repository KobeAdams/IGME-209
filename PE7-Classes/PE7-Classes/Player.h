#pragma once
class Player
{
	private:
		const char* name;
		int str, dex, wis;
	public:
		Player();
		Player(const char* name, int& str, int& dex, int& wis);
		void printPlayer();

};