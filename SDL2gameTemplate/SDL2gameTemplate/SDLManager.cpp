#include "SDLManager.h"

SDLManager*	SDLManager::pSharedSDLManager = NULL;

SDLManager::SDLManager(void)
{
}


SDLManager::~SDLManager(void)
{
}

SDLManager* SDLManager::sharedSDLManager()
{	
	if(pSharedSDLManager == NULL){pSharedSDLManager = new SDLManager();}
	return pSharedSDLManager;
}