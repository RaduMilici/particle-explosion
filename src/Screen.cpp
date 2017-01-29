#include "Screen.h"

namespace render {

Screen::Screen() :
		_window(NULL), _renderer(NULL), _texture(NULL), _buffer(NULL) {

}
//--------------------------------------------------------------------------------------

bool Screen::init() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		SDL_Quit();
		return false;
	}

	_window = SDL_CreateWindow("particle explosion",
	SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_PRESENTVSYNC);

	_texture = SDL_CreateTexture(_renderer, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

	_buffer = new Uint32[TOTAL_PIXELS];

	memset(_buffer, 0, TOTAL_PIXELS * sizeof(Uint32));

	SDL_UpdateTexture(_texture, NULL, _buffer, SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(_renderer);
	SDL_RenderCopy(_renderer, _texture, NULL, NULL);
	SDL_RenderPresent(_renderer);

	return true;
}
//--------------------------------------------------------------------------------------
void Screen::close() {
	delete[] _buffer;
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyTexture(_texture);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}
//--------------------------------------------------------------------------------------
bool Screen::processEvents() {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			return false;
		}
	} // SDL_PollEvent
	return true;
}
//--------------------------------------------------------------------------------------

} /* namespace render */
