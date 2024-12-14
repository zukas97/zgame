#ifndef ZGAME_H
#define ZGAME_H
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
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


class Game {
	public:
		struct window {
		    SDL_Window* SDL_win;
		    SDL_Renderer* SDL_rend;
		    int x, y, w, h;
		    char* name;
		} win;
		enum state {
			STOPPED,
			GAMEOVER,
			RUNNING
		};
		int init() {
			printf("initalizing zgame...\n");
			if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
				perror("Failed to init SDL\n");
				return -1;
			}
			win.SDL_win = SDL_CreateWindow(win.name,
					SDL_WINDOWPOS_CENTERED,
					SDL_WINDOWPOS_CENTERED,
					win.w,
					win.h,
					0);
			if (!win.SDL_win) {
				perror("failed to init window");
				return -1;
			}
			win.SDL_rend = SDL_CreateRenderer(win.SDL_win, -1, SDL_RENDERER_ACCELERATED);
			if (!win.SDL_rend) {
				perror("failed to init renderer");
				return -1;
			}
			if (!IMG_Init(IMG_INIT_PNG || IMG_INIT_JPG)) {
				perror(IMG_GetError());
				return -1;
			}
			return 0;
		}
		void set_background_color() {

		}
		void destroy() {
			SDL_DestroyRenderer(win.SDL_rend);
			SDL_DestroyWindow(win.SDL_win);
			SDL_Quit();
		}
};

class Sprite {
	public:
		SDL_Surface* surface;
		SDL_Texture* texture;
		void set_image(Game game, char* image) {
			surface = IMG_Load(image);
			if (surface == NULL) {
				perror("image is NULL");
			}
			SDL_CreateTextureFromSurface(game.win.SDL_rend, surface);
			SDL_FreeSurface(surface);
		}
		SDL_Rect rect;
};

void ZG_Init_Renderer(Game game);


#endif
