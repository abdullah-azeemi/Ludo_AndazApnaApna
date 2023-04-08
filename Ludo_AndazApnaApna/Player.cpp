#include "Player.h"

Player::Player(string _Name, Color _C, int _start_Pos, int _end_Pos, int _diceWin_Pos, char* _sym)
{
	this->Name = _Name;
	this->C = _C;
	this->start_Pos = _start_Pos;
	this->end_Pos = _end_Pos;
	this->diceWin_Pos = _diceWin_Pos;
	this->Sym = _sym;
}
string Player:: getName()
{
	return this->Name;
}
Color Player::getColor()
{
	return this->C;
}
int Player::get_StartPos()
{
	return this->start_Pos;
}
int Player::get_EndPos()
{
	return this->end_Pos;
}
int Player::get_diceWin_Pos()
{
	return this->diceWin_Pos;
}
char* Player::getSymbols()
{
	return this->Sym;
}