#ifndef PARTICLE_H
#define PARTICLE_H

#include "Eigen/Dense"

/**
 * \brief   Particle object for molecular dynamics simulation
 * \details Fully describes a particle for time evolution via Verlet, RK4, or
 *          other such integrators. Some other class must handle the actual
 *          integration, however. Particle objects live in a cartesian 3
 *          dimensional space.
 */
class Particle {
  private:
    Eigen::RowVector3d _pos, _vel, _acc;
    double _mass;
  public:
    /*=====Constructors=====================================*/
    Particle();
    Particle(Eigen::RowVector3d);
    Particle(Eigen::RowVector3d, double);
    Particle(Eigen::RowVector3d, Eigen::RowVector3d, Eigen::RowVector3d);
    Particle(Eigen::RowVector3d, Eigen::RowVector3d, Eigen::RowVector3d,
            double);

    /*=====Mutators=========================================*/
    void setPosition(Eigen::RowVector3d);
    void setVelocity(Eigen::RowVector3d);
    void setAcceleration(Eigen::RowVector3d);
    void setMass(double);

    /*=====Accessors========================================*/
    Eigen::RowVector3d position() const;
    Eigen::RowVector3d velocity() const;
    Eigen::RowVector3d acceleration() const;
    double mass() const;
};

#endif
