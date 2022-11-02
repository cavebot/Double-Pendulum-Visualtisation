#pragma once

#include "include/game.h"
#include "include/textureManager.h"
#include <SDL_image.h>
#include "include/gameObject.h"

gameObject* point1 = NULL;
gameObject* point2 = NULL;

game::game()
{}
game::~game()
{}

void game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems initialised successfully" << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}

		isRunning = true;
	} else{
		isRunning = false;
	}

	point1 = new gameObject("assets/mono-point.png", renderer, 0, 0);
	point2 = new gameObject("assets/mono-point.png", renderer, 50, 50);

}


void game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {	
	case SDL_QUIT:
		isRunning = false;
		break;

	default:
		break; 
	}
}


void game::update()
{
	point1->update();
	point2->update();

	std::cout << "looping" << std::endl;
}

void game::render()
{
	SDL_RenderClear(renderer);

	//add stuff here to render
	point1->render();
	point2->render();

	SDL_RenderPresent(renderer);
}

void game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned" << std::endl;
}