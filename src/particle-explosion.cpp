#include <iostream>
#include <SDL2/SDL.h>
#include "Screen.h"

using namespace std;
using namespace render;

//--------------------------------------------------------------------------------------
int main() {
	Screen screen;
	screen.init();

	while (true) {

		if(screen.processEvents() == false) break;

	} // while !quit

	screen.close();
	return 0;
}
//--------------------------------------------------------------------------------------
