#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/OpenGL.hpp>
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
	int column = 0, row = 0;
	sf::Texture temp;
	if (!temp.loadFromFile("board-6.png"))  //  img ==> file name for image
	{
		throw("Unable to load img");
	}

	//sf::Sprite s(temp);
	sf::Sprite s;
	s.setTexture(temp);
	s.setScale(0.105,0.105); //  (width and heigth of image to be printed)

	s.setPosition(column, row); // position of image
	window.draw(s);	// draw() will only draw image on backend, image will not display on screen
	//window.display();  // display() will show image on screen

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

	else 
		return 100;

}

static void printYellow(sf::RenderWindow& window, int ri, int ci, vector<sf::Sprite> & yellow)
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
	yellow.push_back(s);
}
static void printRed(sf::RenderWindow& window, int ri, int ci, vector<sf::Sprite> & red)
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

	red.push_back(s);
	// display() will show image on screen
}
static void printGreen(sf::RenderWindow& window, int ri, int ci, vector<sf::Sprite> & green)
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
	green.push_back(s);
}
static void printBlue(sf::RenderWindow& window, int ri, int ci, vector<sf::Sprite> &blue)
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
	blue.push_back(s);
}
static void printMagenda(sf::RenderWindow& window, int ri, int ci, vector<sf::Sprite>& magenda)
{
	sf::Texture temp;
	if (!temp.loadFromFile("Pmagenda.png"))  //  img ==> file name for image
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
	magenda.push_back(s);
}
static void printGray(sf::RenderWindow& window, int ri, int ci, vector<sf::Sprite>& gray)
{
	sf::Texture temp;
	if (!temp.loadFromFile("Pgreyy.png"))  //  img ==> file name for image
	{
		throw("Unable to load img");
	}

	//sf::Sprite s(temp);
	sf::Sprite s;
	s.setTexture(temp);
	s.setScale(0.12, 0.12); //  (width and heigth of image to be printed)

	s.setPosition(ci, ri); // position of image
	window.draw(s);	// draw() will only draw image on backend, image will not display on screen
	// display() will show image on screen
	gray.push_back(s);
}

