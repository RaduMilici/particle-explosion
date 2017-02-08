#include "Particle.h"
#include "Screen.h"

namespace render {

int Particle::num = 0;

Particle::Particle() {
	direction = randomNum(0, M_PI * 2);
	speed = randomNum(MIN_SPEED, MAX_SPEED);
	num++;

	x = randomNum(-0.5, 0.5);
	y = randomNum(-0.5, 0.5);

	randomColor();

	radius = randomNum(0.1, 0.9);
}

Particle::~Particle() {}

void Particle::update(double delta){
	x = sin(delta) * (cos(direction - delta * speed) * Screen::SCREEN_HEIGHT / Screen::SCREEN_WIDTH);
	y = sin(delta) * (sin(direction - delta * speed));

	//x += xSpeed * Screen::SCREEN_HEIGHT / Screen::SCREEN_WIDTH * delta;
	//y += ySpeed * delta;
}

double Particle::randomNum(double min, double max){
	double f = (double)rand() / RAND_MAX;
	return min + f * (max - min);
}

void Particle::randomColor(){
	red   = randomNum(0, 255);
	blue  = randomNum(0, 255);
	green = randomNum(0, 255);
}

} /* namespace render */
