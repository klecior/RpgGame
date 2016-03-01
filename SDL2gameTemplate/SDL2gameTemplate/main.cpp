#include "program.h"

int main(int argc, char* argv[])
{
	program		newProgram;


	if(newProgram.initialise() == false)
	{
		std::cout<<"could not initialise"<<std::endl;
	}
	else
	{
		newProgram.gameLoop();
	}
	
	//clean up.
	newProgram.close();
	SDL_Quit();

	return 0;
}