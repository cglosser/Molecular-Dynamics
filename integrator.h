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
 *          instances. Both the Interaction and the vector of \link Particle
 *          Particles \endlink exist at the end of reference variables
 *          contained within the Integrator.
 */
class Integrator {
  protected:
    Interaction &_interaction; 
    std::vector<Particle> &_particles;
    virtual void _updatePositions()  = 0;
    virtual void _updateVelocities() = 0;
  public:
    /**
     * \brief   Default Interaction constructor
     * \details Fundamental constructor for \link Integrator
     *          Integrators \endlink. Sets the Interaction to use for updating
     *          forces and the vector of \link Particle Particles\endlink via
     *          reference variables.
     * \param &inter Referenced Interaction object used to compute updates 
     * \param &p0    Referenced Particle vector to update
     */
    Integrator(Interaction &inter, std::vector<Particle> &p0) :
            _interaction(inter), _particles(p0) {
        return;
    }

    virtual void step() = 0;
};

/**
 * \brief   Base class for \link Integrator Integrators \endlink with fixed
 *          timesteps
 * \details Provides a constant _timestep variable for integration schemes
 *          that require it (Euler, Verlet, RK4, etc.)
 */
class FixedTimestepIntegrator : public Integrator {
  protected:
    const double _timestep;//!< Constant timestep to use in all vector updates
  public:
    /**
     * \brief Default constructor
     * \param dt     Timestep
     * \param &inter Referenced Interaction instance used to compute updates
     * \param &p0    Referenced Particle vector to update
     */
    FixedTimestepIntegrator(double dt, Interaction &inter,
            std::vector<Particle> &p0) : Integrator(inter, p0), _timestep(dt) {
        return;
    }
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
    void _updatePositions();
    void _updateVelocities();
    void _updateAccelerations();
  public:
    /**
     * \brief   Default constructor
     * \param dt     Timestep
     * \param &inter Referenced Interaction instance used to compute updates
     * \param &p0    Referenced Particle vector to update
     */
    VerletIntegrator(double dt, Interaction &inter, std::vector<Particle> &p0) 
            : FixedTimestepIntegrator(dt, inter, p0) {
        return;
    }

    void step();

};

#endif
