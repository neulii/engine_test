#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <point.h>

#include <iostream>

//kleine hilfsfunktion
int getSum(int a, int b);

int main()
{
	

	double d = 0;
	double fps = 0;

	sf::RectangleShape r(sf::Vector2f(50,30));
	sf::Clock clock;

	sf::RenderWindow window(sf::VideoMode(800,800),"MyGame");

	while (window.isOpen())
	{
		
		sf::Time elapsed = clock.restart();
	
		fps = 1.f/elapsed.asMicroseconds()*1000000;

//		std::cout << fps << std::endl;


		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			r.move(0.05,0);	
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			r.move(-0.05,0);
		}

		sf::Event event;

		while(window.pollEvent(event))
		{
			if(event.type==sf::Event::Closed)
				window.close();
			
			if(event.type==sf::Event::KeyPressed)
			{
				if(event.key.code == sf::Keyboard::Escape)
					window.close();
			}
			
			sum(10,10);

			if(event.type == sf::Event::MouseMoved)
			{
				std::cout << event.mouseMove.x << "  /  " << event.mouseMove.y << std::endl;
				sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
				sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
				std::cout << worldPos.x << "  /  " << worldPos.y << std::endl;
				std::cout << sum(10,10) << std::endl;
			}
		}

		window.clear(sf::Color::Black);
		window.draw(r);

		window.display();
	}


	return 0;
}

int getSum(int a, int b)
{
	int sum = a + b;

	return sum;
}


