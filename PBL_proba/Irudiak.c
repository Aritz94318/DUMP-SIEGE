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

void argazkiak() {
    SDL_Surface* surface = IMG_Load("smile.png");
    entityTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    surface = IMG_Load("istockphoto-1334677938-612x612.png");

    valueZeroTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("pixil-frame-0.png");

    valueTwoTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("suelo.png");

    valueOneTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("pixil-frame-0.png");

    valueThreeTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("bellegia.png");

    valueFourTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    surface = IMG_Load("RED.png");

    valueFiveTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    surface = IMG_Load("urdina.png");

    valueSixTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    surface = IMG_Load("Grisa.png");

    valueSevenTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    surface = IMG_Load("marroia.png");
    valueEightTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    surface = IMG_Load("errefusa.png");
    entityTexture2 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    surface = IMG_Load("sagarra.png");
    entityTexture3 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    surface = IMG_Load("papela.png");
    entityTexture4 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    surface = IMG_Load("menua.jpg");
    backgroundImage = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    surface = IMG_Load("urdinamenurako.png");
    urdmenu = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    surface = IMG_Load("marroiamenurako.png");
    marmenu = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    surface = IMG_Load("grisAmenurako.png");
    grimenu = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    surface = IMG_Load("bellegiamenurako.png");
    hormenu = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);





}
void argazkiak_itxi(){
    SDL_DestroyTexture(entityTexture);
    SDL_DestroyTexture(entityTexture2);
    SDL_DestroyTexture(entityTexture3);
    SDL_DestroyTexture(entityTexture4);
    SDL_DestroyTexture(valueZeroTexture);
    SDL_DestroyTexture(valueTwoTexture);
    SDL_DestroyTexture(valueOneTexture);
    SDL_DestroyTexture(valueThreeTexture);
    SDL_DestroyTexture(valueFourTexture);
    SDL_DestroyTexture(valueFiveTexture);
    SDL_DestroyTexture(valueSixTexture);
    SDL_DestroyTexture(valueSevenTexture);
    SDL_DestroyTexture(valueEightTexture);
    SDL_DestroyTexture(marmenu);
    SDL_DestroyTexture(urdmenu);
    SDL_DestroyTexture(hormenu);
    SDL_DestroyTexture(grimenu);
}