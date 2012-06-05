#include "integrator.h"

/**
 * \brief   Update particle positions with a second order Taylor approximation:
 *          x(t + dt) = x(t) + v(t)*dt + 0.5*a(t)*dt^2
 */
void VerletIntegrator::updatePositions_(std::vector<Particle> &particles) {
    for(auto &p0 : particles) {
        p0.setPosition(p0.position() + p0.velocity()*timestep_);
    }
    return;
}

/**
 * \brief   Perform the half-step velocity update for the memory-efficient
 *          Verlet algorithm.
 * \details The half-step velocity update gets called twice: initially, and
 *          after calculation of the (t + dt) forces.
 */
void VerletIntegrator::updateVelocities_(std::vector<Particle> &particles) {
    for(auto &p0 : particles) {
        p0.setVelocity(p0.velocity() + 0.5*p0.acceleration()*timestep_);
    }
    return;
}

/**
 * \brief   Perform one integration timestep.
 */
void VerletIntegrator::step(std::vector<Particle> &particles, Interaction
        &interaction) {
    updateVelocities_(particles);
    updatePositions_(particles);
    interaction.updateForces(particles);
    updateVelocities_(particles);
    return;
}
