#include "program.h"


program::program(void)
{

	mainWindow		=	NULL;

}


program::~program(void)
{
}


bool program::initialise()
{

	gameManager::sharedGameManager()->setGameState(TITLE);

	bool success = true;	//success flag

	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout<<"failed to initialise, SDL Error: "<<SDL_GetError()<<std::endl;
		success = false;
	}
	else
	{
		//create main window.
		mainWindow = SDL_CreateWindow("TempName",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
		if(mainWindow == NULL)
		{
			std::cout<<"window could not be created: "<<SDL_GetError()<<std::endl;
			success = false;
		}
		else
		{
			//create main renderer.
			SDLManager::sharedSDLManager()->mainRenderer = SDL_CreateRenderer(mainWindow,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	
			if(SDLManager::sharedSDLManager()->mainRenderer == NULL)
			{
				std::cout<<"renderer could not be created: "<<SDL_GetError()<<std::endl;
				success = false;
			}
			else
			{
				//set color to white
				SDL_SetRenderDrawColor(SDLManager::sharedSDLManager()->mainRenderer,0xFF,0xFF,0xFF,0xFF);

				//--creating states--//
				stateHandler.push_back(theTitle		= new title()		);
				stateHandler.push_back(theGame		= new gamePlay()	);
				stateHandler.push_back(theHelp		= new help()		);
				stateHandler.push_back(theGameOver	= new gameOver()	);
				stateHandler.push_back(thePause		= new pause()		);
				//-------------------//
			}
		}
	}
	return success;
}

void program::gameLoop()
{
	while(gameManager::sharedGameManager()->isRunning == true)
	{
		//--reset the window--//
		SDL_SetRenderDrawColor(SDLManager::sharedSDLManager()->mainRenderer,0xFF,0xBB,0xFF,0xFF);
		SDL_RenderClear(SDLManager::sharedSDLManager()->mainRenderer);
		//--------------------//

		//--State handling--//
		stateHandler[gameManager::sharedGameManager()->getGameState()]->handleEvent(evt);
		stateHandler[gameManager::sharedGameManager()->getGameState()]->updateWorld();
		stateHandler[gameManager::sharedGameManager()->getGameState()]->updateDrawing();
		//--State handling--//
		
		//--Draw current screen, same function as previously SDL_Flip()--//
		SDL_RenderPresent(SDLManager::sharedSDLManager()->mainRenderer);
		
		gameManager::sharedGameManager()->regulateFrameRate();
		gameManager::sharedGameManager()->sweep();

	}
}

void program::close()
{

	SDL_DestroyWindow(mainWindow);
	mainWindow		=	NULL;

	SDL_DestroyRenderer(SDLManager::sharedSDLManager()->mainRenderer);
	SDLManager::sharedSDLManager()->mainRenderer	=	NULL;

	delete theTitle;
	delete theGameOver;
	delete theHelp;
	delete theGame;
	delete thePause;

	theTitle	= NULL;
	theGameOver = NULL;
	theHelp		= NULL;
	theGame		= NULL;
	thePause	= NULL;

}