#include "Game.h"

using namespace sf;

Enemy::Enemy(GameScreen *gs, Vector2f pos, Vector2f dst)
{
	parent = gs;
	position = pos;
	start = pos;
	end = dst;
	velocity.x = SPEED * 0.3;
	
	Image img;
	img.LoadFromFile("assets/Bounce-3sm.png");
	images.push_back(img);
	
	sprite.SetImage(images[0]);
	sprite.SetCenter(img.GetWidth() / 2, img.GetHeight());
}

void Enemy::update()
{
	//If velocity is pointing away from destination
		//Reverse velocity
		//Change destination
		
	if(dot(velocity, end - position) < 0)
	{
		velocity *= -1.0f;
		swap(start, end);
	}
	
	position += velocity * DELTA_TIME;
}

void Enemy::draw()
{
	sprite.SetImage(images[0]);
	sprite.SetPosition(position - parent->cameraPosition);
	window->Draw(sprite);
}
