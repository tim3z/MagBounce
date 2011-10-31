/*
 * LevelBuilder.cpp
 *
 *  Created on: 27.10.2011
 *      Author: moritz
 */

#include "LevelBuilder.h"
#include <iostream>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/foreach.hpp>
#include <boost/lexical_cast.hpp>

namespace file = boost::filesystem;
using boost::bad_lexical_cast; using boost::lexical_cast; using boost::split;
using file::path; using file::ifstream;
using std::cerr; using std::endl; using std::vector;
#define foreach BOOST_FOREACH

void LevelBuilder::parseFileContents(const string& filePath, list<string>& result) {
	path path(filePath);

	try {
		if (file::exists(path)) {
			if (file::is_regular_file(path)) {
				ifstream file(path);
				if (file) {
					string temp;
					while (std::getline(file, temp)) {
						if (temp.substr(0, 1) != "#" && !temp.empty()) { // Ignore comments and empty lines
							result.push_back(temp);
						}
					}
				} else {
					cerr << "Unable to open file " << path << '\n';
				}
				file.close();
			} else {
				cerr << path << " is no regular file." << '\n';
			}
		} else {
			cerr << "Path does not exist: " << path << '\n';
		}
	} catch (const file::filesystem_error& e) {
		cerr << "Error while trying to read " << path << ": " << e.what() << '\n';
	}
}

Level* LevelBuilder::build(const string& levelFile) {
	Level* level = 0;
	list<string> fileContents;
	vector<string> currentLineContents;

	parseFileContents(levelFile, fileContents);

	if (fileContents.empty()) {
		cerr << "Level file seems to be empty.";
		return 0; // File could not be read or is empty
	}

	// Try to parse first line, return 0 on failure
	split(currentLineContents, fileContents.front(), boost::is_any_of(","));
	if (currentLineContents.size() != 2) {
		cerr << "Bad first line, should only contain level width and height separated by one comma.\n";
		return 0;
	}
	try {
		level = new Level(lexical_cast<int>(currentLineContents.at(0)), lexical_cast<int>(currentLineContents.at(1)));
	} catch (const bad_lexical_cast& e) {
		cerr << "Error while trying to parse level properties. Width and/or height are not valid integer values.\n";
		return 0;
	}
	fileContents.pop_front();

	// FIXME: parse second and third line
	fileContents.pop_front();
	fileContents.pop_front();

	// Try to parse additional lines
	foreach(string line, fileContents) {
		split(currentLineContents, fileContents.front(), boost::is_any_of(","));
		int size = currentLineContents.size();
		RectangularLevelObject* levelObject = 0;
		try {
			switch (size) {
			case 5:
				levelObject = new RectangularLevelObject(
							lexical_cast<float>(currentLineContents.at(0)),
							lexical_cast<float>(currentLineContents.at(1)),
							lexical_cast<float>(currentLineContents.at(2)),
							lexical_cast<float>(currentLineContents.at(3))
						);
				levelObject->setMagneticState(lexical_cast<int>(currentLineContents.at(4)));
				break;
			case 4:
				levelObject = new RectangularLevelObject(
							lexical_cast<float>(currentLineContents.at(0)),
							lexical_cast<float>(currentLineContents.at(1)),
							lexical_cast<float>(currentLineContents.at(2)),
							lexical_cast<float>(currentLineContents.at(3))
						);
				break;
			default:
				cerr << "Error while trying to parse level object properties.\n";
				delete level;
				return 0;
			}
		} catch (const bad_lexical_cast& e) {
			cerr << "Error while trying to parse level object properties.\n";
			if (levelObject != 0) delete levelObject;
			delete level;
			return 0;
		}
		level->addLevelObject(levelObject);
		fileContents.pop_front();
	}

	return level;
}

/*int main(int argc, char** argv) {
	string test("test.level");
    queue<string>* fileContents = LevelBuilder::getFileContents(test);
    string line;

    while(!fileContents->empty()) {
    	line = fileContents->front();
    	fileContents->pop();
    	std::cout << line << '\n';
    }

    return 0;
}*/
