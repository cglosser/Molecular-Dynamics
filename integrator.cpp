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
    Eigen::RowVector3d zeroVector(0,0,0);
    particleIterator p0, p1;
    for(p0 = _particles.begin(); p0 != _particles.end(); p0++) {
        p0->setAcceleration(zeroVector);
    }

    for(p0 = _particles.begin(); p0 != _particles.end() - 1; p0++) {
        for(p1 = p0 + 1; p1 != _particles.end(); p1++) {
            Eigen::RowVector3d dij = p1->position() - p0->position(),
                               fij = _force.force(dij);
            p0->setAcceleration(p0->acceleration() + fij);
            p1->setAcceleration(p1->acceleration() - fij);
        }
    }

    return;
}

void VerletIntegrator::step() {
    _updateVelocities();
    _updatePositions();
    _updateAccelerations();
    _updateVelocities();
    return;
}
