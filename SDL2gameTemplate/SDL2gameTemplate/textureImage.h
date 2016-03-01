#pragma once

#include <SDL_image.h>
#include <string>
#include <iostream>
#include "SDLManager.h"

//**textureImage class loads an image in any format supported by SDL_image, and creates a texture out of it.**//
class textureImage
{
protected:

	SDL_Texture*	texture;
	SDL_Rect		offset;

public:
	textureImage(void);
	~textureImage(void);

	void draw();								
	bool loadTexture(std::string path);

	void free();

	SDL_Texture* getTexture();
	SDL_Rect	 getOffset();

};

