/* 
 * File:   Graphics.h
 * Author: jonathan
 *
 * Created on 26. Oktober 2011, 17:19
 */

#ifndef GRAPHICS_H
#define	GRAPHICS_H

#include <allegro5/allegro5.h>
#include <cstdio>

/**
  * class Graphics
  * 
  */

class Graphics {
    
private:
    ALLEGRO_DISPLAY *display;
    
public:

    /**
     * Empty Constructor
     */
    Graphics ();
    
    void render(ALLEGRO_BITMAP*);

    /**
     * Empty Destructor
     */
    virtual ~Graphics ();

};

#endif	/* GRAPHICS_H */

