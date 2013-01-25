#ifndef GAME_H
#define GAME_H

#include "GameScreen.h"
#include "GameObject.h"

#include <vector>

extern bool running;
std::vector<GameScreen *> gameScreens;

void initialise();
void cleanup();
void update();
void draw();

#endif
