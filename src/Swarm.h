#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace render {

class Swarm {
public:
	Swarm();
	virtual ~Swarm();
	const static int PARTICLES_NUM = 100;
	const Particle* const getParticles();
	void update(int elapsed);
private:
	int _lastUpdate;
	double _delta;
	Particle* _particles;
};

} /* namespace render */

#endif /* SWARM_H_ */
