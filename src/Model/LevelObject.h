
#ifndef LEVELOBJECT_H
#define LEVELOBJECT_H

#include <string>
#include "../Physics/Vector2D.h"

/**
  * class LevelObject
  * 
  */

class LevelObject {
    
private:
    
    Vector2D position;
    
public:

    /**
     * Empty Constructor
     */
    LevelObject ();

    /**
     * Empty Destructor
     */
    virtual ~LevelObject ();
    
    /**
     * Set the current position of this object
     * @param x the x coordinate
     * @param y the y coordinate
     */
    void setPosition(float x, float y);
    
    /**
     * Set the current position of this object
     * @param position an Vector2D containing the position
     */
    void setPosition(const Vector2D &position);
    
    /**
     * Return the position of this Object
     * @return an Vector2D containing the position
     */
    Vector2D getPosition() const {
        return position;
    }
  
};

#endif // LEVELOBJECT_H
