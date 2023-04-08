#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"header.h"
using namespace std;

class Player
{
private:
	string Name;
	Color C;
	int start_Pos;
	int end_Pos;
	int diceWin_Pos;
	char* Sym;
		
protected :
	int piecesAthome;
	int piecesAtJail;
	int piecesonBoard;
	vector<int> initPos;

public:
	Player(string _Name, Color _C, int _start_Pos, int _end_Pos, int _diceWin_Pos, char* _sym, vector<int> _initPos);
	string getName();
	Color getColor();
	int get_StartPos();
	int get_EndPos();
	int get_diceWin_Pos();
	char* getSymbols();



};

