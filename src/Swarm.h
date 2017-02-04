#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace render {

class Swarm {
public:
	Swarm();
	virtual ~Swarm();
	const static int PARTICLES_NUM = 1500;
	const Particle* const getParticles();
	void update(int time);
private:
	Particle* _particles;
};

} /* namespace render */

#endif /* SWARM_H_ */
