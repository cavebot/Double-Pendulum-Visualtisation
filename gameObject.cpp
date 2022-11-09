#include "include/gameObject.h"
#include "include/textureManager.h"

using namespace std;

gameObject::gameObject(const char* texturesheet, int x, int y)
{
	objectTexture = textureManager::loadTexture(texturesheet);

	xpos = x;
	ypos = y;
}

void gameObject::update(int xnew, int ynew)
{

	xpos = xnew;
	ypos = ynew;

	sourceRect.h = 32;
	sourceRect.w = 32;
	sourceRect.x = 0;
	sourceRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = sourceRect.w *0.5 +1;
	destRect.h = sourceRect.h *0.5 +1;
}

void gameObject::render()
{
	SDL_RenderCopy(game::renderer, objectTexture, NULL, &destRect);

}





////////////////////////////////static object//////////////////////////////////



gameObjectStatic::gameObjectStatic(const char* texturesheet, int x, int y)
{
	objectTexture = textureManager::loadTexture(texturesheet);

	xpos = x;
	ypos = y;
}

void gameObjectStatic::update()
{

	sourceRect.h = 3;
	sourceRect.w = 100;
	sourceRect.x = 0;
	sourceRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = sourceRect.w ;
	destRect.h = sourceRect.h ;
}

void gameObjectStatic::render(double angle)
{

	SDL_Point pt;
	pt.x = 1;
	cout << pt.x << endl;
	pt.y = 0;
	
	SDL_RenderCopyEx(game::renderer, objectTexture, NULL, &destRect, angle, &pt, SDL_FLIP_NONE);
}


















objectPoint2::objectPoint2(const char* texturesheet, int x, int y)
{
	objectTexture = textureManager::loadTexture(texturesheet);

	xpos = x;
	ypos = y;
}

void objectPoint2::update()
{


	//xpos++;
	//ypos++;

	sourceRect.h = 32;
	sourceRect.w = 32;
	sourceRect.x = 0;
	sourceRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = sourceRect.w * 2;
	destRect.h = sourceRect.h * 2;
}

void objectPoint2::render()
{
	SDL_RenderCopy(game::renderer, objectTexture, NULL, &destRect);

}
