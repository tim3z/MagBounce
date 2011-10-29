/* 
 * File:   Collision.h
 * Author: eagle
 *
 * Created on 28. Oktober 2011, 22:01
 */

#ifndef COLLISION_H
#define	COLLISION_H

#include "../Vector2D.h"
#include "../../Model/LevelObject.h"

class Collision {
private:
    
    Vector2D collisionPoint;
    Vector2D collisionNormal;
    float movementFraction; // How much of the original move to move til the collision
    LevelObject* collisionObject1;
    LevelObject* collisionObject2;
    
    
public:
    
    Collision();
    Collision(const Collision& orig);
    virtual ~Collision();
    
    void setCollisionObject2(LevelObject *collisionObject2);
    LevelObject* getCollisionObject2() const;
    void setCollisionObject1(LevelObject *collisionObject1);
    LevelObject* getCollisionObject1() const;
    void setMovementFraction(float movementFraction);
    float getMovementFraction() const;
    void setCollisionNormal(Vector2D collisionNormal);
    Vector2D getCollisionNormal() const;
    void setCollisionPoint(Vector2D collisionPoint);
    Vector2D getCollisionPoint() const;
    
    
private:

};

#endif	/* COLLISION_H */

