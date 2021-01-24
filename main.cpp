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

	//create score count
	sf::Text p1score;
	sf::Font p1text;
	if (!p1text.loadFromFile("C:\\Users\\amanp\\Downloads\\fff-forward\\FFFFORWA.ttf"))
		{
			std::cout<<"cannot load font" << std::endl;
		}
	p1score.setFont(p1text);
	p1score.setString("0");
	p1score.setPosition(325.f,20.0f);
	p1score.setCharacterSize(50);
	
	sf::Text p2score;
	p2score.setFont(p1text);
	p2score.setString("0");
	p2score.setCharacterSize(50);
	p2score.setPosition(450.f,20.0f);


	//create ball
	sf::CircleShape ball(12.5f);
	ball.setPosition(400.f,200.f);
	ball.setOrigin(ball.getRadius(),ball.getRadius());
	
	//create middle line 
	sf::RectangleShape midline(sf::Vector2f(10.f,1000000.f));
	midline.setOrigin(5.f,500000.f);
	midline.setPosition(400.f,200.f);

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
		
		//move our ball
//		ball.move(-.5f,-.5f);
		


		window.clear();
		window.draw(p1);
		window.draw(p1score);
		window.draw(p2score);
		window.draw(p2);
		window.draw(ball);
		window.draw(midline);
		window.display();
		
	}
}
