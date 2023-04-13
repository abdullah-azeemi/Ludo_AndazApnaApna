#include "Player.h"

Player::Player(string _Name, Color _C, int _start_Pos, int _end_Pos, int _diceWin_Pos, char* _sym, vector<int> _initPos, int piecesH, int piecesJ, int piecesB)
{
	this->Name = _Name;
	this->C = _C;
	this->start_Pos = _start_Pos;
	this->end_Pos = _end_Pos;
	this->diceWin_Pos = _diceWin_Pos;
	this->Sym = _sym;
	this->initPos = _initPos;
	this->piecesAthome = piecesH;
	this->piecesAtJail = piecesJ;
	this->piecesonBoard = piecesB;
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
int Player::getpiecesAtHome()
{
	return this->piecesAthome;
}
int Player::getpiecesAtJail()
{
	return this->piecesAtJail;
}
int Player::getpiecesonBoard()
{
	return this->piecesonBoard;
}
void Player::getOutofHome(int turn, int nop)
{
	if (nop > 4)
	{
		if (piecesAtJail > 0)
		{
			int x = piecesonBoard;

			this->piecesonBoard += 1;
			this->piecesAtJail -= 1;
			if (turn == 0)
				initPos[x] = 1;

			else if (turn == 1)
				initPos[x] = 14;

			else if (turn == 2)
				initPos[x] = 27;

			else if (turn == 4)
				initPos[x] = 46;

			else if (turn == 5)
				initPos[x] = 59;

			else
				initPos[x] = 72;

		}
	}
	else
	{
		if (piecesAtJail > 0)
		{
			int x = piecesonBoard;

			this->piecesonBoard += 1;
			this->piecesAtJail -= 1;
			if (turn == 0)
				initPos[x] = 1;

			else if (turn == 1)
				initPos[x] = 14+1;

			else if (turn == 2)
				initPos[x] = 27+1;

			else if (turn == 3)
				initPos[x] = 40;

		}
	}
}   
int Player::getPos(int index)
{
	return this->initPos[index];
}
void Player::move(int number, int Pieceindex)
{
	//initPos[Pieceindex]
	if (this->getpiecesonBoard() > 0)
	{
		cout << "\n Do you want to move : (Y) / (N) : ";
		char choice;
		cin >> choice;
		
	}
}
vector<int>Player::getPositions()
{
	return this->initPos;
}