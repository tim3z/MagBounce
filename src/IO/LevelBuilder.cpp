/*
 * LevelBuilder.cpp
 *
 *  Created on: 27.10.2011
 *      Author: moritz
 */

#include "LevelBuilder.h"
#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>

namespace file = boost::filesystem;
using file::path; using file::ifstream;
using std::cerr; using std::endl;

queue<string>* LevelBuilder::getFileContents(const string& filePath) {
	queue<string>* fileContents = new queue<string>();
	path path(filePath);

	try {
		if (file::exists(path)) {
			if (file::is_regular_file(path)) {
				ifstream file(path);
				if (file.is_open()) {
					string temp;
					while (std::getline(file, temp)) {
						if (temp.substr(0, 1) != "#") {
							fileContents->push(temp);
						}
					}
				} else {
					cerr << "Unable to open file " << path << '\n';
				}
			} else {
				cerr << path << " is no regular file." << '\n';
			}
		} else {
			cerr << "Path does not exist: " << path << '\n';
		}
	} catch (const file::filesystem_error& e) {
		cerr << "Error while trying to read " << path << ": " << e.what() << '\n';
	}

	return fileContents;
}

Level& LevelBuilder::build(const std::string& levelFile) {
	Level* level = 0;
	// TODO:
	return *level;
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
