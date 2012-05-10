#ifndef UNIVERSE_H
#define UNIVERSE_H

#include <fstream>
#include <iostream>
#include <vector>

#include "particle.h"
#include "integrator.h"

/**
 * \brief   Control evolution of all interactions, particles, etc.
 * \details The Universe class provides an interface between the simulated
 *          universe and the user. It controls time-evolution of the system
 *          and the display/write of all simulated quantities. Also contains a
 *          progress bar to show percent (time to run to/timestep) completed.
 */
class Universe {
  private:
    std::vector<Particle> _particles;
    Interaction &_interaction;
    FixedTimestepIntegrator &_integrator;
  public:
    Universe(std::vector<Particle> p0, Interaction
            &interaction, FixedTimestepIntegrator &integrator) : _particles(p0),
            _interaction(interaction), _integrator(integrator) {return;}

    void simulate(double);

};



#endif
