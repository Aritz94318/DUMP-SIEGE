#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "text_render.h"
#include "Pantalla.h"
#include "deadScreen.h"
#include "menua.h"
void renderBlackButton() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    int buttonSize = 50;  
    int buttonX = WINDOW_WIDTH - buttonSize - 20;  
    int buttonY = WINDOW_HEIGHT - buttonSize - 20;
    int cornerRadius = 31; 

    
    for (int i = 0; i < buttonSize; ++i) {
        for (int j = 0; j < buttonSize; ++j) {
            float dx = fabs(i - buttonSize / 2.0f);
            float dy = fabs(j - buttonSize / 2.0f);

            if (sqrt(dx * dx + dy * dy) < cornerRadius) {
                
                SDL_RenderDrawPoint(renderer, buttonX + i, buttonY + j);
            }

        }
    }
}
void renderTower1() {
    SDL_Rect rect = { WINDOW_WIDTH - 340, 100, 100, 100 };
    SDL_RenderCopy(renderer, hormenu, NULL, &rect);

}
void renderTower2() {
    SDL_Rect rect = { WINDOW_WIDTH - 340, 350, 100, 100 };
    SDL_RenderCopy(renderer, marmenu, NULL, &rect);

}
void renderTower3() {
    SDL_Rect rect = { WINDOW_WIDTH - 340, 600, 100, 100 };
    SDL_RenderCopy(renderer, grimenu, NULL, &rect);

}
void renderTower4() {
    SDL_Rect rect = { WINDOW_WIDTH - 340, 850, 100, 100 };
    SDL_RenderCopy(renderer, urdmenu, NULL, &rect);


}
void renderizarPestana() {

    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
    SDL_Rect pestanaRect = { WINDOW_WIDTH - 400, 0, WINDOW_WIDTH , WINDOW_HEIGHT };
    SDL_RenderFillRect(renderer, &pestanaRect);
    renderTower1();

    renderText("3", WINDOW_WIDTH - 300, 200);
    renderTower2();
    renderText("4", WINDOW_WIDTH - 300, 450);
    renderTower3();
    renderText("5", WINDOW_WIDTH - 300, 700);
    renderTower4();
    renderText("6", WINDOW_WIDTH - 300, 950);
}
void barrak_renderizatu() {
    char testua[25];
    char testua2[25];
    char testua3[25];
    SDL_Rect healthBarOutline = { 10,10, MAX_HEALTH_JOKALARIA * 2,20 };
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &healthBarOutline);

    SDL_Rect healthBar = { 10,10,  health_jokalaria * 2,20 };
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &healthBar);
    sprintf(testua3, "Bizitza: %d", health_jokalaria);
    renderText(testua3, 10, 50);

    SDL_Rect healthBarOutline3 = { 10,90, ENTITYKOPURUA,20 };
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &healthBarOutline3);

    SDL_Rect healthBar3 = { 10,90, kopurua,20 };
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_RenderFillRect(renderer, &healthBar3);
    sprintf(testua2, "%d. Ronda", RoundCount + 1);
    renderText(testua2, 10, 130);
    SDL_Rect healthBarOutline4 = { 10,170, DIRUA_MAX,20 };
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &healthBarOutline4);

    SDL_Rect healthBar4 = { 10,170, dirua,20 };
    SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
    SDL_RenderFillRect(renderer, &healthBar4);
    sprintf(testua, "Energia: %d", dirua);
    renderText(testua, 10, 210);

}