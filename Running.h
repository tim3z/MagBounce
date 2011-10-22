
#ifndef RUNNING_H
#define RUNNING_H
#include "GameState.h"
#include "Level.h"
#include "CollisionHandler.h"

#include <string>

/**
  * class Running
  * 
  */

class Running : virtual public GameState {

private:

    Level level;
    CollisionHandler collisionHandler;
    
public:

    /**
     * Empty Constructor
     */
    Running ();

    /**
     * Empty Destructor
     */
    virtual ~Running ();

    /**
     * Set the value of level
     * @param new_var the new value of level
     */
    void setLevel (Level new_var)   {
        level = new_var;
    }

    /**
     * Get the value of level
     * @return the value of level
     */
    Level getLevel ( )   {
        return level;
    }

    /**
     * Set the value of collisionHandler
     * @param new_var the new value of collisionHandler
     */
    void setCollisionHandler ( CollisionHandler new_var )   {
        collisionHandler = new_var;
    }

    /**
     * Get the value of collisionHandler
     * @return the value of collisionHandler
     */
    CollisionHandler getCollisionHandler ( )   {
        return collisionHandler;
    }
  
private:
    
    void initAttributes ( ) ;

};

#endif // RUNNING_H
