#include <iostream>
#include <SDL2/SDL.h>

typedef struct Zgame {
    SDL_Window* win;
    SDL_Renderer* rend;
    enum gamestate = {
        STOPPED,
        GAMEOVER,
        RUNNING
    }
} Game;

int ZG_Init(Game game);