#include "Level.h"
#include "PlayerObject.h"
#include <boost/foreach.hpp>

#define foreach BOOST_FOREACH

// Constructors/Destructors
//  

Level::Level(int width, int height) :
		physics(new StandardPhysics()), ball(new PlayerObject()), levelObjects(std::vector<RectangularLevelObject*>()),
				width(width), height(height) {

}

Level::~Level() {
	delete physics;
	delete ball;
	foreach (LevelObject* levelObject, levelObjects) {
		delete levelObject;
	}
}

const PhysicalProperties* const Level::getLevelPhysics() const {
	return physics;
}

void Level::getPhysicsApplyableObjects(std::vector<PhysicsApplyableObject*>* objects) {
	objects->push_back(ball);
}

void Level::getLevelObjectsAround(const Vector2D& position, float radius,
		std::vector<RectangularLevelObject*>* objects) {
	for (unsigned int i = 0; i < levelObjects.size(); i++) {
		objects->push_back(levelObjects[i]);
		// TODO filter
	}
}

void Level::getLevelObjects(std::vector<LevelObject*>* objects) {
	objects->push_back(ball);
	for (unsigned int i = 0; i < levelObjects.size(); i++) {
		objects->push_back(levelObjects[i]);
	}
}

void Level::addLevelObject(RectangularLevelObject* object) {
	levelObjects.push_back(object);
}
