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
			string filename;
			fIn >> width;
			fIn >> height;
			fIn >> xend;
			fIn >> yend;
			fIn >> speed;
			fIn >> filename;

			gs->gameObjects.push_back(new MovingPlatform(gs, Vector2f(x, y), Vector2f(width, height), Vector2f(xend, yend), speed, filename));
			continue;
			}

		if (strcmp("staticplatform", name) == 0) {
			int width, height;
			string filename;
			fIn >> width;
			fIn >> height;
			fIn >> filename;
			gs->gameObjects.push_back(new StaticPlatform(gs, Vector2f(x, y), Vector2f(width, height), filename));
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
			
		if (strcmp("pit", name) == 0) {
			int x2, y2;
			fIn >> x2;
			fIn >> y2;
			gs->gameObjects.push_back(new PitObject(gs, Vector2f(x, y), Vector2f(x2, y2)));
			continue;
			}
			
		if (strcmp("healthpack", name) == 0) {
			gs->gameObjects.push_back(new HealthPack(gs, Vector2f(x, y), true));
			continue;
			}
			
		if (strcmp("uberpack", name) == 0) {
			gs->gameObjects.push_back(new HealthPack(gs, Vector2f(x, y), false));
			continue;
			}
		}

	fIn.close();
}
