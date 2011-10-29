#include "StandardGravityBehaviour.h"

// Constructors/Destructors
//  

StandardGravityBehaviour::StandardGravityBehaviour () {}

StandardGravityBehaviour::~StandardGravityBehaviour () {}

Vector2D StandardGravityBehaviour::getAccelerationAt() {
    Vector2D gravity(2);
    gravity(1) = 1.0f;
    return gravity;
}