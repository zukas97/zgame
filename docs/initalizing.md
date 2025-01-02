# Initalizing Zgame
The first step is creating a `Game` frome the `Game` class
```C++
Game game;
```
Then you must set some properties and calle `Game.init()`
```C++
Game game;
game.win.w = 1280;
game.win.h = 720;
game.win.name = "Test Game"
game.init();

```
<br />

# Destroy and Exit
To cleanly Exit run:
```C++
game.destroy();
```
# Main Loop
For a game, it is seggested to have a main loop, sometimes called the gameloop. Here is an example:
```C++

SDL_Color black = {0, 0, 0, 0};


int main() {
	Game game;
    //set game properties
	game.win.w = 500;
	game.win.h = 500;
	game.win.name = "test";
	game.init();

    //create a sprite
	Sprite sprite;
	sprite.init(&game);
	sprite.set_image("test.png");
	sprite.rect.x = game.win.w / 2;
	sprite.rect.y = game.win.h / 2;
	sprite.rect.w = 100;
	sprite.rect.h = 100;


    //init the renderer
	ZG_Init_Renderer(game, black);

    //game loop
	while (game.state == RUNNING) {
		ZG_Render_Update(game);
		if (ZG_Is_Quitting(game)) { //detect if the window is closed
			game.state = STOPPED;
		}
		ZG_Render_Sprite(game, sprite); //add the sprite to the renderer


	}


	game.destroy(); //clean up and exit
    return 0;
}
```
