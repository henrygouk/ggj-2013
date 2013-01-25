#ifndef GAME_H
#define GAME_H

#include "GameScreen.h"
#include "GameObject.h"
#include "PlayerObject.h"

#include <SFML/Graphics.hpp>
#include <glm/glm.hpp>

#include <cstddef>
#include <vector>

extern bool running;
extern std::vector<GameScreen *> gameScreens;
extern sf::RenderWindow *window;

void initialise();
void cleanup();
void update();
void draw();

#endif
