LIBS = -lSDL2 -lSDL2_image
build:
	g++ -fPIC -shared -c $(LIBS) ./src/zrenderer.cpp -o zrenderer.o
	g++ -fPIC -shared -c $(LIBS) ./src/zgame.cpp -o zgame.o
	g++ -fPIC -shared -c $(LIBS) ./src/zmessages.cpp -o zmessages.o
	g++ -fPIC -shared  $(LIBS) zgame.o zrenderer.o zmessages.o -o libzgame.so
	rm *.o
test:
	make build
	cp libzgame.so test
	

