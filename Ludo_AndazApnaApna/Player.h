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
	vector<int> initPos;  // initPos actually stores the Piece's location ,
                                   	//initialiy it will be -1 and ther will be 4 indiceis (0-3)
	

public:
	static sf::Texture goti1;
	static sf::Texture goti2;
	static sf::Texture goti3;
	static sf::Texture goti4;
	static sf::Texture goti5;
	static sf::Texture goti6;

	Player(string _Name, Color _C, int _start_Pos, int _end_Pos, int _diceWin_Pos, char* _sym, vector<int> _initPos, int piecesH, int piecesJ, int piecesB);
	string getName();
	Color getColor();
	int get_StartPos();
	int get_EndPos();
	int get_diceWin_Pos();
	char* getSymbols();
	int getpiecesAtHome();
	int getpiecesAtJail();
	int getpiecesonBoard();
	int getPos(int index);

	void getOutofHome(int turn);
	void move(int number, int indexPiece);



};

