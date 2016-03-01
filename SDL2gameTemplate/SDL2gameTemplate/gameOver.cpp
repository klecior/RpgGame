#include "gameOver.h"


gameOver::gameOver(void)
{
}


gameOver::~gameOver(void)
{
}

void gameOver::handleEvent(SDL_Event& evt)
{
	if(finishedLoading)
	{
		while(SDL_PollEvent(&evt))
		{
			gameManager::sharedGameManager()->handleKeyboard(evt);
			
		}
	}
}

void gameOver::updateWorld()
{

	loadOnCreation();
	if(finishedLoading)
	{
		gameManager::sharedGameManager()->updateList(GAMEOVER);
	}
	
}

void gameOver::updateDrawing()
{
	if(finishedLoading)
	{
		gameManager::sharedGameManager()->drawList(GAMEOVER);
		std::cout<<"gameOver "<<std::endl;
	}
}

void gameOver::loadOnCreation()
{
	if(finishedLoading == false)
	{

		//LOAD STUFF HERE//
		finishedLoading = true;
	}
}