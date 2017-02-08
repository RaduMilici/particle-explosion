#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL2/SDL.h>

namespace render {

class Screen {
public:
	const static int SCREEN_WIDTH = 1000;
	const static int SCREEN_HEIGHT = 800;
	const static int TOTAL_PIXELS = SCREEN_WIDTH * SCREEN_HEIGHT;
	const static int CLEAR_COLOR = 0x00000000;
private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;
	SDL_Texture* _texture;
	Uint32* _buffer1;
	Uint32* _buffer2;

public:
	Screen();
	bool init();
	void close();
	bool processEvents();
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	void clearBuffer();
	void update();
	void blur();
};

} /* namespace render */

#endif /* SCREEN_H_ */
