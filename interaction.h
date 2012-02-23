#ifndef INTERACTION_H
#define INTERACTION_H

#include "Eigen/Dense"
#include "particle.h"
#include <cmath>

/**
 * \brief   Base class for particle interactions
 * \details Interaction provides the basic form for pairwise particle
 *          interactions (gravity, harmonic oscillator, Lennard-Jones, etc.)
 *          and thus requires methods for computing a force given a
 *          separation. As these forces arise as the negative gradient of
 *          some potential, each Interaction must also provide a method to
 *          calculate the potential energy of a pair. Interaction classes
 *          <b>only</b> compute force vectors/potential energies (to preserve
 *          encapsulation); the class controlling time-evolution must
 *          accumulate these properly for every particle.
 */
class Interaction {
  public:
    virtual Eigen::RowVector3d force(Eigen::RowVector3d) const = 0;
    virtual double potential(Eigen::RowVector3d) const = 0;
};

/**
 * \brief   Pairwise interaction for a Lennard-Jones potential
 * \details Define a spherically symmetric Lennard-Jones interaction as a
 *          function of (vector) separation with optional depth and LJ radius
 *          parameters.
 */
class LennardJones : public Interaction {
  private:
    double _epsilon, //Depth of the potential well
           _sigma;   //Lennard-Jones radius (x-intercept of the well)
  public:
    LennardJones();
    LennardJones(double, double);

    Eigen::RowVector3d force(Eigen::RowVector3d) const;
    double potential(Eigen::RowVector3d) const;
};

/**
 * \brief   Pairwise interaction for a Harmonic Oscillator potential
 * \details Define a spherically symmetric harmonic oscillator interaction as a
 *          function of (vector) separation with optional separation and spring
 *          constant parameters.
 */
class HarmonicOscillator : public Interaction {
  private:
    double _springConstant,
           _fundamentalLength; //Zero point of the HO potential
  public:
    HarmonicOscillator();
    HarmonicOscillator(double, double);

    Eigen::RowVector3d force(Eigen::RowVector3d) const;
    double potential(Eigen::RowVector3d) const;
};

#endif
