# Game
## Game
The `game` class stores the window info, and `SDL_Window` and `SDL_Renderer` structs.

This is mainly usedto init and deinit zgame
```C++
Game game;
game.init(); // run this before main loop
game.destroy(); // run this after main loop
```

## Sprite
The `Sprite` class stores, the dimensions, position, and texture of the sprite. 
### Sprite.rect
this is a sprite's [SDL_Rect](https://wiki.libsdl.org/SDL2/SDL_Rect). you can update it's x and y values if you don't want to call `update_pos()` after you change them.

### example use
```C++
Sprite sprite;
sprite.init(&game);
sprite.set_image("image.png");
sprite.update_pos(); // updates the position of it's SDL_Rect based on sprite.x, sprite.y, sprite.vel, and gravity
```

