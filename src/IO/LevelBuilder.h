/*
 * LevelBuilder.h
 *
 *  Created on: 27.10.2011
 *      Author: moritz
 */

#ifndef LEVELBUILDER_H_
#define LEVELBUILDER_H_

#include <queue>
#include <string>
#include "../Model/Level.h"

using std::queue; using std::string;

class LevelBuilder {
private:
	LevelBuilder();
	LevelBuilder (const LevelBuilder&);
	const LevelBuilder& operator=(const LevelBuilder &);
	virtual ~LevelBuilder();

	static queue<string>* getFileContents(const string& path);
public:
	static Level& build(const std::string& levelFile);
};

#endif /* LEVELBUILDER_H_ */
