#pragma once
#include "basegamestate.h"
#include "constants.h"

#include "textureImage.h"
#include "button.h"

class pause :
	public baseGameState
{
protected:

	void loadOnCreation();

	button* backButton;

public:
	pause(void);
	~pause(void);

	void handleEvent(SDL_Event& evt);
	void updateDrawing();
	void updateWorld();
};

