
#include "Game.h"

float StaticPlatform::top() 
{
	return position.y;
}

float StaticPlatform::left()
{
	return position.x;
}

float StaticPlatform::right() 
{
	return position.x + dimensions.x;
}
