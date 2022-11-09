#pragma once

#include "include/game.h"
#include "include/textureManager.h"
#include <SDL_image.h>
#include "include/gameObject.h"
#include "include/rungeKutta4.h"


gameObject* pointBlack1 = nullptr;
gameObject* pointBlack2 = nullptr;
gameObject* pointBlack3 = nullptr;

gameObject* pointRed1 = nullptr;
gameObject* pointRed2 = nullptr;
gameObject* pointRed3 = nullptr;

gameObject* pointBlue1 = nullptr;
gameObject* pointBlue2 = nullptr;
gameObject* pointBlue3 = nullptr;

gameObjectStatic* line1Black = nullptr;
gameObjectStatic* line2Black = nullptr;

gameObjectStatic* line1Blue = nullptr;
gameObjectStatic* line2Blue = nullptr;

gameObjectStatic* line1Red = nullptr;
gameObjectStatic* line2Red = nullptr;



SDL_Renderer* game::renderer = nullptr;

int xinit = 300;
int yinit = 300;


double l1 = 1;
double l2 = 1;
double m1 = 0.5;
double m2 = 1;
double time_i = 0.0;

double theta1 = 3.0000;
double omega1 = 0.00;
double theta2 = 3.0000;
double omega2 = 0.00;

double thetaRed1 = 3.0001;
double omegaRed1 = 0.00;
double thetaRed2 = 3.0001;
double omegaRed2 = 0.00;

double thetaBlue1 = 3.0002;
double omegaBlue1 = 0.00;
double thetaBlue2 = 3.0002;
double omegaBlue2 = 0.00;

double angle =0;

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

	

	pointBlack1 = new gameObject("assets/pointBlack.png", xinit, yinit);
	pointBlack2 = new gameObject("assets/pointBlack.png", xinit, yinit);
	pointBlack3 = new gameObject("assets/pointBlack.png", xinit, yinit);

	pointRed1 = new gameObject("assets/pointRed.png", xinit, yinit);
	pointRed2 = new gameObject("assets/pointRed.png", xinit, yinit);
	pointRed3 = new gameObject("assets/pointRed.png", xinit, yinit);

	pointBlue1 = new gameObject("assets/pointBlue.png", xinit, yinit);
	pointBlue2 = new gameObject("assets/pointBlue.png", xinit, yinit);
	pointBlue3 = new gameObject("assets/pointBlue.png", xinit, yinit);

	line1Black = new gameObjectStatic("assets/line.png", xinit+9, xinit+7);
	line2Black = new gameObjectStatic("assets/line.png", xinit+9, xinit+7);
	line1Blue = new gameObjectStatic("assets/line.png", xinit + 9, xinit + 7);
	line2Blue = new gameObjectStatic("assets/line.png", xinit + 9, xinit + 7);
	line1Red = new gameObjectStatic("assets/line.png", xinit + 9, xinit + 7);
	line2Red = new gameObjectStatic("assets/line.png", xinit + 9, xinit + 7);

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
	/// <Black pendulum>
	for (int i = 0; i < 10; i++) {
		DoublePendulum(0.001, l1, l2, m1, m2, theta1, omega1, theta2, omega2, time_i);
	}
	int x1 = xinit + (l1 * 200 / 2) * sin(theta1);
	int y1 = yinit + (l1 * 200 / 2) * cos(theta1);
	int x2 = x1 + (l2 * 200 / 2) * sin(theta2);
	int y2 = y1 + (l2 * 200 / 2) * cos(theta2);

	pointBlack1->update(xinit,yinit); //fulcrum point object 
	pointBlack2->update(x1,y1);
	pointBlack3->update(x2,y2);

	line1Black->update(xinit + 9, yinit + 7);
	line2Black->update(x1+9, y1+7);

	//////////////////////////////////////////////////////////////////////////////////////////////
	/// <Red pendulum>
	for (int i = 0; i < 10; i++) {
		DoublePendulum(0.001, l1, l2, m1, m2, thetaRed1, omegaRed1, thetaRed2, omegaRed2, time_i);
	}

	x1 = xinit + (l1 * 200 / 2) * sin(thetaRed1);
	y1 = yinit + (l1 * 200 / 2) * cos(thetaRed1);
	x2 = x1 + (l2 * 200 / 2) * sin(thetaRed2);
	y2 = y1 + (l2 * 200 / 2) * cos(thetaRed2);

	pointRed1->update(xinit, yinit); //fulcrum point object 
	pointRed2->update(x1, y1);
	pointRed3->update(x2, y2);

	line1Red->update(xinit + 9, yinit + 7);
	line2Red->update(x1 + 9, y1 + 7);

	//////////////////////////////////////////////////////////////////////////////////////////////
	/// <Blue pendulum>
	for (int i = 0; i < 10; i++) {
		DoublePendulum(0.001, l1, l2, m1, m2, thetaBlue1, omegaBlue1, thetaBlue2, omegaBlue2, time_i);
	}

	x1 = xinit + (l1 * 200 / 2) * sin(thetaBlue1);
	y1 = yinit + (l1 * 200 / 2) * cos(thetaBlue1);
	x2 = x1 + (l2 * 200 / 2) * sin(thetaBlue2);
	y2 = y1 + (l2 * 200 / 2) * cos(thetaBlue2);

	pointBlue1->update(xinit, yinit); //fulcrum point object 
	pointBlue2->update(x1, y1);
	pointBlue3->update(x2, y2);
	
	line1Blue->update(xinit + 9, yinit + 7);
	line2Blue->update(x1 + 9, y1 + 7);
	
	
	
}

void game::render()
{
	SDL_RenderClear(renderer);


	line1Black->render(90 - (theta1 * 180.0 / 3.141459));
	line2Black->render(90 - (theta2 * 180.0 / 3.141459));
	line1Blue->render(90 - (thetaBlue1 * 180.0 / 3.141459));
	line2Blue->render(90 - (thetaBlue2 * 180.0 / 3.141459));
	line1Red->render(90 - (thetaRed1 * 180.0 / 3.141459));
	line2Red->render(90 - (thetaRed2 * 180.0 / 3.141459));

	pointRed1->render();
	pointRed2->render();
	pointRed3->render();
	pointBlue1->render();
	pointBlue2->render();
	pointBlue3->render();
	pointBlack1->render();
	pointBlack2->render();
	pointBlack3->render(); 


	SDL_RenderPresent(renderer);
}

void game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned" << std::endl;
}