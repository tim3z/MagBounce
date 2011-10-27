/* 
 * File:   TestRenderer.h
 * Author: jonathan
 *
 * Created on 26. Oktober 2011, 17:54
 */

#ifndef TESTRENDERER_H
#define	TESTRENDERER_H

#include <allegro5/allegro5.h>

class TestRenderer {
    
private:
    ALLEGRO_BITMAP *bitmap;
    
public:

    /**
     * Empty Constructor
     */
    TestRenderer ();
    
    ALLEGRO_BITMAP* getBitmap();

    /**
     * Empty Destructor
     */
    virtual ~TestRenderer ();

};

#endif	/* TESTRENDERER_H */

