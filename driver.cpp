#include "particle.h"
#include "interaction.h"
#include "integrator.h"
#include <iostream>
using namespace std;

int main() {
    Eigen::RowVector3d p0(0,0,0), p1(1,0,0);

    vector<Particle> object;
    object.push_back(Particle(p0));
    object.push_back(Particle(p1));

    LennardJones lj(1,1);

    VerletIntegrator verlet(0.004, lj, object);


    for(double time = 0; time < 10; time += 0.004) {
       cout << object.size() << endl;
       cout << "Time: " << time << endl;
       for(vector<Particle>::iterator p = object.begin(); p != object.end();
               p++) {
           cout << "Ar\t" << p->position() << endl;
       }
       verlet.step();
    }

    return 0;
}
