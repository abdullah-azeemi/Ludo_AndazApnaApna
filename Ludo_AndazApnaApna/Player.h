#pragma once
#include<iostream>
#include<string>
#include"Header.h"
using namespace std;

class Player
{
private:
	string Name;
	Color C;
	Pos start_Pos;
	Pos end_Pos;
	Pos diceWin_Pos;
	char* Sym;
	ki haaal ai thek ho na 
protected :
	int piecesAthome;
	int piecesAtJail;
	int piecesonBoard;

public:
	Player(string _Name, Color _C, Pos _start_Pos, Pos _end_Pos, Pos _diceWin_Pos, char* _sym);
	string getName();
	Color getColor();
	Pos get_StartPos();
	Pos get_EndPos();
	Pos get_diceWin_Pos();
	char* getSymbols();



};

