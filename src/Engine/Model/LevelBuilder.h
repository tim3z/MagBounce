/*
 * LevelBuilder.h
 *
 *  Created on: 27.10.2011
 *      Author: moritz
 */

#ifndef LEVELBUILDER_H_
#define LEVELBUILDER_H_

#include <list>
#include <string>

using std::list; using std::string;
class Level;

class LevelBuilder {
private:
	LevelBuilder();
	//LevelBuilder(const LevelBuilder&);
	//const LevelBuilder& operator=(const LevelBuilder &);
	virtual ~LevelBuilder();

	static void parseFileContents(const string& path, list<string>& result);
public:
	/**
	 * Builds a new Level from a level file and returns it.
	 *
	 * The caller takes ownership of the returned level.
	 *
	 * @param levelFile Path to the level file to parse
	 * @return Level built from the file or null pointer on error
	 */
	static Level* build(const string& levelFile);
};

#endif /* LEVELBUILDER_H_ */
