#include "universe.h"

void Universe::simulate(double timeMax) {
    std::fstream coords("positions.xyz", std::fstream::out);
    for(double time = 0; time < timeMax; time += _integrator.timestep()) {
        _integrator.step(_particles, _interaction);
        coords << _particles.size() << std::endl;
        coords << "Time: " << time << std::endl;
        for(std::vector<Particle>::iterator p = _particles.begin(); p !=
                _particles.end(); p++) {
            coords << "Ar\t" << (p->position()) << std::endl;
        }
    }
    return;
}
