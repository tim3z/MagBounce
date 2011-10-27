/* 
 * File:   PhysicalPorperties.h
 * Author: eagle
 *
 * Created on 27. Oktober 2011, 15:02
 */

#ifndef PHYSICALPORPERTIES_H
#define	PHYSICALPORPERTIES_H

#include "ForceBehaviour.h"
#include "TimeBehaviour.h"

class PhysicalPorperties {
protected:
    
    ForceBehaviour* gravityBehaviour;
    ForceBehaviour* magnetismBehaviour;
    TimeBehaviour* timeBehaviour;
    
public:
    
    PhysicalPorperties();
    PhysicalPorperties(const PhysicalPorperties& orig);
    virtual ~PhysicalPorperties();
    
private:

};

#endif	/* PHYSICALPORPERTIES_H */

