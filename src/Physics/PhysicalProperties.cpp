/* 
 * File:   PhysicalProperties.cpp
 * Author: eagle
 * 
 * Created on 27. Oktober 2011, 15:02
 */

#include "PhysicalProperties.h"

PhysicalProperties::~PhysicalProperties() {
    delete gravityBehaviour;
    delete magnetismBehaviour;
    delete timeBehaviour;
}

