#include "Game.h"

using namespace sf;

PlayerObject::PlayerObject(Vector2f pos)
{
	position = pos;
}

void PlayerObject::update()
{
	if(window->GetInput().IsKeyDown(Key::Right))
	{
		position.x += 5.0;
	}
	else if(window->GetInput().IsKeyDown(Key::Left))
	{
		position.x -= 5.0;
	}
}

void PlayerObject::draw()
{
	sprite.SetPosition(position);
	window->Draw(sprite);
}
