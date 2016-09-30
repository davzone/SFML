#include "Background.hpp"

void Background::init(){
	srand(time(NULL));
	
	tx.loadFromFile("../gfx/tiles.png");
//	tx.create(32,32);
	sp.setTexture(tx);
	
	for(int y= 0; y<15; y++){
		for(int x= 0; x<20; x++){
			tiles[y][x] = rand()%2;
		}	
	}
}
void Background::draw(sf::RenderWindow &rWindow ){
	for(int y= 0; y<15; y++){
		for(int x= 0; x<20; x++){

		// limits texture size drawing
	 ///	 	IntRect( textureXoffset ,textureYoffset, width, height)
			sp.setTextureRect(sf::IntRect(tiles[y][x]*32.0f,0.0f,32.0f,32.0f));
			sp.setPosition(x*32,y*32);
			rWindow.draw(sp);
		}	
	}
}
