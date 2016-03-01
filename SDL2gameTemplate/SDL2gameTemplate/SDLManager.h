#pragma once

#include <iostream>
#include "constants.h"
#include <SDL.h>

//**SDLManager class is responsible for renderers and possibly windows. It is used in order to avoid unnecessarily complex parameter passing trees. This class should also be where multiple windows would go.**//
class SDLManager
{
protected:

	SDLManager(void);
	static SDLManager*	pSharedSDLManager;

public:

	~SDLManager(void);

	static SDLManager*	sharedSDLManager();

	SDL_Renderer*		mainRenderer;

};

