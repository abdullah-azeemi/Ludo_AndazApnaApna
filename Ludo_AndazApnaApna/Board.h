#pragma once
#include"Player.h"

class Player;

class Board 
{
private:
	char** B;
	Player* P;
	Pos *start;
	Pos *stop;
	Pos *atHome;
	int nop;

public:
	Board(char** _B, Player* _P, Pos *_st, Pos *_stop, Pos *_home, int _nop);
};

