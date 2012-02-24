#include "integrator.h"

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

void VerletIntegrator::runUpdates() {
    _updatePositions();
    _updateVelocities();
    _updateAccelerations();

    std::cout << "Timestep:\t" << _timestep << std::endl;
    return;
}
