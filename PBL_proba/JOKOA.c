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
#include "Mapa.h"
#include "zaborrak.h"
#include "Renderizatu.h"
#include "irudiak.h"


void jokoa() {

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    renderGrid();


    for (int k = 0; k < n; ++k) {

        if (k < defi && defi < 2 + k) {
            entity[k].bai = 0;
            defi++;
            mugitu(k);
        }
        if (entity[k].bai == 1) {
            mugitu(k);
        }
        renderEntity(k, entity);
    }

    if (SDL_GetTicks() - lastDisappearTime > 3000 && n <= 3 + gei && lastDisappearTime != 0) {
        RoundCount++;
        lastDisappearTime = 0;
        gei += 2;
        for (int k = 0; k < n + gei; ++k) {
            entity[k].bai = 0;

        }
        n = 0;
        defi = 1;
        kopurua = ENTITYKOPURUA;

    }

    if (SDL_GetTicks() - denboraagertu > 2000) {

        denboraagertu = SDL_GetTicks();
        tiroegin();


    }


    renderMouseSquare();
    renderSelection();

    renderBullets(bullets);
    moveBullets(bullets);
    renderBullets();
    processBullets();
    barrak_renderizatu();

    if (mostrarPestana) {
        renderizarPestana();
    }
    renderBlackButton();

    SDL_RenderPresent(renderer);
    frame++;
    if (frame > 180 + aurreko_frame - 10 * gei && n < 3 + gei) {
        n++;
        aurreko_frame = frame;
    }
}