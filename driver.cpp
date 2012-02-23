#include "particle.h"
#include "interaction.h"
#include <iostream>
using namespace std;

int main() {
    Interaction *pair = new HarmonicOscillator(3, 1);
//  HarmonicOscillator HO(3,1);
    Eigen::Vector3d v0(1,2,3);

    for(double x = -10; x <= 10; x += 0.1) {
        Eigen::RowVector3d r(0,0,x);
        cout << x << "\t" << pair->potential(r) << endl;
    }


    return 0;
}
