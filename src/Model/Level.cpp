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

void Level::getPhysicsApplyableObjects(std::vector<PhysicsApplyableObject*>* objects) {
    objects->push_back(ball);
}

void Level::getLevelObjectsAround(const Vector2D& position, float radius, std::vector<RectangularLevelObject*>* objects) {
    for (int i = 0; i < levelObjects.size(); i++) {
        objects->push_back(levelObjects[i]);
        // TODO filter
    }
}

void Level::getLevelObjects(std::vector<LevelObject*>* objects) {
    objects->push_back(ball);
    for (int i = 0; i < levelObjects.size(); i++) {
        objects->push_back(levelObjects[i]);
    }
}

void Level::addLevelObject(RectangularLevelObject* object) {
    levelObjects.push_back(object);
}