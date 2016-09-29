#include <iostream>
#include "src/Background.hpp"
#include "src/ControlledCreature.hpp"
/*   DONT IGNORE US
	Texture
	Font
	Sprite
	Vector2d
	Color
	CircleShaoe, RectangleShape
*/

/*
	 // move hero  
	 // move rat randomly
	 // move to other stage?
*/

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML works!");
	sf::Texture tHero,tRat;
	sf::Sprite  sHero,sRat;
	
	tHero.loadFromFile("gfx/hero.png");
	tRat.loadFromFile("gfx/rat.png");
	
	sRat.setTexture(tRat);
	sRat.setPosition(128,32);
	sHero.setTexture(tHero);
	sHero.setPosition(256,32);
	
	Background bg;
	ControlledCreature player(tHero);
	bg.init();
	

	
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type){
            	case sf::Event::Closed:
                	window.close();
				break;
            	case sf::Event::KeyPressed:
            		std::cout<< event.key.code;
            		switch(event.key.code){
            			case 73:  // up
					 		player.setDir(0);
						break;  // down
						case 74: 
					 		player.setDir(1);
						break;
						case 71: // left
					 		player.setDir(2);
						break;
						case 72:  // right
					 		player.setDir(3);
						break;
					}
			
				break;
				case sf::Event::JoystickButtonPressed:
					
				break;
				case sf::Event::JoystickMoved:
					if(event.joystickMove.axis == sf::Joystick::X){
						
					}else if( event.joystickMove.axis == sf::Joystick::Y){
						
					}
				break;
			}
        }
		player.update();
        window.clear();
        
        bg.draw(window);
        player.draw(window);
        window.draw(sRat);
        window.display();
    }

    return 0;
}
