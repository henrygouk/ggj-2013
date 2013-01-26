#include "Game.h"

#define ASSETS_BASE "assets/Bounce-"
#define ASSETS_EXT "sm.png"
#define ANIMATION_IMAGE_COUNT 11
#define ANIMATION_SPEED_MOVING 1.0
#define ANIMATION_SPEED_IDLE 0.55

#define BOUNDINGBOX_WIDTH -20
#define BOUNDINGBOX_HEIGHT -60
#define BOUNDINGBOX_LEFT_OFFSET 20
#define BOUNDINGBOX_RIGHT_OFFSET 0

#include <iostream>
#include <sstream>

using namespace std;
using namespace sf;

PlayerObject::PlayerObject(GameScreen* gs, Vector2f pos)
{
	parent = gs;
	position = pos;
	velocity = Vector2f(0.0, 0.0);

	imageCount = ANIMATION_IMAGE_COUNT;
	imageIndex = 0;
	imageAnimationSwitch = 0.05;
	imageAnimationPos = 0.0;
	imageAnimationSpeed = ANIMATION_SPEED_IDLE;
	
	for(int i = 1; i <= imageCount; i++) 
	{
		stringstream ss (stringstream::in | stringstream::out);
		ss << ASSETS_BASE << i << ASSETS_EXT;

		sf::Image img;
		img.LoadFromFile(ss.str());
		images.push_back(img);
	}
	
	sprite.FlipX(true);
	sprite.SetImage(images[imageIndex]);
	sprite.SetCenter(images[imageIndex].GetWidth() / 2, images[imageIndex].GetHeight());

	boundingBoxXoffset = 0;
	boundingBoxSize = Vector2f(BOUNDINGBOX_WIDTH, BOUNDINGBOX_HEIGHT);
}

void PlayerObject::update()
{

	if(window->GetInput().IsKeyDown(Key::Right) || window->GetInput().IsKeyDown(Key::D))
	{
		velocity.x += 3.0 * SPEED * DELTA_TIME;
		velocity.x = min(velocity.x, SPEED);
		
		boundingBoxXoffset = BOUNDINGBOX_RIGHT_OFFSET;
		sprite.FlipX(true);
	}
	else if(window->GetInput().IsKeyDown(Key::Left) || window->GetInput().IsKeyDown(Key::A))
	{
		velocity.x -= 3.0 * SPEED * DELTA_TIME;
		velocity.x = max(velocity.x, -SPEED);
		
		boundingBoxXoffset = BOUNDINGBOX_LEFT_OFFSET;
		sprite.FlipX(false);
	}
	else
	{
		if(velocity.x < 0.0)
		{
			velocity.x += FRICTION * SPEED * DELTA_TIME;
			velocity.x = min(velocity.x, SPEED);
			
			if(velocity.x > 0.0)
			{
				velocity.x = 0.0;
			}
		}
		else if(velocity.x > 0.0)
		{
			velocity.x -= FRICTION * SPEED * DELTA_TIME;

			if(velocity.x < 0.0)
			{
				velocity.x = 0.0;
			}
		}
	}

	if(window->GetInput().IsKeyDown(Key::Up) || window->GetInput().IsKeyDown(Key::W)) 
	{
		if (velocity.y == 0.0)
			velocity.y += JUMP_STRENGTH * SPEED;
	}
	else if(window->GetInput().IsKeyDown(Key::Down) || window->GetInput().IsKeyDown(Key::S))
	{
		if (velocity.y == 0.0)
			position.y += 1.0;
	}

	velocity.y += GRAVITY * SPEED * DELTA_TIME;

	Platform* snapped = NULL;

	for (auto it = parent->gameObjects.begin(); it!=parent->gameObjects.end(); it++) 
	{
		Platform* obj = dynamic_cast<Platform*>(*it);

		if (!obj) continue;

		if (boundingBoxLeft() < obj->left()) continue;
		if (boundingBoxRight() > obj->right()) continue;

		if (boundingBoxBottom() <= obj->top() && boundingBoxBottom() + velocity.y * DELTA_TIME >= obj->top()) 
		{
			snapped = obj;
			position.y = obj->top();
			velocity.y = 0;
			break;
		}
	}

	position += velocity * DELTA_TIME;
	if (snapped) position += snapped->velocity * DELTA_TIME;
	
	parent->cameraPosition.x = (int)(position.x - (float)window->GetWidth() / 2.0f);

	imageAnimationSpeed = (velocity.x == 0) ? ANIMATION_SPEED_IDLE : ANIMATION_SPEED_MOVING;

	if (velocity.y == 0 || imageIndex != 0)
		imageAnimationPos += imageAnimationSpeed * DELTA_TIME;

	if (imageAnimationPos > imageAnimationSwitch) 
	{
		imageAnimationPos = 0;
		if (imageIndex++ >= imageCount-1) imageIndex = 0;
	}
}

void PlayerObject::draw()
{
	sprite.SetImage(images[imageIndex]);
	sprite.SetPosition(parent->normaliseCoords(position));
	window->Draw(sprite);

	/*
	Vector2f topleft = parent->normaliseCoords(Vector2f(boundingBoxLeft(), boundingBoxTop()));
	Vector2f bottomright = parent->normaliseCoords(Vector2f(boundingBoxRight(), boundingBoxBottom()));

	Shape rect = Shape::Rectangle(topleft.x, topleft.y, bottomright.x, bottomright.y, Color(255, 0, 0, 255));

	window->Draw(rect);
	*/
	
}

inline float PlayerObject::boundingBoxLeft() { return position.x + boundingBoxXoffset; } 
inline float PlayerObject::boundingBoxRight() { return position.x + boundingBoxXoffset + boundingBoxSize.x; } 
inline float PlayerObject::boundingBoxTop() { return position.y + boundingBoxSize.y; } 
inline float PlayerObject::boundingBoxBottom() { return position.y; } 
