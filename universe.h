#ifndef UNIVERSE_H
#define UNIVERSE_H

#include <fstream>
#include <iostream>
#include <vector>

#include "particle.h"
#include "integrator.h"

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
