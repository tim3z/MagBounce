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
#include "../Physics/Vector2D.h"

/**
  * class Graphics
  * Wraps Allegros graphic library for MagBounce usage.
  */

class Graphics {
public:
    
    /**
     * Singleton method
     * @return an instance of this Graphics
     */
    static Graphics* getInstance();
    
    ALLEGRO_DISPLAY* getDisplay();
    
    /**
     * Draws bitmaps at a given position on the screen (back buffer bitmap)
     * @param ALLEGRO_BITMAP that will be drawn to the back buffer bitmap.
     * @param Vector2D that contains the position of the drawn bitmap on the screen.
     */
    void render(ALLEGRO_BITMAP*, Vector2D);
    
    /**
     * Implementation should call al_flip_display
     */
    void flipDisplay();
    
    void destroyDisplay();

    /**
     * Should at least destroy the ALLEGRO_DISPLAY.
     */
    virtual ~Graphics ();
    
protected:
    
    /**
     * Implementation should create ALLEGRO_DISPLAY and set possible flags and options.
     */
    Graphics ();
    
private:
    
    /**
     * Thie Singleton of this class.
     */
    static Graphics* graphicsInstance;
    
    ALLEGRO_DISPLAY *display;

    Graphics(const Graphics&);
    const Graphics& operator=(const Graphics&);
};

#endif	/* GRAPHICS_H */

