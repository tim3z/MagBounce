/* 
 * File:   GameStateRenderer.h
 * Author: jonathan
 *
 * Created on 27. Oktober 2011, 23:07
 */

#ifndef GAMESTATERENDERER_H
#define	GAMESTATERENDERER_H

#include <vector>
#include "Graphics/StateRenderer.h"

using std::vector;
class Object;

class GameStateRenderer : public StateRenderer {

public:
    /**
     * Empty Constructor
     */
    GameStateRenderer();

    void renderObjects(vector<Object*>*);

    /**
     * Empty Destructor
     */
    virtual ~GameStateRenderer();
};

#endif	/* GAMESTATERENDERER_H */

