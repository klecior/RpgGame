#pragma once

#include "basegamestate.h"
#include "constants.h"

#include "gameObject.h"
#include "textureImage.h"

#include "button.h"

class title :
	public baseGameState
{
protected:

	void loadOnCreation();

	button*	startButton;
	button* helpButton;
	button* quitButton;

public:
	title(void);
	~title(void);

	void handleEvent(SDL_Event& evt);
	void updateDrawing();
	void updateWorld();

};

