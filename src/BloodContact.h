#ifndef BLOODCONTACT_H
#define BLOODCONTACT_H

#include "Game.h"

class BloodContact : public GameObject
{
	public:
		BloodContact(GameScreen *gs, GameObject* _follow, sf::Vector2f offset, int imageIndex);
		void update();
		void draw();

		GameObject* follow;
		float lifeSpan;
		float opacity;


		static std::vector<sf::Image> staticImages;
		static bool imagesLoaded;
};

#endif
