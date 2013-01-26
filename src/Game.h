#ifndef GAME_H
#define GAME_H

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>

#include "GameScreen.h"
#include "GameObject.h"
#include "PlayerObject.h"
#include "Platform.h"
#include "StaticPlatform.h"
#include "MovingPlatform.h"
#include "Enemy.h"
#include "Background.h"
#include "ObjectFactory.h"
#include "HealthBar.h"
#include "BloodFart.h"
#include "BloodSquirt.h"
#include "BloodContact.h"
#include "PitObject.h"
#include "HealthPack.h"

#define GRAVITY 4.81f
#define JUMP_STRENGTH -2.5f
#define SPEED 200.0f
#define DELTA_TIME (float)window->GetFrameTime()
#define FRICTION 4.0
#define ASSETS_FOLDER "assets/"

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
