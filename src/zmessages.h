#ifndef ZMESSAGES_H
#define ZMESSAGES_H 
#include <iostream>

#define NORMAL_MSG 0
#define WARNING 1
#define ERROR -1
using namespace std;

int ZG_VerboseMessage(string message, int type, int flags);

void ZG_MessageBox(string title, string message, int type);

#endif
