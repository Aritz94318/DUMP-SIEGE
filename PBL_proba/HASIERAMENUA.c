#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include "Pantalla.h"
#include "menua.h"
#include "text_render.h"

void kredituak() {
    renderRectangulo(200, 200, 400, 600, 50, 100, 50, 255);
    renderText("-Aritz Ugarte", 400, 600);
    renderText("-Eneko Urien", 400, 650);
    renderText("-Asier Otxoa", 400, 700);
    renderText("-Aimar Zabala", 400, 750);

}
void tuto() {
    renderRectangulo(1000, 200, ((WINDOW_WIDTH / 2) - 325), 600, 50, 50, 50, 255);
    renderText("Jokoan zabor desberdinak rondaka etorriko dira.", ((WINDOW_WIDTH / 2) - 175), 610, 255, 0, 0);
    renderText("Hauei aurka egiteko, zakarrontziak jarri beharko dira.", ((WINDOW_WIDTH / 2) - 200), 660, 255, 0, 0);
    renderText("Zakarrontzi hauek energia behar dute, eta hori birziklatzen lortzen da.", ((WINDOW_WIDTH / 2) - 290), 710, 255, 0, 0);
    renderText("Zakarrontzi mota bakoitzak zabor mota bateri kalte bikoitza egingo dio.", ((WINDOW_WIDTH / 2) - 300), 760, 255, 0, 0);

}
void menu(int kredi,int tut) {


    SDL_Surface* surface = IMG_Load("menua.jpg"); 
    backgroundImage = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    SDL_RenderCopy(renderer, backgroundImage, NULL, NULL);
    SDL_RenderPresent(renderer);
    renderRectangulo(130, 35, 400, WINDOW_HEIGHT - 225, 50, 50, 50, 255);
    renderText("Kredituak", 400, WINDOW_HEIGHT - 225, 255, 0, 0);
    renderRectangulo(90, 35, ((WINDOW_WIDTH / 2) - 40), WINDOW_HEIGHT - 225, 50, 50, 50, 255);
    renderText("Jolastu", ((WINDOW_WIDTH / 2) - 40), WINDOW_HEIGHT - 225, 255, 0, 0);
    renderRectangulo(130, 35,WINDOW_WIDTH- 500, WINDOW_HEIGHT - 225, 50, 50, 50, 255);
    renderText("Azalpenak",WINDOW_WIDTH- 500, WINDOW_HEIGHT - 225, 255, 0, 0);
    if (kredi == true){
        kredituak();
   } 
    if (tut == true) {
        tuto();
    }
  
    SDL_RenderPresent(renderer);

}
