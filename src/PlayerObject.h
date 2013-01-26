#ifndef PLAYEROBJECT_H
#define PLAYEROBJECT_H

#include "Game.h"

class PlayerObject : public GameObject
{
	public:
		PlayerObject(GameScreen* gs, sf::Vector2f pos);
		void update();
		void draw();

		float boundingBoxXoffset;
		sf::Vector2f boundingBoxSize;

		//Burst Jump shit
		int facingDirection;
		bool ctrlDown;
		float jumpCoolDown;

		//Animations shit
		int imageIndex;
		int imageCount;
		float imageAnimationSwitch;
		float imageAnimationPos;
		float imageAnimationSpeed; 

		//Gets absolute positions of bounding box borders
		//takes into account player position but not 
		//camera cuz obvious.
		inline float boundingBoxTop();
		inline float boundingBoxBottom();
		inline float boundingBoxLeft();
		inline float boundingBoxRight();
};

#endif
