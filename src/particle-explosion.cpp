#include <iostream>
#include <SDL2/SDL.h>
#include "Screen.h"

using namespace std;
using namespace render;

//--------------------------------------------------------------------------------------
int main() {
	Screen screen;
	screen.init();
	int time = 0;
	int amp = 150;
	double freq = 0.05;
	int halfHeight = screen.SCREEN_HEIGHT / 2;
	double speed = 0.5;
	int thick = 25;

	while (true) {
		time = SDL_GetTicks();

		if(screen.processEvents() == false) break;


		/*for(int x = 0; x < screen.SCREEN_WIDTH; x++){
			for(int y = 0; y < screen.SCREEN_HEIGHT; y++){
				screen.setPixel(x, y, 255, 0, 0);
			}
		}*/
		for(int x = 0; x < screen.SCREEN_WIDTH; x++){
			int y = halfHeight + amp * sin(x * freq);

			for(int th = -thick / 2; th < thick / 2; th++){
				int thx = th + x;
				screen.setPixel(thx + time * speed,  y, 255, 0, 0);
			}
		}

		screen.update();

	}

	screen.close();
	return 0;
}
//--------------------------------------------------------------------------------------
