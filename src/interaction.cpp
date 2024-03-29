#include "interaction.h"
using namespace std;

typedef vector<Particle>::iterator particleIterator;

/**
 * \brief   Update all pairwise forces
 * \details Use a triangular loop (forces equal but opposite) to zero,
 *          calculate, and accumulate the force on a referenced set of
 *          particles. Currently runs over every pair, will eventually require
 *          Particle objects to carry a list of appropriate interacting
 *          neighbors (for bonding potentials like the HarmonicOscillator).
 * \param &particles Referenced set of particles to update.
 */
void Interaction::updateForces(vector<Particle> &particles) {
    const Eigen::RowVector3d zero(0,0,0);
    for(auto &i : particles) {
        i.setAcceleration(zero);
    }

    for(particleIterator i = particles.begin(); i != particles.end()-1; i++) {
        for(particleIterator j = i + 1; j != particles.end(); j++) {
            Eigen::RowVector3d dij(j->position() - i->position());
            Eigen::RowVector3d fij = force_(dij);

            i->setAcceleration(i->acceleration() - fij/i->mass());
            j->setAcceleration(j->acceleration() + fij/j->mass());
        }
    }
    return;
}

/**
 * \brief   Default LennardJones constructor
 * \details Set potential depth and LJ radius to 1 (LJ units)
 */
LennardJones::LennardJones() {
    epsilon_ = sigma_ = 1.0;
    return;
}

/**
 * \brief   LennardJones value constructor
 * \details Set the depth and LJ radius of the potential via arguments
 * \param eps maximum depth of the potential well
 * \param sig Lennard-Jones radius (x-intercept of the potential)
 */
LennardJones::LennardJones(double eps, double sig) {
    epsilon_ = eps;
    sigma_   = sig;
    return;
}

/**
 * \brief Compute a Lennard-Jones force for a given separation
 * \param rvec Cartesian vector separation
 * \returns -(d/dr) U evaluated at |<b>rvec</b>|
 */
Eigen::RowVector3d LennardJones::force_(Eigen::RowVector3d &rvec) const {
    double rsq = rvec.squaredNorm();
    return 4*epsilon_*(12*pow(sigma_,12)/pow(rsq,7) -
                        6*pow(sigma_,6)/pow(rsq,4))*rvec;
}

/**
 * \brief Compute the potential energy for a given separation
 * \param rvec Cartesian vector separation
 * \returns 4*epsilon*((sigma/r)^12 - (sigma/r)^6)
 */
double LennardJones::potential_(Eigen::RowVector3d &rvec) const {
    double dist = rvec.norm();
    return 4*epsilon_*(pow(sigma_/dist,12) - pow(sigma_/dist,6));
}

/**
 * \brief   Default HarmonicOscillator constructor
 * \details Use a "standard" spring constant of one with an equilibrium radius
 *          of zero.
 */
HarmonicOscillator::HarmonicOscillator() {
    springConstant_    = 1;
    fundamentalLength_ = 0;
    return;
}

/**
 * \brief   HarmonicOscillator value constructor
 * \details Set spring constant and equilibrium radius via arguments
 * \param r0       equilibrium radius
 * \param strength spring constant
 */
HarmonicOscillator::HarmonicOscillator(double r0, double strength) {
    fundamentalLength_ = r0;
    springConstant_    = strength;
    return;
}

/**
 * \brief   Compute a force vector from a HarmonicOscillator
 * \details Computes the force from a spherically-symmetric HarmonicOscillator.
 * \param rvec radial separation vector
 * \returns -k*(<b>r</b>-<b>r0</b>)
 */
Eigen::RowVector3d HarmonicOscillator::force_(Eigen::RowVector3d &rvec) const {
    return -1*springConstant_*(rvec - fundamentalLength_*rvec.normalized());
}

/**
 * \brief Compute the value of a HarmonicOscillator potential at a given
 *        radius
 * \param rvec radial separation vector
 * \returns 0.5*(r)^2
 */
double HarmonicOscillator::potential_(Eigen::RowVector3d &rvec) const {
    double r = rvec.norm();
    return 0.5*springConstant_*pow(fundamentalLength_ - r, 2);
}
