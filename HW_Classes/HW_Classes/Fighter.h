#pragma once
#include "Player.h"
class Fighter :
    public Player
{
public:
    Fighter();
    Fighter(const char* fname,int weapSkill, int str, int dex,int wis);
    void PrintFighter();
    void Attack(Player* player);
    ~Fighter();
private:
    int weapSkill;
};

