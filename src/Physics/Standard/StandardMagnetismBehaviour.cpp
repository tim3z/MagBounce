#include "StandardMagnetismBehaviour.h"

// Constructors/Destructors
//  

using namespace boost::numeric::ublas;

StandardMagnetismBehaviour::StandardMagnetismBehaviour () {}

StandardMagnetismBehaviour::~StandardMagnetismBehaviour () {}

Vector2D StandardMagnetismBehaviour::getAccelerationAt(const Vector2D& position, const std::vector<LevelObject*> &objects) {
    Vector2D force(2);
    
    for (unsigned int i = 0; i < objects.size(); i++) {
        Vector2D dif = position - objects[i]->getPosition();
        float norm = norm_2(dif);
                
        force += dif * objects[i]->getMagneticState() / (norm * norm);
    }
    
    return force;
}
