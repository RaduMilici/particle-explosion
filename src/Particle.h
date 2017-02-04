#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;

namespace render {

class Particle {
public:
	static const double MIN_SPEED = 0.0001;
	static const double MAX_SPEED = 0.005;

	Particle();
	virtual ~Particle();

	double x;
	double y;
	double speed;
	double direction;

	char red;
	char green;
	char blue;

	void update(int time);
private:
	double xSpeed;
	double ySpeed;
	double randomNum(double min, double max);
};

} /* namespace render */

#endif /* PARTICLE_H_ */
