#pragma once
#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "imp/displays.hpp"
#include "imp/opstacle.hpp"
class opsgenerate
{
public:
    int randomnum;
    int x;
    int gap;

    opsgenerate(SDL_Renderer *renderer)
    {
        render = renderer;
    }
    void create(int m)
    {

        begin = m;
        opstacle Opstacle(render);
        randomnum = Opstacle.OpstacleGenerate(m);
    }
    void show()
    {
        opstacle Opstacle(render);
        Opstacle.x = x;
        gap = Opstacle.gap;

        Opstacle.displayopst(x, randomnum);
    }

private:
    SDL_Renderer *render;
    int begin;
};
