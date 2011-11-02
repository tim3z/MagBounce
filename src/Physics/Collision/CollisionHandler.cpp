#include "CollisionHandler.h"
#include "Collision.h"
#include "../../Model/RectangularLevelObject.h"

using namespace boost::numeric::ublas;

// Constructors/Destructors
//  

CollisionHandler::CollisionHandler () {}

CollisionHandler::~CollisionHandler () {}

Collision* CollisionHandler::checkForCollision(PhysicsApplyableObject &object, const Vector2D &move, const std::vector<RectangularLevelObject*> &objects) {
    Collision* collision = new Collision();
    collision->setMovementFraction(2.0f);
    collision->setCollisionObject1(&object);
    Vector2D offset = getOffsetVector(object.getCollisionRadius());
    Vector2D begin = object.getPosition();
    Vector2D end = object.getPosition() + move;
    
    for (unsigned int i = 0; i < objects.size(); i++) {
        Vector2D ul = objects[i]->getUpperLeftCorner() - offset;
        Vector2D lr = objects[i]->getLowerRightCorner() + offset;
        
        if (!((begin[1] > lr[1] && end[1] > lr[1]) || (begin[1] < ul[1] && end[1] < ul[1]))) {
            if (begin[0] < ul[0] && end[0] > ul[0]) {
                float fraction = (ul[0] - begin[0]) / move[0];
                if (collision->getMovementFraction() > fraction) {
                    collision->setMovementFraction(fraction);
                    collision->setCollisionObject2(objects[i]);
                    collision->setCollisionPoint(begin + fraction * move);
                    collision->setCollisionNormal(-unit_vector<float>(2,0));
                }
            }
            if (begin[0] > lr[0] && end[0] < lr[0]) {
                float fraction = (begin[0] - lr[0]) / move[0];
                if (collision->getMovementFraction() > fraction) {
                    collision->setMovementFraction(fraction);
                    collision->setCollisionObject2(objects[i]);
                    collision->setCollisionPoint(begin + fraction * move);
                    collision->setCollisionNormal(unit_vector<float>(2,0));
                }
            }
        }
        if (!((begin[0] > lr[0] && end[0] > lr[0]) || (begin[0] < ul[0] && end[0] < ul[0]))) {
            
            if (begin[1] < ul[1] && end[1] > ul[1]) {
                float fraction = (ul[1] - begin[1]) / move[1];
                if (collision->getMovementFraction() > fraction) {
                    collision->setMovementFraction(fraction);
                    collision->setCollisionObject2(objects[i]);
                    collision->setCollisionPoint(begin + fraction * move);
                    collision->setCollisionNormal(-unit_vector<float>(2,1));
                }
            }
            if (begin[1] > lr[1] && end[1] < lr[1]) {
                float fraction = (begin[1] - lr[1]) / move[1];
                if (collision->getMovementFraction() > fraction) {
                    collision->setMovementFraction(fraction);
                    collision->setCollisionObject2(objects[i]);
                    collision->setCollisionPoint(begin + fraction * move);
                    collision->setCollisionNormal(unit_vector<float>(2,1));
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
    return (unit_vector<float>(2,0) + unit_vector<float>(2,1)) * collisionRadius;
}
