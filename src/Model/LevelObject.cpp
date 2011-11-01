#include "LevelObject.h"

// Constructors/Destructors
//  

LevelObject::LevelObject() :
		renderer(0), position(Vector2D(2)), magneticState(0) {
}

void LevelObject::setMagneticState(int magneticState) {
	this->magneticState = magneticState;
}

int LevelObject::getMagneticState() const {
	return magneticState;
}

LevelObject::~LevelObject() {
	if (renderer != NULL) {
		delete renderer;
		renderer = NULL;
	}
}

void LevelObject::setPosition(float x, float y) {
	position(0) = x;
	position(1) = y;
}

void LevelObject::setPosition(const Vector2D &pos) {
	position = pos;
}

void LevelObject::setRenderer(Renderer* rend) {
	renderer = rend;
}
