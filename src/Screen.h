#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL2/SDL.h>

namespace render {

class Screen {
public:
	const static int SCREEN_WIDTH = 800;
	const static int SCREEN_HEIGHT = 600;
	const static int TOTAL_PIXELS = SCREEN_WIDTH * SCREEN_HEIGHT;
private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;
	SDL_Texture* _texture;
	Uint32* _buffer;

public:
	Screen();
	bool init();
	void close();
	bool processEvents();
};

} /* namespace render */

#endif /* SCREEN_H_ */
