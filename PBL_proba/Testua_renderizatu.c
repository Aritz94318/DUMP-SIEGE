#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include "Pantalla.h"

extern SDL_Renderer* renderer;
extern TTF_Font* font;

void renderText(const char* text, int x, int y) {
    SDL_Color textColor = { 255, 255, 255, 255 }; 
    SDL_Surface* textSurface = TTF_RenderText_Blended(font, text, textColor);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

    SDL_Rect textRect = { x, y, textSurface->w, textSurface->h };
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);

    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
}