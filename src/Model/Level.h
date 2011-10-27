
#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include "LevelObject.h"
#include "../Physics/Vector2D.h"

/**
  * class Level
  * 
  */

class Level {
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
     * @return LevelObject
     */
    LevelObject getLevelObjects ();


    /**
     * @return LevelObject
     * @param  position
     * @param  radius
     */
    LevelObject getLevelObjectsAround (Vector2D position, float radius);
  
};

#endif // LEVEL_H
