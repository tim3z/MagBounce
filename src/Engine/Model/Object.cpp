#include "Object.h"
#include "Graphics/Renderer.h"

// Constructors/Destructors
//  

Object::Object() :
		renderer(0), position(Vector2D()), magneticState(0) {
}

void Object::setMagneticState(int magneticState) {
	this->magneticState = magneticState;
}

int Object::getMagneticState() const {
	return magneticState;
}

Object::~Object() {
	if (renderer != NULL) {
		delete renderer;
		renderer = NULL;
	}
}

void Object::setPosition(float x, float y) {
	position(0) = x;
	position(1) = y;
}

void Object::setPosition(const Vector2D &pos) {
	position = pos;
}

void Object::setRenderer(Renderer* rend) {
	renderer = rend;
}
