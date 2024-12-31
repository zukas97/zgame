#include "./zgame.hpp"
#include <SDL2/SDL_render.h>

extern SDL_Color red;// = {255, 0, 0, 255};
extern SDL_Color green;// = {0, 255, 0, 255};
extern SDL_Color blue;// = {0, 0, 255, 255};
extern SDL_Color black;// = {0, 0, 0, 255};
extern SDL_Color white;// = {255, 255, 255, 255};

void ZG_Init_Colors() {
	red = {255, 0, 0, 255};
	green = {0, 255, 0, 255};
	blue = {0, 0, 255, 255};
	black = {0, 0, 0, 255};
	white = {255, 255, 255, 255};
}

void ZG_add_vector(Vec2 vector, int* x, int* y) {
	*x += vector.x;
	*y += vector.y;
}

void ZG_Sprite_add_vector(Vec2 vector, Sprite sprite) {
	sprite.rect.x += vector.x;
	sprite.rect.y += vector.y;
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

bool ZG_Sprites_Colliding(Sprite sprite1, Sprite sprite2) {
	if (SDL_HasIntersection(&sprite1.rect, &sprite2.rect)) {
		return true;
	}
	return false;
}

