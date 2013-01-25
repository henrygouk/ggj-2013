#ifndef GAME_H
#define GAME_H

#include <cstddef>
#include <vector>

#include <SFML/Graphics.hpp>

#include "GameScreen.h"
#include "GameObject.h"
#include "PlayerObject.h"
#include "ObjectFactory.h"

extern bool running;
extern std::vector<GameScreen *> gameScreens;
extern sf::RenderWindow *window;

void initialise();
void cleanup();
void update();
void draw();

#endif
