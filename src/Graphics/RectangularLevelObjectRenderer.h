/* 
 * File:   RectangularLevelObjectRenderer.h
 * Author: eagle
 *
 * Created on 29. Oktober 2011, 23:58
 */

#ifndef RECTANGULARLEVELOBJECTRENDERER_H
#define	RECTANGULARLEVELOBJECTRENDERER_H

#include "Graphics/Renderer.h"
#include "Model/RectangularLevelObject.h"

class RectangularLevelObjectRenderer : public Renderer {
public:

    RectangularLevelObjectRenderer(RectangularLevelObject& levelObject, float height, float width);
    RectangularLevelObjectRenderer(const RectangularLevelObjectRenderer& orig);
    virtual ~RectangularLevelObjectRenderer();
    
    ALLEGRO_BITMAP* getBitmap();

private:
    RectangularLevelObject& levelObject;

};

#endif	/* RECTANGULARLEVELOBJECTRENDERER_H */

