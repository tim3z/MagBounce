#include "StandardGravityBehaviour.h"

// Constructors/Destructors
//  

StandardGravityBehaviour::StandardGravityBehaviour() {
}

StandardGravityBehaviour::~StandardGravityBehaviour() {
}

Vector2D StandardGravityBehaviour::getAccelerationAt() {
    Vector2D gravity(2);
    gravity[0] = 0.0f;
    gravity[1] = 0.0005f;
    return gravity;
}