#include "Game.h"

#define ANIMATION_IMAGE_COUNT 9
#define ANIMATION_SPEED_MOVING 1.0
#define ANIMATION_SPEED_IDLE 0.55

#include <sstream>
#include <iostream>
using namespace sf;
using namespace std;

bool BloodFart::imagesLoaded = false;
vector<Image> BloodFart::staticImages;

BloodFart::BloodFart(GameScreen* gs, GameObject* follow, Vector2f off, int mirrow, int rotation, float scale) 
{

	offset = off;
	if (follow)
		position = follow->position + offset;
	else
		position = offset;

	parent = gs;
	creator = follow;

	imageCount = ANIMATION_IMAGE_COUNT;
	imageIndex = 0;
	imageAnimationSwitch = 0.05;
	imageAnimationPos = 0.0;
	imageAnimationSpeed = ANIMATION_SPEED_IDLE;
		
	if (!imagesLoaded) 
	{
		Image img;
		for(int i = 1; i <= imageCount; i++) 
		{
			stringstream ss (stringstream::in | stringstream::out);
			ss << ASSETS_FOLDER << "launch-" << i << ".png";

			img.LoadFromFile(ss.str());
			staticImages.push_back(img);
		}
		
		imagesLoaded = true;
	}
	
	sprite.SetRotation(rotation);
	sprite.FlipX(mirrow != 1);
	sprite.SetScale(1.0f, scale);
	sprite.SetImage(staticImages[imageIndex]);
	sprite.SetCenter(staticImages[imageIndex].GetWidth()/ 2, staticImages[imageIndex].GetHeight());
}

void BloodFart::update()
{
	if (creator)
		position = creator->position + offset;
	else
		position = offset;
	
	imageAnimationPos += imageAnimationSpeed * DELTA_TIME;

	if (imageAnimationPos > imageAnimationSwitch) 
	{
		imageAnimationPos = 0;
		if (imageIndex++ >= imageCount-1) 
		{
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
	}
}

void BloodFart::draw()
{
	sprite.SetImage(staticImages[imageIndex]);
	sprite.SetPosition(parent->normaliseCoords(position));
	window->Draw(sprite);
}
