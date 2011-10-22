
#ifndef PHYSICS_H
#define PHYSICS_H

#include <string>

/**
  * class Physics
  * 
  */

/******************************* Abstract Class ****************************
Physics does not have any pure virtual methods, but its author
  defined it as an abstract class, so you should not use it directly.
  Inherit from it instead and create only objects from the derived classes
*****************************************************************************/

class Physics
{
public:


  // Public attribute accessor methods
  //  


  // Public attribute accessor methods
  //  



  /**
   * @return 2dVector
   * @param  Object
   */
  virtual 2dVector calculateMoveFor (PhysicsApplyableObject Object )
  {
  }

protected:

public:


  // Protected attribute accessor methods
  //  

protected:

public:


  // Protected attribute accessor methods
  //  

protected:


private:

public:


  // Private attribute accessor methods
  //  

private:

public:


  // Private attribute accessor methods
  //  

private:



};

#endif // PHYSICS_H
