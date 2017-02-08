#include "Screen.h"

namespace render {

Screen::Screen() :
		_window(NULL), _renderer(NULL), _texture(NULL), _buffer1(NULL), _buffer2(NULL) {

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

	_buffer1 = new Uint32[TOTAL_PIXELS];
	_buffer2 = new Uint32[TOTAL_PIXELS];

	memset(_buffer1, 0, TOTAL_PIXELS * sizeof(Uint32));
	memset(_buffer2, 0, TOTAL_PIXELS * sizeof(Uint32));


	return true;
}
//--------------------------------------------------------------------------------------
void Screen::close() {
	delete[] _buffer1;
	delete[] _buffer2;
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
	}

	return true;
}
//--------------------------------------------------------------------------------------
void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue){
	if(x < 0 || x >= SCREEN_WIDTH ||
	   y < 0 || y >= SCREEN_HEIGHT)
		return;

	Uint32 color = 0;

	color += red;
	color <<= 8;

	color += green;
	color <<= 8;

	color += blue;
	color <<=8;

	color += 0xFF;

	_buffer1[y * SCREEN_WIDTH + x] = color;
}
//--------------------------------------------------------------------------------------
void Screen::clearBuffer(){
	memset(_buffer1, CLEAR_COLOR, TOTAL_PIXELS * sizeof(Uint32));
	//memset(_buffer2, CLEAR_COLOR, TOTAL_PIXELS * sizeof(Uint32));
}
//--------------------------------------------------------------------------------------
void Screen::blur(){
	// swap buffers
	Uint32* temp = _buffer1;
	_buffer1 = _buffer2;
	_buffer2 = temp;

	for(int y = 1; y < SCREEN_HEIGHT - 1; y++){
		for(int x = 1; x < SCREEN_WIDTH - 1; x++){

			int redTotal = 0;
			int greenTotal = 0;
			int blueTotal = 0;

			for(int row = -1; row <= 1; row++){
				for(int col = -1; col <= 1; col++){

					int curX = x + col;
					int curY = y + row;

					Uint32 color = _buffer2[curY * SCREEN_WIDTH + curX];
					Uint8 red = color >> 24;
					Uint8 green = color >> 16;
					Uint8 blue = color >> 8;

					redTotal += red;
					greenTotal += green;
					blueTotal += blue;

				}
			}

			Uint8 red = redTotal / 9;
			Uint8 green = greenTotal / 9;
			Uint8 blue = blueTotal / 9;

			setPixel(x, y, red, green, blue);

		}
	}

}
//--------------------------------------------------------------------------------------
void Screen::update(){
	SDL_UpdateTexture(_texture, NULL, _buffer1, SCREEN_WIDTH * sizeof(Uint32));
    //SDL_SetRenderDrawColor(_renderer, 0, 0, 255, 255);
	SDL_RenderClear(_renderer);
	SDL_RenderCopy(_renderer, _texture, NULL, NULL);
	SDL_RenderPresent(_renderer);
	//clearBuffer();
}
//--------------------------------------------------------------------------------------

} /* namespace render */
