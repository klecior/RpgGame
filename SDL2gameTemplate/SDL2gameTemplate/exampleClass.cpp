#include "exampleClass.h"


exampleClass::exampleClass(int list)
{

	finishedLoading		= false;

	isMoving = false;

	idle	=	NULL;
	moving	=	NULL;

	position.x = 350;
	position.y = 350;
	position.w = 0;
	position.h = 0;

	objectType = "example";
	collisionBox.w = 100;
	collisionBox.h = 100;

	secondCollision.x = 0;
	secondCollision.y = 0;
	secondCollision.w = 100;
	secondCollision.h = 100;

	collisionBoxes.push_back(&secondCollision);						//pushes second collision box onto the vector list of collision boxes for the object.

	gameManager::sharedGameManager()->addToList(this,list);			//adds this object onto a selected list in the game manager.
}


exampleClass::~exampleClass(void)
{
	idle	= NULL;
	moving	= NULL;
}

//--stuff to do each frame--//
void exampleClass::update()
{
	
	loadOnCreation();

	if(finishedLoading)
	{

		controls();
		collisionControl();

		moving->loopThrough();



	}
}

//--load on creation function will always pre load everything needed by the class, before it tries to use anything--//
void exampleClass::loadOnCreation()
{
	if(finishedLoading == false)
	{

		idle	=	new textureImage();
		idle	=	SpriteManager::sharedSpriteManager()->getImage("images/template/exampleIdle.png");

		moving	=	new sequenceAnimation();
		moving	=	SpriteManager::sharedSpriteManager()->getAnimation(33,"images/template/Run/RunningSpriteSheet");

		changeImage(idle);

		finishedLoading = true;
	}
}

//--moves the object and changes it's sprite depending on movement--//
void exampleClass::controls()
{
	isMoving = false;

	if(gameManager::sharedGameManager()->up)	{ position.y--; isMoving = true; }
	if(gameManager::sharedGameManager()->down)	{ position.y++; isMoving = true; }
	if(gameManager::sharedGameManager()->left)	{ position.x--; isMoving = true; }
	if(gameManager::sharedGameManager()->right)	{ position.x++; isMoving = true; }

	if(isMoving == false){ changeImage(idle); }
	if(isMoving == true){ changeImage(moving->getCurrentFrame()); }

}

//--sets up and updates collision boxes--//
void exampleClass::collisionControl()
{
	collisionBox.x = position.x;
	collisionBox.y = position.y;

	secondCollision.x = position.x + 200;
	secondCollision.y = position.y;


	if (gameManager::sharedGameManager()->checkCollisionWith("example", collisionBox))
	{

		std::cout << "colided";
	}
}