#pragma once
#include<SFML/Graphics.hpp>

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
	window.display();  // display() will show image on screen

}
static int returnIndexforBoard(int ci, int ri)
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

	else if ((ci >= 595 && ci <= 640) && (ri >= 385 && ri <= 430))
		return 6;
	else if ((ci >= 554 && ci <= 589) && (ri >= 385 && ri <= 430))
		return 7;
	else if ((ci >= 513 && ci <= 548) && (ri >= 385 && ri <= 430))
		return 8;
	else if ((ci >= 472 && ci <= 507) && (ri >= 385 && ri <= 430))
		return 9;
	else if ((ci >= 431 && ci <= 466) && (ri >= 385 && ri <= 430))
		return 10;
	else if ((ci >= 390 && ci <= 425) && (ri >= 385 && ri <= 430))
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


	else if ((ci >= 730 && ci <= 775) && (ri >= 40 && ri <= 75))
		return 26;
	else if ((ci >= 730 && ci <= 775) && (ri >= 81 && ri <= 116))
		return 27;
	else if ((ci >= 730 && ci <= 775) && (ri >= 122 && ri <= 157))
		return 28;
	else if ((ci >= 730 && ci <= 775) && (ri >= 165 && ri <= 200))
		return 29;
	else if ((ci >= 730 && ci <= 775) && (ri >= 208 && ri <= 243))
		return 30;
	else if ((ci >= 730 && ci <= 775) && (ri >= 249 && ri <= 285))
		return 31;


	else if ((ci >= 999 && ci <= 1038) && (ri >= 385 && ri <= 430))
		return 32;
	else if ((ci >= 955 && ci <= 993) && (ri >= 385 && ri <= 430))
		return 33;
	else if ((ci >= 913 && ci <= 948) && (ri >= 385 && ri <= 430))
		return 34;
	else if ((ci >= 866 && ci <= 905) && (ri >= 385 && ri <= 430))
		return 35;
	else if ((ci >= 820 && ci <= 862) && (ri >= 385 && ri <= 430))
		return 36;
	else if ((ci >= 775 && ci <= 816) && (ri >= 385 && ri <= 430))
		return 37;

	else if ((ci >= 999 && ci <= 1038) && (ri >= 385 && ri <= 430))
		return 39;
	else if ((ci >= 955 && ci <= 993) && (ri >= 385 && ri <= 430))
		return 40;
	else if ((ci >= 913 && ci <= 948) && (ri >= 385 && ri <= 430))
		return 41;
	else if ((ci >= 866 && ci <= 905) && (ri >= 385 && ri <= 430))
		return 42;
	else if ((ci >= 820 && ci <= 862) && (ri >= 385 && ri <= 430))
		return 43;
	else if ((ci >= 775 && ci <= 816) && (ri >= 385 && ri <= 430))
		return 44;

	else if ((ci >= 730 && ci <= 775) && (ri >= 645 && ri <= 677))
		return 45;
	else if ((ci >= 730 && ci <= 775) && (ri >= 602 && ri <= 637))
		return 46;
	else if ((ci >= 730 && ci <= 775) && (ri >= 562 && ri <= 597))
		return 47;
	else if ((ci >= 730 && ci <= 775) && (ri >= 521 && ri <= 556))
		return 48;
	else if ((ci >= 730 && ci <= 775) && (ri >= 480 && ri <= 515))
		return 49;
	else if ((ci >= 730 && ci <= 775) && (ri >= 439 && ri <= 474))
		return 50;

}