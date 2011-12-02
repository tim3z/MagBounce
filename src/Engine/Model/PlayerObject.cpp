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
    Vector2D pos(2);
    pos[0] = position[0] - 25;
    pos[1] = position[1] - 25;
    return pos;
}
