#include "Game.h"

#define GRAVITY 4.81f
#define JUMP_STRENGTH -2.0f
#define SPEED 200.0f
#define DELTA_TIME (float)window->GetFrameTime()

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

	if(window->GetInput().IsKeyDown(Key::Right) || window->GetInput().IsKeyDown(Key::D))
	{
		velocity.x += 3.0 * SPEED * DELTA_TIME;
		velocity.x = min(velocity.x, SPEED);
		
		sprite.FlipX(true);
	}
	else if(window->GetInput().IsKeyDown(Key::Left) || window->GetInput().IsKeyDown(Key::A))
	{
		velocity.x -= 3.0 * SPEED * DELTA_TIME;
		velocity.x = max(velocity.x, -SPEED);
		
		sprite.FlipX(false);
	}
	else
	{
		if(velocity.x < 0.0)
		{
			velocity.x += 2.0 * SPEED * DELTA_TIME;
			velocity.x = min(velocity.x, SPEED);
			
			if(velocity.x > 0.0)
			{
				velocity.x = 0.0;
			}
		}
		else if(velocity.x > 0.0)
		{
			velocity.x -= 2.0 * SPEED * DELTA_TIME;

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

	for (auto it = parent->gameObjects.begin(); it!=parent->gameObjects.end(); it++) 
	{
		StaticPlatform* obj = dynamic_cast<StaticPlatform*>(*it);
		if (!obj) continue;

		if (position.x + sprite.GetImage()->GetWidth() / 4 < obj->left()) continue;
		if (position.x - sprite.GetImage()->GetWidth() / 4 > obj->right()) continue;

		if (position.y <= obj->top() && position.y + velocity.y * DELTA_TIME >= obj->top()) 
		{
			position.y = obj->top();
			velocity.y = 0;
		}
	}

	position += velocity * DELTA_TIME;
	
	parent->cameraPosition.x = position.x - (float)window->GetWidth() / 2.0f;
}

void PlayerObject::draw()
{
	sprite.SetImage(images[0]);
	sprite.SetPosition(position - parent->cameraPosition);
	window->Draw(sprite);
}
