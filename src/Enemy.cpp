#include "Game.h"
#define ASSETS_BASE "frame"
#define ASSETS_EXT "sm.png"
#define ANIMATION_IMAGE_COUNT 5
#define ANIMATION_SPEED 0.5
#include <sstream>

using namespace std;
using namespace sf;

Enemy::Enemy(GameScreen *gs, Vector2f pos, Vector2f dst)
{
	parent = gs;
	position = pos;
	start = pos;
	end = dst;
	velocity.x = SPEED * 0.3;
	
	imageCount = ANIMATION_IMAGE_COUNT;
	imageIndex = 0;
	imageAnimationSwitch = 0.05;
	imageAnimationPos = 0.0;
	imageAnimationSpeed = ANIMATION_SPEED;
	
	for(int i = 1; i <= imageCount; i++) 
	{
		stringstream ss (stringstream::in | stringstream::out);
		ss << ASSETS_FOLDER << ASSETS_BASE << i << ASSETS_EXT;

		sf::Image img;
		img.LoadFromFile(ss.str());
		images.push_back(img);
	}
	
	flipped = true;
	sprite.SetScaleX(0.75);
	sprite.SetScaleY(0.75);
	sprite.FlipX(flipped);
	sprite.SetImage(images[imageIndex]);
	sprite.SetCenter(images[imageIndex].GetWidth() / 2, images[imageIndex].GetHeight());
}

void Enemy::update()
{
	//If velocity is pointing away from destination
	//Reverse velocity
	//Change destination
		
	if(dot(velocity, end - position) < 0)
	{
		flipped = !flipped;
		sprite.FlipX(flipped);
		velocity *= -1.0f;
		swap(start, end);
	}
	
	position += velocity * DELTA_TIME;

	imageAnimationPos += imageAnimationSpeed * DELTA_TIME;

	if (imageAnimationPos > imageAnimationSwitch) 
	{
		imageAnimationPos = 0;
		if (imageIndex++ >= imageCount-1) imageIndex = 0;
	}
}

void Enemy::draw()
{
	sprite.SetImage(images[imageIndex]);
	sprite.SetPosition(parent->normaliseCoords(position));
	window->Draw(sprite);
}

float Enemy::top() { return position.y - images[0].GetHeight(); }
float Enemy::bottom() { return position.y; }
float Enemy::left() { return position.x - images[0].GetWidth() / 2; }
float Enemy::right() { return position.x + images[0].GetWidth() / 2; }
