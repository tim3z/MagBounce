#include "PlayerObject.h"
#include "Graphics/BallRenderer.h" // TODO: keine Abhängigkeit von nicht-Engine-Klassen!
// Constructors/Destructors
//  

PlayerObject::PlayerObject() {
    renderer = new BallRenderer(*this, 25.0f);
}

PlayerObject::~PlayerObject() {
}

int PlayerObject::getCollisionRadius() const {
    return 25;
}

Vector2D PlayerObject::getRenderingPosition() const {
    Vector2D pos;
    pos.setX(position.getX() - 25);
    pos.setY(position.getY() - 25);
    return pos;
}

