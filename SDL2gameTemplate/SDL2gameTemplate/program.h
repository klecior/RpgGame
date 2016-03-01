#pragma once

#include<SDL.h>
#include<vector>
#include<iostream>

#include"constants.h"
#include"gameManager.h"
#include"SDLManager.h"

//--all of the states--//
#include"baseGameState.h"
#include "title.h"
#include "gameplay.h"
#include "help.h"
#include "gameOver.h"
#include "pause.h"
//---------------------//

//**Main class for the game, contains all of the states as well as the game loop**//
class program
{
public:
	program(void);
	~program(void);

	//--SDL2--//
	SDL_Window*		mainWindow;
	SDL_Event		evt;
	//--------//


	//--states--//
	std::vector<baseGameState*> stateHandler;

	gamePlay*		theGame;
	title*			theTitle;
	help*			theHelp;
	gameOver*		theGameOver;
	pause*			thePause;
	//----------//

	bool initialise();
	void gameLoop();
	void close();

};

