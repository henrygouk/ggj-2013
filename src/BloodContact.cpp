#include "Game.h"

#define IMAGE_COUNT 5
#define LIFE_SPAN 10

#include <sstream>
#include <stdlib.h>
#include <time.h>

using namespace std;
using namespace sf;

bool BloodContact::imagesLoaded = false;
vector<Image> BloodContact::staticImages;

BloodContact::BloodContact(GameScreen* gs, GameObject* _follow, Vector2f offset, int imageIndex)
{
	parent = gs;
	follow = _follow;
	position = offset;

	if (!imagesLoaded) 
	{
		Image img;
		for(int i = 1; i <= IMAGE_COUNT; i++) 
		{
			stringstream ss (stringstream::in | stringstream::out);
			ss << ASSETS_FOLDER << "BloodContact" << i << ".png";

			img.LoadFromFile(ss.str());
			staticImages.push_back(img);
		}
		
		imagesLoaded = true;
	}

	sprite.SetImage(staticImages[imageIndex]);
	sprite.SetCenter(staticImages[imageIndex].GetWidth()/ 2, 0);
	sprite.SetColor(Color(255 - rand() % 30, 255 - rand() % 30, 255 - rand() % 30, 240));

	lifeSpan = LIFE_SPAN;
	opacity = 255.0;
}

void BloodContact::update()
{
	if (follow != NULL)
		velocity = follow->velocity;

	position += velocity * DELTA_TIME;

	lifeSpan -= DELTA_TIME;

	if (lifeSpan > 0) return;

	opacity -= 128.0 * DELTA_TIME;

	if (opacity > 0) return;

	for (auto it = parent->gameObjects.begin(); it!=parent->gameObjects.end(); it++) 
	{
		if (*it == this) 
		{
			parent->gameObjects.erase(it);
			break;
		}
	}

	delete this;
	return;
}

void BloodContact::draw()
{
	sprite.SetColor(sf::Color(255, 255, 255, (int)opacity));
	sprite.SetPosition(parent->normaliseCoords(position));
	window->Draw(sprite);
}
