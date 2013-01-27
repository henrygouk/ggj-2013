#include "Game.h"

using namespace sf;
using namespace std;

StaticPlatform::StaticPlatform(GameScreen* gs, Vector2f pos, Vector2f dimens, string filename)
{
 	parent = gs;
	position = pos;
	velocity.x = 0;
	velocity.y = 0;
	
	if(filename != "null")
	{
		Image img;
		img.LoadFromFile(filename);
		images.push_back(img);
	
		sprite.SetCenter(dimens);
		sprite.SetImage(images[0]);
		loaded = true;
		
		dimensions = Vector2f(img.GetWidth(), img.GetHeight());
	}
	else
	{
		loaded = false;
		dimensions = dimens;
	}
}

void StaticPlatform::update()
{
	//Static it up in here
}


void StaticPlatform::draw()
{
	Vector2f topLeft = parent->normaliseCoords(position);

	if(loaded)
	{
		sprite.SetPosition(topLeft);
		window->Draw(sprite);
	}
}
