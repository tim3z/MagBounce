#include "StandardGravityBehaviour.h"

// Constructors/Destructors
//  

StandardGravityBehaviour::StandardGravityBehaviour() {
}

StandardGravityBehaviour::~StandardGravityBehaviour() {
}

Vector2D StandardGravityBehaviour::getAccelerationAt() {
    Vector2D gravity;
    gravity.setX(0.0f);
    gravity.setY(0.0005f);
    return gravity;
}
