#pragma once
#include "basegamestate.h"
#include "constants.h"

class gameOver :
	public baseGameState
{
protected:

	void loadOnCreation();

public:
	gameOver(void);
	~gameOver(void);

	void handleEvent(SDL_Event& evt);
	void updateDrawing();
	void updateWorld();

};

