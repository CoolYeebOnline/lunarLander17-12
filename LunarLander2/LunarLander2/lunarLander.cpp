////////////////////////////////////////////////////////////
// File: lunarLander.cpp
// Author: Harry Oldham
// Date Created: 9/11/2019
// Brief: Lunar Lander assingment project for CT4019 
//////////////////////////////////////////////////////////// 
#include <windows.h>
#include <chrono>
#include <string>
#include "Game.h"
#include "GameObjects.h"

typedef std::chrono::steady_clock::time_point Time;
typedef std::chrono::high_resolution_clock HiResClock;
typedef std::chrono::duration<float> TimeDiff;

//Game Variables
int frameCounter = 0;
Time previousFrameTime = HiResClock::now();

int main()
{
	Game gameInstance;
	//initialises the main window 
	gameInstance.initialise();

	//initialise variables
	float deltaTime = 0.0f;

	while (!gameInstance.exitGame)
	{
		//Calculate Delta time
		Time currentFrameTime = HiResClock::now();
		TimeDiff diff = currentFrameTime - previousFrameTime;
		deltaTime = diff.count();
		frameCounter++;

		if (deltaTime >= (1.0f / FRAME_RATE))
		{
			gameInstance.update(deltaTime);
			//cache the timestamp of this frame
			previousFrameTime = currentFrameTime;
		}

		gameInstance.draw();
	}
	return 0;
}

