/* 
 * File:   GameStateRenderer.h
 * Author: jonathan
 *
 * Created on 27. Oktober 2011, 23:07
 */

#ifndef GAMESTATERENDERER_H
#define	GAMESTATERENDERER_H

#include "../../Engine/Graphics/StateRenderer.h"
#include <vector>
#include "../../Engine/Model/Object.h"

class GameStateRenderer : public StateRenderer {
        
public:
    /**
     * Empty Constructor
     */
    GameStateRenderer ();

    void renderObjects(std::vector<Object*>*);
    
    /**
     * Empty Destructor
     */
    virtual ~GameStateRenderer ();
};

#endif	/* GAMESTATERENDERER_H */

