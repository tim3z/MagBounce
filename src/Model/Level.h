
#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <vector>
#include "LevelObject.h"
#include "../Physics/Vector2D.h"
#include "../Physics/PhysicalProperties.h"
#include "../Physics/PhysicsApplyableObject.h"
#include "../Physics/StandardPhysics.h"

/**
  * class Level
  * 
  */

class Level {
    
    PhysicalProperties* physics;
    
public:
    
    /**
     * Empty Constructor
     */
    Level ();

    /**
     * Empty Destructor
     */
    virtual ~Level ();

    /**
     * Get all LevelObjects which are in this Level
     * @param a pointer to a vector to fill in the objects
     */
    void getLevelObjects(std::vector<LevelObject>*);
    
    /**
     * Return all Objects, which movements should be handled by the physics
     * @param a pointer to a vector to fill in the objects
     */
    void getPhysicsApplyableObjects(std::vector<PhysicsApplyableObject>*);


    /**
     * @param  position
     * @param  radius
     * @param a pointer to a vector to fill in the objects
     */
    void getLevelObjectsAround (Vector2D position, float radius, std::vector<LevelObject>*);
  
    /**
     * Returns the Physics Object of this Level
     * @return a pointer to this Levels Physics Object
     */
    PhysicalProperties* getLevelPhysics();
  
};

#endif // LEVEL_H
