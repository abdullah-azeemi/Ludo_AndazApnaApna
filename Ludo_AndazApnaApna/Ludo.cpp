#include "Ludo.h"
#include"Header.h"
#include"Dice.h"
#include"Player.h"
#include"Board.h"
#include"utility.h"




Ludo::Ludo()
{ 

	vector<int> initPositions = { -1,-1,-1,-1 };
	/// Initializing all the players 
	char sym1[4] = { 'b1', 'b2', 'b3','b4' };
	this->Ps[0] = new Player("Player 1", Color (BLUE), 1, 9, 89, sym1, initPositions,0,4,0);

	char sym2[4] = { 'r1', 'r2', 'r3','r4' };
	this->Ps[1] = new Player("Player 2", Color(RED), 14, 22, 12, sym1, initPositions, 0, 4, 0);

	char sym3[4] = { 'y1', 'y2', 'y3','y4' };
	this->Ps[2] = new Player("Player 3", Color(YELLOW), 37, 35, 25, sym1, initPositions, 0, 4, 0);

	char sym4[4] = { 'm1', 'm2', 'm3','m4' };
	this->Ps[3] = new Player("Player 4", Color(MAGENTA), 46,54,44, sym1, initPositions, 0, 4, 0);

	char sym5[4] = { 'g1', 'g2', 'g3','g4' };
	this->Ps[4] = new Player("Player 5", Color(GREEN), 59,67,57, sym1, initPositions, 0, 4, 0);

	char sym6[4] = { 'dg1', 'dg2', 'dg3','dg4' };
	this->Ps[5] = new Player("Player 6", Color(DARKGREY), 72,80,70, sym1, initPositions, 0, 4, 0);

	this->Nop= 6;
	this->turn = 0;
	this->indexForMaxRolls = 0;
	
}
void Ludo::displayTurnMsg(Player* P1)
{
	cout << "\n\n " << P1->getName() << "'s Turn : ";
}
void Ludo::turnChange()
{
	this->turn = (turn + 1) % 6;
}
void Ludo::Play()
{
	int x = 0, y =0, z ;
	while (false)
	{
		indexForMaxRolls = 0;
		displayTurnMsg(Ps[turn]);

		do
		{
			cout << "\n Press Enter to roll Dice : ";
			cin >> y;

			x = D->rollDice();
			cout << "\n The number is : " << x;
			indexForMaxRolls++;

			if (x == 6)
			{
				Ps[turn]->getOutofHome(turn);
				Ps[turn]->move(x, 0);
				cout << "\n Count in Jail : " << Ps[turn]->getpiecesAtJail();
				cout << "\n Count on Board : " << Ps[turn]->getpiecesonBoard();
				cout << "\n Pieces location : " << Ps[turn]->getPos(0);
				cin >> y;
			}
		} while (x == 6 && indexForMaxRolls < 3);
		turnChange();
		cin >> z;
	}

	if (true)
	{

		sf::RenderWindow window(sf::VideoMode(1440,720), "Ludo Game", sf::Style::Close | sf::Style::Resize);
		//sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
		//player.setFillColor(sf::Color::Blue);
		//player.setOrigin(50.0f, 50.0f);
		//sf::Image img;
	
		int ri, ci;
		while (window.isOpen())
		{
			print4(window);
			sf::Event evnt;
			while (window.pollEvent(evnt))
			{
				//MouseClick(window, ri, ci);
				
				switch (evnt.type)
				{

				case sf::Event::Closed:
					window.close();
					break;

				case sf::Event::Resized:
					std::cout << "new window width  " << evnt.size.width << "  new window height  " << evnt.size.height << std::endl;
					break;

				case sf::Event::TextEntered:
					cout << " " << char(evnt.text.unicode);
					break;
				case sf::Event::MouseButtonReleased:
					if (evnt.mouseButton.button == sf::Mouse::Left) {
						ri = evnt.mouseButton.y;
						ci = evnt.mouseButton.x;
						//cout << "\n row is : " << ri << " col is : " << ci;
						int x = returnIndexforBoard(ci, ri);
						cout << "\n Index is : " << x;
					}
					break;

				}
			
			}

			/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
			{
				player.move(-0.1f, 0.0f);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
			{
				player.move(0.1f, 0.0f);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
			{
				player.move(0.0f, -0.1f);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
			{
				player.move(0.f, 0.1f);
			}*/
		/*	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				sf::Vector2i mousePos = sf::Mouse::getPosition(window);
				player.setPosition((float)mousePos.x, (float)(mousePos.y));
			}*/
			window.clear();
			//window.draw(player);
			//window.display();
			
		}
	}
}
void Ludo::loadAssests()
{
	//Player::goti1.loadFromFile("pieces/bluePiece.png");;
	//Player::goti2.loadFromFile();
	//Player::goti3.loadFromFile();
	//Player::goti4.loadFromFile();
	//Player::goti5.loadFromFile();
	//Player::goti6.loadFromFile();

}