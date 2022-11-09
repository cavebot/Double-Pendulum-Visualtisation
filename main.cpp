#include <cmath>
#include <iostream>
#include <fstream>
#include <SDL.h>
#include <SDL_image.h>
#include "include/game.h"
#include "include/gameObject.h"
//#include "include/rungeKutta4.h"


using namespace std;

game *gameInstance = nullptr;


int main(int argc, char *argv[])
{
    double tp = 0.001; // RK timestep
    cout << "Evaluating with timestep = " << tp << endl;


    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    int frameTime;


    gameInstance = new game;
    gameInstance->init("AdamEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, false);




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

       // cout << "looping" << endl;
       
    }

    gameInstance->clean();

   

    
    

    //point in a pair of (time,function value)
    //for a double pendumlum we have O1(t), O2(t), v1(t), v2(t) representing angle and speed of each pendulum
    //four points needed
    
    return 0;

}

