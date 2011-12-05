#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include "Physics/Vector.h"

using std::vector;
class Object;
class PhysicsAppliableObject;
class PhysicalProperties;
class PlayerObject;
class RectangularLevelObject;

/**
 * class Level
 * 
 */

class Level {
private:
    PhysicalProperties* physics;
    PlayerObject* ball;
    vector<RectangularLevelObject*> levelObjects;
    int width;
    int height;

    Level(const Level&);
    const Level& operator=(const Level&);

public:
    /**
     * Empty Constructor
     */
    Level(int width, int height);

    /**
     * Empty Destructor
     */
    virtual ~Level();

    /**
     * Get all LevelObjects which are in this Level
     * @param a pointer to a vector to fill in the objects
     */
    void getLevelObjects(vector<Object*>*);

    void addLevelObject(RectangularLevelObject*);

    /**
     * Return the Player object
     * @return a pointer to the player object
     */
    PlayerObject* getPlayerObject() {
        return ball;
    }

    /**
     * Return all Objects, which movements should be handled by the physics
     * @param a pointer to a vector to fill in the objects
     */
    void getMovableObjects(vector<PhysicsAppliableObject*>*);

    /**
     * @param  position
     * @param  radius
     * @param a pointer to a vector to fill in the objects
     */
    void getLevelObjectsAround(const Vector2D &position, float radius, vector<RectangularLevelObject*>*);

    /**
     * Returns the Physics Object of this Level
     * @return a pointer to this Levels Physics Object
     */
    PhysicalProperties* const getLevelPhysics();

};

#endif // LEVEL_H
