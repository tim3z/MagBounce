#include "Physics.h"

Physics::~Physics() {}

void Physics::move(int time) {
    std::vector<PhysicsApplyableObject*> objects; // TODO warum macht objects(); es kaputt??
    std::vector<Vector2D> movements;
    currentLevel->getPhysicsApplyableObjects(&objects);
    
    for (int i = 0; i < objects.size(); i++) {
        movements[i] = calculateMoveFor(*objects[i], time);
    }
    
    // collision detection
}

Vector2D Physics::calculateMoveFor (const PhysicsApplyableObject &object, int time) {
    time = currentLevel->getLevelPhysics()->getTimeBehaviour()->manipulateTime(time);
    
    Vector2D speed(2);
    speed += object.getSpeed();
    speed += currentLevel->getLevelPhysics()->getGravityBehaviour()->getAccelerationAt(object.getPosition()) * time;
    speed += currentLevel->getLevelPhysics()->getMagnetismBehaviour()->getAccelerationAt(object.getPosition()) * time;
    
    return speed * time;
}
