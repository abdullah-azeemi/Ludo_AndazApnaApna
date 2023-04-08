#include "Board.h"
#include"Player.h"
#include"Header.h"
#include<string>

Board::Board()
{
	Pos start1, end1, win1;
	start1.ri = 1, end1.ri = 9, win1.ri = 52;
	char* sym1 = new char[4];
	sym1[0] = 'b1'; sym1[1] = 'b2', sym1[2] = 'b3', sym1[3] = 'b4';

	Ps[0] = new Player("Abdullah", BLUE, start1, end1, win1, sym1);
}
Board::Board(char** _B, Player _P[6], Pos* _st, Pos* _stop, Pos* _home, int _nop)
{
	this->B = _B;
	this->Ps = _P;
	this->start = _st;
	this->stop = _stop;
	this->atHome = _home;
	this->nop = _nop;
}