/* 
 * File:   RectangularLevelObject.cpp
 * Author: eagle
 * 
 * Created on 29. Oktober 2011, 17:57
 */

#include "RectangularLevelObject.h"

RectangularLevelObject::RectangularLevelObject() {
}

RectangularLevelObject::RectangularLevelObject(const RectangularLevelObject& orig) {
}

RectangularLevelObject::~RectangularLevelObject() {
}

Vector2D RectangularLevelObject::getUpperLeftCorner() const {
    return upperLeftCorner;
}

Vector2D RectangularLevelObject::getLowerRightCorner() const {
    return (position - upperLeftCorner) * 2;
}

