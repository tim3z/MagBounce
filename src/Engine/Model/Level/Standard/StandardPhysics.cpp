#include "StandardPhysics.h"
#include "StandardGravityBehaviour.h"
#include "StandardMagnetismBehaviour.h"
#include "StandardTimeBehaviour.h"

// Constructors/Destructors
//  

StandardPhysics::StandardPhysics()
        : PhysicalProperties(new StandardGravityBehaviour(), new StandardMagnetismBehaviour(),
                new StandardTimeBehaviour()) {

}

StandardPhysics::~StandardPhysics() {
}
