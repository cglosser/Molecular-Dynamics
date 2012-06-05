#ifndef INTEGRATOR_H
#define INTEGRATOR_H

#include "particle.h"
#include "interaction.h"
#include <iostream>
#include <vector>

/**
 * \brief   Base class for integrating equations of motion for a set (vector)
 *          of particles.
 * \details Implements integration algorithms to update all
 *          positions/velocities/accelerations of a std::vector of Particle
 *          instances. To preserve encapsulation, methods that update \link
 *          Particle Particles\endlink in time acccept reference parameters to
 *          an appropriate vector and Interaction. 
 */
class Integrator {
  protected:
    virtual void updatePositions_(std::vector<Particle> &)  = 0;
    virtual void updateVelocities_(std::vector<Particle> &) = 0;
  public:

    virtual void step(std::vector<Particle> &, Interaction &) = 0;
};

/**
 * \brief   Base class for \link Integrator Integrators \endlink with fixed
 *          timesteps
 * \details Provides a constant _timestep variable for integration schemes
 *          that require it (Euler, Verlet, RK4, etc.)
 */
class FixedTimestepIntegrator : public Integrator {
  protected:
    const double timestep_;//!< Constant timestep to use in all vector updates
  public:
    /**
     * \brief Value constructor
     * \param dt Timestep
     */
    FixedTimestepIntegrator(double dt) : timestep_(dt) {return;}

    /**
     * \brief   Timestep accessor
     * \returns _timestep value
     */
    double timestep() const {return timestep_;}
};

/**
 * \brief   Integrator implementing a standard four-step Velocity-Verlet
 *          algorithm
 * \details Uses the four-step (half-velocity, position, acceleration,
 *          half-velocity) Velocity-Verlet algorithm to time evolve a set
 *          of \link Particle Particles\endlink.
 */
class VerletIntegrator : public FixedTimestepIntegrator {
  protected:
    void updatePositions_(std::vector<Particle> &);
    void updateVelocities_(std::vector<Particle> &);
  public:
    /**
     * \brief   Default constructor
     * \param dt     Timestep
     * \param &inter Referenced Interaction instance used to compute updates
     * \param &p0    Referenced Particle vector to update
     */
    VerletIntegrator(double dt) : FixedTimestepIntegrator(dt) {return;}
    void step(std::vector<Particle> &, Interaction &);
};

#endif
