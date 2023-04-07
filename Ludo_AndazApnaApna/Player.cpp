#include "Player.h"

Player::Player(string _Name, Color _C, Pos _start_Pos, Pos _end_Pos, Pos _diceWin_Pos, char* _sym)
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
Pos Player::get_StartPos()
{
	this->start_Pos;
}
Pos Player::get_EndPos()
{
	this->end_Pos;
}
Pos Player::get_diceWin_Pos()
{
	this->diceWin_Pos;
}
char* Player::getSymbols()
{
	this->Sym;
}