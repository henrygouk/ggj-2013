#include "Game.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;
using namespace sf;

void ObjectFactory::loadFile(string filename, GameScreen* gs)
{
	fstream fIn (filename.c_str(), fstream::in);

	if (!fIn.is_open()) {
		cout << "ERROR: could not open level file (" << filename << ")" << endl;
		exit(0);
		}

	int count;
	fIn >> count;

	char name[256];
	int x;
	int y;
	for (int i = 0; i < count; i++) {
		fIn >> name;
		fIn >> x;
		fIn >> y;
	
		if (strcmp("player", name) == 0) {
			gs->gameObjects.push_back(new PlayerObject(gs, Vector2f(x, y)));		
			continue;
			}

		if (strcmp("movingplatform", name) == 0) {
			int width, height;
			float xend, yend, speed;
			fIn >> width;
			fIn >> height;
			fIn >> xend;
			fIn >> yend;
			fIn >> speed;

			gs->gameObjects.push_back(new MovingPlatform(gs, Vector2f(x, y), Vector2f(width, height), Vector2f(xend, yend), speed));
			continue;
			}

		if (strcmp("staticplatform", name) == 0) {
			int width, height;
			fIn >> width;
			fIn >> height;
			gs->gameObjects.push_back(new StaticPlatform(gs, Vector2f(x, y), Vector2f(width, height)));
			continue;
			}
			
		if (strcmp("enemy", name) == 0) {
			int x2, y2;
			fIn >> x2;
			fIn >> y2;
			gs->gameObjects.push_back(new Enemy(gs, Vector2f(x, y), Vector2f(x2, y2)));
			continue;
			}
			
		if (strcmp("background", name) == 0) {
			string filename;
			float opacity;
			fIn >> filename;
			fIn >> opacity;
			gs->gameObjects.push_back(new Background(gs, Vector2f(x, y), filename, opacity));
			continue;
			}
		}

	fIn.close();
}
