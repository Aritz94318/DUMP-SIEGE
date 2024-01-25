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
void initializeGrid() {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            grid[i][j] = 0;
        }
    }
}
void generateRandomPath() {

    srand((unsigned int)time(NULL));
    int direction;
    int i, o = 0;
    int currentCol = COLS / 2;
    int currentRow = ROWS - 1;

    grid[currentRow][currentCol] = 1;

    while (currentCol < COLS - 1 && currentRow > 0 && currentCol > 0) {
        for (i = 0; i < 2 + rand() % 4 && currentRow > 0; i++) {
            grid[currentRow][currentCol] = 1;
            currentRow--;
        }

        currentRow++;

        direction = rand() % 2;
        if (direction == 0) {
            for (i = 0; i < 1 + rand() % 6 && currentCol > 0 && currentRow > 1; i++) {
                currentCol--;
                grid[currentRow][currentCol] = 1;
            }
        }
        else if (direction == 1) {
            for (i = 0; i < rand() % 6 && currentRow > 1 && currentCol < COLS - 1; i++) {
                currentCol++;
                grid[currentRow][currentCol] = 1;
            }
        }

        currentRow--;
    }
    grid[currentRow][currentCol] = 1;

    hasieraRow = currentRow;
    hasieraCol = currentCol;
}
void zuhaitzak() {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (grid[i - 1][j] == 0 && grid[i + 1][j] == 0 && grid[i][j - 1] == 0 && grid[i][j + 1] == 0 &&
                grid[i][j] == 0 && rand() % 30 == 0) {
                grid[i][j] = 3;
            }
        }
    }
}