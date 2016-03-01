#include "sequenceAnimation.h"


sequenceAnimation::sequenceAnimation(void)
{

	framesAmount	= 0;
	currentFrame	= 0;

	tempImage		= NULL;

}


sequenceAnimation::~sequenceAnimation(void)
{

	tempImage->free();
	delete tempImage;
	tempImage = NULL;

	for(unsigned int i = 0; i < frames.size(); i++)
	{
		frames[i]->free();
		delete frames[i];
		frames[i] = NULL;
	}

	frames.clear();

}

//--loads the amount of frames you ask it too, from the path provided--//
bool sequenceAnimation::loadSequence(unsigned int amount, std::string path)
{

	bool success = true;

	//--creates strings used to construct, and store the final path to the image frame--//
	std::string providedPath = path;
	std::string finalPath;

	//--sets the amount of frames in the animation to the amount provided--//
	framesAmount = amount;

	//--loops through for the amount of frames provided--//
	for(int i = 0; i < amount; i++)
	{
		//--clears the path constructor--//
		stringConverter.clear();

		//--clears the finalPath so it's ready for next image--//
		finalPath.clear();


		//--Assembling of the path--//
		//--if the frame is less than 10, insert three zeros in front of it--//
		if(i + 1 < 10){stringConverter << providedPath << 0 << 0 << 0 << (i + 1) << ".png";}
		//--if the frame is above 10, but less than 100, insert two zeros in front of it--//
		if(i + 1 >9 && i +1 < 100){stringConverter << providedPath << 0 << 0 << (i + 1) << ".png";}
		
		//--puts the final path onto a string--//
		stringConverter >> finalPath;
		
	
		//--creates a new image, loads it from current final path, and pushes it onto a vector list--//
		tempImage = new textureImage();
		tempImage->loadTexture(finalPath);
		//if(tempImage->getTexture() == NULL)
		//{
		//	std::cout<<"could not load the sequence image: "<<finalPath<<std::endl;
		//	success = false;
		//}

		frames.push_back(tempImage);
		//-------------------------------------------------------------------------------------------//
		tempImage = NULL;
	
	}
	return success;
}

void sequenceAnimation::loopThrough()
{

	if(currentFrame < frames.size()-1)
	{
		currentFrame++;
	}
	else
	{
		currentFrame = 0;
	}

}

textureImage* sequenceAnimation::getCurrentFrame()
{
	return frames[currentFrame];
}

textureImage* sequenceAnimation::getFrame(unsigned int frameNumber)
{
	return frames[frameNumber];
}