#pragma once

class Player;
class Dice;
class Board;

class Ludo
{
private:
	Player* Ps[6];
	//Board B;
	int turn;
	Dice *D;
	int Nop;
	int indexForMaxRolls;
public:
	Ludo();
	void displayTurnMsg(Player* P1);
	void Play();
	void turnChange();
	void loadAssests();

};

