#ifndef ZGAME_H
#define ZGAME_H
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "ztypes.hpp"
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

using namespace std;




void ZG_add_vector(Vec2 vector, int x, int y);
void ZG_Sprite_add_vector(Vec2 vector, Sprite sprite);

void ZG_Init_Renderer(Game game, SDL_Color background);
void ZG_Render_Image(Game game, SDL_Texture* texture);
void ZG_Render_Sprite(Game game, Sprite sprite);
void ZG_Render_Update(Game game);

bool ZG_Is_Key_Pressed(Game game, int key);
bool ZG_Is_Quitting(Game game);

bool ZG_Sprites_Colliding(Sprite sprite1, Sprite sprite2);

#endif
