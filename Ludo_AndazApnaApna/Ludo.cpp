#include "Ludo.h"
#include"Header.h"
#include"Dice.h"
#include"Player.h"
#include"Board.h"
#include"utility.h"


bool isSpriteHover(sf::FloatRect sprite, sf::Vector2f mp)
{
	if (sprite.contains(mp)) {
		return true;
	}
	return false;
}

Ludo::Ludo(int nop)
{ 
	//cout << "\n How many Players : ";
	//int x;
	//cin >> x;
	//this->Nop = x;

	if (nop == 4)
	{
		vector<int> initPositions1 = { 10,-2,-3,-4 };
		vector<int> initPositions2 = { 11,-12,-13,-14 };
		vector<int> initPositions3 = { 12,12,-23,-24 };
		vector<int> initPositions4 = { 14,-32,-33,-34 };
		/// Initializing all the players 

		char sym1[4] = { 'b1', 'b2', 'b3','b4' };
		this->Ps[0] = new Player("Player 1", Color(RED), 1, 9, 52, sym1, initPositions1, 0, 4, 0, 101);

		char sym2[4] = { 'r1', 'r2', 'r3','r4' };
		this->Ps[1] = new Player("Player 2", Color(GREEN), 14, 22, 12, sym1, initPositions2, 0, 4,0, 201);

		char sym3[4] = { 'y1', 'y2', 'y3','y4' };
		this->Ps[2] = new Player("Player 3", Color(YELLOW), 27, 35, 25, sym1, initPositions3, 0, 4, 0,301);

		char sym4[4] = { 'm1', 'm2', 'm3','m4' };
		this->Ps[3] = new Player("Player 4", Color(BLUE), 40, 48, 38, sym1, initPositions4, 0, 4, 0,401);

	}
	else if (nop == 6)
	{
		vector<int> initPositions1 = { -1,-2,-3,-4 };
		vector<int> initPositions2 = { -11,-12,-13,-14 };
		vector<int> initPositions3 = { -21,-22,-23,-24 };
		vector<int> initPositions4 = { -31,-32,-33,-34 };
		vector<int> initPositions5 = { -41,-42,-43,-44 };
		vector<int> initPositions6 = { -51,-52,-53,-54 };
		/// Initializing all the players 
		char sym1[4] = { 'b1', 'b2', 'b3','b4' };
		this->Ps[0] = new Player("Player 1", Color(RED), 1, 9, 78, sym1, initPositions1, 0, 4, 0,101);

		char sym2[4] = { 'r1', 'r2', 'r3','r4' };
		this->Ps[1] = new Player("Player 2", Color(MAGENTA), 14, 22, 12, sym1, initPositions2, 0, 4, 0,201);

		char sym3[4] = { 'y1', 'y2', 'y3','y4' };
		this->Ps[2] = new Player("Player 3", Color(BLUE), 27, 36, 25, sym1, initPositions3, 0, 4, 0,301);

		char sym4[4] = { 'm1', 'm2', 'm3','m4' };
		this->Ps[3] = new Player("Player 4", Color(GREEN), 41, 49, 39, sym1, initPositions4, 0, 4, 0,401);

		char sym5[4] = { 'g1', 'g2', 'g3','g4' };
		this->Ps[4] = new Player("Player 5", Color(YELLOW), 54, 62, 52, sym1, initPositions5, 0, 4, 0,501);

		char sym6[4] = { 'dg1', 'dg2', 'dg3','dg4' };
		this->Ps[5] = new Player("Player 6", Color(DARKGREY), 67, 75, 65, sym1, initPositions6, 0, 4, 0,601);

	}
	
	this->turn = 0;
	this->indexForMaxRolls = 0;
	this->hasDice_rolled = false;
	this->moved = false;
	this->hasDice_displayed = false;
	this->Nop = nop;
}
void Ludo::displayTurnMsg(Player* P1)
{
	cout << "\n\n " << P1->getName() << "'s Turn : ";
}
void Ludo::turnChange()
{
	this->turn = (turn + 1) % (Nop);
} 
void Ludo::Play()
{

	vector <sf::Sprite> dice;
	vector<int> saveC = { 1,12,14,25,27,38,40,52 };
	vector<int>saveC6 = {1,9,14,22,27,36,41,49,54,62,67,75 };

	int x = 0, y = 0, z;
	while (false)
	{
		indexForMaxRolls = 0;
		displayTurnMsg(Ps[turn]);

		do
		{
			cout << "\n Press Enter to roll Dice : ";
			cin >> y;

			//x = D->rollDice();
			cout << "\n The number is : " << x;
			indexForMaxRolls++;

			if (x == 6)
			{
				Ps[turn]->getOutofHome(turn, this->Nop);
				Ps[turn]->move(x, 0, turn);
				cout << "\n Count in Jail : " << Ps[turn]->getpiecesAtJail();
				cout << "\n Count on Board : " << Ps[turn]->getpiecesonBoard();
				cout << "\n Pieces location : " << Ps[turn]->getPos(0);
				cin >> y;
			}
		} while (x == 6 && indexForMaxRolls < 3);
		turnChange();
		cin >> z;
	}

	
	if (false)
	{
		vector <sf::Sprite> red;
		vector <sf::Sprite> blue;
		vector <sf::Sprite> green;
		vector <sf::Sprite> yellow;

		sf::RenderWindow window(sf::VideoMode(1440, 720), "Ludo Game", sf::Style::Close | sf::Style::Resize);
		
		turn = 0;
		int ri, ci;
		while (window.isOpen())
		{
			print6(window);
			//printAllPieces(window, this->Ps, red, yellow, blue, green);

			indexForMaxRolls = 0;


			sf::Event evnt;
			while (window.pollEvent(evnt))
			{
				cout << "\n Turn is : " << turn;

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
				//case sf::Event::MouseButtonReleased:
				//	//if (evnt.mouseButton.button == sf::Mouse::Left) {
				//	//	ri = evnt.mouseButton.y;
				//	//	ci = evnt.mouseButton.x;
				//	//	//cout << "\n row is : " << ri << " col is : " << ci;
				//	//	int x = returnIndexforBoardfor4Board(ci, ri);
				//	//	//cout << "\n Index is : " << x;
				//	//}
				//	do
				//	{
				//		displayTurnMsg(Ps[turn]);
				//		x = D->rollDice();
				//		cout << "\n The number is : " << x;
				//		indexForMaxRolls++;

				//		if (x == 6)
				//		{
				//			Ps[turn]->getOutofHome(turn, this->Nop);
				//			Ps[turn]->move(x, 0);
				//			cout << "\n Count in Jail : " << Ps[turn]->getpiecesAtJail();
				//			cout << "\n Count on Board : " << Ps[turn]->getpiecesonBoard();
				//			cout << "\n Pieces location : " << Ps[turn]->getPos(0);
				//			window.clear();
				//			printAllPieces(window, this->Ps);
				//		}
				//	} while (indexForMaxRolls < 3 || x == 6);
				//	break;

				case sf::Event::MouseButtonPressed:
					if (evnt.mouseButton.button == sf::Mouse::Left) {
						ri = evnt.mouseButton.y;
						ci = evnt.mouseButton.x;
						int index = returnIndexforBoardfor4Board(ci, ri);
						cout << "\n Index is : " << index;
						cout << "\n turn is : " << turn;
						//index = 1;
						this->Ps[turn]->move(index, 5, turn);
						printAllPieces(window, this->Ps, red, yellow, blue, green,Nop);
					}
					break;
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
				{
					
				}
				window.clear();
			}
			turnChange();

		}
		window.display();
	}

	if (0)
	{
		vector <sf::Sprite> red;
		vector <sf::Sprite> blue;
		vector <sf::Sprite> green;
		vector <sf::Sprite> yellow;
		if (true)
		{	
			sf::RenderWindow window(sf::VideoMode(1440, 720), "Ludo Game", sf::Style::Close | sf::Style::Resize);
			
			turn = 0;
			int ri, ci;

			sf::Sprite sprite;
			sf::Texture texture;
			if (!texture.loadFromFile("Dice1.png"))
			{
				cout << "button not loaded";
			}
			sprite.setTexture(texture);
			sprite.setScale(0.35, 0.35);
			
			sf::Vector2f mp;
			mp.x = sf::Mouse::getPosition(window).x;
			mp.y = sf::Mouse::getPosition(window).y;

			vector<sf::Sprite> gr;
			gr.push_back(sprite);

			int drn = 0;
			while (window.isOpen())
			{
				print4(window);
				printAllPieces(window, this->Ps, red, yellow, blue, green,Nop);
				indexForMaxRolls = 0;
				sf::Event evnt;
				while (window.pollEvent(evnt))
				{
					if (moved)
					{
						//turnChange();
						cout << "turn is " << turn;
						moved = false;
					}
					

					
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

					//case sf::Event::MouseButtonPressed:
					//	if (evnt.mouseButton.button == sf::Mouse::Left) {
					//		ri = evnt.mouseButton.y;
					//		ci = evnt.mouseButton.x;
					//		int index = returnIndexforBoardfor4Board(ci, ri);
					//		if (index != 100)
					//		{
					//			cout << "\n Index is : " << index;
					//			cout << "\n turn is : " << turn;
					//			//index = 1;
					//			this->Ps[turn]->move(index, 5, turn);
					//			printAllPieces(window, this->Ps, red, yellow, blue, green);
					//		}
					//	}
						break;
					}
					if (isSpriteHover(sprite.getGlobalBounds(), sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)) == true)
					{
						if (evnt.type == sf::Event::MouseButtonReleased && evnt.mouseButton.button == sf::Mouse::Left)
						{
							hasDice_displayed = false;
							cout << "\n Turn : " << turn << " Dice rolled : ";
							vector<int> x = D->rollDice();
							ostream_iterator <int>output(cout, ", ");
							copy(x.begin(), x.end(), output);
							printDice(window, this->Ps, x, dice, hasDice_displayed);
							//window.clear();
							//hasDice_displayed = true;
							hasDice_rolled = true;
							drn = getDiceSelection(window, dice,x);
							cout << "\nDice : " << drn;
						}
					}
					/*while (window.pollEvent(evnt))
					{
						if (evnt.type == sf::Event::Closed)
							window.close();

						if (isSpriteHover(sprite.getGlobalBounds(), sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)) == true)
						{
							if (evnt.type == sf::Event::MouseButtonReleased && evnt.mouseButton.button == sf::Mouse::Left)
							{
								cout << "\n The button Worked";
							}
						}

					}*/

					if (isSpriteHover(red[0].getGlobalBounds(), sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)) == true)
					{
						if (evnt.type == sf::Event::MouseButtonPressed && evnt.mouseButton.button == sf::Mouse::Left)
						{
							if (turn == 0)
							{
								cout << "\n Red 1 has been selected";
								cout << "\n loaction : "; vector<int> x = Ps[0]->getPositions();
								cout << x[0];
								this->Ps[turn]->move2(6, 0,red[0],Nop);
								moved = true;

								kill(Ps);
								break;
							}
						}
					}
					else if (isSpriteHover(red[1].getGlobalBounds(), sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)) == true)
					{
						if (evnt.type == sf::Event::MouseButtonPressed && evnt.mouseButton.button == sf::Mouse::Left)
						{
							if (turn == 0)
							{
								cout << "\n Red 2 has been selected";
								this->Ps[turn]->move2(6, 1, red[1],Nop);
								moved = true;
								kill(Ps);
								break;
							}
						}
					}
					else if (isSpriteHover(red[2].getGlobalBounds(), sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)) == true)
					{
						if (evnt.type == sf::Event::MouseButtonPressed && evnt.mouseButton.button == sf::Mouse::Left)
						{
							if (turn == 0)
							{
								cout << "\n Red 3 has been selected";
								this->Ps[turn]->move2(6, 2, red[2],Nop);
								moved = true;
								kill(Ps);
								break;
							}
						}
					}
					else if (isSpriteHover(red[3].getGlobalBounds(), sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)) == true)
					{
						if (evnt.type == sf::Event::MouseButtonPressed && evnt.mouseButton.button == sf::Mouse::Left)
						{
							if (turn == 0)
							{
								cout << "\n Red 4 has been selected";
								Ps[turn]->move2(6, 3, red[3],Nop);
								moved = true;
								kill(Ps);
								break;
							}
						}
					}

					else if (isSpriteHover(green[0].getGlobalBounds(), sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)) == true)
					{
						if (evnt.type == sf::Event::MouseButtonPressed && evnt.mouseButton.button == sf::Mouse::Left)
						{
							if (turn == 1)
							{
								cout << "\n green 1 has been selected";
								this->Ps[turn]->move2(6, 0, green[0],Nop);
								moved = true;
								kill(Ps);
								break;
							}
						}
					}
					else if (isSpriteHover(green[1].getGlobalBounds(), sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)) == true)
					{
						if (evnt.type == sf::Event::MouseButtonPressed && evnt.mouseButton.button == sf::Mouse::Left)
						{
							if (turn == 1)
							{
								cout << "\n green 2 has been selected";
								this->Ps[turn]->move2(6, 1, green[1],Nop);
								moved = true;
								kill(Ps);
								break;
							}
						}
					}
					else if (isSpriteHover(green[2].getGlobalBounds(), sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)) == true)
					{
						if (evnt.type == sf::Event::MouseButtonPressed && evnt.mouseButton.button == sf::Mouse::Left)
						{
							if (turn == 1)
							{
								cout << "\n green 3 has been selected";
								this->Ps[turn]->move2(6, 2, green[2],Nop);
								moved = true;
								kill(Ps);
								break;
							}
						}
					}
					else if (isSpriteHover(green[3].getGlobalBounds(), sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)) == true)
					{
						if (evnt.type == sf::Event::MouseButtonPressed && evnt.mouseButton.button == sf::Mouse::Left)
						{
							if (turn == 1)
							{
								cout << "\n green 4 has been selected";
								Ps[turn]->move2(6, 3, green[3],Nop);
								moved = true;
								kill(Ps);
								break;
							}
						}
					}

					else if (isSpriteHover(yellow[0].getGlobalBounds(), sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)) == true)
					{
						if (evnt.type == sf::Event::MouseButtonPressed && evnt.mouseButton.button == sf::Mouse::Left)
						{
							if (turn == 2)
							{
								cout << "\n yellow 1 has been selected";
								this->Ps[turn]->move2(6, 0, yellow[0],Nop);
								moved = true;
								kill(Ps);
								break;
							}
						}
						}
					else if (isSpriteHover(yellow[1].getGlobalBounds(), sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)) == true)
					{
						if (evnt.type == sf::Event::MouseButtonPressed && evnt.mouseButton.button == sf::Mouse::Left)
						{
							if (turn == 2)
							{
								cout << "\n yellow 2 has been selected";
								this->Ps[turn]->move2(6, 1, yellow[1],Nop);
								moved = true;
								kill(Ps);
								break;
							}
						}
						}
					else if (isSpriteHover(yellow[2].getGlobalBounds(), sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)) == true)
					{
						if (evnt.type == sf::Event::MouseButtonPressed && evnt.mouseButton.button == sf::Mouse::Left)
						{
							if (turn == 2)
							{
								cout << "\n green 3 has been selected";
								this->Ps[turn]->move2(6, 2, yellow[2],Nop);
								moved = true;
								kill(Ps);
								break;
							}
						}
					}
					else if (isSpriteHover(yellow[3].getGlobalBounds(), sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)) == true)
					{
						if (evnt.type == sf::Event::MouseButtonPressed && evnt.mouseButton.button == sf::Mouse::Left)
						{
							if (turn == 2)
							{
								cout << "\n yellow 4 has been selected";
								Ps[turn]->move2(6, 3, yellow[3],Nop);
								moved = true;
								kill(Ps);
								break;
							}
						}
					}


					else if (isSpriteHover(blue[0].getGlobalBounds(), sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)) == true)
					{
						if (evnt.type == sf::Event::MouseButtonPressed && evnt.mouseButton.button == sf::Mouse::Left)
						{
							if (turn == 3)
							{
								cout << "\n blue 1 has been selected";
								this->Ps[turn]->move2(6, 0, blue[0],Nop);
								moved = true;
								kill(Ps);
								break;
							}
						}
						}
					else if (isSpriteHover(blue[1].getGlobalBounds(), sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)) == true)
					{
						if (evnt.type == sf::Event::MouseButtonPressed && evnt.mouseButton.button == sf::Mouse::Left)
						{
							if (turn == 3)
							{
								cout << "\n blue 2 has been selected";
								this->Ps[turn]->move2(6, 1, blue[1],Nop);
								moved = true;
								kill(Ps);
								break;
							}
						}
					}
					else if (isSpriteHover(blue[2].getGlobalBounds(), sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)) == true)
					{
						if (evnt.type == sf::Event::MouseButtonPressed && evnt.mouseButton.button == sf::Mouse::Left)
						{
							if (turn == 3)
							{
								cout << "\n blue 3 has been selected";
								this->Ps[turn]->move2(6, 2, blue[2],Nop);
								moved = true;
								kill(Ps);
								break;
							}
						}
					}
					else if (isSpriteHover(blue[3].getGlobalBounds(), sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)) == true)
					{
						if (evnt.type == sf::Event::MouseButtonPressed && evnt.mouseButton.button == sf::Mouse::Left)
						{
							if (turn == 3)
							{
								cout << "\n blue 4 has been selected";
								Ps[turn]->move2(6, 3, blue[3],Nop);
								moved = true;
								kill(Ps);
								break;
							}
						}
					}
					
					
					window.clear(sf::Color::Black);
					sprite.setPosition(sf::Vector2f(50, 300));

					window.draw(sprite);

					//window.display();

				}
			}
		}
	}
	if (1)
	{
		vector <sf::Sprite> red;
		vector <sf::Sprite> blue;
		vector <sf::Sprite> green;
		vector <sf::Sprite> yellow;
		vector <sf::Sprite> grey;
		vector <sf::Sprite> magenda;
		if (true)
		{
			sf::RenderWindow window(sf::VideoMode(1440, 720), "Ludo Game", sf::Style::Close | sf::Style::Resize);

			turn = 0;
			int ri, ci;

			sf::Sprite sprite;
			sf::Texture texture;
			if (!texture.loadFromFile("Dice1.png"))
			{
				cout << "button not loaded";
			}
			sprite.setTexture(texture);
			sprite.setScale(0.35, 0.35);

			sf::Vector2f mp;
			mp.x = sf::Mouse::getPosition(window).x;
			mp.y = sf::Mouse::getPosition(window).y;

			vector<sf::Sprite> gr;
			gr.push_back(sprite);

			while (window.isOpen())
			{
				print6(window);
				printAllPieces2(window, this->Ps, red, yellow, blue, green,magenda, grey, Nop);
				indexForMaxRolls = 0;
				sf::Event evnt;

				while (window.pollEvent(evnt))
				{
					if (moved)
					{
						turnChange();
						cout << "turn is " << turn;
						moved = false;
					}

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

						//case sf::Event::MouseButtonPressed:
						//	if (evnt.mouseButton.button == sf::Mouse::Left) {
						//		ri = evnt.mouseButton.y;
						//		ci = evnt.mouseButton.x;
						//		int index = returnIndexforBoardfor4Board(ci, ri);
						//		if (index != 100)
						//		{
						//			cout << "\n Index is : " << index;
						//			cout << "\n turn is : " << turn;
						//			//index = 1;
						//			this->Ps[turn]->move(index, 5, turn);
						//			printAllPieces(window, this->Ps, red, yellow, blue, green);
						//		}
						//	}
						break;
					}
					if (isSpriteHover(sprite.getGlobalBounds(), sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)) == true)
					{
						if (evnt.type == sf::Event::MouseButtonReleased && evnt.mouseButton.button == sf::Mouse::Left)
						{
							hasDice_displayed = false;
							cout << "\n Turn : " << turn << " Dice rolled : ";
							vector<int> x = D->rollDice();
							ostream_iterator <int>output(cout, ", ");
							copy(x.begin(), x.end(), output);
							printDice(window, this->Ps, x, dice, hasDice_displayed);
							window.clear();
							//hasDice_displayed = true;
							hasDice_rolled = true;
						}
					}
					/*while (window.pollEvent(evnt))
					{
						if (evnt.type == sf::Event::Closed)
							window.close();

						if (isSpriteHover(sprite.getGlobalBounds(), sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)) == true)
						{
							if (evnt.type == sf::Event::MouseButtonReleased && evnt.mouseButton.button == sf::Mouse::Left)
							{
								cout << "\n The button Worked";
							}
						}

					}*/

					if (isSpriteHover(red[0].getGlobalBounds(), sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)) == true)
					{
						if (evnt.type == sf::Event::MouseButtonPressed && evnt.mouseButton.button == sf::Mouse::Left)
						{
							if (turn == 0)
							{
								cout << "\n Red 1 has been selected";
								cout << "\n loaction : "; vector<int> x = Ps[0]->getPositions();
								cout << x[0];
								this->Ps[turn]->move2(6, 0, red[0], Nop);
								moved = true;

								kill(Ps);
								break;
							}
						}
					}
					else if (isSpriteHover(red[1].getGlobalBounds(), sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)) == true)
					{
						if (evnt.type == sf::Event::MouseButtonPressed && evnt.mouseButton.button == sf::Mouse::Left)
						{
							if (turn == 0)
							{
								cout << "\n Red 2 has been selected";
								this->Ps[turn]->move2(6, 1, red[1], Nop);
								moved = true;
								break;
							}
						}
					}
					else if (isSpriteHover(red[2].getGlobalBounds(), sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)) == true)
					{
						if (evnt.type == sf::Event::MouseButtonPressed && evnt.mouseButton.button == sf::Mouse::Left)
						{
							if (turn == 0)
							{
								cout << "\n Red 3 has been selected";
								this->Ps[turn]->move2(6, 2, red[2], Nop);
								moved = true;
								break;
							}
						}
					}
					else if (isSpriteHover(red[3].getGlobalBounds(), sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)) == true)
					{
						if (evnt.type == sf::Event::MouseButtonPressed && evnt.mouseButton.button == sf::Mouse::Left)
						{
							if (turn == 0)
							{
								cout << "\n Red 4 has been selected";
								Ps[turn]->move2(1, 3, red[3], Nop);
								moved = true;
								break;
							}
						}
					}

					else if (isSpriteHover(magenda[0].getGlobalBounds(), sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)) == true)
					{
						if (evnt.type == sf::Event::MouseButtonPressed && evnt.mouseButton.button == sf::Mouse::Left)
						{
							if (turn == 1)
							{
								cout << "\n magenda 1 has been selected";
								this->Ps[turn]->move2(6, 0, magenda[0], Nop);
								moved = true;
								break;
							}
						}
					}
					else if (isSpriteHover(magenda[1].getGlobalBounds(), sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)) == true)
					{
						if (evnt.type == sf::Event::MouseButtonPressed && evnt.mouseButton.button == sf::Mouse::Left)
						{
							if (turn == 1)
							{
								cout << "\n magenda 2 has been selected";
								this->Ps[turn]->move2(6, 1, magenda[1], Nop);
								moved = true;
								break;
							}
						}
					}
					else if (isSpriteHover(magenda[2].getGlobalBounds(), sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)) == true)
					{
						if (evnt.type == sf::Event::MouseButtonPressed && evnt.mouseButton.button == sf::Mouse::Left)
						{
							if (turn == 1)
							{
								cout << "\n magenda 3 has been selected";
								this->Ps[turn]->move2(6, 2, magenda[2], Nop);
								moved = true;
								break;
							}
						}
					}
					else if (isSpriteHover(magenda[3].getGlobalBounds(), sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)) == true)
					{
						if (evnt.type == sf::Event::MouseButtonPressed && evnt.mouseButton.button == sf::Mouse::Left)
						{
							if (turn == 1)
							{
								cout << "\n magenda 4 has been selected";
								Ps[turn]->move2(6, 3, magenda[3], Nop);
								moved = true;
								break;
							}
						}
					}

					else if (isSpriteHover(blue[0].getGlobalBounds(), sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)) == true)
					{
						if (evnt.type == sf::Event::MouseButtonPressed && evnt.mouseButton.button == sf::Mouse::Left)
						{
							if (turn == 2)
							{
								cout << "\n blue 1 has been selected";
								this->Ps[turn]->move2(6, 0, blue[0], Nop);
								moved = true;
								break;
							}
						}
						}
					else if (isSpriteHover(blue[1].getGlobalBounds(), sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)) == true)
					{
						if (evnt.type == sf::Event::MouseButtonPressed && evnt.mouseButton.button == sf::Mouse::Left)
						{
							if (turn == 2)
							{
								cout << "\n blue 2 has been selected";
								this->Ps[turn]->move2(6, 1, blue[1], Nop);
								moved = true;
								break;
							}
						}
						}
					else if (isSpriteHover(blue[2].getGlobalBounds(), sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)) == true)
					{
						if (evnt.type == sf::Event::MouseButtonPressed && evnt.mouseButton.button == sf::Mouse::Left)
						{
							if (turn == 2)
							{
								cout << "\n blue 3 has been selected";
								this->Ps[turn]->move2(6, 2, blue[2], Nop);
								moved = true;
								break;
							}
						}
						}
					else if (isSpriteHover(blue[3].getGlobalBounds(), sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)) == true)
					{
						if (evnt.type == sf::Event::MouseButtonPressed && evnt.mouseButton.button == sf::Mouse::Left)
						{
							if (turn == 2)
							{
								cout << "\n blue 4 has been selected";
								Ps[turn]->move2(6, 3, blue[3], Nop);
								moved = true;
								break;
							}
						}
						}

					else if (isSpriteHover(green[0].getGlobalBounds(), sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)) == true)
					{
						if (evnt.type == sf::Event::MouseButtonPressed && evnt.mouseButton.button == sf::Mouse::Left)
						{
							if (turn == 3)
							{
								cout << "\n green 1 has been selected";
								this->Ps[turn]->move2(6, 0, green[0], Nop);
								moved = true;
								break;
							}
						}
					}
					else if (isSpriteHover(green[1].getGlobalBounds(), sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)) == true)
					{
						if (evnt.type == sf::Event::MouseButtonPressed && evnt.mouseButton.button == sf::Mouse::Left)
						{
							if (turn == 3)
							{
								cout << "\n green 2 has been selected";
								this->Ps[turn]->move2(6, 1, green[1], Nop);
								moved = true;
								break;
							}
						}
					}
					else if (isSpriteHover(green[2].getGlobalBounds(), sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)) == true)
					{
						if (evnt.type == sf::Event::MouseButtonPressed && evnt.mouseButton.button == sf::Mouse::Left)
						{
							if (turn == 3)
							{
								cout << "\n green 3 has been selected";
								this->Ps[turn]->move2(6, 2, green[2], Nop);
								moved = true;
								break;
							}
						}
					}
					else if (isSpriteHover(green[3].getGlobalBounds(), sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)) == true)
					{
						if (evnt.type == sf::Event::MouseButtonPressed && evnt.mouseButton.button == sf::Mouse::Left)
						{
							if (turn == 3)
							{
								cout << "\n green 4 has been selected";
								Ps[turn]->move2(6, 3, green[3], Nop);
								moved = true;
								break;
							}
						}
					}

					else if (isSpriteHover(yellow[0].getGlobalBounds(), sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)) == true)
					{
						if (evnt.type == sf::Event::MouseButtonPressed && evnt.mouseButton.button == sf::Mouse::Left)
						{
							if (turn == 4)
							{
								cout << "\n yellow 1 has been selected";
								this->Ps[turn]->move2(6, 0, yellow[0], Nop);
								moved = true;
								break;
							}
						}
					}
					else if (isSpriteHover(yellow[1].getGlobalBounds(), sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)) == true)
					{
						if (evnt.type == sf::Event::MouseButtonPressed && evnt.mouseButton.button == sf::Mouse::Left)
						{
							if (turn == 4)
							{
								cout << "\n yellow 2 has been selected";
								this->Ps[turn]->move2(6, 1, yellow[1], Nop);
								moved = true;
								break;
							}
						}
					}
					else if (isSpriteHover(yellow[2].getGlobalBounds(), sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)) == true)
					{
						if (evnt.type == sf::Event::MouseButtonPressed && evnt.mouseButton.button == sf::Mouse::Left)
						{
							if (turn == 4)
							{
								cout << "\n green 3 has been selected";
								this->Ps[turn]->move2(6, 2, yellow[2], Nop);
								moved = true;
								break;
							}
						}
					}
					else if (isSpriteHover(yellow[3].getGlobalBounds(), sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)) == true)
					{
						if (evnt.type == sf::Event::MouseButtonPressed && evnt.mouseButton.button == sf::Mouse::Left)
						{
							if (turn == 4)
							{
								cout << "\n yellow 4 has been selected";
								Ps[turn]->move2(6, 3, yellow[3], Nop);
								moved = true;
								break;
							}
						}
					}

					else if (isSpriteHover(grey[0].getGlobalBounds(), sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)) == true)
					{
						if (evnt.type == sf::Event::MouseButtonPressed && evnt.mouseButton.button == sf::Mouse::Left)
						{
							if (turn == 5)
							{
								cout << "\n grey 1 has been selected";
								this->Ps[turn]->move2(6, 0, grey[0], Nop);
								moved = true;
								break;
							}
						}
						}
					else if (isSpriteHover(grey[1].getGlobalBounds(), sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)) == true)
					{
						if (evnt.type == sf::Event::MouseButtonPressed && evnt.mouseButton.button == sf::Mouse::Left)
						{
							if (turn == 5)
							{
								cout << "\n grey 2 has been selected";
								this->Ps[turn]->move2(6, 1, grey[1], Nop);
								moved = true;
								break;
							}
						}
						}
					else if (isSpriteHover(grey[2].getGlobalBounds(), sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)) == true)
					{
						if (evnt.type == sf::Event::MouseButtonPressed && evnt.mouseButton.button == sf::Mouse::Left)
						{
							if (turn == 5)
							{
								cout << "\n grey 3 has been selected";
								this->Ps[turn]->move2(6, 2, grey[2], Nop);
								moved = true;
								break;
							}
						}
						}
					else if (isSpriteHover(grey[3].getGlobalBounds(), sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)) == true)
					{
						if (evnt.type == sf::Event::MouseButtonPressed && evnt.mouseButton.button == sf::Mouse::Left)
						{
							if (turn == 5)
							{
								cout << "\n grey 4 has been selected";
								Ps[turn]->move2(6, 3, grey[3], Nop);
								moved = true;
								break;
							}
						}
						}


					window.clear(sf::Color::Black);
					sprite.setPosition(sf::Vector2f(50, 300));

					window.draw(sprite);

					//window.display();

				}
			}
		}
	}

}
void Ludo::kill(Player* Ps[6])
{
	int index = turn;
	vector<int> saveC = { 1,10,14,22,27,35,40,52 };
	vector<int> positions1 = Ps[turn]->getPositions();

	bool isFound = false, saved = false;
	int ri = 0, rr = 0;

	int count;
	for (; ri < Nop && isFound == false; ri++)
	{
		saved = false;
		vector<int> positions2 = Ps[ri]->getPositions();
		if (ri != index)
		{
			count = 0;
			for (int r = 0; r < 4; r++)
			{
				if (positions1[r] == positions2[r])
				{
					for (int x = 0; x < positions1.size(); x++)
					{
						if (positions1[r] == positions2[x])
						{
							count++;
						}
					}
					
					int foundPos = positions1[r];
					
					for (int i = 0; i < saveC.size(); i++)
					{
						if (foundPos == saveC[i])
						{
							saved = true;
							break;
						}
					}
					if (!saved || count < 2)
					{
						isFound = true;
						rr = r;
						break;
					}
				}
				
			}
		}
	}
	if (!saved)
	{
		ri--;
		if (isFound && count < 2)
		{
			vector<int> pos;
			if (ri == 0)
			{
				pos = Ps[ri]->getPositions();
				int number;
				if (rr == 0) { number = -1; }
				else if (rr == 1) { number = -2; }
				else if (rr == 2) { number = -3; }
				else { number = -4; }
				pos[rr] = number;
			}
			else if (ri == 1)
			{
				pos = Ps[ri]->getPositions();
				int number;
				if (rr == 0) { number = -11; }
				else if (rr == 1) { number = -12; }
				else if (rr == 2) { number = -13; }
				else { number = -14; }
				pos[rr] = number;
			}
			else if (ri == 2)
			{
				pos = Ps[ri]->getPositions();
				int number;
				if (rr == 0) { number = -21; }
				else if (rr == 1) { number = -22; }
				else if (rr == 2) { number = -23; }
				else { number = -24; }
				pos[rr] = number;
			}
			else if (ri == 3)
			{
				pos = Ps[ri]->getPositions();
				int number;
				if (rr == 0) { number = -31; }
				else if (rr == 1) { number = -32; }
				else if (rr == 2) { number = -33; }
				else { number = -34; }
				pos[rr] = number;
			}
			Ps[ri]->update_the_Pos(pos);
		}
	}
}
int Ludo::getDiceSelection(sf::RenderWindow & window, std::vector<sf::Sprite> &dice, std::vector<int> & x)
{
	int number = 0;
	bool isPiece_selected = false;
	while (!isPiece_selected)
	{
		sf::Event evnt2;
		while (window.pollEvent(evnt2))
		{
			print4(window);
			
			if (isSpriteHover(dice[0].getGlobalBounds(), sf::Vector2f(evnt2.mouseButton.x, evnt2.mouseButton.y)) == true)
			{
				if (evnt2.type == sf::Event::MouseButtonReleased && evnt2.mouseButton.button == sf::Mouse::Left)
				{
					cout << "Dice 1 : Selected ";
					isPiece_selected = true;
					return x[0];

					break;
			    }
		    }
		}
	}
	dice.clear();
	return number;
}
