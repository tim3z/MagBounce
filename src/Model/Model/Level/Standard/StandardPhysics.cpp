#include "StandardPhysics.h"
#include "StandardGravityBehavior.h"
#include "StandardMagnetismBehavior.h"
#include "StandardTimeBehavior.h"

// Constructors/Destructors
//  

StandardPhysics::StandardPhysics()
        : PhysicalProperties(new StandardGravityBehavior(), new StandardMagnetismBehavior(),
                new StandardTimeBehavior()) {

}

StandardPhysics::~StandardPhysics() {
}
