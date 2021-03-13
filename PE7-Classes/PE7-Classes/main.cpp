#include <iostream>
#include "Player.h"
using namespace std;

int main()
{
	Player p1;
	
	const char* point = "Bari";
	int s, w, d;
	s = 7;
	w = 8;
	d = 9;
	Player p2(point, s, d, w);
	
	const char* name = "Zepher";
	Player* p3 = new Player;
	Player* p4 = new Player(name, w, s, d);

	p1.printPlayer();
	cout << "\n\n";
	p2.printPlayer();
	cout << "\n\n";
	p3->printPlayer();
	cout << "\n\n";
	p4->printPlayer();

	delete p3;
	delete p4;
}