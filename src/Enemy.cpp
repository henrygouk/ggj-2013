#include "Game.h"

using namespace sf;

Enemy::Enemy(GameScreen *gs, Vector2f pos)
{
	parent = gs;
	position = pos;
	
	Image img;
	img.LoadFromFile("assets/Bounce-3sm.png");
	images.push_back(img);
	
	sprite.SetImage(images[0]);
	sprite.SetCenter(img.GetWidth() / 2, img.GetHeight());
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
