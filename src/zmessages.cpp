#include <SDL2/SDL.h>
#include <SDL2/SDL_messagebox.h>
#include "zmessages.h"

int ZG_VerboseMessage(string message, int type, int flags) {
	string head;
	switch (type) {
		case NORMAL_MSG:
			head = "ZG: ";
			break;
		case WARNING:
			head = "W: ";
			break;
		case ERROR:
			head = "E: ";
			break;
		default:
			head = "ZG: ";

	}
	if (flags == 3) {
		cout << head << message << endl;
		return 0;
	}
	return 1;
}
void ZG_MessageBox(string title, string message, int type) {
	uint32_t flag;
	switch (type) {
		case NORMAL_MSG:
			flag = SDL_MESSAGEBOX_INFORMATION;
			break;
		case WARNING:
			flag = SDL_MESSAGEBOX_WARNING;
			break;
		case ERROR:
			flag = SDL_MESSAGEBOX_ERROR;
	}

	SDL_ShowSimpleMessageBox(flag, title.c_str(), message.c_str(), NULL);
	
}
