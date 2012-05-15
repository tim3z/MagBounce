/* 
 * File:   RectangularLevelObject.cpp
 * Author: eagle
 * 
 * Created on 29. Oktober 2011, 17:57
 */

#include "RectangularLevelObject.h"
#include <stdlib.h>
#include "Graphics/RectangularLevelObjectRenderer.h"

RectangularLevelObject::RectangularLevelObject(float x1, float y1, float x2, float y2)
        : upperLeftCorner(Vector2D(x1, y1)) {
    position = Vector2D(x1 + (x2 - x1) / 2, y1 + (y2 - y1) / 2);
    renderer = new RectangularLevelObjectRenderer(*this, abs(x1 - x2), abs(y1 - y2));
}

RectangularLevelObject::~RectangularLevelObject() {
}

Vector2D RectangularLevelObject::getUpperLeftCorner() const {
    return upperLeftCorner;
}

Vector2D RectangularLevelObject::getLowerRightCorner() const {
    return position + (position - upperLeftCorner);
}

Vector2D RectangularLevelObject::getRenderingPosition() const {
    return upperLeftCorner;
}

