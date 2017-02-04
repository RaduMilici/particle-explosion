#include "Swarm.h"

namespace render {

Swarm::Swarm() {
	_particles = new Particle[PARTICLES_NUM];
}

Swarm::~Swarm() {
	delete [] _particles;
}

void Swarm::update(int time){
	for(int i = 0; i < PARTICLES_NUM; i++){
		_particles[i].update(time);
	}
}

const Particle* const Swarm::getParticles(){
	return _particles;
}

} /* namespace render */
