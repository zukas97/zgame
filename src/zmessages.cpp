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
