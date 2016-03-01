#include "gamePlay.h"


gamePlay::gamePlay(void)
{
	backButton = NULL;
}


gamePlay::~gamePlay(void)
{
	backButton = NULL;
}

void gamePlay::handleEvent(SDL_Event& evt)
{
	if(finishedLoading)
	{
		while(SDL_PollEvent(&evt))
		{
			gameManager::sharedGameManager()->handleKeyboard(evt);
			
			if(backButton->mouseClick(evt)){ gameManager::sharedGameManager()->setGameState(TITLE); }
			if(gameManager::sharedGameManager()->esc){ gameManager::sharedGameManager()->setGameState(PAUSE); }
		}
	}
}

void gamePlay::updateWorld()
{

	loadOnCreation();
	if(finishedLoading)
	{
		gameManager::sharedGameManager()->updateList(GAME);

		secondExample->setPos('x', 500);
		secondExample->setPos('y', 500);

	}
	
}

void gamePlay::updateDrawing()
{
	if(finishedLoading)
	{
		gameManager::sharedGameManager()->drawList(GAME);
		
		if (gameManager::sharedGameManager()->space)
		{
			gameManager::sharedGameManager()->drawCollisionBoxes();
		}

	}
}

void gamePlay::loadOnCreation()
{
	if(finishedLoading == false)
	{
		//LOAD STUFF HERE//

		backButton = new button(GAME,"images/template/buttons/back.png","images/template/buttons/backOver.png");
		backButton->setPos('x',1000);
		backButton->setPos('y',600);

		example = new exampleClass(GAME);
		secondExample = new exampleClass(GAME);


		finishedLoading = true;
	}
}