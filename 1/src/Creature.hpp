#ifndef CREATURE
#define CREATURE
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

class Creature{
	protected:
	// int spd; // faster atacks == more dps
	// int family;  // light , darkness, twilight 
	//int race; // human , dwarf, elf, etc.. etc..
	int hp, str, mgk, mana, stamina, agi;
	sf::Texture tex;
	int weight;
	int steps, maxSteps;
	
	sf::Vector2f destiny;
	Creature* target;
	sf::Sprite sp;
	public:
		Creature (sf::Texture &tx){
			tex=tx;
			sp.setTexture(tex);
			stamina = 100;
			steps=weight=5;
			initStats();
		}
		virtual void initStats(){
			// load base race stats form  file
		}
		virtual void move(){	// defined by str and current weight
			stamina-= (steps*2)-(str-(weight/1.7));
		}
		
		virtual void atack(){
			// pum!!
		}
		
		virtual void enemyInRange(){
			// charge to enemy , after he dies return path to previous destiny
		}
		
		virtual bool rest(){  // if stamina == 0   wait until stamina == 100
			if(stamina < 100){
			//	stamina += ((hp/baseHp)*0.7); // to do: create formula to regenerate stamina each turn
				return false;
			}
			return true;	
		}
		
		virtual void setDestiny(sf::Vector2f dest){
			destiny = dest;
		}
		
		virtual void setDestiny(Creature* cDest){
			destiny = cDest->destiny;	
		}
		
		virtual void setTarget(Creature* dest){ // select weakest of nearest foes, to do:  enemy vector
			
		}
		virtual void update(){
			move();
		}
		virtual void draw(sf::RenderWindow &rWindow){
			// select creature image
			rWindow.draw(sp);
		}
};

#endif
