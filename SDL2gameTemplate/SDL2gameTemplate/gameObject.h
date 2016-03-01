#pragma once

#include <SDL.h>
#include "textureImage.h"
#include <vector>
#include "SpriteManager.h"

//**gameObject class is the main base level object with common functionality. Most other object inherit from it.**//
class gameObject
{
protected:

	SDL_Rect		position;
	textureImage*	displayImage;
	bool			alive;

public:

	gameObject(void);
	virtual ~gameObject(void);					//virtual destructor will cause the derived object destructor to be called.

	//--setters and getters--//
	void setPos(char pos, int newPos);			//in the set pos function, you can select between 4 variables (x,y,w,h), and set them. I done it this way in order to avoid having 4 different functions for setters.
	SDL_Rect getPosition();
	bool getAlive();
	//----------------------//

	std::string objectType;						//used to label the type of object it is. Usefull for filtering.

	virtual void draw();
	virtual void update();

	void changeImage(textureImage* image);		//changes the image and position rect.
	void setImage(std::string path);			//loads a new image.

	//--collision boxes and their drawing--//
	//--every object has at least one collision box by default--//
	SDL_Rect	collisionBox;
	std::vector<SDL_Rect*> collisionBoxes;

	void drawCollisionBox();
	bool collisionWith(SDL_Rect* positions, SDL_Rect* currentBox);
	//------------------------------------//


};


