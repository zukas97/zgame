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
<br />
<br />
# Destroy and Exit
To cleanly Exit run:
```C++
game.destroy();
```
