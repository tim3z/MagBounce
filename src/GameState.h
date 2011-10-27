#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <string>

/**
  * interface GameState
  * 
  */

/******************************* Abstract Class ****************************
GameState does not have any pure virtual methods, but its author
  defined it as an abstract class, so you should not use it directly.
  Inherit from it instead and create only objects from the derived classes
*****************************************************************************/

class GameState {
public:
	virtual ~GameState();
};

#endif // GAMESTATE_H
