#pragma once
#include<vector>
#include<iostream>
#include"Header.h"
using namespace std;
class Dice
{
private:
	vector<int> diceRoll;

public:
	int rollDice();
	void diceRollSave(int & roller);
};

