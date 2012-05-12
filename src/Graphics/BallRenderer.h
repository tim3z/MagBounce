/* 
 * File:   BallRenderer.h
 * Author: jonathan
 *
 * Created on 30. Oktober 2011, 00:02
 */

#ifndef BALLRENDERER_H
#define	BALLRENDERER_H

#include "Graphics/Renderer.h"

class BallRenderer : public Renderer {
public:
    BallRenderer(float radius);
    void setColor(int r, int g, int b);
};

#endif	/* BALLRENDERER_H */

