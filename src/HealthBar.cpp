#include "Game.h"

#define ASSETS_EXT ".png"
#define EMPTY_INDEX 0 
#define BACK_INDEX 1
#define RECT_WIDTH 389.0f
#define RECT_HEIGHT 15.0f
#define HEALTH_ANIMATE_SPEED 15
//Animate speed in % per second

#include <sstream>

using namespace sf;

HealthBar* HealthBar::ref = NULL;

HealthBar::HealthBar(GameScreen* gs, Vector2f pos, int _maxHealth) 
{
	parent = gs;
	position = pos;
	maxHealth = _maxHealth;
	currentHealth = maxHealth;
	targetHealth = maxHealth;

	stringstream ss (stringstream::in | stringstream::out);
	Image img;

	ss << ASSETS_FOLDER << "BarEmpty" << ASSETS_EXT;
	img.LoadFromFile(ss.str());
	images.push_back(img);

	ss.str(string());
	ss << ASSETS_FOLDER << "BarBack" << ASSETS_EXT;
	img.LoadFromFile(ss.str());
	images.push_back(img);

	sprite.SetPosition(position);
}

HealthBar* HealthBar::createHealthBar(GameScreen* gs, Vector2f pos, int _maxHealth) 
{
	if (ref == NULL)
		ref = new HealthBar(gs, pos, _maxHealth);

	return ref;
}

HealthBar* HealthBar::getHealthBar() 
{
	return ref;
}

void HealthBar::setHealthTo(float h) 
{
	targetHealth = h;
}

void HealthBar::addHealth(float h)
{
	targetHealth = currentHealth + h;
}

void HealthBar::update() 
{
	if (currentHealth == targetHealth)
		return;

	float healthPercent = maxHealth / 100;
	float healthSpeed = HEALTH_ANIMATE_SPEED * healthPercent * DELTA_TIME;

	if (currentHealth > targetHealth) 
	{
		if (currentHealth - healthSpeed < targetHealth)
			currentHealth = targetHealth;
		else
			currentHealth -= healthSpeed;
	}
		else
	{
		if (currentHealth + healthSpeed > targetHealth)
			currentHealth = targetHealth;
		else
			currentHealth += healthSpeed;
	}
}

void HealthBar::draw()
{
	sprite.SetImage(images[BACK_INDEX]);
	window->Draw(sprite);
	
	Vector2f rectOrigin (position.x + 30, position.y + 30);

	float healthPercent = currentHealth / maxHealth;

	Shape rect = Shape::Rectangle(rectOrigin.x, rectOrigin.y, rectOrigin.x+RECT_WIDTH*healthPercent, rectOrigin.y+RECT_HEIGHT,
								  Color(143, 0, 4, 255));

	window->Draw(rect);

	sprite.SetImage(images[EMPTY_INDEX]);
	window->Draw(sprite);
}
