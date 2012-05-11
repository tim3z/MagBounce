#include "StandardGravityBehavior.h"

// Constructors/Destructors
//  

StandardGravityBehavior::StandardGravityBehavior() {
}

StandardGravityBehavior::~StandardGravityBehavior() {
}

Vector2D StandardGravityBehavior::getAccelerationAt() {
    Vector2D gravity;
    gravity.setX(0.0f);
    gravity.setY(0.0005f);
    return gravity;
}
