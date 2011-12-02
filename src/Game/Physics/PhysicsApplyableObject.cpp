#include "PhysicsApplyableObject.h"

PhysicsApplyableObject::PhysicsApplyableObject()
        : speed(Vector2D()) {
    speed[0] = 0.0f;
    speed[1] = 0.0f;
}

PhysicsApplyableObject::~PhysicsApplyableObject() {
}
