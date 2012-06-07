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
            }

        } else {
            playerObject->setSpeed(move / movedTime);
        }
        playerObject->setPosition(playerObject->getPosition() + move);

        time = time - movedTime;
    }

}

Vector2D Physics::calculateMoveFor(const PhysicsAppliableObject &object, double time) {
    std::vector<Object*> objects;
    currentLevel->getLevelObjects(&objects);

    time = currentLevel->getLevelPhysics()->getTimeBehavior()->manipulateTime(time);

    Vector2D speed;
    speed += object.getSpeed();
    speed += currentLevel->getLevelPhysics()->getGravityBehavior()->getAccelerationAt() * time;
    speed += currentLevel->getLevelPhysics()->getMagnetismBehavior()->getAccelerationAt(object.getPosition(), objects) * object.getMagneticState() * time;

    return speed * time;
}
