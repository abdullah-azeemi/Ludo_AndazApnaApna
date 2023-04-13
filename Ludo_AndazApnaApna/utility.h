#pragma once
#include<SFML/Graphics.hpp>
#include"Player.h"

static void MouseClick(sf::RenderWindow& window, int& ri, int& ci)
{
	ri = -1;
	ci = -1;
	sf::Event event;
	while (window.waitEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			window.close();
			exit(0);
			break;
		case sf::Event::MouseButtonReleased:
			if (event.mouseButton.button == sf::Mouse::Left) {
				ci = event.mouseButton.y;
				ri = event.mouseButton.x;
			}
			break;
		default:
			break;
		}
	}
}
static void getRowColbyLeftClick(int& rpos, int& cpos, sf::RenderWindow& window)
{
	while (true)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i p = sf::Mouse::getPosition(window);

			cpos = p.x;
			rpos = p.y;
			break;
		}
	}
}
static void print6(sf::RenderWindow& window)
{
	int column = 300, row = 5;
	sf::Texture temp;
	if (!temp.loadFromFile("6board.png"))  //  img ==> file name for image
	{
		throw("Unable to load img");
	}

	//sf::Sprite s(temp);
	sf::Sprite s;
	s.setTexture(temp);
	s.setScale(1.5, 1.5); //  (width and heigth of image to be printed)

	s.setPosition(column, row); // position of image
	window.draw(s);	// draw() will only draw image on backend, image will not display on screen
	window.display();  // display() will show image on screen

}
static void print4(sf::RenderWindow& window)
{
	int column = 350, row = 5;
	sf::Texture temp;
	if (!temp.loadFromFile("4board.png"))  //  img ==> file name for image
	{
		throw("Unable to load img");
	}

	//sf::Sprite s(temp);
	sf::Sprite s;
	s.setTexture(temp);
	s.setScale(0.8, 0.8); //  (width and heigth of image to be printed)

	s.setPosition(column, row); // position of image
	window.draw(s);	// draw() will only draw image on backend, image will not display on screen
	//window.display();  // display() will show image on screen

}
static int returnIndexforBoardfor4Board(int ci, int ri)
{
	if ((ci >= 612 && ci <= 642) && (ri >= 645 && ri <= 677))
		return 0;
	else if ((ci >= 612 && ci <= 642) && (ri >= 602 && ri <= 637))
		return 1;
	else if ((ci >= 612 && ci <= 642) && (ri >= 562 && ri <= 597))
		return 2;
	else if ((ci >= 612 && ci <= 642) && (ri >= 521 && ri <= 556))
		return 3;
	else if ((ci >= 612 && ci <= 642) && (ri >= 480 && ri <= 515))
		return 4;
	else if ((ci >= 612 && ci <= 642) && (ri >= 439 && ri <= 474))
		return 5;

	else if ((ci >= 575 && ci <= 640) && (ri >= 385 && ri <= 430))
		return 6;
	else if ((ci >= 535 && ci <= 570) && (ri >= 385 && ri <= 430))
		return 7;
	else if ((ci >= 495 && ci <= 530) && (ri >= 385 && ri <= 430))
		return 8;
	else if ((ci >= 455 && ci <= 490) && (ri >= 385 && ri <= 430))
		return 9;
	else if ((ci >= 415 && ci <= 450) && (ri >= 385 && ri <= 430))
		return 10;
	else if ((ci >= 375 && ci <= 410) && (ri >= 385 && ri <= 430))
		return 11;
	else if ((ci >= 390 && ci <= 425) && (ri >= 285 && ri <= 330))
		return 13;
	else if ((ci >= 431 && ci <= 466) && (ri >= 285 && ri <= 330))
		return 14;
	else if ((ci >= 472 && ci <= 507) && (ri >= 285 && ri <= 330))
		return 15;
	else if ((ci >= 513 && ci <= 548) && (ri >= 285 && ri <= 330))
		return 16;
	else if ((ci >= 554 && ci <= 589) && (ri >= 285 && ri <= 330))
		return 17;
	else if ((ci >= 595 && ci <= 640) && (ri >= 285 && ri <= 330))
		return 18;

	else if ((ci >= 612 && ci <= 642) && (ri >= 249 && ri <= 285))
		return 19;
	else if ((ci >= 612 && ci <= 642) && (ri >= 208 && ri <= 243))
		return 20;
	else if ((ci >= 612 && ci <= 642) && (ri >= 165 && ri <= 200))
		return 21;
	else if ((ci >= 612 && ci <= 642) && (ri >= 122 && ri <= 157))
		return 22;
	else if ((ci >= 612 && ci <= 642) && (ri >= 81 && ri <= 116))
		return 23;
	else if ((ci >= 612 && ci <= 642) && (ri >= 40 && ri <= 75))
		return 24;

	else if ((ci >= 690 && ci <= 730) && (ri >= 40 && ri <= 75))
		return 26;
	else if ((ci >= 690 && ci <= 730) && (ri >= 81 && ri <= 116))
		return 27;
	else if ((ci >= 690 && ci <= 730) && (ri >= 122 && ri <= 157))
		return 28;
	else if ((ci >= 690 && ci <= 730) && (ri >= 165 && ri <= 200))
		return 29;
	else if ((ci >= 690 && ci <= 730) && (ri >= 208 && ri <= 243))
		return 30;
	else if ((ci >= 690 && ci <= 730) && (ri >= 249 && ri <= 285))
		return 31;


	else if ((ci >= 735 && ci <= 780) && (ri >= 290 && ri <= 340))
		return 32;
	else if ((ci >= 780 && ci <= 815) && (ri >= 290 && ri <= 340))
		return 33;
	else if ((ci >= 821 && ci <= 855) && (ri >= 290 && ri <= 340))
		return 34;
	else if ((ci >= 860 && ci <= 895) && (ri >= 290 && ri <= 340))
		return 35;
	else if ((ci >= 900 && ci <= 935) && (ri >= 290 && ri <= 340))
		return 36;
	else if ((ci >= 940 && ci <= 975) && (ri >= 290 && ri <= 340))
		return 37;

	else if ((ci >= 940 && ci <= 975) && (ri >= 385 && ri <= 430))
		return 39;
	else if ((ci >= 900 && ci <= 935) && (ri >= 385 && ri <= 430))
		return 40;
	else if ((ci >= 855 && ci <= 895) && (ri >= 385 && ri <= 430))
		return 41;
	else if ((ci >= 827 && ci <= 853) && (ri >= 385 && ri <= 430))
		return 42;
	else if ((ci >= 777 && ci <= 825) && (ri >= 385 && ri <= 430))
		return 43;
	else if ((ci >= 735 && ci <= 775) && (ri >= 385 && ri <= 430))
		return 44;

	else if ((ci >= 690 && ci <= 730) && (ri >= 645 && ri <= 677))
		return 50;
	else if ((ci >= 690 && ci <= 730) && (ri >= 602 && ri <= 637))
		return 49;
	else if ((ci >= 690 && ci <= 730) && (ri >= 562 && ri <= 597))
		return 48;
	else if ((ci >= 690 && ci <= 730) && (ri >= 521 && ri <= 556))
		return 47;
	else if ((ci >= 690 && ci <= 730) && (ri >= 480 && ri <= 515))
		return 46;
	else if ((ci >= 690 && ci <= 730) && (ri >= 439 && ri <= 474))
		return 45;

}


