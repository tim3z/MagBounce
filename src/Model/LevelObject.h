
#ifndef LEVELOBJECT_H
#define LEVELOBJECT_H

#include <string>
#include "../Physics/Vector2D.h"
#include "../Graphics/Renderer.h"

/**
  * class LevelObject
  * 
  */

class LevelObject {
    
private:
    
    Renderer* renderer;
    
protected:
    
    Vector2D position;
    int magneticState;
    
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
    
    void setRenderer(Renderer* renderer);
    
    /**
     * Returns this LevelObjects Renderer
     * @return a Renderer
     */
    Renderer* getRenderer() {
        return renderer;
    }
    
    /**
     * Return the position of this Object
     * @return an Vector2D containing the position
     */
    Vector2D getPosition() const {
        return position;
    }
    
    void setMagneticState(int magneticState);
    
    int getMagneticState() const;
  
};

#endif // LEVELOBJECT_H
