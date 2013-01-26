#include "Game.h"
#include "ObjectFactory.h"

using namespace std;
using namespace sf;

bool running;
vector<GameScreen *> gameScreens;
sf::RenderWindow *window;

int main(int argc, char **argv)
{
	//Set running to true so the game loop does something
	running = true;
	
	//Init various things that need initing
	initialise();
	
	//The game loop
	while(running)
	{
		//Update and draw
		update();
		draw();
	}
	
	//Clean up
	cleanup();

	return 0;
}

//Initialise things that need something done at startup
void initialise()
{
	window = new sf::RenderWindow(sf::VideoMode(800, 600, 32), "Orangeyness", sf::Style::Fullscreen); 
	
	///HACKHACKHACK
	gameScreens.push_back(new GameScreen());
	gameScreens.push_back(new GameScreen());
	gameScreens.push_back(HealthBar::createHealthBar(Vector2f(10, 10), 100));

	string str1 ("assets/lvl1.txt");
	string str2 ("assets/ash.txt");
	ObjectFactory::loadFile(str1, gameScreens[0]);
	ObjectFactory::loadFile(str2, gameScreens[1]);
}

//Clean up resources
void cleanup()
{
	window->Close();
	delete window;
}

//Update game logic
void update()
{
	//Process events
	sf::Event event;

	while(window->GetEvent(event))
	{
		if(event.Type == Event::Closed || (event.Type == Event::KeyPressed && event.Key.Code == Key::Escape))
			running = false;
	}

	for(size_t i = 0; i < gameScreens.size(); i++)
	{
		gameScreens[i]->update();
	}
}

//Draw the world
void draw()
{
	window->Clear();

	for(size_t i = 0; i < gameScreens.size(); i++)
	{
		gameScreens[i]->draw();
	}
	
	window->Display();
	
	//window->Capture().SaveToFile("screenshot.png");
}

float dot(const Vector2f &v1, const Vector2f &v2)
{
	return v1.x * v2.x + v1.y * v2.y;
}

Vector2f unit(const Vector2f &v)
{
	return v * (1.0f / sqrtf(dot(v, v)));
}
