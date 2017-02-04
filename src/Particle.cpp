#include "Particle.h"
#include "Screen.h"

namespace render {

Particle::Particle(): x(0), y(0) {
	direction = randomNum(0, M_PI * 2);
	speed = randomNum(MIN_SPEED, MAX_SPEED);

	xSpeed = speed * cos(direction);
	ySpeed = speed * sin(direction);

	red   = randomNum(0, 255);
	green = randomNum(0, 255);
	blue  = randomNum(0, 255);
}

Particle::~Particle() {
}

void Particle::update(int time){
	x += xSpeed * Screen::SCREEN_HEIGHT / Screen::SCREEN_WIDTH;
	y += ySpeed;
}

double Particle::randomNum(double min, double max){
	double f = (double)rand() / RAND_MAX;
	return min + f * (max - min);
}

} /* namespace render */
