#include "Physics.h"
#include <iostream>
#include "Collision/Collision.h"
#include "Collision/CollisionHandler.h"
#include "Model/Level.h"
#include "Model/Level/GravityBehavior.h"
#include "Model/Level/MagnetismBehavior.h"
#include "Model/Level/TimeBehavior.h"
#include "Model/Level/PhysicalProperties.h"
#include "Model/PlayerObject.h"
#include "Physics/PhysicsAppliableObject.h"

Physics::Physics(Level* level)
        : currentLevel(level) {

}

Physics::~Physics() {
}

void Physics::move(double time) {
    PhysicsAppliableObject* playerObject = currentLevel->getPlayerObject();

    while (time > 0) {
        Vector2D move = calculateMoveFor(*playerObject, time);

        float radius = playerObject->getCollisionRadius() + move.length();
        std::vector<RectangularLevelObject*> levelObjects;
        currentLevel->getLevelObjectsAround(playerObject->getPosition(), radius, &levelObjects);

        Collision* collision = CollisionHandler::checkForCollision(*playerObject, move, levelObjects);
        double movedTime = time;

        if (collision != nullptr) {
            move = move * collision->getMovementFraction();
            movedTime = time * collision->getMovementFraction();

            Vector2D collisionNormal = collision->getCollisionNormal();
            collisionNormal.normalize(); // TODO: check for zero length!

            Vector2D reflected = move - 2 * (collisionNormal * move) * collisionNormal;
            if (movedTime != 0.0f) {
                playerObject->setSpeed(reflected / movedTime);
            } else {
                playerObject->setSpeed(Vector2D(.0f, .0f));
                movedTime = time;
            }
            
            delete collision;
            collision = nullptr;
        } else {
            playerObject->setSpeed(move / movedTime);
        }
        playerObject->setPosition(playerObject->getPosition() + move);

        time = time - movedTime;
    }

}

Vector2D Physics::calculateMoveFor(const PhysicsAppliableObject &object, double time) {
    time = currentLevel->getLevelPhysics()->getTimeBehavior()->manipulateTime(time);

    Vector2D speed;
    speed += object.getSpeed();
    speed += getAccelerationFor(object) * time;

    return speed * time;
}

Vector2D Physics::getAccelerationFor(const PhysicsAppliableObject& object) {
    std::vector<Object*> objects;
    currentLevel->getLevelObjects(&objects);
    
    return currentLevel->getLevelPhysics()->getGravityBehavior()->getAccelerationAt() +
        currentLevel->getLevelPhysics()->getMagnetismBehavior()->getAccelerationAt(object.getPosition(), objects) * object.getMagneticState();    
}