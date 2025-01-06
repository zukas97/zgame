#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <algorithm>
#include "zgame.hpp"
#include "zmessages.h"

using namespace std;

void ZG_Init_Renderer(Game game, SDL_Color background) {
	SDL_SetRenderDrawColor(game.win.SDL_rend, background.r, background.g, background.b, background.a);
	SDL_RenderClear(game.win.SDL_rend);
}

void ZG_Render_Image(Game game, SDL_Texture* texture, SDL_Rect rect) {
	
	SDL_RenderClear(game.win.SDL_rend);

	SDL_RenderCopy(game.win.SDL_rend, texture, NULL, &rect);
}
bool compare_by_Z(const Sprite& s1, const Sprite& s2) {
	return s1.Z < s2.Z;
}
void ZG_Render_Add_Sprite(Game game, Sprite sprite) {
	game.sprites.push_back(sprite);
	sort(game.sprites.begin(), game.sprites.end(), compare_by_Z);
	for (int i=0; i < game.sprites.size(); i++) {
		SDL_RenderCopy(game.win.SDL_rend, game.sprites.at(i).texture, NULL, &game.sprites.at(i).rect);
	}
}
void ZG_Render_Update(Game game){
	SDL_RenderPresent(game.win.SDL_rend);
	SDL_RenderClear(game.win.SDL_rend);
}