static void printYellow(sf::RenderWindow& window, int ri, int ci)
{
	sf::Texture temp;
	if (!temp.loadFromFile("Pyellow.png"))  //  img ==> file name for image
	{
		throw("Unable to load img");
	}

	//sf::Sprite s(temp);
	sf::Sprite s;
	s.setTexture(temp);
	s.setScale(0.05, 0.05); //  (width and heigth of image to be printed)

	s.setPosition(ci, ri); // position of image
	window.draw(s);	// draw() will only draw image on backend, image will not display on screen
	  // display() will show image on screen
}
static void printRed(sf::RenderWindow& window, int ri, int ci)
{
	sf::Texture temp;
	if (!temp.loadFromFile("Pred.png"))  //  img ==> file name for image
	{
		throw("Unable to load img");
	}

	//sf::Sprite s(temp);
	sf::Sprite s;
	s.setTexture(temp);
	s.setScale(0.1, 0.1); //  (width and heigth of image to be printed)

	s.setPosition(ci, ri); // position of image
	window.draw(s);	// draw() will only draw image on backend, image will not display on screen
	// display() will show image on screen
}
static void printGreen(sf::RenderWindow& window, int ri, int ci)
{
	sf::Texture temp;
	if (!temp.loadFromFile("Pgreen.png"))  //  img ==> file name for image
	{
		throw("Unable to load img");
	}

	//sf::Sprite s(temp);
	sf::Sprite s;
	s.setTexture(temp);
	s.setScale(0.1, 0.1); //  (width and heigth of image to be printed)

	s.setPosition(ci, ri); // position of image
	window.draw(s);	// draw() will only draw image on backend, image will not display on screen
	// display() will show image on screen
}
static void printBlue(sf::RenderWindow& window, int ri, int ci)
{
	sf::Texture temp;
	if (!temp.loadFromFile("Pblue.png"))  //  img ==> file name for image
	{
		throw("Unable to load img");
	}

	//sf::Sprite s(temp);
	sf::Sprite s;
	s.setTexture(temp);
	s.setScale(0.08, 0.08); //  (width and heigth of image to be printed)

	s.setPosition(ci, ri); // position of image
	window.draw(s);	// draw() will only draw image on backend, image will not display on screen
	// display() will show image on screen
}
static void returnLocforBoard(int number, int& ri, int& ci)
{
	/// These are the inityal hardcorded location for pieces in their homes 
				// It will be different for each piece
	//vector<int> Redri = { 290,513,287,589 };
	//vector<int> Redci = { 439,519,516,439 };

	vector<int> Redri = { 513,513,589,589 };
	vector<int> Redci = { 439,519,519,439 };

	vector<int> Greenri = { 120, 195, 195, 123 };
	vector<int> Greenci = { 437, 436, 517, 519 };

	vector<int> Yellowri = { 117,195,195,117 };
	vector<int> Yellowci = { 840,840,925,925 };

	vector<int> Blueri = { 512, 512, 590, 590 };
	vector<int> Blueci = { 842, 920, 842, 920 };

	// Intail pieces initialization ends here

	vector<int> all_Ri_Locations = {660,614,573,526,485,441,  387,387,387,387,387,387, 345,
		                               300,300,300,300,300,300,300  ,250,215,170,125,80,35  , 35,35, 75,105,165,210,
										 255,300,300,300,300,300,347,370,390,390,390,390,390,432,477,522,567,612,657,657};

	vector<int> all_Ci_Locations = {645,645,645,645,645,645,  600,555,510,465,420,375,  371,371,
		                               371,431,465,511,556,601, 645,645,645,645,645,645,  690, 735,  735,735,735,735,735,
	                                    780,825,870,915,960,1005,  980,960,915,870,825,780,735,735,735,735,735,735,735,667};

	if (number <= -1 && number >= -4)
	{
		ri = Redri[abs(number) - 1];
		ci = Redci[abs(number) - 1];
	}
	else if (number <= -11 && number >= -14)
	{
		int x = abs(number) % 10 -1;
		ri = Greenri[(abs(number)/10) - 1 + x];
		ci = Greenci[(abs(number)/10) - 1 + x];
	}
	else if (number <= -21 && number >= -24)
	{
		int x = abs(number) % 20 - 1;
		ri = Yellowri[(abs(number)/20) - 1 + x];
		ci = Yellowci[(abs(number)/20) - 1 + x];
	}
	else if (number <= -31 && number >= -34)
	{
		int x = abs(number) % 30 - 1;
		ri = Blueri[(abs(number)/30) - 1 + x];
		ci = Blueci[(abs(number)/30) - 1 + x];
	}
	else
	{
		ri = all_Ri_Locations[number];
		ci = all_Ci_Locations[number];
	}
}

static void printAllPieces(sf::RenderWindow& window, Player** Ps)
{
	vector<int> redPos = Ps[0][0].getPositions();
	vector<int> greenPos = Ps[1][0].getPositions();
	vector<int> yellowPos = Ps[2][0].getPositions();
	vector<int> bluePos = Ps[3][0].getPositions();

	for (int i = 0; i < 4; i++)
	{
		int ri = 0, ci = 0;
		returnLocforBoard(redPos[i], ri, ci);
		printRed(window, ri,ci);
	}
	for (int i = 0; i < 4; i++)
	{
		int ri = 0, ci = 0;
		returnLocforBoard(greenPos[i], ri, ci);
		printGreen(window, ri, ci);
	}
	for (int i = 0; i < 4; i++)
	{
		int ri = 0, ci = 0;
		returnLocforBoard(yellowPos[i], ri, ci);
		printYellow(window, ri, ci);
	}
	for (int i = 0; i < 4; i++)
	{
		int ri = 0, ci = 0;
		returnLocforBoard(bluePos[i], ri, ci);
		printBlue(window, ri, ci);
	}
	window.display();
}
