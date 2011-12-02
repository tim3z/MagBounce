/* 
 * File:   TestRenderer.h
 * Author: jonathan
 *
 * Created on 26. Oktober 2011, 17:54
 */

#ifndef TESTRENDERER_H
#define	TESTRENDERER_H

#include <allegro5/allegro5.h>

class Renderer {
private:
	Renderer(const Renderer&);
	const Renderer& operator=(const Renderer&);
    
protected:
    ALLEGRO_BITMAP *bitmap;
    
public:
    Renderer();
    
    virtual ALLEGRO_BITMAP* getBitmap();

    /**
     * Empty Destructor
     */
    virtual ~Renderer ();

};

#endif	/* TESTRENDERER_H */

