#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>

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
			

		}

		window.clear(sf::Color::Black);
		window.draw(r);

		window.display();
	}


	return 0;
}




