#include "Physics.h"
#include <iostream>
#include "Collision/Collision.h"
#include "Collision/CollisionHandler.h"
#include "Model/Level.h"
#include "Model/Level/GravityBehaviour.h"
#include "Model/Level/MagnetismBehaviour.h"
#include "Model/Level/TimeBehaviour.h"
#include "Model/Level/PhysicalProperties.h"
#include "Model/PlayerObject.h"
#include "Physics/PhysicsApplyableObject.h"

Physics::Physics(Level* level)
        : currentLevel(level) {

}

Physics::~Physics() {
}

//void Physics::move(int time) {
//    std::vector<PhysicsApplyableObject*> objects; // TODO warum macht objects(); es kaputt??
//    std::vector<Vector2D> movements;
//    currentLevel->getPhysicsApplyableObjects(&objects);
//    
//    bool finished = false;
//    
//    while (!finished) {
//        finished = true;
//        for (int i = 0; i < objects.size(); i++) {
//            movements[i] = calculateMoveFor(*objects[i], time);
//
//            float radius = objects[i]->getCollisionRadius() + norm_2(*objects[i]);
//            std::vector<LevelObject*> levelObjects;
//            currentLevel->getLevelObjectsAround(objects[i]->getPosition(), radius, levelObjects);
//
//            Collision* collision = CollisionHandler.checkForCollision(*objects[i], movements[i], levelObjects);
//            if (collision != NULL) {
//                finished = false;
//                // TODO
//            }
//            
//            
//        }
//    }
//    
//    
//    // collision detection
//}

void Physics::move(int time) {
    PhysicsApplyableObject* playerObject = currentLevel->getPlayerObject();

    while (time > 0) {
        Vector2D move = calculateMoveFor(*playerObject, time);

        float radius = playerObject->getCollisionRadius() + move.length();
        std::vector<RectangularLevelObject*> levelObjects;
        currentLevel->getLevelObjectsAround(playerObject->getPosition(), radius, &levelObjects);

        Collision* collision = CollisionHandler::checkForCollision(*playerObject, move, levelObjects);
        int movedTime = time;

        if (collision != NULL) {
            move = move * collision->getMovementFraction();
            movedTime = time * collision->getMovementFraction();

            Vector2D collisionNormal = collision->getCollisionNormal();
            collisionNormal.normalize(); // TODO: check for zero length!

            Vector2D reflected = move - 2 * (collisionNormal * move) * collisionNormal;
            playerObject->setSpeed(reflected / movedTime);

        } else {
            playerObject->setSpeed(move / movedTime);
        }
        playerObject->setPosition(playerObject->getPosition() + move);

        time = time - movedTime;
    }

}

Vector2D Physics::calculateMoveFor(const PhysicsApplyableObject &object, int time) {
    std::vector<Object*> objects;
    currentLevel->getLevelObjects(&objects);

    time = currentLevel->getLevelPhysics()->getTimeBehaviour()->manipulateTime(time);

    Vector2D speed;
    speed += object.getSpeed();
    std::cout << "speed: x: " << speed.getX() << " y: " << speed.getY() << std::endl;
    speed += currentLevel->getLevelPhysics()->getGravityBehaviour()->getAccelerationAt() * time;
    speed += currentLevel->getLevelPhysics()->getMagnetismBehaviour()->getAccelerationAt(object.getPosition(), objects)
            * object.getMagneticState() * time;

    return speed * time;
}
