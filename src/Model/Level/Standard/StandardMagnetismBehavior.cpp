#include "StandardMagnetismBehavior.h"
#include "Model/Object.h"

// Constructors/Destructors

StandardMagnetismBehavior::StandardMagnetismBehavior() {
}

StandardMagnetismBehavior::~StandardMagnetismBehavior() {
}

Vector2D StandardMagnetismBehavior::getAccelerationAt(const Vector2D& position, const std::vector<Object*> &objects) {
    Vector2D force;

    for (unsigned int i = 0; i < objects.size(); i++) {
        Vector2D dif = position - objects[i]->getPosition();
        float norm = dif.length();

        if (norm != 0) {
            force += dif * objects[i]->getMagneticState() / (norm * norm);
        }
    }

    return force;
}
