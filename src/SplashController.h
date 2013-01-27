#ifndef SPLASHCONTROLLER_H
#define SPLASHCONTROLLER_H

#include "Game.h"

class SplashController : public GameObject
{
	public:
		SplashController(int end);
		void update();
		void draw();

		bool countDownDoStuff;
		float doStuffDelay;
		bool isFinallyEnd;

};


#endif