static void printDice1(sf::RenderWindow& window, int ri, int ci, vector<sf::Sprite> & dice)
{
	sf::Texture temp;
	if (!temp.loadFromFile("diceRoll1.png"))  //  img ==> file name for image
	{
		throw("Unable to load img");
	}

	//sf::Sprite s(temp);
	sf::Sprite s;
	s.setTexture(temp);
	s.setScale(0.25, 0.25); //  (width and heigth of image to be printed)

	s.setPosition(ci, ri); // position of image
	window.draw(s);	// draw() will only draw image on backend, image will not display on screen
	// display() will show image on screen
	dice.push_back(s);
	
}
static void printDice2(sf::RenderWindow& window, int ri, int ci, vector<sf::Sprite> & dice)
{
	sf::Texture temp;
	if (!temp.loadFromFile("diceRoll2.png"))  //  img ==> file name for image
	{
		throw("Unable to load img");
	}

	//sf::Sprite s(temp);
	sf::Sprite s;
	s.setTexture(temp);
	s.setScale(0.25, 0.25); //  (width and heigth of image to be printed)

	s.setPosition(ci, ri); // position of image
	window.draw(s);	// draw() will only draw image on backend, image will not display on screen
	// display() will show image on screen
	dice.push_back(s);

}
static void printDice3(sf::RenderWindow& window, int ri, int ci, vector<sf::Sprite> & dice)
{
	sf::Texture temp;
	if (!temp.loadFromFile("diceRoll3.png"))  //  img ==> file name for image
	{
		throw("Unable to load img");
	}

	//sf::Sprite s(temp);
	sf::Sprite s;
	s.setTexture(temp);
	s.setScale(0.25, 0.25); //  (width and heigth of image to be printed)

	s.setPosition(ci, ri); // position of image
	window.draw(s);	// draw() will only draw image on backend, image will not display on screen
	// display() will show image on screen
	dice.push_back(s);

}
static void printDice4(sf::RenderWindow& window, int ri, int ci, vector<sf::Sprite> & dice)
{
	sf::Texture temp;
	if (!temp.loadFromFile("diceRoll4.png"))  //  img ==> file name for image
	{
		throw("Unable to load img");
	}

	//sf::Sprite s(temp);
	sf::Sprite s;
	s.setTexture(temp);
	s.setScale(0.25, 0.25); //  (width and heigth of image to be printed)

	s.setPosition(ci, ri); // position of image
	window.draw(s);	// draw() will only draw image on backend, image will not display on screen
	// display() will show image on screen
	dice.push_back(s);

}
static void printDice5(sf::RenderWindow& window, int ri, int ci, vector<sf::Sprite> & dice)
{
	sf::Texture temp;
	if (!temp.loadFromFile("diceRoll5.png"))  //  img ==> file name for image
	{
		throw("Unable to load img");
	}

	//sf::Sprite s(temp);
	sf::Sprite s;
	s.setTexture(temp);
	s.setScale(0.25, 0.25); //  (width and heigth of image to be printed)

	s.setPosition(ci, ri); // position of image
	window.draw(s);	// draw() will only draw image on backend, image will not display on screen
	// display() will show image on screen
	dice.push_back(s);

}
static void printDice6(sf::RenderWindow& window, int ri, int ci, vector<sf::Sprite> & dice)
{
	sf::Texture temp;
	if (!temp.loadFromFile("diceRoll6.png"))  //  img ==> file name for image
	{
		throw("Unable to load img");
	}

	//sf::Sprite s(temp);
	sf::Sprite s;
	s.setTexture(temp);
	s.setScale(0.25, 0.25); //  (width and heigth of image to be printed)

	s.setPosition(ci, ri); // position of image
	window.draw(s);	// draw() will only draw image on backend, image will not display on screen
	// display() will show image on screen
	dice.push_back(s);

}
static void returnLocforBoard(int number, int& ri, int& ci, int Nop)
{

	if (Nop < 5)
	{
		/// These are the inityal hardcorded location for pieces in their homes 
					// It will be different for each piece

		vector<int> Redri = { 513,513,589,589 };
		vector<int> Redci = { 439,519,519,439 };

		vector<int> Greenri = { 120, 195, 195, 123 };
		vector<int> Greenci = { 437, 436, 517, 519 };

		vector<int> Yellowri = { 117,195,195,117 };
		vector<int> Yellowci = { 840,840,925,925 };

		vector<int> Blueri = { 512, 512, 590, 590 };
		vector<int> Blueci = { 842, 920, 842, 920 };

		// Intail pieces initialization ends here

		vector<int> all_Ri_Locations = { 660,614,573,526,485,441,  387,387,387,387,387,387, 345,
										   300,300,300,300,300 ,300,250,215,170,125,80 ,30,30    , 35, 75,120,165,210,
											 255,300,300,300,300,300,300,345,390,390,390,390,390 ,390,432,477,522,567,612,657,657 };
		vector<int> all_Ci_Locations = { 645,645,645,645,645,645,  600,555,510,465,420,375,  378,378,
										   423,468,513,558, 603, 645,645,645,645,645,645,  690, 735,  735,735,735,735,735,
											780,825,870,915,960,1005,1005,1005,960,915,870,825, 780 ,735,735,735,735,735,735,690,667 };


		vector<int> homeGreen_ri = { 347 , 347 , 347 , 347 , 347 };
		vector<int> homeGreen_ci = { 435 , 480, 515 , 560 , 605 };

		vector<int> homeRed_ri = { 620 , 575 , 520 , 485 , 440 };
		vector<int> homeRed_ci = { 690 , 690 , 690 , 690 , 690 };

		vector<int> homeYellow_ri = { 82 , 125 , 173 , 212 , 263 };
		vector<int> homeYellow_ci = { 695 , 695 , 695 , 695 , 695 };

		vector<int> homeBlue_ri = { 350 , 350 , 350 , 350 , 350 };
		vector<int> homeBlue_ci = { 964 , 916 , 874 ,829, 783 };

		if (number <= -1 && number >= -4)
		{
			ri = Redri[abs(number) - 1];
			ci = Redci[abs(number) - 1];
		}
		else if (number <= -11 && number >= -14)
		{
			int x = abs(number) % 10 - 1;
			ri = Greenri[(abs(number) / 10) - 1 + x];
			ci = Greenci[(abs(number) / 10) - 1 + x];
		}
		else if (number <= -21 && number >= -24)
		{
			int x = abs(number) % 20 - 1;
			ri = Yellowri[(abs(number) / 20) - 1 + x];
			ci = Yellowci[(abs(number) / 20) - 1 + x];
		}
		else if (number <= -31 && number >= -34)
		{
			int x = abs(number) % 30 - 1;
			ri = Blueri[(abs(number) / 30) - 1 + x];
			ci = Blueci[(abs(number) / 30) - 1 + x];
		}
		else if (number >= 101 && number <= 105)
		{
			int x = abs(number) % 100 - 1;
			ri = homeRed_ri[(abs(number) / 100) - 1 + x];
			ci = homeRed_ci[(abs(number) / 100) - 1 + x];
		}
		else if (number >= 201 && number <= 206)
		{
			int x = abs(number) % 200 - 1;
			ri = homeGreen_ri[(abs(number) / 200) - 1 + x];
			ci = homeGreen_ci[(abs(number) / 200) - 1 + x];
		}
		else if (number >= 301 && number <= 306)
		{
			int x = abs(number) % 300 - 1;
			ri = homeYellow_ri[(abs(number) / 300) - 1 + x];
			ci = homeYellow_ci[(abs(number) / 300) - 1 + x];
		}
		else if (number >= 401 && number <= 406)
		{
			int x = abs(number) % 400 - 1;
			ri = homeBlue_ri[(abs(number) / 400) - 1 + x];
			ci = homeBlue_ci[(abs(number) / 400) - 1 + x];
		}
		else
		{
			ri = all_Ri_Locations[number];
			ci = all_Ci_Locations[number];
		}

	}
	else if (Nop == 6)
	{
		vector<int> Red_home_ri = {539,600,583,521};
		vector<int> Red_home_ci = {525,510,444,460};

		vector<int> Magenda_home_ri = {589,607,525,542};
		vector<int> Magenda_home_ci = {270,208,255,190};

		vector<int> Blue_home_ri = {335,383,335,290};
		vector<int> Blue_home_ci = {142,95,49,95};

		vector<int> Green_home_ri = {151,134,71,87};
		vector<int> Green_home_ci = {252,189,204,270};

		vector<int> Yellow_home_ri = {88,150,134,70};
		vector<int> Yellow_home_ci = {450,466,530,513};

		vector<int> LightGrey_home_ri = {338,291,337,383};
		vector<int> LightGrey_home_ci = {576,622,668,622};


		vector<int> board_Positions_ri = {508,491,480,462,445,428,  464,499,532,566,596,633,   632,632,595,563,531,499,   464,425,444,460,480,498,   508,480,454,435,418,405,
			                              388,371,296,281,266,251,  230,215,186,156,178,171,   189,202,226,235,203,170,136,   102,68,39,35,35,68,        105,135,168,201,242,
			                              220,200,185,170,160,183,   213,232,250,265,280,295,   369,388,403,420,440,450,482};
		vector<int> board_Positions_ci = {600,563,537,511,482,453,  387,387,387,387,387,387,   355,322,322,322,322,322,   322,258,232,200,171,142,   120,98,83,110,137,165,
			                              194,223,225,196,170,140,  113, 85,96,112,130,140,    165,200,227,255,322,322,322,   322,322,322,366,387,387,   387,387,387,387,452,
			                              475,510,538,565,595,610,   629,605,575,540,515,487,   480,517,545,565,595,630,615};


		vector<int> red_des_ri = {466,451,433,417,402};
		vector<int> red_des_ci = {600,573,542,513,485};

		vector<int> magenda_des_ri = {600,568,532,501,464};
		vector<int> magenda_des_ci = {370,370,370,370,370};

		vector<int> blue_des_ri = {463,450,434,419,401};
		vector<int> blue_des_ci = {142,169,201,230,258};

		vector<int> green_des_ri = {200,217,238,252,270};
		vector<int> green_des_ci = {143,170,199,227,256};

		vector<int> yellow_des_ri = {70,104,136,169,203};
		vector<int> yellow_des_ci = {375,375,375,375,375};


		vector<int> lightGrey_des_ri = {201,219,234,249,267};
		vector<int> lightGrey_des_ci = {601,573,540,519,486};
		if (number <= -1 && number >= -4)
		{
			if (number == -1)
			{
				ri = Red_home_ri[0];
				ci = Red_home_ci[0];
			}
			else if (number == -2)
			{
				ri = Red_home_ri[1];
				ci = Red_home_ci[1];
			}
			else if (number == -3)
			{
				ri = Red_home_ri[2];
				ci = Red_home_ci[2];
			}
			else if (number == -4)
			{
				ri = Red_home_ri[3];
				ci = Red_home_ci[3];
			}	
		}
		else if (number <= -11 && number >= -14)
		{
		    if (number == -11)
			{
				ri = Magenda_home_ri[0];
				ci = Magenda_home_ci[0];
			}
			else if (number == -12)
			{
				ri = Magenda_home_ri[1];
				ci = Magenda_home_ci[1];
			}
			else if (number == -13)
			{
				ri = Magenda_home_ri[2];
				ci = Magenda_home_ci[2];
			}
			else if (number == -14)
			{
				ri = Magenda_home_ri[3];
				ci = Magenda_home_ci[3];
			}
		}
		else if (number <= -21 && number >= -24)
		{
			if (number == -21)
			{
				ri = Blue_home_ri[0];
				ci = Blue_home_ci[0];
			}
			else if (number == -22)
			{
				ri = Blue_home_ri[1];
				ci = Blue_home_ci[1];
			}
			else if (number == -23)
			{
				ri = Blue_home_ri[2];
				ci = Blue_home_ci[2];
			}
			else if (number == -24)
			{
				ri = Blue_home_ri[3];
				ci = Blue_home_ci[3];
			}

		}

		else if (number <= -31 && number >= -34)
		{
			if (number == -31)
			{
				ri = Green_home_ri[0];
				ci = Green_home_ci[0];
			}
			else if (number == -32)
			{
				ri = Green_home_ri[1];
				ci = Green_home_ci[1];
			}
			else if (number == -33)
			{
				ri = Green_home_ri[2];
				ci = Green_home_ci[2];
			}
			else if (number == -34)
			{
				ri = Green_home_ri[3];
				ci = Green_home_ci[3];
			}
		}
		else if (number <= -41 && number >= -44)
		{
			if (number == -41)
			{
				ri = Yellow_home_ri[0];
				ci = Yellow_home_ci[0];
			}
			else if (number == -42)
			{
				ri = Yellow_home_ri[1];
				ci = Yellow_home_ci[1];
			}
			else if (number == -43)
			{
				ri = Yellow_home_ri[2];
				ci = Yellow_home_ci[2];
			}
			else if (number == -44)
			{
				ri = Yellow_home_ri[3];
				ci = Yellow_home_ci[3];
			}
		}
		else if (number <= -51 && number >= -54)
		{
			if (number == -51)
			{
				ri = LightGrey_home_ri[0];
				ci = LightGrey_home_ci[0];
			}
			else if (number == -52)
			{
				ri = LightGrey_home_ri[1];
				ci = LightGrey_home_ci[1];
			}
			else if (number == -53)
			{
				ri = LightGrey_home_ri[2];
				ci = LightGrey_home_ci[2];
			}
			else if (number == -54)
			{
				ri = LightGrey_home_ri[3];
				ci = LightGrey_home_ci[3];
			}

		}

		else if (number >= 101 && number <= 105)
		{
			if (number == 101)
			{
				ri = red_des_ri[0];
				ci = red_des_ci[0];
			}
			else if (number == 102)
			{
				ri = red_des_ri[1];
				ci = red_des_ci[1];
			}
			else if (number == 103)
			{
				ri = red_des_ri[2];
				ci = red_des_ci[2];
			}
			else if (number == 104)
			{
				ri = red_des_ri[3];
				ci = red_des_ci[3];
			}
			else if (number == 105)
			{
				ri = red_des_ri[4];
				ci = red_des_ci[4];
			}
		}
		else if (number >= 201 && number <= 205)
		{
			if (number == 201)
			{
				ri = magenda_des_ri[0];
				ci = magenda_des_ci[0];
			}
			else if (number == 202)
			{
				ri = magenda_des_ri[1];
				ci = magenda_des_ci[1];
			}
			else if (number == 203)
			{
				ri = magenda_des_ri[2];
				ci = magenda_des_ci[2];
			}
			else if (number == 204)
			{
				ri = magenda_des_ri[3];
				ci = magenda_des_ci[3];
			}
			else if (number == 205)
			{
				ri = magenda_des_ri[4];
				ci = magenda_des_ci[4];
			}
			}
		else if (number >= 301 && number <= 305)
		{
			if (number == 301)
			{
				ri = blue_des_ri[0];
				ci = blue_des_ci[0];
			}
			else if (number == 302)
			{
				ri = blue_des_ri[1];
				ci = blue_des_ci[1];
			}
			else if (number == 303)
			{
				ri = blue_des_ri[2];
				ci = blue_des_ci[2];
			}
			else if (number == 304)
			{
				ri = blue_des_ri[3];
				ci = blue_des_ci[3];
			}
			else if (number == 305)
			{
				ri = blue_des_ri[4];
				ci = blue_des_ci[4];
			}
			}
		else if (number >= 401 && number <= 405)
		{
			if (number == 401)
			{
				ri = green_des_ri[0];
				ci = green_des_ci[0];
			}
			else if (number == 402)
			{
				ri = green_des_ri[1];
				ci = green_des_ci[1];
			}
			else if (number == 403)
			{
				ri = green_des_ri[2];
				ci = green_des_ci[2];
			}
			else if (number == 404)
			{
				ri = green_des_ri[3];
				ci = green_des_ci[3];
			}
			else if (number == 405)
			{
				ri = green_des_ri[4];
				ci = green_des_ci[4];
			}
		}
		else if (number >= 501 && number <= 505)
		{
			if (number == 501)
			{
				ri = yellow_des_ri[0];
				ci = yellow_des_ci[0];
			}
			else if (number == 502)
			{
				ri = yellow_des_ri[1];
				ci = yellow_des_ci[1];
			}
			else if (number == 503)
			{
				ri = yellow_des_ri[2];
				ci = yellow_des_ci[2];
			}
			else if (number == 504)
			{
				ri = yellow_des_ri[3];
				ci = yellow_des_ci[3];
			}
			else if (number == 505)
			{
				ri = yellow_des_ri[4];
				ci = yellow_des_ci[4];
			}
			}
		else if (number >= 601 && number <= 605)
		{
			if (number == 601)
			{
				ri = lightGrey_des_ri[0];
				ci = lightGrey_des_ci[0];
			}
			else if (number == 602)
			{
				ri = lightGrey_des_ri[1];
				ci = lightGrey_des_ci[1];
			}
			else if (number == 603)
			{
				ri = lightGrey_des_ri[2];
				ci = lightGrey_des_ci[2];
			}
			else if (number == 604)
			{
				ri = lightGrey_des_ri[3];
				ci = lightGrey_des_ci[3];
			}
			else if (number == 605)
			{
				ri = lightGrey_des_ri[4];
				ci = lightGrey_des_ci[4];
			}
			}
		else
		{
			ri = board_Positions_ri[number];
			ci = board_Positions_ci[number];
		}

	}
}

