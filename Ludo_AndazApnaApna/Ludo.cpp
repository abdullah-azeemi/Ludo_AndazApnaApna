#include "Ludo.h"

Ludo::Ludo()
{
	char sym1[4] = { 'b1', 'b2', 'b3','b4' };
	this->Ps[0] = new Player("Player 1", Color (BLUE), 1, 9, 89, sym1);

	char sym2[4] = { 'r1', 'r2', 'r3','r4' };
	this->Ps[1] = new Player("Player 2", Color(RED), 14, 22, 12, sym1);

	char sym3[4] = { 'y1', 'y2', 'y3','y4' };
	this->Ps[2] = new Player("Player 3", Color(YELLOW), 37, 35, 25, sym1);

	char sym4[4] = { 'm1', 'm2', 'm3','m4' };
	this->Ps[3] = new Player("Player 4", Color(MAGENTA), 46,54,44, sym1);

	char sym5[4] = { 'g1', 'g2', 'g3','g4' };
	this->Ps[4] = new Player("Player 5", Color(GREEN), 59,67,57, sym1);

	char sym6[4] = { 'dg1', 'dg2', 'dg3','dg4' };
	this->Ps[5] = new Player("Abdullah", Color(DARKGREY), 72,80,70, sym1);




}