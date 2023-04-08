#pragma once
#include"Board.h"
#include"Player.h"
#include"Dice.h"

class Player;
class Dice;
class Board;

class Ludo
{
private:
	Player* Ps[6];
	Board* B;
	int turn;
	int* PlayerPositions;

public:
	Ludo();

};

