#include "./zgame.hpp"
#include <SDL2/SDL_render.h>

SDL_Color red = {255, 0, 0, 255};
SDL_Color green = {0, 255, 0, 255};
SDL_Color blue = {0, 0, 255, 255};
SDL_Color black = {0, 0, 0, 255};
SDL_Color white = {255, 255, 255, 255};

void ZG_add_vector(Vec2 vector, int* x, int* y) {
	*x += vector.x;
	*y += vector.y;
}

void ZG_Sprite_add_vector(Vec2 vector, Sprite sprite) {
	sprite.rect.x += vector.x;
	sprite.rect.y += vector.y;
}

void ZG_Init_Renderer(Game game, SDL_Color background) {
	SDL_SetRenderDrawColor(game.win.SDL_rend, background.r, background.g, background.b, background.a);
	SDL_RenderClear(game.win.SDL_rend);
}


void ZG_Render_Image(Game game, SDL_Texture* texture, SDL_Rect rect) {
	
	SDL_RenderClear(game.win.SDL_rend);

	SDL_RenderCopy(game.win.SDL_rend, texture, NULL, &rect);
	SDL_RenderPresent(game.win.SDL_rend);
}

void ZG_Render_Update(Game game){
	SDL_RenderClear(game.win.SDL_rend);
	SDL_RenderPresent(game.win.SDL_rend);
}

bool ZG_Is_Key_Pressed(Game game, int key) {
	while (SDL_PollEvent(&game.input_event)) {
		if (game.input_event.key.keysym.sym == key) {
			return true;
		}
	}
	return false;
}

bool ZG_Is_Quitting(Game game) {
	while (SDL_PollEvent(&game.input_event)) {
		if (game.input_event.type == SDL_QUIT) {
			return true;
		}
	}
	return false;

}
