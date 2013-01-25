#include <iostream>

using namespace std;

bool running;

int main(int argc, char **argv)
{
	//Set running to true so the game loop does something
	running = true;
	
	//Init various things that need initing
	initialise();
	
	//The game loop
	while(true)
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

}

//Clean up resources
void cleanup()
{

}

//Update game logic
void update()
{

}

//Draw the world
void draw()
{

}
