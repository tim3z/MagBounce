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

//void Physics::move(int time) {
//    std::vector<PhysicsAppliableObject*> objects; // TODO warum macht objects(); es kaputt??
//    std::vector<Vector2D> movements;
//    currentLevel->getPhysicsAppliableObjects(&objects);
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
	    std::cout << "Collision!\n";
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

Vector2D Physics::calculateMoveFor(const PhysicsAppliableObject &object, double time) {
    std::vector<Object*> objects;
    currentLevel->getLevelObjects(&objects);

    time = currentLevel->getLevelPhysics()->getTimeBehavior()->manipulateTime(time);

    Vector2D speed;
    speed += object.getSpeed();
    speed += currentLevel->getLevelPhysics()->getGravityBehavior()->getAccelerationAt() * time;
    speed += currentLevel->getLevelPhysics()->getMagnetismBehavior()->getAccelerationAt(object.getPosition(), objects)
            * object.getMagneticState() * time;

    return speed * time;
}
