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

Vector2D PlayerObject::getRenderingPosition() const {
    Vector2D pos = position;
    pos[0] -= 25.0f;
    pos[1] -= 25.0f;
    return pos;
}

