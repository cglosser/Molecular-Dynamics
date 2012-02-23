#ifndef UNIVERSE_H
#define UNIVERSE_H

#include <vector>

#include "particle.h"
#include "interaction.h"

class Universe {
  private:
    std::vector<Particle> _particles;
    Interaction *_potential; //poor name...
    double _timestep;

    void _updatePositions()
    void _updateVelocities();
    void _updateAccelerations();
    void _verletUpdate();
  public:
    Universe();
    Universe(std::vector<Particle>, Interaction &, double);

    void evolve(double);
};



#endif
