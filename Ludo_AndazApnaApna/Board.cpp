#include "Board.h"
#include"Player.h"
#include"Header.h"
#include<string>

Board::Board()
{
	B = new char* [2];
	for (int ri = 0; ri < 2; ri++)
	{
		B[ri] = new char[8];
		for (int ci = 0; ci < 90; ci++)
		{
			B[ri][ci] = '-';
		}
	}
	this->start = { 1,14,27,46,59,72 };
	this->stop = { 9,22,35,41,54,67,80,86 };
	this->atHome = { 89,12,25,44,57,70 };
	nop = 6;
}
Board::Board(char** _B, vector<int>_st, vector<int> _stop, vector<int> _home, int _nop)
{
	this->B = _B;
	this->start = _st;
	this->stop = _stop;
	this->atHome = _home;
	this->nop = _nop;
}