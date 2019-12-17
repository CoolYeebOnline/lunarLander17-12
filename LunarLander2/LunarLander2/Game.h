#ifndef GAME_H
#define GAME_H

//includes
#include <Windows.h>
#include "GameObjects.h"


class Game
{
public:
	//functions
	Game();
	void initialise();
	void update(float deltaTime);
	void draw();
	bool exitGame = false;

private:
	//ENUMS
	enum GAME_STATE {
		SPLASH,
		MENU,
		PLAY,
		OPTIONS,
		GAME_OVER,
	};
	//console variables 
	//window size coordinates, ensures it starts at 0
	SMALL_RECT windowSize{ 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1 };

	//coord struct for specifying the screen buffer's dimensions 
	COORD buffersize = { SCREEN_WIDTH, SCREEN_HEIGHT };
	CONSOLE_SCREEN_BUFFER_INFO SBInfo;

	//setting up different variables for passing to WriteConsoleOutput
	COORD characterBufferSize = { SCREEN_WIDTH, SCREEN_HEIGHT };
	COORD characterPosition = { 0,0 };
	SMALL_RECT consoleWriteArea = { 0,0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1 };

	//a CHAR_INFO structure containing info about our frame 
	CHAR_INFO consoleBuffer[SCREEN_WIDTH * SCREEN_HEIGHT];

	//initialise handles 
	HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE rHnd = GetStdHandle(STD_INPUT_HANDLE);

	//game variables
	GAME_STATE currentGameState = SPLASH;
	Player player;
	Background background;
	

};
#endif //!GAME_H
