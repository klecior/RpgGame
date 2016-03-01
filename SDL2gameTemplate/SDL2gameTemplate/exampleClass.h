#pragma once
#include "gameobject.h"
#include "gameManager.h"
#include "sequenceAnimation.h"

//** this class is just an example, and a refresher showing how to use the rest of the template**//
class exampleClass :
	public gameObject
{
protected:

	//--different states for the actual object--//
	textureImage*	idle;
	sequenceAnimation* moving;
	//------------------------------------------//

	SDL_Rect		secondCollision;		//testing multiple collision boxes.

	bool finishedLoading;					//makes sure it loads all the assets only once.
	bool isMoving;							//used to determine the state/actions of the object.
	
	void loadOnCreation();					//load on creation function is used to avoid loading assets through the constructor, as it often creates further problems.
	void controls();						//controls for the object.
	void collisionControl();				//sets up and updates the collision boxes.

public:
	exampleClass(int list);
	~exampleClass(void);

	void update();

};

