#include <SFML/Graphics.hpp>
#include <iostream>


int main()
{
	//creates window for the game 
	sf::RenderWindow window(sf::VideoMode(800,400), "Pong Game", sf::Style::Titlebar | sf::Style::Close);

	//create our rectangle for the game player 1
	sf::RectangleShape p1(sf::Vector2f(25.0f,75.0f));
	p1.setPosition(30.f,163.5f);

	//create our rectangle for the game player 2
	sf::RectangleShape p2(sf::Vector2f(25.0f,75.0f));
	p2.setPosition(740.f,163.5f);

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

		//checks if the p1 is colliding with any of the borders
		if (p1.getPosition().y != 0&&p1.getPosition().y + p1.getLocalBounds().height != window.getSize().y )
		{
			//when the 'W' key is pressed move up
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				p1.move(0.f,-0.5f);
			}
			//when the 'S' key is pressed move down
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				p1.move(0.f,.5f);
			}
		}
		//if the p1 is colliding with the top...
		else if (p1.getPosition().y == 0){
			//only allow it to move down
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				p1.move(0.f,.5f);
			}
		}
		//if the p1 is colliding with the bottom...
		else if (p1.getPosition().y + p1.getLocalBounds().height == window.getSize().y){
			//only allow it to move up
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				p1.move(0.f,-0.5f);
			}
		}

		if (p2.getPosition().y != 0&&p2.getPosition().y + p2.getLocalBounds().height != window.getSize().y )
		{
			//when the 'W' key is pressed move up
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
			{
				p2.move(0.f,-0.5f);
			}
			//when the 'S' key is pressed move down
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
			{
				p2.move(0.f,.5f);
			}
		}
		//if the p1 is colliding with the top...
		else if (p2.getPosition().y == 0){
			//only allow it to move down
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
			{
				p2.move(0.f,.5f);
			}
		}
		//if the p1 is colliding with the bottom...
		else if (p2.getPosition().y + p2.getLocalBounds().height == window.getSize().y){
			//only allow it to move up
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
			{
				p2.move(0.f,-0.5f);
			}
		}

		window.clear();
		window.draw(p1);
		window.draw(p2);
		window.display();

	}
}
