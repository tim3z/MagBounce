#include "StandardPhysics.h"

// Constructors/Destructors
//  

StandardPhysics::StandardPhysics() :
		PhysicalProperties(new StandardGravityBehaviour(), new StandardMagnetismBehaviour(), new StandardTimeBehaviour()) {

}

StandardPhysics::~StandardPhysics() {
}
