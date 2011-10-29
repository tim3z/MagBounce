#include "PlayerObject.h"

// Constructors/Destructors
//  

PlayerObject::PlayerObject () {
    renderer = new BallRenderer(25.0f);
}

PlayerObject::~PlayerObject () {}

int PlayerObject::getCollisionRadius() const {
    return 25;
}