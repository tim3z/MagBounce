/*
 * Config.h
 *
 *  Created on: 11.02.2012
 *      Author: moritz
 */

#ifndef CONFIG_H_
#define CONFIG_H_

#include "Graphics/DisplayConfig.h"

struct Config {
    DisplayConfig displayConfig;
    double maxFPS;            // target FPS
    // should not be configurable by the user, otherwise the physics simulation may break and is not reproducible
    double physicsInterval;   // time interval simulated by the physics in one simulation step (in seconds)
    double maxSimulationTime; // max time simulated within one iteration of the game loop (in seconds)
};

#endif /* CONFIG_H_ */
