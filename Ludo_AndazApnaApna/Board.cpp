#include "Board.h"

Board::Board (char** _B, Player* _P, Pos *_st, Pos *_stop, Pos *_home, int _nop)
{
	this->B = _B;
	this->P = _P;
	this->start = _st;
	this->stop = _stop;
	this->atHome = _home;
	this->nop = _nop;
}