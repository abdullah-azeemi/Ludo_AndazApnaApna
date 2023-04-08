#include "Ludo.h"

Ludo::Ludo()
{
	Pos start1, end1, win1;
	start1.ri = 1, end1.ri = 9, win1.ri = 52;
	char* sym1 = new char[4];
	sym1[0] = 'b1'; sym1[1] = 'b2', sym1[2] = 'b3', sym1[3] = 'b4';
	this->Ps[0] = new Player("Abdullah", Color (BLUE), start1, end1, win1, sym1);
}