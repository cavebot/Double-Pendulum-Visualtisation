#include "textureManager.h"

SDL_Texture* textureManager::loadTexture(const char* texture, SDL_Renderer* renderer)
{
	SDL_Surface* tempSurface = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	return tex;
}