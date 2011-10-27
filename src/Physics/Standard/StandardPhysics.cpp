#include "StandardPhysics.h"

// Constructors/Destructors
//  

StandardPhysics::StandardPhysics () {
    gravityBehaviour = new StandardGravityBehaviour();
    magnetismBehaviour = new StandardMagnetismBehaviour();
    timeBehaviour = new StandardTimeBehaviour();
}

StandardPhysics::~StandardPhysics () {
}
