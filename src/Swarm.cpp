#include "Swarm.h"

namespace render {

Swarm::Swarm(): _lastUpdate(0), _delta(0) {
	_particles = new Particle[PARTICLES_NUM];
}

Swarm::~Swarm() {
	delete [] _particles;
}

void Swarm::update(int elapsed){
	elapsed = elapsed - _lastUpdate;
	_lastUpdate = elapsed;
	_delta = (double)elapsed / 1000;

	for(int i = 0; i < PARTICLES_NUM; i++){
		_particles[i].update(_delta);
	}
}

const Particle* const Swarm::getParticles(){
	return _particles;
}

} /* namespace render */
