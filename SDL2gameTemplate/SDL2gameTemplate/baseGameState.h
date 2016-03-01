#pragma once

#include <SDL.h>
#include"gameManager.h"
#include"constants.h"
#include"gameObject.h"
#include"textureImage.h"

//**baseGameState class is a class that all the other game states inherit from.**//
class baseGameState
{
protected:

	bool finishedLoading;
	virtual void loadOnCreation();

public:
	baseGameState(void);
	~baseGameState(void);

	virtual void handleEvent(SDL_Event& evt);
	virtual void updateDrawing();
	virtual void updateWorld();

};

