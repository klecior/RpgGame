#include "button.h"

//--Creates a button with one, state containing temporary 'x' image--//
button::button(int list)
{

	sprIdle = SpriteManager::sharedSpriteManager()->getImage("images/temp/X.png");
	displayImage = sprIdle;

	position.x = 0;
	position.y = 0;
	position.w = 0;
	position.h = 0;

	gameManager::sharedGameManager()->addToList(this,list);

}

//--Creates a button and loads both of the states straight away. Lowers the amount of code required later--//
button::button(int list, std::string idle, std::string over)
{

	sprIdle = SpriteManager::sharedSpriteManager()->getImage(idle.c_str());
	sprOver = SpriteManager::sharedSpriteManager()->getImage(over.c_str());

	displayImage = sprIdle;

	position.x = 0;
	position.y = 0;
	position.w = sprIdle->getOffset().w;
	position.h = sprIdle->getOffset().h;

	gameManager::sharedGameManager()->addToList(this,list);
}


button::~button(void)
{
	displayImage = NULL;
	sprIdle		 = NULL;
	sprOver		 = NULL;
}


//--loads images for both states--//
void button::loadImages(std::string idle, std::string over)
{
	//--loads images--//
	//--images are loaded through the sprite manager, because it's more efficient this way--//
	sprIdle = SpriteManager::sharedSpriteManager()->getImage(idle.c_str());
	sprOver = SpriteManager::sharedSpriteManager()->getImage(over.c_str());
	//---------------//

	//--fills the width and height, used when centering the object--//
	position.w = sprIdle->getOffset().w;
	position.h = sprIdle->getOffset().h;
	//------------------------------------//

}

//--returns true or false depending on if the button was clicked--//
bool button::mouseClick(SDL_Event evt)
{

	//--sets default sprite if there is no collision--//
	displayImage = sprIdle;

		//--x collision--//
		if(evt.button.x > getPosition().x && evt.button.x < (getPosition().x + getPosition().w) )
		{
			//y collision--//
			if(evt.button.y > getPosition().y && evt.button.y < (getPosition().y +getPosition().h) )
			{
				
				//--change the image to an different one--//
				displayImage = sprOver;

				//--if left mouse button was clicked while it was colliding, return true--//
				if(evt.type == SDL_MOUSEBUTTONDOWN && evt.button.button == SDL_BUTTON_LEFT)
				{
					return true;
				}
			}
		}
	//--if the mouse was not clicked on the button, return false--//
	return false;
}
