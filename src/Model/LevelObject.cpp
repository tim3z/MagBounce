#include "LevelObject.h"

// Constructors/Destructors
//  

LevelObject::LevelObject () {
    position = Vector2D(2);
}

LevelObject::~LevelObject () {}

void LevelObject::setPosition(float x, float y) {
    position(0) = x;
    position(1) = y;
}

void LevelObject::setPosition(const Vector2D& pos) {
    position = pos;
}