#include "Board.h"
#include"Player.h"
#include"Header.h"
#include<string>

Board::Board()
{

}
Board::Board(char** _B, int* _st, int* _stop, int* _home, int _nop)
{
	this->B = _B;
	this->start = _st;
	this->stop = _stop;
	this->atHome = _home;
	this->nop = _nop;
}