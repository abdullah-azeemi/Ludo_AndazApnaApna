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
	int Home_Pos;
	char* Sym;
		
protected :
	int piecesAthome;
	int piecesAtJail;
	int piecesonBoard;
	vector<int> initPos;  // initPos actually stores the Piece's location ,
                                   	//initialiy it will be -1 and ther will be 4 indiceis (0-3)
	bool isValidSource;
	

public:
	Player(string _Name, Color _C, int _start_Pos, int _end_Pos, int _diceWin_Pos, char* _sym, vector<int> _initPos, int piecesH, int piecesJ, int piecesB, int getHomePos);
	string getName();
	Color getColor();
	int get_StartPos();
	int get_EndPos();
	int get_diceWin_Pos();
	char* getSymbols();
	int getpiecesAtHome();
	int getpiecesAtJail();
	int getpiecesonBoard();
	int getHomePos();
	int getPos(int index);
	vector<int>getPositions();
	void getOutofHome(int turn, int nop);
	void move(int number, int diceRolled_number, int turn);

	void move2(int diceRolled_number, int index, sf::Sprite &s);

};

