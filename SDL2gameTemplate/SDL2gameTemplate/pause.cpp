#include "pause.h"


pause::pause(void)
{
	backButton = NULL;
}


pause::~pause(void)
{
	backButton = NULL;
}

void pause::handleEvent(SDL_Event& evt)
{
	if(finishedLoading)
	{
		while(SDL_PollEvent(&evt))
		{
			gameManager::sharedGameManager()->handleKeyboard(evt);
			
			if(backButton->mouseClick(evt)){ gameManager::sharedGameManager()->setGameState(GAME); }

		}
	}
}

void pause::updateWorld()
{

	loadOnCreation();
	if(finishedLoading)
	{
		gameManager::sharedGameManager()->updateList(PAUSE);
	}
	
}

void pause::updateDrawing()
{
	if(finishedLoading)
	{
		gameManager::sharedGameManager()->drawList(PAUSE);

	}
}

void pause::loadOnCreation()
{
	if(finishedLoading == false)
	{
		//LOAD STUFF HERE//

		backButton = new button(PAUSE,"images/template/buttons/back.png","images/template/buttons/backOver.png");
		backButton->setPos('x',( SCREEN_WIDTH / 2) - ( backButton->getPosition().w / 2 ) );
		backButton->setPos('y', 550);

		finishedLoading = true;
	}
}