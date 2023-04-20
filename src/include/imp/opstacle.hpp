#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cstdlib>
#include <ctime>
#include "imp/displays.hpp"
#include "imp/birdAi.hpp"
class opstacle
{

private:
    int randomNum;
    SDL_Renderer *render;
    int y1;
    int y2;

public:
    int x;
    int gap = 90;
    opstacle(SDL_Renderer *renderer)
    {
        render = renderer;
    }
    int OpstacleGenerate(int count);
    void displayopst(int pull, int rannum);
};
int opstacle::OpstacleGenerate(int count)
{
    int min = 100, max = 550;

    std::srand(std::time(NULL));
    int i = count + std::rand() % (20 - count + 1);
    std::srand(i);
    for (int num = 0; num < i; num++)
    {
        int j = 50 + std::rand() % (1000 - 50 + 1);
        std::srand(j);
    }

    randomNum = min + std::rand() % (max - min + 1);
    return randomNum;
}
void opstacle::displayopst(int x1, int rannum)
{
    Displays d(render);
    SDL_Texture *poles = IMG_LoadTexture(render, "src\\res\\poles.png");

    y1 = 0;
    y2 = rannum + gap;
    SDL_Rect up_pole_source;
    SDL_Rect up_pole_destination;
    SDL_Rect down_pole_source;
    SDL_Rect down_pole_destination;
    up_pole_source = d.get_rect(24, 0, 85, 22);
    up_pole_destination = d.get_rect(x1, 0, rannum, 30);
    down_pole_source = d.get_rect(0, 0, 85, 22);
    down_pole_destination = d.get_rect(x1, y2, 750, 30);
    d.Displaie(render,poles, up_pole_source, up_pole_destination);
    d.Displaie(render,poles, down_pole_source, down_pole_destination);
}