static void printAllPieces2(sf::RenderWindow& window, Player** Ps, vector<sf::Sprite>& red, vector<sf::Sprite>& yellow, vector<sf::Sprite>& blue, vector<sf::Sprite>& green, vector < sf::Sprite> & magenda, vector<sf::Sprite> & gray, int Nop)
{
	vector<int> redPos = Ps[0][0].getPositions();
	vector<int> magendaPos = Ps[1][0].getPositions();
	vector<int> bluePos = Ps[2][0].getPositions();
	vector<int> greenPos = Ps[3][0].getPositions();
	vector<int> yellowPos = Ps[4][0].getPositions();
	vector<int> greyPos = Ps[5][0].getPositions();

	for (int i = 0; i < 4; i++)
	{
		int ri = 0, ci = 0;
		returnLocforBoard(redPos[i], ri, ci,Nop);
		printRed(window, ri,ci,red);
	}
	for (int i = 0; i < 4; i++)
	{
		int ri = 0, ci = 0;
		returnLocforBoard(magendaPos[i], ri, ci,Nop);
		printMagenda(window, ri, ci,magenda);
	}
	for (int i = 0; i < 4; i++)
	{
		int ri = 0, ci = 0;
		returnLocforBoard(bluePos[i], ri, ci,Nop);
		printBlue(window, ri, ci,blue);
	}
	for (int i = 0; i < 4; i++)
	{
		int ri = 0, ci = 0;
		returnLocforBoard(greenPos[i], ri, ci,Nop);
		printGreen(window, ri, ci,green);
	}
	for (int i = 0; i < 4; i++)
	{
		int ri = 0, ci = 0;
		returnLocforBoard(yellowPos[i], ri, ci, Nop);
		printYellow(window, ri, ci, yellow);
	}
	for (int i = 0; i < 4; i++)
	{
		int ri = 0, ci = 0;
		returnLocforBoard(greyPos[i], ri, ci, Nop);
		printGray(window, ri, ci, gray);
	}
	
	window.display();
}

