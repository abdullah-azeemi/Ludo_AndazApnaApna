#include "Dice.h"
#include<vector>
vector<int> Dice::rollDice()
{
	srand(time(0));
	int rolls = 1; vector<int> rollsS;
	int number;
	number = (rand() % 6)+1;
	rollsS.push_back(number);
	if (number == 6)
	{
		number = (rand() % 6) + 1;
		rolls++;
		rollsS.push_back(number);
		if(number != 6)
		{
			number = (rand() % 6) + 1;
			rollsS.push_back(number);
		}
		else
		{
			rollsS.empty();
		}
	}
	return rollsS;
}
