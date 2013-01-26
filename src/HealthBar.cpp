#include "Game.h"

#define ASSETS_EXT ".png"
#define EMPTY_INDEX 0 
#define BACK_INDEX 1
#define BLOOD_START 2
#define BLOOD_COUNT 5
#define RECT_WIDTH 389.0f
#define RECT_HEIGHT 15.0f
#define HEALTH_ANIMATE_SPEED 50
//Animate speed in % per second

#include <sstream>

using namespace sf;

HealthBar* HealthBar::ref = NULL;

HealthBar::HealthBar(Vector2f pos, int _maxHealth) 
{
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

	for(int i = 1; i <= BLOOD_COUNT; i++) 
	{
		ss.str(string());
		ss << ASSETS_FOLDER << "Blood-overlay-" << i << ASSETS_EXT;
		img.LoadFromFile(ss.str());
		images.push_back(img);
	}

}

HealthBar* HealthBar::createHealthBar(Vector2f pos, int _maxHealth) 
{
	if (ref == NULL)
		ref = new HealthBar(pos, _maxHealth);

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
	
	currentHealth = max(0.0f, currentHealth);
}

void HealthBar::draw()
{
	sprite.SetPosition(position);
	sprite.SetImage(images[BACK_INDEX]);
	window->Draw(sprite);
	
	Vector2f rectOrigin (position.x + 30, position.y + 30);

	float healthPercent = currentHealth / maxHealth;

	Shape rect = Shape::Rectangle(rectOrigin.x, rectOrigin.y, rectOrigin.x+RECT_WIDTH*healthPercent, rectOrigin.y+RECT_HEIGHT,
								  Color(163, 0, 4, 255));

	window->Draw(rect);

	sprite.SetImage(images[EMPTY_INDEX]);
	window->Draw(sprite);

	Shape bloodRect = Shape::Rectangle(0, 0, 800, 600, Color(255, 0, 0, 20));

	if (healthPercent < 0.5) 
	{
		Sprite blood;
		blood.SetPosition(Vector2f(800-images[BLOOD_START].GetWidth(), 0));
		blood.SetImage(images[BLOOD_START]);
		blood.SetColor(sf::Color(255, 255, 255, 60));
		window->Draw(blood);
		window->Draw(bloodRect);
	}
	if (healthPercent < 0.4) 
	{
		Sprite blood;
		blood.SetPosition(Vector2f(800-images[BLOOD_START+1].GetWidth(), 600-images[BLOOD_START+1].GetHeight()));
		blood.SetImage(images[BLOOD_START+1]);
		blood.SetColor(sf::Color(255, 255, 255, 70));
		window->Draw(blood);
		window->Draw(bloodRect);
	}
	if (healthPercent < 0.3) 
	{
		Sprite blood;
		blood.SetPosition(Vector2f(0, 0));
		blood.SetImage(images[BLOOD_START+2]);
		blood.SetColor(sf::Color(255, 255, 255, 75));
		window->Draw(blood);
		window->Draw(bloodRect);
	}
	if (healthPercent < 0.2) 
	{
		Sprite blood;
		blood.SetPosition(Vector2f(800-images[BLOOD_START+3].GetWidth(), 0));
		blood.SetImage(images[BLOOD_START+3]);
		blood.SetColor(sf::Color(255, 255, 255, 80));
		window->Draw(blood);
		window->Draw(bloodRect);
	}
	if (healthPercent < 0.1) 
	{
		Sprite blood;
		blood.SetPosition(Vector2f(50, 50));
		blood.SetImage(images[BLOOD_START+4]);
		blood.SetColor(sf::Color(255, 255, 255, 85));
		window->Draw(blood);
		window->Draw(bloodRect);
	}
}
