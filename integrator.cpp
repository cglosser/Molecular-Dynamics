#include "integrator.h"

typedef std::vector<Particle>::iterator particleIterator;
typedef std::vector< particleIterator >::iterator doubleParticleIterator;

void VerletIntegrator::_updatePositions() {
    particleIterator p0;
    for(p0 = _particles.begin(); p0 != _particles.end(); p0++) {
        p0->setPosition(p0->position() + p0->velocity()*_timestep);
    }
    return;
}

void VerletIntegrator::_updateVelocities() {
    particleIterator p0;
    for(p0 = _particles.begin(); p0 != _particles.end(); p0++) {
        p0->setVelocity(p0->velocity() + 0.5*p0->acceleration()*_timestep);
    }
    return;
}

void VerletIntegrator::_updateAccelerations() {
    return;
}
