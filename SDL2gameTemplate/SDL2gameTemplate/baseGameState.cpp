#include "baseGameState.h"


baseGameState::baseGameState(void)
{
	finishedLoading		=	false;
}


baseGameState::~baseGameState(void)
{
}


void baseGameState::handleEvent(SDL_Event& evt)
{
	while(SDL_PollEvent(&evt))
	{
		gameManager::sharedGameManager()->handleKeyboard(evt);
	}
}

void baseGameState::updateWorld()
{

}

void baseGameState::updateDrawing()
{

}

void baseGameState::loadOnCreation()
{

}