#pragma once
#include "gameobject.h"
#include <SDL.h>
#include <string>
#include "gameManager.h"
#include "SpriteManager.h"

 /**Button that returns "true" if clicked, contains 2 states: idle, and over.**/
class button :
	public gameObject
{
protected:

	//--images for the button to display--//
	textureImage* sprIdle;
	textureImage* sprOver;

public:
	button(int list);
	button(int list, std::string idle, std::string over);
	~button(void);

	void loadImages(std::string idle, std::string over);			//loads images for both states of the button.

	bool mouseClick(SDL_Event evt);									//returns true of false depending if the mouse was clicked.
};

