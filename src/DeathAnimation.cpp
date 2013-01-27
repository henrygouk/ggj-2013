#include "Game.h"

#define IMAGE_COUNT 12
#define LIFE_SPAN 4

#include <sstream>
#include <stdlib.h>
#include <time.h>

using namespace std;
using namespace sf;

bool DeathAnimation::imagesLoaded = false;
vector<Image> DeathAnimation::staticImages;

DeathAnimation::DeathAnimation(GameScreen* gs, Vector2f offset)
{
	parent = gs;
	position = offset;
	position.y += 27;

	imageCount = IMAGE_COUNT;
	imageIndex = 0;
	imageAnimationSwitch = 0.05;
	imageAnimationPos = 0.0;
	imageAnimationSpeed = 1;1;

	if (!imagesLoaded) 
	{
		Image img;
		for(int i = 1; i <= IMAGE_COUNT; i++) 
		{
			stringstream ss (stringstream::in | stringstream::out);
			ss << ASSETS_FOLDER << "DieF" << i << ".png";

			img.LoadFromFile(ss.str());
			staticImages.push_back(img);
		}
		
		imagesLoaded = true;
	}

	sprite.SetImage(staticImages[imageIndex]);
	sprite.SetCenter(staticImages[imageIndex].GetWidth() / 2, staticImages[imageIndex].GetHeight());
	sprite.SetColor(Color(255 - rand() % 30, 255 - rand() % 30, 255 - rand() % 30, 240));

	lifeSpan = LIFE_SPAN;
	opacity = 255.0;
}

void DeathAnimation::update()
{
	if (imageIndex != imageCount-1) 
	{
		imageAnimationPos += imageAnimationSpeed * DELTA_TIME;

		if (imageAnimationPos > imageAnimationSwitch) 
		{
			imageAnimationPos = 0;
			if (imageIndex++ < imageCount-1) return;
		}
	}

	lifeSpan -= DELTA_TIME;

	if (lifeSpan > 0) return;

	opacity -= 64.0 * DELTA_TIME;

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

void DeathAnimation::draw()
{
	sprite.SetColor(sf::Color(255, 255, 255, (int)opacity));
	sprite.SetPosition(parent->normaliseCoords(position));
	sprite.SetImage(staticImages[imageIndex]);
	window->Draw(sprite);
}
