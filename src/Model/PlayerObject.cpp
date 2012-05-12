#include "PlayerObject.h"
#include "Graphics/BallRenderer.h" // TODO: keine Abhängigkeit von nicht-Engine-Klassen!
// Constructors/Destructors
//  

PlayerObject::PlayerObject() {
    renderer = new BallRenderer(25.0f);
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

void PlayerObject::setColor(int magneticState) {
    if (magneticState < 0) {
	static_cast<BallRenderer*>(renderer)->setColor(0, 0, 127);
    } else if (magneticState > 0) {
	static_cast<BallRenderer*>(renderer)->setColor(127, 0, 0);
    } else {
	static_cast<BallRenderer*>(renderer)->setColor(127, 127, 127);
    }
}

