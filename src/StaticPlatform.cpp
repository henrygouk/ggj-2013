#include "Game.h"

using namespace sf;

StaticPlatform::StaticPlatform(GameScreen* gs, Vector2f pos, Vector2f dimens)
{
 	parent = gs;
	position = pos;
	dimensions = dimens;
	velocity.x = 0;
	velocity.y = 0;
	
	Image img;
	img.LoadFromFile("assets/Stretcher.png");
	images.push_back(img);
	
	if(dimens.y = 150.0)
	{
		sprite.SetCenter(0, 35);
	}
	
	sprite.SetImage(images[0]);
}

void StaticPlatform::update()
{
	//Static it up in here
}


void StaticPlatform::draw()
{
	Vector2f topLeft = parent->normaliseCoords(position);
	/*Vector2f bottomRight = parent->normaliseCoords(position + dimensions);

	Shape rect = Shape::Rectangle(topLeft.x, topLeft.y, bottomRight.x, bottomRight.y,
								  Color(255, 255, 255, 255));*/
	
	if(dimensions.y > 0)
	{
		sprite.SetPosition(topLeft);
		window->Draw(sprite);
	}

//	window->Draw(rect);
}
