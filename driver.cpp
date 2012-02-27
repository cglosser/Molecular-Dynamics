#include "particle.h"
#include "interaction.h"
#include "integrator.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    vector<Particle> object;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            for(int k = 0; k < 5; k++) {
                Eigen::RowVector3d p(i, j, k);
                object.push_back(Particle(p));
                object.push_back(Particle(p+Eigen::RowVector3d(0.0,0.5,0.5)));
                object.push_back(Particle(p+Eigen::RowVector3d(0.5,0.0,0.5)));
                object.push_back(Particle(p+Eigen::RowVector3d(0.5,0.5,0.0)));
            }
        }
    }

    for(vector<Particle>::iterator p = object.begin(); p != object.end();
            p++) {
          p->setPosition(p->position()*2);
    }

    LennardJones lj(1,1);

    VerletIntegrator verlet(0.004, lj, object);

    fstream output("positions.xyz", fstream::out);

    for(double time = 0; time < 10; time += 0.004) {
       output << object.size() << endl;
       output << "Time: " << time << endl;
       for(vector<Particle>::iterator p = object.begin(); p != object.end();
               p++) {
           output << "Ar\t" << p->position() << endl;
       }
       verlet.step();
    }

    return 0;
}
