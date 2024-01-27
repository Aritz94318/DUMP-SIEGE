#define _CRT_SECURE_NO_WARNINGS
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "Pantalla.h"
#include "jaurtigaiak.h"
#include <math.h>
void spawnBullet(float startX, float startY, int targetEntityIndex, int i) {

    if (dorreak[i].dorre_mota == 1) {
        bullets[i].bullet_mota = 1;
    }
    else if (dorreak[i].dorre_mota == 2) {
        bullets[i].bullet_mota = 2;
    }
    else if (dorreak[i].dorre_mota == 3) {
        bullets[i].bullet_mota = 3;
    }
    else if (dorreak[i].dorre_mota == 4) {
        bullets[i].bullet_mota = 4;
    }

    bullets[i].position[0] = startX;
    bullets[i].position[1] = startY;
    bullets[i].speed = 1 + 0.05 * gei;
    bullets[i].active = true;
    bullets[i].targetEntityIndex = targetEntityIndex;

    float targetX = entity[targetEntityIndex].entityDim[1];
    float targetY = entity[targetEntityIndex].entityDim[0];
    float deltaX = targetX - startX;
    float deltaY = targetY - startY;
    float length = sqrt(deltaX * deltaX + deltaY * deltaY);

    bullets[i].direction[0] = deltaX / length;
    bullets[i].direction[1] = deltaY / length;
    bullets[i].direction[2] = targetEntityIndex;
    bullets[i].active = true;
    return;



}
void tiroegin() {

    int activeEntities = 0;
    for (int k = 0; k < n; k++) {
        if (entity[k].Zaborren_Bizitza > 0 && entity[k].entityDim[0] > 0) {
            activeEntities = 1;
        }

    }

    if (activeEntities == 1) {
        for (int m = 0; m < dorre; m++) {
            float minDistance = INFINITY;
            dorreak[m].targetEntityIndex = -1;

            for (int k = 0; k < n; ++k) {
                if (
                    dorreak[m].dorreDim[1] - entity[k].entityDim[0] > -6 &&
                    dorreak[m].dorreDim[0] - entity[k].entityDim[1] > -6 &&
                    dorreak[m].dorreDim[1] - entity[k].entityDim[0] < 6 &&
                    dorreak[m].dorreDim[0] - entity[k].entityDim[1] < 6) {

                    float targetX = entity[k].entityDim[1];
                    float targetY = entity[k].entityDim[0];
                    float deltaX = targetX - dorreak[m].dorreDim[1];
                    float deltaY = targetY - dorreak[m].dorreDim[0];
                    float distance = sqrt(deltaX * deltaX + deltaY * deltaY);

                    if (distance < minDistance) {
                        minDistance = distance;
                        dorreak[m].targetEntityIndex = k;
                    }
                }
            }

            if (dorreak[m].targetEntityIndex != -1) {
                spawnBullet(dorreak[m].dorreDim[0], dorreak[m].dorreDim[1], dorreak[m].targetEntityIndex, m);
            }


        }
    }
}
void moveBullets() {
    for (int i = 0; i < dorre; ++i) {

        bullets[i].position[0] += bullets[i].speed * bullets[i].direction[0];
        bullets[i].position[1] += bullets[i].speed * bullets[i].direction[1];

    }
}
void renderBullets() {
    for (int i = 0; i < dorre; ++i) {
        if (bullets[i].active) {

            SDL_Rect bulletRect = { bullets[i].position[0] * GRID_SIZE, bullets[i].position[1] * GRID_SIZE, GRID_SIZE, GRID_SIZE };
            SDL_RenderCopy(renderer, valueFiveTexture, NULL, &bulletRect);
        }
    }
}

void processBullets() {
    int ñ;
    for (int i = 0; i < dorre; ++i) {



        bullets[i].bulletHitEntity = false;
        ñ = bullets[i].direction[2];
        float targetX = entity[ñ].entityDim[1];
        float targetY = entity[ñ].entityDim[0];
        float deltaX = targetX - bullets[i].position[0];
        float deltaY = targetY - bullets[i].position[1];
        float distance = sqrt(deltaX * deltaX + deltaY * deltaY);
        if (distance > 6) {
            bullets[i].active = false;
        }
        if (distance <= 0.8 && bullets[i].active != false) {
            Mix_Music* music = Mix_LoadMUS("tiro.mp3");
            Mix_PlayMusic(music, 0);
            if (bullets[i].bullet_mota == entity[ñ].mota) {
                entity[ñ].Zaborren_Bizitza -= BULLET_DAMAGE * 2;
            }
            else {
                entity[ñ].Zaborren_Bizitza -= BULLET_DAMAGE;
            }
            bullets[i].active = false;
           
        }




    }
}