#pragma once
#include"Player.h"
#include"Dice.h"

class Player;
class Dice;

class Board 
{
private:
	char** B;
	Pos *start;
	Pos *stop;
	Pos *atHome;
	int nop;


public:
	Player* Ps[6];
	Board();
	Board(char** _B, Player _P[6], Pos* _st, Pos* _stop, Pos* _home, int _nop);
};

