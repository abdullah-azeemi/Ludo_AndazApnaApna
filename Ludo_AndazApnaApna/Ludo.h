#pragma once
#include"Header.h"
#include<vector>

class Player;
class Dice;
class Board;

class Ludo
{
private:
	Player* Ps[6];
	int turn;
	Dice *D;
	int Nop;
	int indexForMaxRolls;
	bool hasDice_rolled;
	bool moved;
	bool hasDice_displayed;

public:
	Ludo(int nop);
	void displayTurnMsg(Player* P1);
	void Play();
	void turnChange();
	void kill(Player* Ps[6]);
	int getDiceSelection(sf::RenderWindow & window, std::vector<sf::Sprite>& dice, std::vector<int> & x);
};

