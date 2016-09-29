#ifndef CONTROLLED_CREATURE
#define CONTROLLED_CREATURE
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include "Creature.hpp"

class ControlledCreature: public Creature {
	int action; //  a UI apears : move, atack, cast spell, use item
	int dir;
	public:
		ControlledCreature (sf::Texture &tx):Creature(tx){
		//	sp.setTexture(tx);
			stamina = 100;
			steps=weight=5;
			initStats();
			dir=-1;
		}
		void setDir(int tDir){
			dir=tDir; // you don't say!
		}
		void move(/* float dTime*/){	// only moves one step by now
			// lerp(vec2 orig, vec2 dest,speed,dTime);
			sf::Vector2f pos=sp.getPosition();
			switch(dir){
				case 0: pos.y-=32; break;
				case 1: pos.y+=32; break;
				case 2: pos.x-=32; break;
				case 3: pos.x+=32; break;
				default: break;
			}
			dir= -1;
			sp.setPosition(pos) ;
		}
		void update(){
			move();
		}	
		void atack(){
			// pum!! pum!! pum!!
		}
		void magic(){
			// paz!! pazz! paz!!!
		}
		
		void draw(sf::RenderWindow &rWindow){
			// select creature image
			rWindow.draw(sp);
		}
};

#endif
