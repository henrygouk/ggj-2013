#ifndef BLOODFART_H 
#define BLOODFART_H

#include "Game.h"

class BloodFart : public GameObject
{
	public:
		BloodFart(GameScreen* gs, GameObject* follow, sf::Vector2f offset, int mirror, int rotation);

		void update();
		void draw();

		static std::vector<sf::Image> staticImages;
		static bool imagesLoaded;

		GameObject* creator;
		sf::Vector2f offset;

		//Animations shit
		int imageIndex;
		int imageCount;
		float imageAnimationSwitch;
		float imageAnimationPos;
		float imageAnimationSpeed; 
};

#endif
