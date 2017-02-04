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
	int ticks;
	int side = 3;
	const Particle* const particles = swarm.getParticles();

	screen.init();

	while (true) {
		ticks = SDL_GetTicks();

		if(screen.processEvents() == false) break;

		swarm.update(ticks);

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

		screen.update();

	}

	screen.close();
	return 0;
}
//--------------------------------------------------------------------------------------
