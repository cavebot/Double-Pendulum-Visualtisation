#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>


class game
{
public:
	game();
	~game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();

	bool running() { return isRunning; }

private:
	bool isRunning;
	int count = 0;
	SDL_Window* window;
	SDL_Renderer* renderer;

};
