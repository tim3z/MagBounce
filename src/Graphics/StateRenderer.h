/* 
 * File:   StateRenderer.h
 * Author: jonathan
 *
 * Created on 27. Oktober 2011, 23:13
 */

#ifndef STATERENDERER_H
#define	STATERENDERER_H

#include <vector>
#include "../Model/LevelObject.h"

/**
  * class StateRenderer
  * 
  */

class StateRenderer {
    
public:
    
    /**
     * Empty Constructor
     */
    StateRenderer ();
    
    void renderObjects(std::vector<LevelObject>*);

    /**
     * Empty Destructor
     */
    virtual ~StateRenderer ();
    
};

#endif	/* STATERENDERER_H */

