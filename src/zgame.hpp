#include <iostream>
#include <SDL2/SDL.h>
/*
typedef struct Zgame {
    SDL_Window* win;
    SDL_Renderer* rend;
    enum gamestate = {
        STOPPED,
        GAMEOVER,
        RUNNING
    }
} Game;*/

class Game {
    public:
    SDL_Window* win;
    SDL_Renderer* rend;
    enum gamestate = {
        STOPPED,
        GAMEOVER,
        RUNNING
    }
}

int ZG_Init(Game game);