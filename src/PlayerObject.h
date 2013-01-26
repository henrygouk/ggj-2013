#ifndef PLAYEROBJECT_H
#define PLAYEROBJECT_H

#include "Game.h"

class PlayerObject : public GameObject
{
	public:
		PlayerObject(GameScreen* gs, sf::Vector2f pos);
		void update();
		void draw();

		bool flipped;
		float boundingBoxXoffset;
		sf::Vector2f boundingBoxSize;
		bool enemyCollidable;
		float enemyCollidableCoolDown;

		//Bloods
		float bloodSpawnCountDown;
		float bloodSpawnXChange;

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
		
		//Shooting stuff
		bool shootingFlag;
		sf::Clock shootTimer;

		//Gets absolute positions of bounding box borders
		//takes into account player position but not 
		//camera cuz obvious.
		inline float boundingBoxHMiddle();
		inline float boundingBoxTop();
		inline float boundingBoxBottom();
		inline float boundingBoxLeft();
		inline float boundingBoxRight();
};

#endif
