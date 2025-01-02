#include <iostream>
#include <SDL2/SDL.h>
#include "zgame.hpp"
void ZG_Init_Renderer(Game game, SDL_Color background) {
	SDL_SetRenderDrawColor(game.win.SDL_rend, background.r, background.g, background.b, background.a);
	SDL_RenderClear(game.win.SDL_rend);
}


void ZG_Render_Image(Game game, SDL_Texture* texture, SDL_Rect rect) {
	
	SDL_RenderClear(game.win.SDL_rend);

	SDL_RenderCopy(game.win.SDL_rend, texture, NULL, &rect);
}
void ZG_Render_Sprite(Game game, Sprite sprite) {
	SDL_RenderCopy(game.win.SDL_rend, sprite.texture, NULL, &sprite.rect);
}
void ZG_Render_Update(Game game){
	SDL_RenderPresent(game.win.SDL_rend);
	SDL_RenderClear(game.win.SDL_rend);
}
