#define _CRT_SECURE_NO_WARNINGS
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "Pantalla.h"
#include "jaurtigaiak.h"

void renderMouseSquare() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_RenderDrawLine(renderer, mouseDim[1] * GRID_SIZE, mouseDim[0] * GRID_SIZE,
        (mouseDim[1] + 1) * GRID_SIZE, mouseDim[0] * GRID_SIZE);
    SDL_RenderDrawLine(renderer, (mouseDim[1] + 1) * GRID_SIZE, mouseDim[0] * GRID_SIZE,
        (mouseDim[1] + 1) * GRID_SIZE, (mouseDim[0] + 1) * GRID_SIZE);
    SDL_RenderDrawLine(renderer, (mouseDim[1] + 1) * GRID_SIZE, (mouseDim[0] + 1) * GRID_SIZE,
        mouseDim[1] * GRID_SIZE, (mouseDim[0] + 1) * GRID_SIZE);
    SDL_RenderDrawLine(renderer, mouseDim[1] * GRID_SIZE, (mouseDim[0] + 1) * GRID_SIZE,
        mouseDim[1] * GRID_SIZE, mouseDim[0] * GRID_SIZE);
}
void renderSelection() {

    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_Rect selectedRect = { -1 * GRID_SIZE, -1 * GRID_SIZE, GRID_SIZE, GRID_SIZE };
    SDL_RenderDrawRect(renderer, &selectedRect);

}

void renderGrid() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j)
        {
            if (grid[i][j] == 0)
            {
                SDL_Rect rect = { j * GRID_SIZE, i * GRID_SIZE, GRID_SIZE, GRID_SIZE };
                SDL_RenderCopy(renderer, valueZeroTexture, NULL, &rect);
            }
            else if (grid[i][j] == 1)
            {
                SDL_Rect rect = { j * GRID_SIZE, i * GRID_SIZE, GRID_SIZE, GRID_SIZE };
                SDL_RenderCopy(renderer, valueOneTexture, NULL, &rect);
            }
            else if (grid[i][j] == 2)
            {
                SDL_Rect rect = { j * GRID_SIZE, i * GRID_SIZE, GRID_SIZE, GRID_SIZE };
                SDL_RenderCopy(renderer, valueTwoTexture, NULL, &rect);
            }
            else if (grid[i][j] == 3)
            {
                SDL_Rect rect = { j * GRID_SIZE, i * GRID_SIZE, GRID_SIZE, GRID_SIZE };
                SDL_RenderCopy(renderer, valueThreeTexture, NULL, &rect);
            }
            else if (grid[i][j] == 5)
            {
                SDL_Rect rect = { j * GRID_SIZE, i * GRID_SIZE, GRID_SIZE, GRID_SIZE };
                SDL_RenderCopy(renderer, valueFourTexture, NULL, &rect);
            }
            else if (grid[i][j] == 6) {
                SDL_Rect rect = { j * GRID_SIZE, i * GRID_SIZE, GRID_SIZE, GRID_SIZE };
                SDL_RenderCopy(renderer, valueEightTexture, NULL, &rect);
            }
            else if (grid[i][j] == 7) {
                SDL_Rect rect = { j * GRID_SIZE, i * GRID_SIZE, GRID_SIZE, GRID_SIZE };
                SDL_RenderCopy(renderer, valueSevenTexture, NULL, &rect);
            }
            else if (grid[i][j] == 8) {
                SDL_Rect rect = { j * GRID_SIZE, i * GRID_SIZE, GRID_SIZE, GRID_SIZE };
                SDL_RenderCopy(renderer, valueSixTexture, NULL, &rect);
            }

        }
    }
}
void renderRectangulo(int rectWidth, int rectHeight, int rectX, int rectY, int r, int g, int b, int o) {

    SDL_SetRenderDrawColor(renderer, r, g, b, o);

    SDL_Rect rect = { rectX, rectY, rectWidth, rectHeight };
    SDL_RenderFillRect(renderer, &rect);

}
