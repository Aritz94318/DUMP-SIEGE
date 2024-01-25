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
void processInput(SDL_Event* event) {
    if (event->type == SDL_QUIT) {
        quit = true;
    }
    else if (event->type == SDL_MOUSEMOTION) {
        int mouseX = event->motion.x;
        int mouseY = event->motion.y;

        int hoveredRow = mouseY / GRID_SIZE;
        int hoveredCol = mouseX / GRID_SIZE;

        mouseDim[0] = hoveredRow;
        mouseDim[1] = hoveredCol;
    }
    else if (event->type == SDL_KEYDOWN) {

        if (event->key.keysym.sym == SDLK_ESCAPE) {
            quit = true;
        }
    }
    else if (event->type == SDL_MOUSEBUTTONDOWN) {
        int mouseX = event->button.x;
        int mouseY = event->button.y;
        int buttonX = WINDOW_WIDTH - 70;
        int buttonY = WINDOW_HEIGHT - 70;
        int buttonSize = 50;
        int clickedRow = mouseY / GRID_SIZE;
        int clickedCol = mouseX / GRID_SIZE;
        int tower1X = WINDOW_WIDTH - 340;
        int tower1Y = 100;
        int towerSize = 100;
        int tower2X = WINDOW_WIDTH - 340;
        int tower2Y = 350;
        int tower3X = WINDOW_WIDTH - 340;
        int tower3Y = 600;
        int tower4X = WINDOW_WIDTH - 340;
        int tower4Y = 850;
        if (health_jokalaria <= 0) {
            if (mouseX >= (WINDOW_WIDTH / 2) - 100 && mouseX <= ((WINDOW_WIDTH / 2) - 100) + 200 &&
                mouseY >= WINDOW_HEIGHT - 400 && mouseY <= (WINDOW_HEIGHT - 400) + 75) {

                repeat = 1;
            }

        }

        if (menua == 0) {
            if (mouseX >= (WINDOW_WIDTH / 2) - 40 && mouseX <= ((WINDOW_WIDTH / 2) - 40) + 90 &&
                mouseY >= WINDOW_HEIGHT - 225 && mouseY <= WINDOW_HEIGHT - 225 + 35) {
                menua = 1;
            }
            if (mouseX >= 400 && mouseX <= 400 + 130 &&
                mouseY >= WINDOW_HEIGHT - 225 && mouseY <= WINDOW_HEIGHT - 225 + 35) {
                if (kredi == true) {
                    kredi = false;
                }
                else {
                    kredi = true;
                }
            }
            if (mouseX >= WINDOW_WIDTH - 500 && mouseX <= WINDOW_WIDTH - 500 + 130 &&
                mouseY >= WINDOW_HEIGHT - 225 && mouseY <= WINDOW_HEIGHT - 225 + 35) {
                if (tut == true) {
                    tut = false;
                }
                else {
                    tut = true;
                }
            }
        }
        if (mouseX >= buttonX && mouseX <= buttonX + buttonSize &&
            mouseY >= buttonY && mouseY <= buttonY + buttonSize) {
            mostrarPestana = !mostrarPestana;
        }
        else if (mouseX >= tower1X && mouseX <= tower1X + towerSize &&
            mouseY >= tower1Y && mouseY <= tower1Y + towerSize && mostrarPestana == true) {
            towerSelection = 1;
        }
        else if (mouseX >= tower2X && mouseX <= tower2X + towerSize &&
            mouseY >= tower2Y && mouseY <= tower2Y + towerSize && mostrarPestana == true) {
            towerSelection = 2;
        }


        else if (mouseX >= tower3X && mouseX <= tower3X + towerSize &&
            mouseY >= tower3Y && mouseY <= tower3Y + towerSize && mostrarPestana == true) {
            towerSelection = 3;
        }
        else if (mouseX >= tower4X && mouseX <= tower4X + towerSize &&
            mouseY >= tower4Y && mouseY <= tower4Y + towerSize && mostrarPestana == true) {
            towerSelection = 4;
        }


        else if (grid[clickedRow][clickedCol] == 0) {
            if (towerSelection == 1 && dirua >= 3) {
                grid[clickedRow][clickedCol] = 5;
                dorreak[dorre].dorreDim[1] = clickedRow;
                dorreak[dorre].dorreDim[0] = clickedCol;
                dorreak[dorre].dorre_mota = 1;
                dorre++;
                dirua -= 3;
                towerSelection = 0;

            }
            else if (towerSelection == 2 && dirua >= 4) {
                grid[clickedRow][clickedCol] = 6;
                dorreak[dorre].dorreDim[1] = clickedRow;
                dorreak[dorre].dorreDim[0] = clickedCol;

                dorreak[dorre].dorre_mota = 2; dorre++;
                dirua -= 4;
                towerSelection = 0;
            }
            else if (towerSelection == 3 && dirua >= 5) {
                grid[clickedRow][clickedCol] = 7;
                dorreak[dorre].dorreDim[1] = clickedRow;
                dorreak[dorre].dorreDim[0] = clickedCol;
                dorreak[dorre].dorre_mota = 3;
                dorre++;
                dirua -= 5;
                towerSelection = 0;

            }
            else if (towerSelection == 4 && dirua >= 6) {
                grid[clickedRow][clickedCol] = 8;
                dorreak[dorre].dorreDim[1] = clickedRow;
                dorreak[dorre].dorreDim[0] = clickedCol;
                dorreak[dorre].dorre_mota = 4;
                dorre++;
                dirua -= 6;
                towerSelection = 0;
            }


        }



    }

}