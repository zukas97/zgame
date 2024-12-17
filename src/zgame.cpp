#include "./zgame.hpp"
#include <SDL2/SDL_render.h>

SDL_Color red = {255, 0, 0, 255};
SDL_Color green = {0, 255, 0, 255};
SDL_Color blue = {0, 0, 255, 255};
SDL_Color black = {0, 0, 0, 255};
SDL_Color white = {255, 255, 255, 255};

void ZG_Init_Renderer(Game game, SDL_Color background) {
	SDL_SetRenderDrawColor(game.win.SDL_rend, background.r, background.g, background.b, background.a);
	SDL_RenderClear(game.win.SDL_rend);
}


void ZG_Render_Image(SDL_Renderer* rend, SDL_Texture* texture, SDL_Rect rect) {
	SDL_RenderClear(rend);

	SDL_RenderCopy(rend, texture, NULL, &rect);
	SDL_RenderPresent(rend);
}

void ZG_GetInput() {
	SDL_Event event;
}
