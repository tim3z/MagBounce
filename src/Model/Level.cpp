#include "Level.h"
#include "PlayerObject.h"

// Constructors/Destructors
//  

Level::Level () {
    physics = new StandardPhysics();
    ball = new PlayerObject();
}

Level::~Level () {
    delete physics;
    physics = NULL;
    delete ball;
    ball = NULL;
}

PhysicalProperties* Level::getLevelPhysics() {
    return physics;
}

void Level::getPhysicsApplyableObjects(std::vector<PhysicsApplyableObject*>*) {
    
}

void Level::getLevelObjectsAround(const Vector2D& position, float radius, std::vector<RectangularLevelObject*>*) {
    
}