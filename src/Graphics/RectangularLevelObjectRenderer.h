/* 
 * File:   RectangularLevelObjectRenderer.h
 * Author: eagle
 *
 * Created on 29. Oktober 2011, 23:58
 */

#ifndef RECTANGULARLEVELOBJECTRENDERER_H
#define	RECTANGULARLEVELOBJECTRENDERER_H

#include "Renderer.h"

class RectangularLevelObjectRenderer : virtual public Renderer {
public:
    
    RectangularLevelObjectRenderer(float height, float width);
    RectangularLevelObjectRenderer(const RectangularLevelObjectRenderer& orig);
    virtual ~RectangularLevelObjectRenderer();
    
private:

};

#endif	/* RECTANGULARLEVELOBJECTRENDERER_H */

