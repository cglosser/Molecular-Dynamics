#include "universe.h"

void Universe::_verletUpdate() {
    for(std::vector<Particle> p = _particles.begin(); p != _particles.end(); 
            p++) {
       (*p).setVelocity(p->velocity() + 0.5*p->acceleration()*_timestep); 
       (*p).setPosition(p->position() + p->velocity());




/**
 * \brief   Default Universe constructor
 * \details Create a Universe with no particles
 */
Universe::Universe() {
    _timestep = 0;
    _potential = NULL;
    return;
}

Universe::Universe(std::vector<Particle> &particles, Interaction &i0, 
        double dt) {
    _particles = particles;
    _potential = &i0;
    _timestep  = dt;
    return;
}
