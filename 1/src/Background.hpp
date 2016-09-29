#ifndef BACKGROUND
#define BACKGROUND
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

class Background {
	sf::Texture tx;
	sf::Sprite sp;
	int tiles[15][20];  // 0-5 types of tiles
	public:
		void init();
		void draw(sf::RenderWindow &rWindow);
};
#endif
