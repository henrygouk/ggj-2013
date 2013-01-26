#ifndef GAME_H
#define GAME_H

#include <algorithm>
#include <cstddef>
#include <vector>

#include <SFML/Graphics.hpp>

#include "GameScreen.h"
#include "GameObject.h"
#include "PlayerObject.h"
#include "Platform.h"
#include "StaticPlatform.h"
#include "MovingPlatform.h"
#include "Enemy.h"
#include "ObjectFactory.h"

#define GRAVITY 4.81f
#define JUMP_STRENGTH -2.0f
#define SPEED 200.0f
#define DELTA_TIME (float)window->GetFrameTime()
#define FRICTION 4.0

extern bool running;
extern std::vector<GameScreen *> gameScreens;
extern sf::RenderWindow *window;

void initialise();
void cleanup();
void update();
void draw();

float dot(const sf::Vector2f &v1, const sf::Vector2f &v2);
sf::Vector2f unit(const sf::Vector2f &v);

#endif
