#include <SFML/Graphics.hpp>
#include <iostream>


int main()
{
	//creates window for the game 
	sf::RenderWindow window(sf::VideoMode(800,400), "Pong Game", sf::Style::Titlebar | sf::Style::Close);

	//create our rectangle for the game
	sf::RectangleShape p1(sf::Vector2f(25.0f,75.0f));
	p1.setPosition(30.f,163.5f);

	bool c_move = false;


	while (window.isOpen())
	{
		//event is for if the the close button is pressed, it will close the game
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type) 
			{
				case sf::Event::Closed:
					window.close();
					break;
			}
		}

		if (p1.getPosition().y != 0&&p1.getPosition().y + p1.getLocalBounds().height != window.getSize().y )
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				p1.move(0.f,-0.5f);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				p1.move(0.f,.5f);
			}
		}
		else if (p1.getPosition().y == 0){
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				p1.move(0.f,.5f);
			}
		}
		else if (p1.getPosition().y + p1.getLocalBounds().height == window.getSize().y){
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				p1.move(0.f,-0.5f);
			}
		}

		window.clear();
		window.draw(p1);
		window.display();

	}
}
