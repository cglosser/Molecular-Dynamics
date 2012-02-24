#ifndef INTEGRATOR_H
#define INTEGRATOR_H

#include "particle.h"
#include "interaction.h"
#include <iostream>
#include <vector>

/**
 * \brief   Base class for integrating equations of motion for a set (vector)
 *          of particles.
 */
class Integrator {
  protected:
    Interaction &_force;
    std::vector<Particle> &_particles;
    virtual void _updatePositions()     = 0;
    virtual void _updateVelocities()    = 0;
    virtual void _updateAccelerations() = 0;
  public:
    Integrator(Interaction &inter, std::vector<Particle> p0) : _force(inter),
            _particles(p0) {
        return;
    }
};

class FixedTimestepIntegrator : public Integrator {
  protected:
    double _timestep;
  public:
    FixedTimestepIntegrator(double dt, Interaction &inter,
            std::vector<Particle> &p0) : Integrator(inter, p0), _timestep(dt) {
        return;
    }
};

class VerletIntegrator : public FixedTimestepIntegrator {
  protected:
    void _updatePositions();
    void _updateVelocities();
    void _updateAccelerations();
  public:
    VerletIntegrator(double dt, Interaction &inter, std::vector<Particle> &p0) 
            : FixedTimestepIntegrator(dt, inter, p0) {
        return;
    }

    void runUpdates();
};

#endif
