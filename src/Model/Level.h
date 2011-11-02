
#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include "RectangularLevelObject.h"
#include "PlayerObject.h"
#include "../Physics/Vector2D.h"
#include "../Physics/PhysicalProperties.h"
#include "../Physics/PhysicsApplyableObject.h"
#include "../Physics/Standard/StandardPhysics.h"

/**
  * class Level
  * 
  */

class Level {
private:
    
    PhysicalProperties* physics;
    PlayerObject* ball;
    std::vector<RectangularLevelObject*> levelObjects;
    int width;
    int height;
    
    Level(const Level&);
    const Level& operator=(const Level&);

public:
    
    /**
     * Empty Constructor
     */
    Level (int width, int height);

    /**
     * Empty Destructor
     */
    virtual ~Level ();

    /**
     * Get all LevelObjects which are in this Level
     * @param a pointer to a vector to fill in the objects
     */
    void getLevelObjects(std::vector<LevelObject*>*);
    
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
    void getPhysicsApplyableObjects(std::vector<PhysicsApplyableObject*>*);


    /**
     * @param  position
     * @param  radius
     * @param a pointer to a vector to fill in the objects
     */
    void getLevelObjectsAround (const Vector2D &position, float radius, std::vector<RectangularLevelObject*>*);
  
    /**
     * Returns the Physics Object of this Level
     * @return a pointer to this Levels Physics Object
     */
    const PhysicalProperties* const getLevelPhysics() const;
  
};

#endif // LEVEL_H
