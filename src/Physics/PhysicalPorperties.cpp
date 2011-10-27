/* 
 * File:   PhysicalPorperties.cpp
 * Author: eagle
 * 
 * Created on 27. Oktober 2011, 15:02
 */

#include "PhysicalPorperties.h"

PhysicalPorperties::PhysicalPorperties() {}

PhysicalPorperties::PhysicalPorperties(const PhysicalPorperties& orig) {}

PhysicalPorperties::~PhysicalPorperties() {
    delete gravityBehaviour;
    delete magnetismBehaviour;
    delete timeBehaviour;
}

