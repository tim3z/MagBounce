/*
 * LevelBuilder.h
 *
 *  Created on: 27.10.2011
 *      Author: moritz
 */

#ifndef LEVELBUILDER_H_
#define LEVELBUILDER_H_

#include "LevelReader.h"

class LevelBuilder {
private:
	LevelReader *reader;
public:
	LevelBuilder();
	virtual ~LevelBuilder();
};

#endif /* LEVELBUILDER_H_ */
