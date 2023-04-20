#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
class Displays
{
public:
    Displays(SDL_Renderer *renderer)
    {
        //            SDL_Texture *toggle_button=IMG_LoadTexture(renderer,"src\\res\\sprite_sheet.png");
              SDL_Texture *backgrounds=IMG_LoadTexture(renderer,"src\\res\\background.png");
        //  texture=toggle_button;
         background=backgrounds;
    }

public:
    
    void Display(SDL_Renderer *renderer, SDL_Texture *textures, SDL_Rect srect, SDL_Rect drect);
    void Displaie(SDL_Renderer *renderer, SDL_Texture *textures, SDL_Rect srect, SDL_Rect drect);
    void update(SDL_Renderer *renderer);
    void clear(SDL_Renderer *renderer);
    SDL_Rect get_rect(int x1, int y1, int h, int w);

private:
    SDL_Texture *texture;
    SDL_Texture *background;
};
void Displays::update(SDL_Renderer *renderer)
{
    // Update the screen
    SDL_RenderPresent(renderer);
}
void Displays::clear(SDL_Renderer *renderer)
{
    // Clear the screen
    SDL_RenderClear(renderer);
}

void Displays::Display(SDL_Renderer *renderer, SDL_Texture *textures, SDL_Rect srect, SDL_Rect drect)
{
     SDL_RenderCopy(renderer,background,NULL,NULL);
    SDL_RenderCopy(renderer, textures, &srect, &drect);
}
void Displays::Displaie(SDL_Renderer *renderer, SDL_Texture *textures, SDL_Rect srect, SDL_Rect drect)
{
  
    SDL_RenderCopy(renderer, textures, &srect, &drect);
}
SDL_Rect Displays::get_rect(int x1, int y1, int h, int w)
{
    SDL_Rect rect;
    rect.x = x1;
    rect.y = y1;
    rect.h = h;
    rect.w = w;
    return rect;
}
