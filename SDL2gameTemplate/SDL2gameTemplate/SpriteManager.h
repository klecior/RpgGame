#pragma once

#include "textureImage.h"
#include "sequenceAnimation.h"
#include <vector>
#include <string>
#include <fstream>

//**id Structs contains the path of an image/animation, and it's position on a vector list.**//
struct idStruct
{
	std::string name;
	unsigned int id;
};

//**Sprita Manager class is responsible for loading, and retrival of graphics from memory.**//
class SpriteManager
{
protected:

	SpriteManager();
	static SpriteManager*		 pSharedSpriteManager;

	//--lists containing the graphics--//
	std::vector<textureImage*>				imageList;
	std::vector<sequenceAnimation*>			animationList;
	//--------------------------------//

	//--lists containing the indexes--//
	std::vector<idStruct*>				idPngList;
	std::vector<idStruct*>				idAnimList;
	//-------------------------------//

	//--temporary pointers used to create new instances of graphics and indexes--//
	idStruct*			tempID;
	textureImage*		tempImage;
	sequenceAnimation*	tempAnimation;
	//---------------------------------------------------------------------------//

	//--opening and reading from a file--//
	std::stringstream stringConverter;
	std::fstream file;									
	std::string StringForStuff;							
	//----------------------------------//

	//--getting a path and number of frames(if animation) from the file--//
	std::string filePath;
	unsigned int framesAmount;
	//-------------------------------------------------------------------//

	//--used to fill with junk data--//
	char	tempChar;	

public:

	static SpriteManager*	sharedSpriteManager();

	//--returns pointer to image from memory--//
	textureImage*			getImage(std::string path);

	//--returns pointer to animation from memory--//
	sequenceAnimation*		getAnimation(unsigned int frames, std::string path);

	//--reads and loads images and animation from a file--//
	void	initializeFromFile(std::string path);
	void	freeMemory();


};

