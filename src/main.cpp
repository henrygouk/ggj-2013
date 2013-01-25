#include "Game.h"

#include <SFML/Graphics.hpp>

using namespace std;

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
	window = new sf::RenderWindow(sf::VideoMode(800, 600, 32), "Orangeyness");
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
		if(event.Type == sf::Event::Closed)
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
}
