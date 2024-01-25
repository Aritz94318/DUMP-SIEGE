#pragma once
#include <stdbool.h>
#include <SDL_ttf.h>

#include <SDL_mixer.h>
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define GRID_SIZE 24
#define ROWS WINDOW_HEIGHT / GRID_SIZE
#define COLS WINDOW_WIDTH / GRID_SIZE
#define ENTITY_SPEED 0.09
#define MAX_HEALTH_JOKALARIA 100
#define ENTITYKOPURUA 200
#define DAMAGE_ENTITY 20

#define DAMAGE_JOKALARIA 10
#define DIRUA_MAX 200
#define BULLET_DAMAGE 25
extern int dorre;
extern int dirua;
extern bool quit;
extern int gei;

extern int repeat ;
extern int menua ;
extern int lastDisappearTime ;
extern float mouseDim[2];
extern int grid[ROWS][COLS];

extern int n;
extern int health_jokalaria;
extern int kopurua;
extern int hasieraRow;
extern int hasieraCol;
extern int defi;
extern int frame;
extern int RoundCount;
extern int KillCount;
extern int denboraagertu;
extern int aurreko_frame;

extern bool mostrarPestana;
extern int towerSelection ;
struct entities {
    int Zaborren_Bizitza;
    float entityDim[2];
    int ezkesk;
    float z;
    int bai;
    int mota;

};
extern struct entities entity[100];
 struct Bullet {
    float position[2];
    float speed;
    bool active;
    float direction[3];
    int targetEntityIndex;
    bool bulletHitEntity;
    int bullet_mota;
};
extern struct Bullet bullets[100];

extern bool kredi;
extern bool tut ;
struct Horia {
    float dorreDim[2];
    int targetEntityIndex;
    int dorre_mota;
};
extern struct Horia dorreak[100];
extern SDL_Window* window ;
extern SDL_Renderer* renderer ;
extern SDL_Texture* valueZeroTexture ;
extern SDL_Texture* valueTwoTexture ;
extern SDL_Texture* valueOneTexture ;
extern SDL_Texture* valueFourTexture ;
extern SDL_Texture* valueThreeTexture;
extern SDL_Texture* valueFiveTexture;
extern SDL_Texture* valueSixTexture ;
extern SDL_Texture* valueSevenTexture ;
extern SDL_Texture* valueEightTexture ;
extern SDL_Texture* entityTexture ;
extern SDL_Texture* entityTexture2 ;
extern SDL_Texture* entityTexture3 ;
extern SDL_Texture* entityTexture4 ;
extern SDL_Texture* backgroundImage ;
extern SDL_Texture* urdmenu ;
extern SDL_Texture* marmenu ;
extern SDL_Texture* grimenu ;
extern SDL_Texture* hormenu ;
extern TTF_Font* font;
extern Mix_Music* music;