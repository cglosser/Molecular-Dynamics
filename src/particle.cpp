#include "particle.h"
using namespace std;

/*=====Constructors===========================================*/

/**
 * \brief   Full constructor
 * \details Set all Particle fields via arguments -- most general constructor
 *          for use with C++0x constructor chaining.
 * \param position     Particle position vector
 * \param velocity     Particle velocity vector
 * \param acceleration Particle acceleration vector
 * \param mass         Particle mass
 */
Particle::Particle(Eigen::RowVector3d position, Eigen::RowVector3d velocity, 
        Eigen::RowVector3d acceleration, double mass) {
    pos_ = position;
    vel_ = velocity;
    acc_ = acceleration;
    mass_ = mass;

    return;
}

/**
 * \brief   Vector constructor
 * \details Set all vector fields via arguments; mass assumed to equal 1.0.
 * \param position     Particle position vector
 * \param velocity     Particle velocity vector
 * \param Acceleration Particle acceleration vector
 */
Particle::Particle(Eigen::RowVector3d position, Eigen::RowVector3d velocity,
        Eigen::RowVector3d acceleration) : Particle(position, velocity,
            acceleration, 1.0) {}
/**
 * \brief   Position & Mass constructor
 * \details Sets Particle position and mass via arguments, velocity and
 *          acceleration assumed zero.
 * \param position Vector object to assign to position
 * \param mass     Particle mass
 */
Particle::Particle(Eigen::RowVector3d position, double mass) :
    Particle(position, Eigen::RowVector3d(0,0,0), Eigen::RowVector3d(0,0,0),
            mass) {}

/**
 * \brief   Position constructor 
 * \details Only sets Particle position; velocity and acceleration assumed to
 *          equal zero, mass assumed to equal one.
 * \param position Vector object to assign to position
 */
Particle::Particle(Eigen::RowVector3d position) : Particle(position,
        Eigen::RowVector3d(0,0,0), Eigen::RowVector3d(0,0,0), 1.0) {}
/**
 * \brief   Default particle constructor
 * \details Sets all vectors to zero, mass to 1.
 */
Particle::Particle() : Particle(Eigen::RowVector3d(0,0,0),
        Eigen::RowVector3d(0,0,0), Eigen::RowVector3d(0,0,0), 1.0) {}

/*=====Mutators===============================================*/

/**
 * Position mutator
 */
void Particle::setPosition(Eigen::RowVector3d position) {
    pos_ = position;

    return;
}

/**
 * Velocity mutator
 */
void Particle::setVelocity(Eigen::RowVector3d velocity) {
    vel_ = velocity;

    return;
}

/**
 * Acceleration mutator
 */
void Particle::setAcceleration(Eigen::RowVector3d acceleration) {
    acc_ = acceleration;

    return;
}

/**
 * Mass mutator
 */
void Particle::setMass(double mass) {
    mass_ = mass;

    return;
}

/*=====Accessors=============================================*/

/**
 * Position accessor
 */
Eigen::RowVector3d Particle::position() const {
    return pos_;
}

/**
 * Velocity accessor
 */
Eigen::RowVector3d Particle::velocity() const {
    return vel_;
}

/**
 * Acceleration accessor
 */
Eigen::RowVector3d Particle::acceleration() const {
    return acc_;
}

/**
 * Mass accessor
 */
double Particle::mass() const {
    return mass_;
}
