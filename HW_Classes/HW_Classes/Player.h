#pragma once
class Player
{
public:
	Player();
	Player(const char*cName, int strength, int dext, int wisdom);
	void PrintPlayer();
	~Player();
	const char* getName();
	virtual void Attack(Player* player);
private:
	const char* name;
	int str, dex, wis;

	

};

