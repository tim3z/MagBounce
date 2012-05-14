/* 
 * File:   BallRenderer.h
 * Author: jonathan
 *
 * Created on 30. Oktober 2011, 00:02
 */

#ifndef BALLRENDERER_H
#define BALLRENDERER_H

#include "Graphics/Renderer.h"
#include "Model/PlayerObject.h"

class BallRenderer : public Renderer {
public:
    BallRenderer(PlayerObject& ball, float radius);
    
    ALLEGRO_BITMAP* getBitmap();
    
private:
    PlayerObject& ball;
};

#endif	/* BALLRENDERER_H */

