#ifndef HEALTHBAR_H 
#define HEALTHBAR_H

#include "Game.h"

class HealthBar : public GameScreen
{
	private:
		HealthBar(sf::Vector2f pos, int _maxHealth);

	public:
		static HealthBar* createHealthBar(sf::Vector2f pos, int _maxHealth);
		static HealthBar* getHealthBar();
		void update();
		void draw();
		void setHealthTo(float h);
		void addHealth(float h);

		float maxHealth;
		float currentHealth;
		float targetHealth;

		static HealthBar* ref;

		sf::Vector2f position;
		sf::Sprite sprite;
		std::vector<sf::Image> images;

};

#endif
