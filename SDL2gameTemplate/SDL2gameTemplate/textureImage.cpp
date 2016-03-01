#include "textureImage.h"


textureImage::textureImage(void)
{
	texture		= NULL;

	offset.x	= 0;
	offset.y	= 0;
	offset.w	= 0;
	offset.h	= 0;
}


textureImage::~textureImage(void)
{
	free();
}

void textureImage::free()
{
	if(texture != NULL)
	{
		SDL_DestroyTexture(texture);
		texture = NULL;
		offset.w = 0;
		offset.h = 0;
	}
}

bool textureImage::loadTexture(std::string path)
{

	free();
	bool success = true;
	
	//load image
	SDL_Surface*	loadSurface = IMG_Load(path.c_str());
	if(loadSurface == NULL)
	{
		std::cout<<"Unable to load Image "<<path.c_str()<<" SDL_Error: "<<SDL_GetError()<<std::endl;
		success = false;
	}
	else
	{

		texture = SDL_CreateTextureFromSurface(SDLManager::sharedSDLManager()->mainRenderer,loadSurface);
		if(texture == NULL)
		{
			std::cout<<"Unable to create texture from: "<<path.c_str()<<" SDL_Error: "<<SDL_GetError()<<std::endl;
			success = false;
		}
		else
		{
			offset.x = 0;
			offset.y = 0;
			offset.w = loadSurface->w;
			offset.h = loadSurface->h;
		}
		//delete old surface
		SDL_FreeSurface(loadSurface);
	}

	return success;
}

void textureImage::draw()
{
	SDL_RenderCopy(SDLManager::sharedSDLManager()->mainRenderer,texture,NULL,&offset);
}

SDL_Texture* textureImage::getTexture()
{
	return texture;
}

SDL_Rect textureImage::getOffset()
{
	return offset;
}