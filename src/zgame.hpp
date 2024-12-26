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
		    string name;
		} win;
		enum State {
			STOPPED,
			GAMEOVER,
			RUNNING
		};
		State state;
		int init() {
			printf("initalizing zgame...\n");
			if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
				perror("Failed to init SDL\n");
				return -1;
			}
			win.SDL_win = SDL_CreateWindow(win.name.c_str(),
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

			state = RUNNING;
			return 0;
		}
		void set_background_color() {

		}
		void destroy() {
			SDL_DestroyRenderer(win.SDL_rend);
			SDL_DestroyWindow(win.SDL_win);
			SDL_Quit();
		}

		SDL_Event input_event;

};
class Vec2 {
    public:
        int x, y;

        void init(int nx, int ny) {
            x = nx;
            x = ny;
        }
};

class Sprite {
	public:
		SDL_Surface* surface;
		SDL_Texture* texture;
		Vec2 vel = {0, 0};
		SDL_Rect rect;
		int x, y;
		void set_image(Game game, string image) {
			surface = IMG_Load(image.c_str());
			if (surface == NULL) {
				perror("image is NULL");
			}
			texture = SDL_CreateTextureFromSurface(game.win.SDL_rend, surface);
			SDL_FreeSurface(surface);
		}
		void update_pos() {
			x += vel.x;
			y += vel.y;
			rect.x = x;
			rect.y = y;
		}
};


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
