#pragma once

#include <vector>
#include "textureImage.h"
#include <iostream>
#include <string>
#include <sstream>

//**Sequence animation class loads multiple images and saves them as frames of animation.**//
class sequenceAnimation
{
protected:

	std::stringstream	stringConverter;							//used to construct a full path for each of the frames automatically.			
	textureImage*		tempImage;

public:
	sequenceAnimation(void);
	~sequenceAnimation(void);

	//--frames--//
	unsigned int framesAmount;
	unsigned int currentFrame;							

	std::vector<textureImage*> frames;								//vector list holding paths to all of the frames.
	//----------//

	bool loadSequence(unsigned int amount, std::string path);		//loads the frames.
	void loopThrough();												//loops through the animation, rarely used.

	textureImage* getCurrentFrame();								//gets the current frame of the animation.
	textureImage* getFrame(unsigned int frameNumber);				//gets the specyfic frame.

};

