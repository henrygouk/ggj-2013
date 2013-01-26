#include "Game.h"
using namespace sf;

float Platform::top() 
{
	return position.y;
}

float Platform::left()
{
	return position.x;
}

float Platform::right() 
{
	return position.x + dimensions.x;
}
