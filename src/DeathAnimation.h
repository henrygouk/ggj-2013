#ifndef DEATHANIMATION_H
#define DEATHANIMATION_H

#include "Game.h"

class DeathAnimation : public GameObject
{
	public:
		DeathAnimation(GameScreen *gs, sf::Vector2f offset);
		void update();
		void draw();

		float lifeSpan;
		float opacity;

		//Animations shit
		int imageIndex;
		int imageCount;
		float imageAnimationSwitch;
		float imageAnimationPos;
		float imageAnimationSpeed;

		static std::vector<sf::Image> staticImages;
		static bool imagesLoaded;
};

#endif

