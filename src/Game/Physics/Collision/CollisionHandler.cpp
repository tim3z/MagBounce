#include "CollisionHandler.h"
#include "Collision.h"
#include "Model/Level.h"
#include "Physics/PhysicsAppliableObject.h"
#include "Model/RectangularLevelObject.h"

// Constructors/Destructors

CollisionHandler::CollisionHandler() {
}

CollisionHandler::~CollisionHandler() {
}

Collision* CollisionHandler::checkForCollision(PhysicsAppliableObject &object, const Vector2D &move,
        const std::vector<RectangularLevelObject*> &objects) {
    Collision* collision = new Collision();
    collision->setMovementFraction(2.0f);
    collision->setCollisionObject1(&object);
    Vector2D offset = getOffsetVector(object.getCollisionRadius());
    Vector2D begin = object.getPosition();
    Vector2D end = object.getPosition() + move;

    for (unsigned int i = 0; i < objects.size(); i++) {
        Vector2D ul = objects[i]->getUpperLeftCorner() - offset;
        Vector2D lr = objects[i]->getLowerRightCorner() + offset;

        if (!((begin.getY() > lr.getY() && end.getY() > lr.getY())
                || (begin.getY() < ul.getY() && end.getY() < ul.getY()))) {
            if (begin.getX() < ul.getX() && end.getX() > ul.getX()) {
                float fraction = (ul.getX() - begin.getX()) / move.getX();
                if (collision->getMovementFraction() > fraction) {
                    collision->setMovementFraction(fraction);
                    collision->setCollisionObject2(objects[i]);
                    collision->setCollisionPoint(begin + fraction * move);
                    collision->setCollisionNormal(-Vector2D(1, 0));
                }
            }
            if (begin.getX() > lr.getX() && end.getX() < lr.getX()) {
                float fraction = (begin.getX() - lr.getX()) / move.getX();
                if (collision->getMovementFraction() > fraction) {
                    collision->setMovementFraction(fraction);
                    collision->setCollisionObject2(objects[i]);
                    collision->setCollisionPoint(begin + fraction * move);
                    collision->setCollisionNormal(Vector2D(1, 0));
                }
            }
        }
        if (!((begin.getX() > lr.getX() && end.getX() > lr.getX())
                || (begin.getX() < ul.getX() && end.getX() < ul.getX()))) {

            if (begin.getY() < ul.getY() && end.getY() > ul.getY()) {
                float fraction = (ul.getY() - begin.getY()) / move.getY();
                if (collision->getMovementFraction() > fraction) {
                    collision->setMovementFraction(fraction);
                    collision->setCollisionObject2(objects[i]);
                    collision->setCollisionPoint(begin + fraction * move);
                    collision->setCollisionNormal(-Vector2D(0, 1));
                }
            }
            if (begin.getY() > lr.getY() && end.getY() < lr.getY()) {
                float fraction = (begin.getY() - lr.getY()) / move.getY();
                if (collision->getMovementFraction() > fraction) {
                    collision->setMovementFraction(fraction);
                    collision->setCollisionObject2(objects[i]);
                    collision->setCollisionPoint(begin + fraction * move);
                    collision->setCollisionNormal(Vector2D(0, 1));
                }
            }
        }

    }

    if (collision->getMovementFraction() == 2.0f) {
        collision = NULL;
    }
    return collision;
}

Vector2D CollisionHandler::getOffsetVector(int collisionRadius) {
    return (Vector2D(1, 1)) * collisionRadius;
}
