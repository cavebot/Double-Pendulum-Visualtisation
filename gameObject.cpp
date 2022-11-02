#include "include/gameObject.h"
#include "include/textureManager.h"

gameObject::gameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y)
{
	renderer = ren;
	objectTexture = textureManager::loadTexture(texturesheet, ren);

	xpos = x;
	ypos = y;
}

void gameObject::update()
{
	xpos++;
	ypos++;

	sourceRect.h = 32;
	sourceRect.w = 32;
	sourceRect.x = 0;
	sourceRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = sourceRect.w * 2;
	destRect.h = sourceRect.h * 2;

}

void gameObject::render()
{
	SDL_RenderCopy(renderer, objectTexture, NULL, &destRect);
}