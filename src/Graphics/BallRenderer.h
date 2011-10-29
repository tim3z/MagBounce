/* 
 * File:   BallRenderer.h
 * Author: jonathan
 *
 * Created on 30. Oktober 2011, 00:02
 */

#ifndef BALLRENDERER_H
#define	BALLRENDERER_H

#include "Renderer.h"

class BallRenderer : virtual public Renderer {
public:
    
    BallRenderer(float radius);
};

#endif	/* BALLRENDERER_H */