static void printAllPieces(sf::RenderWindow& window, Player** Ps, vector<sf::Sprite>& red, vector<sf::Sprite>& yellow, vector<sf::Sprite>& blue, vector<sf::Sprite>& green, int Nop)
{
	vector<int> redPos = Ps[0][0].getPositions();
	vector<int> greenPos = Ps[1][0].getPositions();
	vector<int> yellowPos = Ps[2][0].getPositions();
	vector<int> bluePos = Ps[3][0].getPositions();

	for (int i = 0; i < 4; i++)
	{
		int ri = 0, ci = 0;
		returnLocforBoard(redPos[i], ri, ci, Nop);
		printRed(window, ri, ci, red);
	}
	for (int i = 0; i < 4; i++)
	{
		int ri = 0, ci = 0;
		returnLocforBoard(greenPos[i], ri, ci, Nop);
		printGreen(window, ri, ci, green);
	}
	for (int i = 0; i < 4; i++)
	{
		int ri = 0, ci = 0;
		returnLocforBoard(yellowPos[i], ri, ci, Nop);
		printYellow(window, ri, ci, yellow);
	}
	for (int i = 0; i < 4; i++)
	{
		int ri = 0, ci = 0;
		returnLocforBoard(bluePos[i], ri, ci, Nop);
		printBlue(window, ri, ci, blue);
	}
	window.display();
}
static void printDice(sf::RenderWindow& window, Player** Ps, vector<int> diceRolled, vector<sf::Sprite> &dice, bool isDisplayed)
{
	vector<int> Dice_ri_Locations = {451, 45, 451};
	vector<int> Dice_ci_Locations = {78,167,202};
	for (int i = 0; i < diceRolled.size(); i++)
	{
		if (diceRolled[i] == 6)
		{
			int ri = 0, ci = 0;
			ri = Dice_ri_Locations[i];
			ci = Dice_ci_Locations[i];
			printDice6(window, ri, ci, dice);
		}
		else if (diceRolled[i] == 5)
		{
			int ri = 0, ci = 0;
			ri = Dice_ri_Locations[i];
			ci = Dice_ci_Locations[i];
			printDice5(window, ri, ci, dice);
		}
		else if (diceRolled[i] == 4)
		{
			int ri = 0, ci = 0;
			ri = Dice_ri_Locations[i];
			ci = Dice_ci_Locations[i];
			printDice4(window, ri, ci, dice);
		}
		else if (diceRolled[i] == 3)
		{
			int ri = 0, ci = 0;
			ri = Dice_ri_Locations[i];
			ci = Dice_ci_Locations[i];
			printDice3(window, ri, ci, dice);
		}
		else if (diceRolled[i] == 2)
		{
			int ri = 0, ci = 0;
			ri = Dice_ri_Locations[i];
			ci = Dice_ci_Locations[i];
			printDice2(window, ri, ci, dice);
		}
		else
		{
			int ri = 0, ci = 0;
			ri = Dice_ri_Locations[i];
			ci = Dice_ci_Locations[i];
			printDice1(window, ri, ci, dice);

		}
	}
	if (!isDisplayed)
	{
		window.display();
	}
}

