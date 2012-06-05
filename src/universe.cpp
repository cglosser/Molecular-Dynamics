#include "universe.h"

/**
 * \brief   Simulate the universe (set of particles) to a specified time.
 * \details Updates particle trajectories until a specified amount of
 *          (simulated) time has elapsed. Because timesteps might not evenly
 *          divide the specified total system time, the simulation may run
 *          <it>slightly</it> longer than requested. Also writes trajectories
 *          in an XYZ format to "positions.xyz" and prints a progress bar on
 *          stdout.
 */
void Universe::simulate(double timeMax) {
    std::fstream coords("positions.xyz", std::fstream::out);
    for(double time = 0; time < timeMax; time += _integrator.timestep()) {
        _integrator.step(_particles, _interaction);
        coords << _particles.size() << std::endl;
        coords << "Time: " << time << std::endl;
        for(auto p : _particles) {
            coords << "Ar\t" << (p.position()) << std::endl;
        }
    }
    return;
}
