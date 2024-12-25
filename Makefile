LIBS = -lSDL2 -lSDL2_image
build:
	g++ -fPIC -shared $(LIBS) ./src/zgame.cpp -o libzgame.so
	

