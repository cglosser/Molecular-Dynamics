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

    fstream output("positions.xyz", fstream::out);

    for(double time = 0; time < 10; time += 0.004) {
       output << object.size() << endl;
       output << "Time: " << time << endl;
       for(vector<Particle>::iterator p = object.begin(); p != object.end();
               p++) {
           output << "Ar\t" << p->position() << endl;
       }
       verlet.step(object, lj);
    }

    return 0;
}
