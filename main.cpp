#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_image.h>
#include "imp/displays.hpp"
#include "imp/birdAi.hpp"
#include "imp/opstacle.hpp"
#include "imp/opsgenerate.hpp"
int main_menu(SDL_Event event, int quit, SDL_Renderer *renderer);
int restart(SDL_Event event, int quit, SDL_Renderer *renderer);
int main(int argc, char *args[])
{
    int clicked = 0;
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);

    // Create window
    SDL_Window *window = SDL_CreateWindow(" Flappy Bird",
                                          SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          750, 750, SDL_WINDOW_SHOWN);

    // Create renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_TARGETTEXTURE);
    opstacle Opstacle(renderer);
    opsgenerate o(renderer);
    Displays d(renderer);
    birdAI Ai(renderer);
    // Set background color
    d.clear(renderer);

    // Wait for user to close the window
    int quit = 0;
    SDL_Event event;
    clicked = main_menu(event, quit, renderer);
    while (quit == 0)
    {
        if (clicked == 1)
            quit = 1;
        else if (clicked == 2)
            clicked = Ai.ai(event, quit);
        if (clicked == 3)
            clicked = restart(event, quit, renderer);
    }

    while (quit == 0)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = 1;
            }
        }
    }

    // Clean up resources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
int main_menu(SDL_Event event, int quit, SDL_Renderer *renderer)
{
    Displays d(renderer);
    SDL_Rect play_source;
    SDL_Rect play_destination;
    SDL_Texture *buttons = IMG_LoadTexture(renderer, "src\\res\\buttons.png");
    play_source = d.get_rect(9, 7, 142, 362);
    play_destination = d.get_rect(276, 357, 142 / 2, 362 / 2);
    int clicked = 0;

    while (quit == 0)
    {
        d.clear(renderer);
        d.Display(renderer, buttons, play_source, play_destination);
        if (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_MOUSEMOTION:
                if (event.button.x > 276 && event.button.x < 357)
                    if (event.button.y > 357 && event.button.y < 357 + 71)
                        play_source = d.get_rect(395, 8, 142, 362);
                    else
                        play_source = d.get_rect(9, 7, 142, 362);

                break;
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.x > 276 && event.button.x < 357 + 181)

                    if (event.button.y > 357 && event.button.y < 357 + 71)
                    {
                        clicked = 2;
                        return clicked;
                    }

                break;
            case SDL_QUIT:
                clicked = 1;
                return clicked;
                break;
            }
        }
        d.update(renderer);
    }
    return clicked;
}
int restart(SDL_Event event, int quit, SDL_Renderer *renderer)
{
    Displays d(renderer);
    SDL_Rect play_source;
    SDL_Rect play_destination;
    SDL_Texture *buttons = IMG_LoadTexture(renderer, "src\\res\\restart.png");
    play_source = d.get_rect(0, 0, 10, 10);
    play_destination = d.get_rect(276, 357, 100, 100);
    int clicked = 0;
    d.clear(renderer);
    while (quit == 0)
    {
        d.clear(renderer);
        d.Display(renderer, buttons, play_source, play_destination);
        if (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.x > 276 && event.button.x < 357 + 100)
                    if (event.button.y > 357 && event.button.y < 357 + 100)
                    {
                        clicked = 2;
                        return clicked;
                    }
                break;
            case SDL_QUIT:
                clicked = 1;
                return clicked;
                break;
            }
        }
        d.update(renderer);
    }
    return clicked;
}
/* 1= game quit
   2=play game
   3=restart button
 */
