#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <iostream>
using namespace std;
enum GameState {
		STOPPED,
		GAMEOVER,
		RUNNING
	};
class Game {
	public:
		struct window {
		    SDL_Window* SDL_win;
		    SDL_Renderer* SDL_rend;
		    int x, y, w, h;
		    string name;
		} win;
		GameState state;
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

class TextureRect {
	public:
		SDL_Surface* surface = NULL;
		SDL_Texture* texture = NULL;
		SDL_Rect rect;
		void set_image(Game game, string image) {
			surface = IMG_Load(image.c_str());
			if (surface == NULL) {
				perror("image is NULL");
			}
			texture = SDL_CreateTextureFromSurface(game.win.SDL_rend, surface);
			SDL_FreeSurface(surface);
		}

		void render(Game game) {
			if (texture == NULL) {
				printf("E: texture is NULL\n");
				return;
			}
			SDL_RenderCopy(game.win.SDL_rend, texture, NULL, &rect);

		}
};

