#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;

namespace render {

class Particle {
public:
	static int num;
	static const double MIN_SPEED = 0.5;
	static const double MAX_SPEED = 1;

	Particle();
	virtual ~Particle();

	double x;
	double y;
	double speed;
	double direction;

	unsigned char red;
	unsigned char green;
	unsigned char blue;

	void update(double delta);
private:
	double xSpeed;
	double ySpeed;
	double radius;
	double randomNum(double min, double max);
	void randomColor();
};

} /* namespace render */

#endif /* PARTICLE_H_ */
