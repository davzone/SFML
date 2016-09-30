#include <iostream>
#include "../src/Background.hpp"
#include "../src/ControlledCreature.hpp"
#include "../src/Rat.hpp"
/*   DONT IGNORE US
	Texture
	Font
	Sprite
	Vector2d
	Color
	CircleShape, RectangleShape
*/

/*			/*   TO DOS  
	 // X move hero
	 // limit player movement only inside visible area
	 	//
		// X move rat to random location
	 	// ** enemy variety
	 	// ** patrol areas
	 	// ** atack variety
	 // move to other stage?
	    // ** 
*/

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML: La leyenda de Melda");
	sf::Texture tHero, tRat, tPirate;

	
	sf::Image iAlpha;  // loads the image , sets magenta pixels to alpha
	iAlpha.loadFromFile("../gfx/hero.png");
	iAlpha.createMaskFromColor(sf::Color::Magenta,0);
	tHero.loadFromImage(iAlpha);
	
	iAlpha.loadFromFile("../gfx/rat.png");
	iAlpha.createMaskFromColor(sf::Color::Magenta,0);
	tRat.loadFromImage(iAlpha);
	
	iAlpha.loadFromFile("../gfx/pirate.png");
	iAlpha.createMaskFromColor(sf::Color::Magenta,0);
	tPirate.loadFromImage(iAlpha);
	
	//sRat.setTexture(tRat);
	//sRat.setPosition(128,32);
	//sHero.setTexture(tHero);
	//sHero.setPosition(256,32);
	
	Background bg;
	ControlledCreature player(tHero);
	Rat rat1(tRat);
	//AICreature c(AIBoss,AIMinion,AIPath);
	bg.init();
	rat1.setPosition(sf::Vector2f(256,64));

	sf::Time currentTime;
	sf::Clock deltaClock;
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
		
		
		player.update(deltaClock.getElapsedTime().asSeconds());
		rat1.update(deltaClock.getElapsedTime().asSeconds());
	//	std::cout<<"Current:"<<currentTime.asSeconds()<<" Elapsed:"<<(double)deltaClock.restart().asSeconds() << std::endl;
		deltaClock.restart();
        window.clear();
        
        bg.draw(window);
        player.draw(window);
        rat1.draw(window);
        
        window.display();
		sf::sleep(sf::milliseconds(10));
    }

    return 0;
}
