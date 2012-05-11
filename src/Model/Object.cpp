#include "Object.h"
#include "Graphics/Renderer.h"

// Constructors/Destructors
//  

Object::Object()
        : renderer(nullptr), position(Vector2D()), magneticState(0) {
}

void Object::setMagneticState(int magneticState) {
    this->magneticState = magneticState;
}

int Object::getMagneticState() const {
    return magneticState;
}

Object::~Object() {
    delete renderer;
}

void Object::setPosition(float x, float y) {
    position.setX(x);
    position.setY(y);
}

void Object::setPosition(const Vector2D &pos) {
    position = pos;
}

void Object::setRenderer(Renderer* rend) {
    renderer = rend;
}
