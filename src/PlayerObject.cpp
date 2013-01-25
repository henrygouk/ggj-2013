#include "Game.h"

#define GRAVITY 9.81

using namespace sf;

PlayerObject::PlayerObject(GameScreen* gs, Vector2f pos)
{
	parent = gs;
	position = pos;
	velocity = Vector2f(0.0, 0.0);

	sf::Image img;
	img.LoadFromFile("assets/Bounce-1sm.png");
	
	images.push_back(img);
	
	sprite.FlipX(true);
	sprite.SetImage(images[0]);
	sprite.SetCenter(img.GetWidth() / 2, img.GetHeight());
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

	velocity.y += GRAVITY * 1.0/60.0;

	for (auto it = parent->gameObjects.begin(); it!=parent->gameObjects.end(); it++) 
	{
		StaticPlatform* obj = dynamic_cast<StaticPlatform*>(*it);
		if (!obj) continue;

		if (position.x + sprite.GetImage()->GetWidth() / 2 < obj->left()) continue;
		if (position.x - sprite.GetImage()->GetWidth() / 2 > obj->right()) continue;

		if (position.y <= obj->top() && position.y + velocity.y >= obj->top()) 
		{
			position.y = obj->top();
			velocity.y = 0;
		}
	}

	position.y += velocity.y;
}

void PlayerObject::draw()
{
	sprite.SetImage(images[0]);
	sprite.SetPosition(position);
	window->Draw(sprite);
}
