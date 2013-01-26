#include "Game.h"

using namespace std;
using namespace sf;

Background::Background(GameScreen *gs, Vector2f pos, string filename)
{
	parent = gs;
	position = pos;

	Image img;
	img.LoadFromFile(filename);
	images.push_back(img);
	
	sprite.SetImage(images[0]);
}

void Background::update()
{
	
}

void Background::draw()
{
	float x = (float)((int)parent->cameraPosition.x / window->GetWidth());
	
	sprite.SetPosition(parent->normaliseCoords(Vector2f(x * window->GetWidth(), 0.0) + position));
	window->Draw(sprite);
	
	sprite.SetPosition(parent->normaliseCoords(Vector2f((x + 1.0f) * (float)window->GetWidth() - 1.0f, 0.0f) + position));
	window->Draw(sprite);
}
