#define _CRT_SECURE_NO_WARNINGS
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "Pantalla.h"
#include "jaurtigaiak.h"

void detektatu(int k) {
    if (entity[k].Zaborren_Bizitza <= 0 && entity[k].entityDim[1] > 0 && entity[k].entityDim[0] > 0) {
        entity[k].entityDim[0] = -1;
        entity[k].entityDim[1] = -1;
        kopurua -= ENTITYKOPURUA / (3 + gei);
        dirua += 1;
        KillCount++;
        if (k == 2 + gei) {
            lastDisappearTime = SDL_GetTicks();
        }
    }
    if ((int)entity[k].entityDim[1] == COLS / 2 && (int)entity[k].entityDim[0] == ROWS - 1) {

        entity[k].entityDim[0] = -1;
        entity[k].entityDim[1] = -1;
        health_jokalaria = health_jokalaria - DAMAGE_ENTITY;

        kopurua -= ENTITYKOPURUA / (3 + gei);

        if (k == 2 + gei) {
            lastDisappearTime = SDL_GetTicks();
        }
    }

}
void moveEntityAlongPath(int k) {

    float currentCol = entity[k].entityDim[1];
    float currentRow = entity[k].entityDim[0];
    float speed = 0.09 + gei * 0.01;

    if (currentRow < ROWS - 1 && grid[(int)(currentRow + 1)][(int)currentCol] == 1 && entity[k].ezkesk != 2 &&
        entity[k].ezkesk != 1 && entity[k].ezkesk != 3) {
        currentRow = currentRow + speed;
        entity[k].ezkesk = 0;
    }
    else if (entity[k].ezkesk != 2 && currentCol > 0 && grid[(int)currentRow][(int)(currentCol - 1)] == 1) {
        currentCol = currentCol - speed;
        if (grid[(int)currentRow][(int)(currentCol - 1)] == 1) {
            entity[k].ezkesk = 1;
        }
        else {
            entity[k].ezkesk = 3;
        }
    }
    else if (entity[k].ezkesk == 3) {
        if (entity[k].z > 0) {
            currentCol = currentCol - speed;
            entity[k].z = entity[k].z - speed;
        }
        else {
            currentCol = (int)currentCol + 1;
            entity[k].ezkesk = 4;
            entity[k].z = 1;
        }
    }
    else if (entity[k].ezkesk != 1 && entity[k].ezkesk != 3 && entity[k].ezkesk != 4 && currentCol < COLS - 1 &&
        grid[(int)currentRow][(int)(currentCol + 1)] == 1) {
        currentCol = currentCol + speed;
        if (grid[(int)currentRow][(int)(currentCol + 1)] == 1) {
            entity[k].ezkesk = 2;
        }
        else {
            entity[k].ezkesk = 0;
        }
    }

    entity[k].entityDim[1] = currentCol;
    entity[k].entityDim[0] = currentRow;

}
void renderEntity(int k) {

    if (entity[k].mota == 1) {
        SDL_Rect entityRect = { entity[k].entityDim[1] * GRID_SIZE, entity[k].entityDim[0] * GRID_SIZE, GRID_SIZE, GRID_SIZE };

        SDL_RenderCopy(renderer, entityTexture, NULL, &entityRect);

        SDL_Rect healthBarOutline2 = { entityRect.x, entityRect.y - 10, GRID_SIZE, 5 };
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawRect(renderer, &healthBarOutline2);
        SDL_Rect healthBar2 = { entityRect.x, entityRect.y - 10, (int)(GRID_SIZE * (entity[k].Zaborren_Bizitza / (float)100)), 5 };
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &healthBar2);
    }
    else if (entity[k].mota == 3) {
        SDL_Rect entityRect = { entity[k].entityDim[1] * GRID_SIZE, entity[k].entityDim[0] * GRID_SIZE, GRID_SIZE, GRID_SIZE };

        SDL_RenderCopy(renderer, entityTexture2, NULL, &entityRect);

        SDL_Rect healthBarOutline2 = { entityRect.x, entityRect.y - 10, GRID_SIZE * 1.4, 5 };
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawRect(renderer, &healthBarOutline2);
        SDL_Rect healthBar2 = { entityRect.x, entityRect.y - 10, (int)(GRID_SIZE * (entity[k].Zaborren_Bizitza / (float)100)), 5 };
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &healthBar2);
    }
    else if (entity[k].mota == 2) {
        SDL_Rect entityRect = { entity[k].entityDim[1] * GRID_SIZE, entity[k].entityDim[0] * GRID_SIZE, GRID_SIZE, GRID_SIZE };

        SDL_RenderCopy(renderer, entityTexture3, NULL, &entityRect);

        SDL_Rect healthBarOutline2 = { entityRect.x, entityRect.y - 10, GRID_SIZE * 1.2, 5 };
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawRect(renderer, &healthBarOutline2);
        SDL_Rect healthBar2 = { entityRect.x, entityRect.y - 10, (int)(GRID_SIZE * (entity[k].Zaborren_Bizitza / (float)100)), 5 };
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &healthBar2);
    }
    else if (entity[k].mota == 4) {
        SDL_Rect entityRect = { entity[k].entityDim[1] * GRID_SIZE, entity[k].entityDim[0] * GRID_SIZE, GRID_SIZE, GRID_SIZE };

        SDL_RenderCopy(renderer, entityTexture4, NULL, &entityRect);

        SDL_Rect healthBarOutline2 = { entityRect.x, entityRect.y - 10, GRID_SIZE * 1.6, 5 };
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawRect(renderer, &healthBarOutline2);
        SDL_Rect healthBar2 = { entityRect.x, entityRect.y - 10, (int)(GRID_SIZE * (entity[k].Zaborren_Bizitza / (float)100)), 5 };
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &healthBar2);
    }

}
void mugitu(int k) {
    int prob;
    srand((unsigned int)time(NULL));
    if (entity[k].bai == 0 || entity[k].bai == -1) {

        if (RoundCount == 0) {
            entity[k].mota = 1;
        }
        if (RoundCount == 1) {
            prob = rand() % (5);
            if (prob <= 2) {
                entity[k].mota = 1;
            }
            else {
                entity[k].mota = 2;
            }
        }
        if (RoundCount == 2) {
            prob = rand() % (15);
            if (prob <= 5) {
                entity[k].mota = 1;
            }
            else if (prob <= 10) {
                entity[k].mota = 2;
            }
            else {
                entity[k].mota = 3;
            }
        }
        if (RoundCount >= 3) {
            prob = rand() % (18);
            if (prob <= 5) {
                entity[k].mota = 1;
            }
            else if (prob <= 10) {
                entity[k].mota = 2;
            }
            else if (prob <= 14) {
                entity[k].mota = 3;
            }
            else {
                entity[k].mota = 4;
            }
        }
        entity[k].ezkesk = 0;
        entity[k].z = 1;
        entity[k].entityDim[0] = hasieraRow;
        entity[k].entityDim[1] = hasieraCol;

        entity[k].bai = 1;
        if (entity[k].mota == 1) {

            entity[k].Zaborren_Bizitza = 100;

        } if (entity[k].mota == 2) {

            entity[k].Zaborren_Bizitza = 100 * 1.2;
        } if (entity[k].mota == 3) {

            entity[k].Zaborren_Bizitza = 100 * 1.4;

        } if (entity[k].mota == 4) {

            entity[k].Zaborren_Bizitza = 100 * 1.6;

        }
        renderEntity(k);
    }

    moveEntityAlongPath(k);
    detektatu(k);


}
