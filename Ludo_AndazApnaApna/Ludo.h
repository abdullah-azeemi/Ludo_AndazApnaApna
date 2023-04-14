#pragma once
#include"Header.h"
#include<vector>

class Player;
class Dice;
class Board;

class Ludo
{
private:
	Player* Ps[6];
	int turn;
	Dice *D;
	int Nop;
	int indexForMaxRolls;
	bool hasDice_rolled;
	bool moved;

public:
	Ludo();
	void displayTurnMsg(Player* P1);
	void Play();
	void turnChange();
};

