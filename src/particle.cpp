#include "particle.h"
using namespace std;

/*=====Constructors===========================================*/

/**
 * \brief   Default particle constructor
 * \details Sets all vectors to zero, mass to 1.
 */
Particle::Particle() {
    _pos = _vel = _acc = Eigen::RowVector3d(0,0,0);
    _mass = 1.0;

    return;
}

/**
 * \brief   Position constructor 
 * \details Only sets Particle position; velocity and acceleration assumed to
 *          equal zero, mass assumed to equal one.
 * \param position Vector object to assign to position
 */
Particle::Particle(Eigen::RowVector3d position) {
    _pos = position;
    _vel = _acc = Eigen::RowVector3d(0,0,0);
    _mass = 1.0;

    return;
}

/**
 * \brief   Position & Mass constructor
 * \details Sets Particle position and mass via arguments, velocity and
 *          acceleration assumed zero.
 * \param position Vector object to assign to position
 * \param mass     Particle mass
 */
Particle::Particle(Eigen::RowVector3d position, double mass) {
    _pos = position;
    _vel = _acc = Eigen::RowVector3d(0,0,0);
    _mass = mass;

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
        Eigen::RowVector3d acceleration) {
    _pos = position;
    _vel = velocity;
    _acc = acceleration;
    _mass = 1.0;

    return;
}

/**
 * \brief   Full constructor
 * \details Set all Particle fields via arguments
 * \param position     Particle position vector
 * \param velocity     Particle velocity vector
 * \param acceleration Particle acceleration vector
 * \param mass         Particle mass
 */
Particle::Particle(Eigen::RowVector3d position, Eigen::RowVector3d velocity, 
        Eigen::RowVector3d acceleration, double mass) {
    _pos = position;
    _vel = velocity;
    _acc = acceleration;
    _mass = mass;

    return;
}

/*=====Mutators===============================================*/

/**
 * Position mutator
 */
void Particle::setPosition(Eigen::RowVector3d position) {
    _pos = position;

    return;
}

/**
 * Velocity mutator
 */
void Particle::setVelocity(Eigen::RowVector3d velocity) {
    _vel = velocity;

    return;
}

/**
 * Acceleration mutator
 */
void Particle::setAcceleration(Eigen::RowVector3d acceleration) {
    _acc = acceleration;

    return;
}

/**
 * Mass mutator
 */
void Particle::setMass(double mass) {
    _mass = mass;

    return;
}

/*=====Accessors=============================================*/

/**
 * Position accessor
 */
Eigen::RowVector3d Particle::position() const {
    return _pos;
}

/**
 * Velocity accessor
 */
Eigen::RowVector3d Particle::velocity() const {
    return _vel;
}

/**
 * Acceleration accessor
 */
Eigen::RowVector3d Particle::acceleration() const {
    return _acc;
}

/**
 * Mass accessor
 */
double Particle::mass() const {
    return _mass;
}
