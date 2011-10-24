
#ifndef STANDARDMAGNETISMBEHAVIOUR_H
#define STANDARDMAGNETISMBEHAVIOUR_H
#include "ForceBehaviour.h"

#include <string>
#include "Level.h"

/**
  * class StandardMagnetismBehaviour
  * 
  */

class StandardMagnetismBehaviour : virtual public ForceBehaviour {
    
private:

    Level level;
  
public:

    /**
     * Empty Constructor
     */
    StandardMagnetismBehaviour ();

    /**
     * Empty Destructor
     */
    virtual ~StandardMagnetismBehaviour ();

    /**
     * Set the value of level
     * @param new_var the new value of level
     */
    void setLevel (Level new_var) {
        level = new_var;
    }

    /**
     * Get the value of level
     * @return the value of level
     */
    Level getLevel () {
        return level;
    }
};

#endif // STANDARDMAGNETISMBEHAVIOUR_H
