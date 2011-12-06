/* 
 * File:   Display.h
 * Author: jonathan
 *
 * Created on 26. Oktober 2011, 17:19
 */

#ifndef DISPLAY_H
#define	DISPLAY_H

#include "Physics/Vector.h"

struct ALLEGRO_BITMAP;
struct ALLEGRO_DISPLAY;

/**
 * This class is responsible for handling the display and wraps the interaction with allegro.
 */
class Display {
public:
    Display();
    ~Display();

    ALLEGRO_DISPLAY* const getAllegroDisplay() const; // TODO: other way to pass Display to EventHandler?

    /**
     * Draws bitmaps at a given position on the screen (back buffer bitmap)
     *
     * @param bitmap ALLEGRO_BITMAP that will be drawn to the back buffer bitmap.
     * @param screenPosition Position of the drawn bitmap on the screen.
     */
    void render(ALLEGRO_BITMAP* bitmap, Vector2D screenPosition);

    /**
     * Flips the buffers to update the display.
     */
    void update();

private:
    ALLEGRO_DISPLAY *display;

    /* uncopyable */
    Display(const Display&);
    const Display& operator=(const Display&);
};

#endif	/* DISPLAY_H */

