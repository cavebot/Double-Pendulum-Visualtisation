#pragma once
#include "game.h"

class gameObject
{
public:
	gameObject(const char* texturesheet, SDL_Renderer* renderer, int x, int y);
	~gameObject();

	void update();
	void render();

private:
	int xpos;
	int ypos;

	SDL_Texture* objectTexture;
	SDL_Rect sourceRect, destRect;
	SDL_Renderer* renderer;
};