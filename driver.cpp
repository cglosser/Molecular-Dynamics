#include "particle.h"
#include "interaction.h"
#include "integrator.h"
#include <iostream>
using namespace std;

int main() {
    HarmonicOscillator ho(3, 1);
    vector<Particle> p;
    p.push_back(Particle(Eigen::RowVector3d(0,0,0)));

    VerletIntegrator v0(0.004, ho, p);

    return 0;
}
