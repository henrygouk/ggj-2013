#include "Game.h"
#include <iostream>

using namespace std;
using namespace sf;

DeathPlatform::DeathPlatform(GameScreen* gs, Vector2f pos, Vector2f dimens, float _damage, string filename, float _scale)
{
 	parent = gs;
	position = pos;
	dimensions = dimens;
	damage = _damage;
	scale = _scale;

	Image img;
	img.LoadFromFile(filename);
	images.push_back(img);

	sprite.SetCenter(0, img.GetHeight());
}

void DeathPlatform::update()
{
}


void DeathPlatform::draw()
{
	Vector2f drawPosition = position;
	drawPosition.y += 6;

	sprite.SetScaleX(scale);
	sprite.SetScaleY(scale);
	sprite.SetPosition(parent->normaliseCoords(drawPosition));
	sprite.SetImage(images[0]);
	window->Draw(sprite);
}
