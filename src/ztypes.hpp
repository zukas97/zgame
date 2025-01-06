#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include "zmessages.h"
using namespace std;

enum Startflags {
	VSYNC = 1,
	NO_VSYNC = 2,
	VERBOSE = 3
};
enum GameState {
		STOPPED,
		GAMEOVER,
		RUNNING
	};
enum ColorList {
	WHITE,
	BLACK,
	RED,
	GREEN,
	BLUE
};
class Sprite;

class Game {
	public:
		struct window {
		    SDL_Window* SDL_win;
		    SDL_Renderer* SDL_rend;
		    int x, y, w, h;
		    string name;
		} win;
		bool is_gravity = false;
		double gravity_multiplier = 1;
		GameState state;
		int FPS = 60;
		int frame_time = (1000/FPS);
		int last_frame_time = SDL_GetTicks();
		float delta;
		vector<Sprite> sprites;

		void update() {
			int wait_time = frame_time - (SDL_GetTicks() - last_frame_time);
			if (wait_time > 0 && wait_time <= frame_time) {
				SDL_Delay(wait_time);
			}
			delta = (SDL_GetTicks() - last_frame_time) / 1000.0f;
			last_frame_time = SDL_GetTicks();
		}

		int init(int flags) {
			ZG_VerboseMessage("initalizing zgame...", NORMAL_MSG, flags);

			// create window
			if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
				perror("Failed to init SDL\n");
				return -1;
			}
			win.SDL_win = SDL_CreateWindow(win.name.c_str(),
					SDL_WINDOWPOS_UNDEFINED,
					SDL_WINDOWPOS_UNDEFINED,
					win.w,
					win.h,
					0);
			if (!win.SDL_win) {
				perror("failed to init window");
				return -1;
			}

			//Create Renderer

			// calculate render flags
			if (flags & !VSYNC || flags & NO_VSYNC) {
				win.SDL_rend = SDL_CreateRenderer(win.SDL_win, -1, SDL_RENDERER_ACCELERATED);
			} else if (flags & VSYNC) {
				win.SDL_rend = SDL_CreateRenderer(win.SDL_win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			} else {
				win.SDL_rend = SDL_CreateRenderer(win.SDL_win, -1, SDL_RENDERER_ACCELERATED);
			}


			if (!win.SDL_rend) {
				perror("failed to init renderer");
				return -1;
			}
			if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG)) {
				perror(IMG_GetError());
				return -1;
			}


			//end of init
			frame_time =  (1000/FPS);
			state = RUNNING;
			return 0;
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
            y = ny;
        }
};

class Sprite {
	public:
		SDL_Surface* surface;
		SDL_Texture* texture;

		Vec2 vel = {0, 0};
		double speed = 1.0;
		SDL_Rect rect;
		int* x = &rect.x;
		int* y = &rect.y;

		int gravity = 250;
		bool is_gravity = false;
		string name;

		int Z = 0;

		Game* game;
		void init(Game* global_game) {
			game = global_game;
			if (game == nullptr) {
				perror("game is NULL");
				exit(1);
			}

		}
		void set_image(string image, double scale) {

			surface = IMG_Load(image.c_str());
			if (surface == NULL) {
				perror("image is NULL");
				exit(1);
			}

			texture = SDL_CreateTextureFromSurface(game->win.SDL_rend, surface);
			SDL_FreeSurface(surface);

			SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
			rect.h *= scale;
			rect.w *= scale;

		}
		void update_pos() {
			rect.x += (vel.x * speed) * (1 +(int)game->delta);
			rect.y += vel.y * speed * game->delta;
			//printf("x vel: %f\n", (vel.x * speed) * game->delta);
			//printf("delta: %f\n", game->delta);
			if (game->is_gravity) {
				if (is_gravity) {
					*y += (gravity * game->gravity_multiplier) * game->delta;
				}
			}

		}
		void destroy_texture() {
			SDL_DestroyTexture(texture);
		}
};

class TextureRect {
	public:
		SDL_Surface* surface = NULL;
		SDL_Texture* texture = NULL;
		SDL_Rect rect;
		Game* game;

		void init(Game global_game) {
			game = &global_game;
		}

		void set_image(string image) {
			surface = IMG_Load(image.c_str());
			if (surface == NULL) {
				perror("image is NULL");
			}
			texture = SDL_CreateTextureFromSurface(game->win.SDL_rend, surface);
			SDL_FreeSurface(surface);
		}

		void render_add() {
			if (texture == NULL) {
				perror("texture is NULL\n");
				return;
			}
			SDL_RenderCopy(game->win.SDL_rend, texture, NULL, &rect);

		}
};

