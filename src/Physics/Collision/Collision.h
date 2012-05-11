/* 
 * File:   Collision.h
 * Author: eagle
 *
 * Created on 28. Oktober 2011, 22:01
 */

#ifndef COLLISION_H
#define	COLLISION_H

#include "Math/Vector.h"

using namespace r2d;

class Object;
class PhysicsAppliableObject;

class Collision {
private:
    Vector2D collisionPoint;
    Vector2D collisionNormal;
    float movementFraction; // How much of the original move to move til the collision
    PhysicsAppliableObject* collisionObject1;
    Object* collisionObject2;

    Collision(const Collision&);
    const Collision& operator=(const Collision&);

public:
    Collision();
    virtual ~Collision();

    void setCollisionObject2(Object *collisionObject2);
    Object* getCollisionObject2() const;
    void setCollisionObject1(PhysicsAppliableObject *collisionObject1);
    PhysicsAppliableObject* getCollisionObject1() const;
    void setMovementFraction(float movementFraction);
    float getMovementFraction() const;
    void setCollisionNormal(Vector2D collisionNormal);
    Vector2D getCollisionNormal() const;
    void setCollisionPoint(Vector2D collisionPoint);
    Vector2D getCollisionPoint() const;

};

#endif	/* COLLISION_H */

