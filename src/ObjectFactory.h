#ifndef OBJECT_FACTORY_H
#define OBJECT_FACTORY_H

#include "GameObject.h"
#include "GameScreen.h"

#include <vector>
#include <string>

using namespace std;

class ObjectFactory 
{
	public:
		static void loadFile(string filename, GameScreen* gs);
};




#endif
