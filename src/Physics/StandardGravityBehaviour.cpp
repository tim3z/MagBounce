#include "StandardGravityBehaviour.h"

// Constructors/Destructors
//  

StandardGravityBehaviour::StandardGravityBehaviour () {}

StandardGravityBehaviour::~StandardGravityBehaviour () {}

Vector2D* StandardGravityBehaviour::getAccelerationAt(Vector2D& position) {
    return new Vector2D();
}