#include <iostream>
#include <fstream>

#include "universe.h"

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
          p->setPosition(p->position()*1.5874);
    }

    LennardJones lj(1,1);
    VerletIntegrator verlet(0.004);

    Universe u0(object, lj, verlet);
    u0.simulate(20);



    return 0;
}
