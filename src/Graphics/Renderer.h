/* 
 * File:   TestRenderer.h
 * Author: jonathan
 *
 * Created on 26. Oktober 2011, 17:54
 */

#ifndef RENDERER_H
#define RENDERER_H

struct ALLEGRO_BITMAP;

class Renderer {
public:
    Renderer();
    Renderer(const Renderer&) = delete;
    const Renderer& operator=(const Renderer&) = delete;

    virtual ALLEGRO_BITMAP* getBitmap();

    /**
     * Empty Destructor
     */
    virtual ~Renderer();

protected:
    ALLEGRO_BITMAP *bitmap;
};

#endif	/* RENDERER_H */

