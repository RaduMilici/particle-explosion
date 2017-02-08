#include <iostream>
#include <stdlib.h>
#include <SDL2/SDL.h>

#include "Screen.h"
#include "Swarm.h"

using namespace std;
using namespace render;

//--------------------------------------------------------------------------------------
int main() {
	srand(time(NULL));

	Swarm swarm;
	Screen screen;
	int elapsed;
	int side = 8;
	const Particle* const particles = swarm.getParticles();

	screen.init();


	while (true) {
		elapsed = SDL_GetTicks();

		if(screen.processEvents() == false) break;

		swarm.update(elapsed);

		for(int i = 0; i < Swarm::PARTICLES_NUM; i++){
			Particle p = particles[i];

			int x = (p.x + 1) * (Screen::SCREEN_WIDTH / 2);
			int y = (p.y + 1) * (Screen::SCREEN_HEIGHT / 2);

			screen.setPixel(x, y, p.red, p.green, p.blue);

			//squares
			for(int w = -side / 2; w < side / 2; w++){
				for(int h = -side / 2; h < side / 2; h++){
					screen.setPixel(x + w, y + h, p.red, p.green, p.blue);
				}
			}

		}

		screen.blur();
		screen.update();

	}

	screen.close();
	return 0;

	/*
		int iterations = 30;
		double minRe = -2.0;
		double maxRe = 1.0;
		double minIm = -1.2;
		double maxIm = minIm + (maxRe - minRe) * Screen::SCREEN_HEIGHT / Screen::SCREEN_WIDTH; // 1.2?
		double reFactor = (maxRe - minRe) / (Screen::SCREEN_WIDTH  - 1);
		double imFactor = (maxIm - minIm) / (Screen::SCREEN_HEIGHT - 1);

	  	while (true) {
		ticks = SDL_GetTicks() * 0.001;

		if(screen.processEvents() == false) break;

		for(int x = 0; x < Screen::SCREEN_WIDTH; x++){
			double cRe = minRe + x * reFactor;

			for(int y = 0; y < Screen::SCREEN_HEIGHT; y++){
				bool isInside = true;
				double cIm = maxIm - y * imFactor;
				double zRe = cRe;
				double zIm = cIm;
				int i = 0;

				for(i = 0; i < iterations; i++){

					double zRe2 = zRe * zRe;
					double zIm2 = zIm * zIm;

					if(zRe2 + zIm2 > 4){
						isInside = false;
						break;
					}

					zIm = 2 * zRe * zIm + cIm;
					zRe = zRe2 - zIm2 + cRe;

				}

				if(isInside)
					screen.setPixel(x, y, 0, 0, 255);
				else
					screen.setPixel(x, y, 0, 0, 0);

			}
		}
		screen.update();
	}*/
}
//--------------------------------------------------------------------------------------
