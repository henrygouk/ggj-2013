#include "Game.h"

using namespace sf;

Enemy::Enemy(GameScreen *gs, Vector2f pos)
{
	parent = gs;
	position = pos;
	
	Image
}

void Enemy::update()
{

}

void Enemy::draw()
{
	sprite.SetImage(images[0]);
	sprite.SetPosition(position - parent->cameraPosition);
	window->Draw(sprite);
}
