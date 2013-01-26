#ifndef HEALTHBAR_H 
#define HEALTHBAR_H

#include "Game.h"

class HealthBar : public GameObject
{
	private:
		HealthBar(GameScreen* gs, sf::Vector2f pos, int _maxHealth);

	public:
		static HealthBar* createHealthBar(GameScreen* gs, sf::Vector2f pos, int _maxHealth);
		static HealthBar* getHealthBar();
		void update();
		void draw();
		void setHealthTo(float h);
		void addHealth(float h);


		float maxHealth;
		float currentHealth;
		float targetHealth;

		static HealthBar* ref;

};

#endif
