#pragma once
#include "basegamestate.h"
#include "constants.h"

#include "exampleClass.h"
#include "button.h"

class gamePlay :
	public baseGameState
{
protected:

	void loadOnCreation();

	button* backButton;

	exampleClass* example;
	exampleClass* secondExample;

public:
	gamePlay(void);
	~gamePlay(void);

	
	void handleEvent(SDL_Event& evt);
	void updateDrawing();
	void updateWorld();

};

