#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include "imp/displays.hpp"
#include "opstacle.hpp"
#include "opsgenerate.hpp"

class birdAI
{

public:
    birdAI(SDL_Renderer *renderer)
    {
        render = renderer;
    }
    bool ai(SDL_Event e, bool quit);
    int y2;

private:
    SDL_Renderer *render;
    int de = 20;
    int pole_passed = 0;
};

bool birdAI::ai(SDL_Event event, bool quit)
{

    Displays d(render);
    SDL_Rect bird_source;
    SDL_Rect bird_destination;
    SDL_Texture *bird = IMG_LoadTexture(render, "src\\res\\sprite_sheet.png");

    std::vector<opsgenerate> poles(4, opsgenerate(render));
    opstacle op(render);
    int i = 0, j = 0;
    int pass = 0;
    int begin = 0;
    int size = 30;
    int x = 357;
    int y = 357;

    int move = 0;
    int next_frame = 0;
    while (!quit)
    {

        if (move >= 51)
            move = 0;
        SDL_Delay(15);
        d.clear(render);
        bird_source = d.get_rect(move, 0, 12, 17);
        bird_destination = d.get_rect(x, y, 30, 30);

        if (begin == 0)
        {
            for (int count = 0; count < 4; count++)
            {

                poles[count].create(begin++);
                poles[count].x = 725 + pass;
                pass = pass + 250;
            }
        }

        if (j > 2)
        {
            j = 0;
            i++;
        }
        else
            j++;
        y = y + 1 + i;
        if (SDL_PollEvent(&event))
        {

            switch (event.type)
            {
            case SDL_KEYDOWN:
                if (event.key.state == SDL_PRESSED)
                    if (event.key.keysym.scancode == SDL_SCANCODE_SPACE)
                    {
                        y = y - 20;
                        i = 0;
                    }
                break;
            case SDL_QUIT:
                quit = true;
                break;
            }
        }
        if (y >= 700)
        {
            d.Display(render, bird, bird_source, bird_destination);
            quit = true;
        }
        else if (y <= 0)
        {
            d.Display(render, bird, bird_source, bird_destination);

            y = 0;
        }
        else
            d.Display(render, bird, bird_source, bird_destination);
        for (int count = 0; count < 4; count++)
            if (poles[count].x <= 387 && poles[count].x >= 327)
                if (poles[count].randomnum >= y || poles[count].randomnum + poles[count].gap - 40 <= y)
                    quit = true;
        for (int count = 0; count < 4; count++)
        {

            poles[count].show();
            poles[count].x--;
            if (poles[count].x == -30)
            {
                poles[count].x = 725 + 250;
                poles[count].create(begin++);
            }
        }
        d.update(render);
        if (next_frame == 12)
            {next_frame=0;
                move = move + 17;}
                else
                next_frame++;
    }
    return quit;
}