/* 
 * File:   GameStateRenderer.h
 * Author: jonathan
 *
 * Created on 27. Oktober 2011, 23:07
 */

#ifndef GAMESTATERENDERER_H
#define	GAMESTATERENDERER_H

#include "StateRenderer.h"
#include <vector>
#include "../Model/LevelObject.h"

class GameStateRenderer : public StateRenderer {
        
public:
    /**
     * Empty Constructor
     */
    GameStateRenderer ();

    void renderObjects(std::vector<LevelObject*>*);
    
    /**
     * Empty Destructor
     */
    virtual ~GameStateRenderer ();
};

#endif	/* GAMESTATERENDERER_H */

