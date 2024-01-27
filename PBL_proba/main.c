#define _CRT_SECURE_NO_WARNINGS
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "text_render.h"
#include "Pantalla.h"
#include "deadScreen.h"
#include "menua.h"
#include "Renderizatu.h"
#include "Jokoa.h"
#include "Input-ak.h"
#include <SDL_mixer.h>
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Texture* valueZeroTexture = NULL;
SDL_Texture* valueTwoTexture = NULL;
SDL_Texture* valueOneTexture = NULL;
SDL_Texture* valueFourTexture = NULL;
SDL_Texture* valueThreeTexture = NULL;
SDL_Texture* valueFiveTexture = NULL;
SDL_Texture* valueSixTexture = NULL;
SDL_Texture* valueSevenTexture = NULL;
SDL_Texture* valueEightTexture = NULL;
SDL_Texture* entityTexture = NULL;
SDL_Texture* entityTexture2 = NULL;
SDL_Texture* entityTexture3 = NULL;
SDL_Texture* entityTexture4 = NULL;
SDL_Texture* backgroundImage = NULL;
SDL_Texture* urdmenu = NULL;
SDL_Texture* marmenu = NULL;
SDL_Texture* grimenu = NULL;
SDL_Texture* hormenu = NULL;
TTF_Font* font = NULL;
Mix_Music* music = NULL;
bool quit = false;
bool mostrarPestana = false;
bool kredi = false;
bool tut = false;
int dirua = 9;
int gei = 0;
int repeat = 0;
int menua = 0;
int lastDisappearTime = 0;
int n = 1;
int health_jokalaria = MAX_HEALTH_JOKALARIA;
int kopurua = ENTITYKOPURUA;
int defi = 1;
int frame = 0;
int RoundCount = 0;
int KillCount = 0;
int aurreko_frame = 0;
int dorre = 0;
int towerSelection = 0;
float mouseDim[2];
int grid[ROWS][COLS];
int hasieraRow;
int hasieraCol;
int denboraagertu;
struct Bullet bullets[100];
struct Horia dorreak[100];
struct entities entity[100];
int main() {
   
    SDL_Init(SDL_INIT_EVERYTHING);
    Mix_Init(MIX_INIT_MP3);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    TTF_Init();
    font = TTF_OpenFont("OETZTYP_.ttf", 24);
    while (!quit) {
        window = SDL_CreateWindow("Randomized Path", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN, SDL_WINDOW_FULLSCREEN);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        initializeGrid();
        generateRandomPath();
        zuhaitzak();
        argazkiak();
        zuhaitzak();
        health_jokalaria = 100;
        dirua = 9;
        quit = false;
        gei = 0;
        repeat = 0;
        lastDisappearTime = 0;
        n = 1;
        kopurua = ENTITYKOPURUA;
        defi = 1;
        frame = 0;
        RoundCount = 0;
        KillCount = 0;
        denboraagertu;
        aurreko_frame = 0;
        dorre = 0;
        mostrarPestana = false;
        towerSelection = 0;
        int a = SDL_GetTicks();
        int b = SDL_GetTicks();
        double delta = 0;

        while (!quit && repeat == 0) {
            a = SDL_GetTicks();
            delta = a - b;
            if (delta >= 1000 / 60.0) {
                if (menua == 1) {
                    if (health_jokalaria > 0) {
                        jokoa();
                    }
                    else {
                        renderDeadScreen();
                    }
                }
                else {

                    menu(kredi, tut);
                }
                b = a;
            }
            SDL_Event event;
            while (SDL_PollEvent(&event)) {
                processInput(&event);
                if (event.type == SDL_QUIT) {
                    quit = true;
                }
            }

            int targetFrameTime = 1000 / 60;
            if (delta < targetFrameTime) {
                SDL_Delay(targetFrameTime - delta);
            }
        }
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
    }
    argazkiak_itxi();
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
    return 0;
}
