#ifndef INTEGRATOR_H
#define INTEGRATOR_H

#include "particle.h"
#include "interaction.h"
#include <vector>

/**
 * \brief   Base class for integrating equations of motion for a set (vector)
 *          of particles.
 */
class Integrator {
  protected:
    Interaction *_force;
    std::vector<Particle> _particles;
    virtual void _updatePositions()     = 0;
    virtual void _updateVelocities()    = 0;
    virtual void _updateAccelerations() = 0;
  public:
    Integrator(Interaction &, std::vector<Particle>);
};

class FixedTimestepIntegrator : public Integrator {
  protected:
    double _timestep;
  public:
    FixedTimestepIntegrator(double, Interaction &, std::vector<Particle>) :
        Integrator(std::vector<Particle>); 
};

class VerletIntegrator : public FixedTimestepIntegrator {
  protected:
    void _updatePositions();
    void _updateVelocities();
    void _updateAccelerations();
  public:
    VerletIntegrator(double, Interaction &, std::vector<Particle>) :
        FixedTimestepIntegrator(double, std::vector<Particle>);
};

#endif
