#include "Level.h"
#include <boost/foreach.hpp>
#include "PlayerObject.h"
#include "Physics/PhysicsAppliableObject.h"
#include "Model/RectangularLevelObject.h"
#include "Model/Level/PhysicalProperties.h"
#include "Model/Level/Standard/StandardPhysics.h"

#define foreach BOOST_FOREACH

// Constructors/Destructors
//  

Level::Level(int width, int height)
        : physics(new StandardPhysics()), ball(new PlayerObject()), levelObjects(vector<RectangularLevelObject*>()),
          width(width), height(height) {

}

Level::~Level() {
    delete physics;
    delete ball;
    foreach (Object* levelObject, levelObjects)
            {
                delete levelObject;
            }
}

PhysicalProperties* const Level::getLevelPhysics() {
    return physics;
}

void Level::getMovableObjects(vector<PhysicsAppliableObject*>* objects) {
    objects->push_back(ball);
}

void Level::getLevelObjectsAround(const Vector2D& position, float radius, vector<RectangularLevelObject*>* objects) {
    for (unsigned int i = 0; i < levelObjects.size(); i++) {
        objects->push_back(levelObjects[i]);
        // TODO filter
    }
}

void Level::getLevelObjects(vector<Object*>* objects) {
    objects->push_back(ball);
    for (unsigned int i = 0; i < levelObjects.size(); i++) {
        objects->push_back(levelObjects[i]);
    }
}

void Level::addLevelObject(RectangularLevelObject* object) {
    levelObjects.push_back(object);
}
