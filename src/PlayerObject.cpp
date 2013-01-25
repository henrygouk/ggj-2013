#include "Game.h"

using namespace sf;

PlayerObject::PlayerObject(Vector2f pos)
{
	position = pos;
	
	sf::Image img;
	img.LoadFromFile("assets/Bounce-1sm.png");
	
	images.push_back(img);
	
	sprite.FlipX(true);
}

void PlayerObject::update()
{
	if(window->GetInput().IsKeyDown(Key::Right))
	{
		position.x += 5.0;
		
		sprite.FlipX(true);
	}
	else if(window->GetInput().IsKeyDown(Key::Left))
	{
		position.x -= 5.0;
		
		sprite.FlipX(false);
	}
}

void PlayerObject::draw()
{
	sprite.SetImage(images[0]);
	sprite.SetPosition(position);
	window->Draw(sprite);
}
