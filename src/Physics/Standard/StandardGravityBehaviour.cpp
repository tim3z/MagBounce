#include "StandardGravityBehaviour.h"

// Constructors/Destructors
//  

StandardGravityBehaviour::StandardGravityBehaviour () {}

StandardGravityBehaviour::~StandardGravityBehaviour () {}

Vector2D StandardGravityBehaviour::getAccelerationAt(const Vector2D &position) {
    Vector2D gravity(2);
    gravity(1) = 1.0f;
    return gravity;
}