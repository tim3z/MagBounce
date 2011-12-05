/* 
 * File:   TestRenderer.h
 * Author: jonathan
 *
 * Created on 26. Oktober 2011, 17:54
 */

#ifndef RENDERER_H
#define	RENDERER_H

struct ALLEGRO_BITMAP;

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
    virtual ~Renderer();

};

#endif	/* RENDERER_H */

