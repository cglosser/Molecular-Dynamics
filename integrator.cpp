#include "integrator.h"

Integrator::Integrator(Interaction &inter, std::vector<Particle> particles) {
    _force = &inter;
    _particles(particles);
    return;
}

FixedTimestepIntegrator::FixedTimestepIntegrator(double dt, Interaction &inter,
        std::vector<Particle> particles) : Integrator(inter, particles) {
    _timestep = dt;
    return;
}

VerletIntegrator::VerletIntegrator(double dt, Interaction &inter,
        std::vector<Particle> particles) : FixedTimestepIntegrator(dt, inter,
            particles) {
    return; //Must have a body
}

void VerletIntegrator::_updatePositions() {
    std::cout<< "updating positions!" << std::endl;
    return;
}

void VerletIntegrator::_updateVelocities() {
    std::cout<< "updating velocities!" << std::endl;
    return;
}

void VerletIntegrator::_updateAccelerations() {
    std::cout<< "updating accelerations!" << std::endl;
    return;
}
