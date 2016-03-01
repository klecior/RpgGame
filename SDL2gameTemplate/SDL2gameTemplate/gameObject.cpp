#include "gameObject.h"


gameObject::gameObject(void)
{

	displayImage	=	NULL;

	position.x		=	0;
	position.y		=	0;
	position.w		=	0;
	position.h		=	0;

	collisionBox	=	position;
	collisionBoxes.push_back(&collisionBox);

	alive			=	true;

	objectType		=	"";
}


gameObject::~gameObject(void)
{

	displayImage->free();
	displayImage = NULL;

}

//--setters and getters--//

void gameObject::setPos(char pos, int newPos)
{
	if     (pos == 'x') { position.x = newPos; }
	else if(pos == 'y')	{ position.y = newPos; }
	else if(pos == 'w') { position.w = newPos; }
	else if(pos == 'h') { position.h = newPos; }
	else
	{
		std::cout<<"could not set new position, only possible variables are 'x,y,w,h' "<<std::endl;
	}
}

SDL_Rect gameObject::getPosition(){ return position; }
bool gameObject::getAlive(){ return alive; }
//--endOf setters and getters--//

//--changes the current image to the one provided--//
void gameObject::changeImage(textureImage* image)
{
	displayImage = image;
	position.w	 = image->getOffset().w;
	position.h   = image->getOffset().h;
}

//--loads a new image through the spriteManager--//
void gameObject::setImage(std::string path)
{
	displayImage = SpriteManager::sharedSpriteManager()->getImage(path);
	position.w  = displayImage->getOffset().w;
	position.h  = displayImage->getOffset().h;
}

//--basic render--//
void gameObject::draw()
{
	SDL_RenderCopy(SDLManager::sharedSDLManager()->mainRenderer,displayImage->getTexture(),NULL,&position);
}

//--empty update, inherited objects will implement it on their own--//
void gameObject::update()
{

}

//--draws all of the collision boxes--//
void gameObject::drawCollisionBox()
{

	//--Change color--//
	SDL_SetRenderDrawColor(SDLManager::sharedSDLManager()->mainRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

	//--draws every collision box in the object--//
	for (int i = 0; i < collisionBoxes.size(); i++)
	{

		//--Draw the rect--//
		SDL_RenderDrawRect(SDLManager::sharedSDLManager()->mainRenderer, collisionBoxes[i]);
	}
}

//--checks the collision between the boxes provided--//
bool gameObject::collisionWith(SDL_Rect* positions, SDL_Rect* currentBox)
{
	//--collision on x--/
	if ((currentBox->x > positions->x && currentBox->x < positions->x + positions->w) || (currentBox->x + currentBox->w > positions->x  && currentBox->x + currentBox->w < positions->x + positions->w))
	{
		//--collision on y--//
		if ((currentBox->y > positions->y && currentBox->y < positions->y + positions->h) || (currentBox->y + currentBox->h > positions->y && currentBox->y + currentBox->h < positions->y + currentBox->h))
		{

			return true;
		}
	}
	return false;
}
