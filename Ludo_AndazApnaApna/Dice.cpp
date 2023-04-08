#include "Dice.h"
#include<vector>
int Dice::rollDice()
{
	srand(time(0));
	int number;
	number = (rand() % 6)+1;
	return number;
}
void Dice::diceRollSave(int & roller)
{
	diceRoll.push_back(roller);
}