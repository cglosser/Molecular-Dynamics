#include "particle.h"
#include "interaction.h"
#include "integrator.h"
#include <iostream>
using namespace std;

int main() {
    Eigen::RowVector3d pos(0,0,0), vel(0,0,0), acc(1,0,0);
    Particle p0(pos, vel, acc);

    vector<Particle> object;
    object.push_back(p0);

    LennardJones lj(1,1);

    VerletIntegrator verlet(0.01, lj, object);


    for(double time = 0; time < 10; time += 0.01) {
        verlet.step();
        cout << time << "\t" << object.at(0).position() << endl;
    }

    return 0;
}
