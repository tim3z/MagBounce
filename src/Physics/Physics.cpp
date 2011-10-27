#include "Physics.h"

Physics::~Physics() {}

Vector2D Physics::calculateMoveFor (PhysicsApplyableObject &object, int time) {
    time = currentLevel->getLevelPhysics()->getTimeBehaviour()->manipulateTime(time);
    
    Vector2D speed(2);
    speed += object.getSpeed();
    speed += currentLevel->getLevelPhysics()->getGravityBehaviour()->getAccelerationAt(object.getPosition()) * time;
    speed += currentLevel->getLevelPhysics()->getMagnetismBehaviour()->getAccelerationAt(object.getPosition()) * time;
    
    return speed * time;
}
