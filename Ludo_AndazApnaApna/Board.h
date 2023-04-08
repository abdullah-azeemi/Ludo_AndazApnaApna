#pragma once
#include"Player.h"
#include"Dice.h"
#include<vector>

class Player;
class Dice;

class Board 
{
private:
	char** B;
	vector <int> start;
	vector <int> stop;
	vector<int> atHome;
	int nop;


public:
	
	Board();
	Board(char** _B, vector<int> _st, vector<int> _stop, vector<int> _home, int _nop);
};

