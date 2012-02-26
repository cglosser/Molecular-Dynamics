#include "integrator.h"

typedef std::vector<Particle>::iterator particleIterator;
typedef std::vector< particleIterator >::iterator doubleParticleIterator;

/**
 * \brief   Update particle positions with a second order Taylor approximation:
 *          x(t + dt) = x(t) + v(t)*dt + 0.5*a(t)*dt^2
 */
void VerletIntegrator::_updatePositions() {
    particleIterator p0;
    for(p0 = _particles.begin(); p0 != _particles.end(); p0++) {
        p0->setPosition(p0->position() + p0->velocity()*_timestep);
    }
    return;
}

/**
 * \brief   Perform the half-step velocity update for the memory-efficient
 *          Verlet algorithm.
 * \details The half-step velocity update gets called twice: initially, and
 *          after calculation of the (t + dt) forces.
 */
void VerletIntegrator::_updateVelocities() {
    particleIterator p0;
    for(p0 = _particles.begin(); p0 != _particles.end(); p0++) {
        p0->setVelocity(p0->velocity() + 0.5*p0->acceleration()*_timestep);
    }
    return;
}

/**
 * \brief   Perform one integration timestep.
 */
void VerletIntegrator::step() {
    _updateVelocities();
    _updatePositions();
    _interaction.updateForces(_particles);
    _updateVelocities();
    return;
}
