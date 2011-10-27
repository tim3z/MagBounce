
#ifndef FORCEBEHAVIOUR_H
#define FORCEBEHAVIOUR_H

#include <string>

/**
  * interface ForceBehaviour
  * 
  */

/******************************* Abstract Class ****************************
ForceBehaviour does not have any pure virtual methods, but its author
  defined it as an abstract class, so you should not use it directly.
  Inherit from it instead and create only objects from the derived classes
*****************************************************************************/

class ForceBehaviour {
public:
	virtual ~ForceBehaviour();
};

#endif // FORCEBEHAVIOUR_H
