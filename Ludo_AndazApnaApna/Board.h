#pragma once
#include"Player.h"
#include"Dice.h"

class Player;
class Dice;

class Board 
{
private:
	char** B;
	int *start;
	int *stop;
	int *atHome;
	int nop;


public:
	
	Board();
	Board(char** _B, int* _st, int* _stop, int* _home, int _nop);
};

