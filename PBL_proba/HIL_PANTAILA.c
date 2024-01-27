#define _CRT_SECURE_NO_WARNINGS
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <SDL_ttf.h>
#include "deadScreen.h"
#include "Pantalla.h"




void renderDeadScreen() {
    char testua[25];
    char testua2[50];
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 100);
    SDL_RenderClear(renderer);

    renderRectangulo(1200, 600, (WINDOW_WIDTH - 1200) / 2, (WINDOW_HEIGHT - 600) / 2, 50, 50, 50, 255);
    renderRectangulo(200, 75, (WINDOW_WIDTH / 2) - 100, WINDOW_HEIGHT - 400, 0, 255, 0, 255);

    renderText("JOLASTU", ((WINDOW_WIDTH / 2) - 60), WINDOW_HEIGHT - 390, 255, 255, 255);
    renderText("BERRIRO", ((WINDOW_WIDTH / 2) - 60), WINDOW_HEIGHT - 360, 255, 255, 255);
    renderText("Galdu duzu", ((WINDOW_WIDTH / 2) - 60), 325, 255, 255, 255);
    renderText("Mundua zaborrez bete da eta bertan bizitzea ezinezkoa da orain", (WINDOW_WIDTH / 2) - 425, 375, 255, 255, 255);
    renderText("ESC sakatu jokutik ateratzeko", (WINDOW_WIDTH / 2) - 150, 425, 255, 255, 255);
    sprintf(testua, "Egindako rondak: %d",RoundCount );
    renderText(testua, 400, 600);
    sprintf(testua2, "Birziklatutako zaborrak: %d", KillCount);
    renderText(testua2, WINDOW_WIDTH-750, 600);


    SDL_RenderPresent(renderer);
}