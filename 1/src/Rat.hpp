#ifndef RAT_H
#define RAT_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Creature.hpp"

class Rat: public Creature{
	double moveInterval; // in seconds
	public:
		Rat(sf::Texture &tx):Creature(tx){
			moveInterval=1;
			destiny.x=32*(rand()%19);
			destiny.y=32*(rand()%14);
		}
	//	void setBaseStats();
		void setMovementIterval(float seconds); // time between movement from current pos to destiny
		
		void move(double dTime){	// defined by str and current weight
		//	to do: flee from player
			sf::Vector2f tmp;
			tmp=sp.getPosition();
			switch(movementType){
				case 0:
					if(destiny != tmp){
						if(tmp.x < destiny.x){
							sp.setPosition(tmp.x+32,tmp.y);
						} else if(tmp.x > destiny.x){
							sp.setPosition(tmp.x-32,tmp.y);
						} else 	if(tmp.y < destiny.y){
							sp.setPosition(tmp.x,tmp.y+32);
						} else if(tmp.y > destiny.y){
							sp.setPosition(tmp.x,tmp.y-32);
						}
					}else{
						// if in destiny get new destiny
						destiny.x=32*(rand()%19);
						destiny.y=32*(rand()%14);
					}
						std::cout<<"Current:x"<<tmp.x <<"y"<<tmp.y<<""<<" Destiny:x"<<destiny.x<<" y "<<destiny.y<< std::endl;

				break;
				case 1: 
				
				break;
				case 2: 
				
				break;
			}
		}
		void update(double dTime){

			if(moveInterval <=0){
				move(dTime);
				moveInterval=1;
			}else{
				moveInterval -= dTime;
			}
		}
};
#endif
