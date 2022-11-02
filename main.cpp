#include <cmath>
#include <iostream>
#include <fstream>

#include <SDL.h>
#include <SDL_image.h>
#include "rungeKutta4.h"
#include "game.h"
#include "gameObject.h"


using namespace std;

game *gameInstance = nullptr;


int main(int argc, char *argv[])
{

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    int frameTime;

    gameInstance = new game;
    gameInstance->init("AdamEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, false);



    while(gameInstance->running())
    {
        frameStart = SDL_GetTicks();

        gameInstance->handleEvents();
        gameInstance->update();
        gameInstance->render();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }

    }

    gameInstance->clean();

   
    //This section of code is the differential equation solver. So far it can solve a system.
    // Now it's just a matter of attaching the dots position variables to the solutions
    //instead of a counter that iterates their position linearly 

    double tp = 0.01;
    int nsteps = 10000;
    cout << "Evaluating with timestep = " << tp << ", for number of steps = " << nsteps << endl;

    point point1(0, 0);

    ofstream datafile;
    datafile.open("data/RK4_data.txt");

    while (nsteps--) 
    {
        point point2 = evaluateRK4(tp, point1);
        point1 = point2;

        datafile << point2.x << ' ' << point2.y << endl;;
    }


    datafile.close();
    return 0;

}

