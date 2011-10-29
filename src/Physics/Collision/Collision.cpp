/* 
 * File:   Collision.cpp
 * Author: eagle
 * 
 * Created on 28. Oktober 2011, 22:01
 */

#include "Collision.h"

Collision::Collision() {
}

Collision::Collision(const Collision& orig) {
}

Collision::~Collision() {
}

void Collision::setCollisionObject2(LevelObject* collisionObject2) {
    this->collisionObject2 = collisionObject2;
}

LevelObject* Collision::getCollisionObject2() const {
    return collisionObject2;
}

void Collision::setCollisionObject1(LevelObject* collisionObject1) {
    this->collisionObject1 = collisionObject1;
}

LevelObject* Collision::getCollisionObject1() const {
    return collisionObject1;
}

void Collision::setMovementFraction(float movementFraction) {
    this->movementFraction = movementFraction;
}

float Collision::getMovementFraction() const {
    return movementFraction;
}

void Collision::setCollisionNormal(Vector2D collisionNormal) {
    this->collisionNormal = collisionNormal;
}

Vector2D Collision::getCollisionNormal() const {
    return collisionNormal;
}

void Collision::setCollisionPoint(Vector2D collisionPoint) {
    this->collisionPoint = collisionPoint;
}

Vector2D Collision::getCollisionPoint() const {
    return collisionPoint;
}

