
#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include <string>

/**
  * class CollisionHandler
  * 
  */

class CollisionHandler
{
public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  CollisionHandler ( );

  /**
   * Empty Destructor
   */
  virtual ~CollisionHandler ( );

  // Static Public attributes
  //  

  // Public attributes
  //  


  // Public attribute accessor methods
  //  


  // Public attribute accessor methods
  //  



  /**
   * @return 2dVector
   * @param  object
   * @param  move
   */
  2dVector checkForCollision (PhysicsApplyableObject object, 2dVector move )
  {
  }

protected:

  // Static Protected attributes
  //  

  // Protected attributes
  //  

public:


  // Protected attribute accessor methods
  //  

protected:

public:


  // Protected attribute accessor methods
  //  

protected:


private:

  // Static Private attributes
  //  

  // Private attributes
  //  

  Level level;
public:


  // Private attribute accessor methods
  //  

private:

public:


  // Private attribute accessor methods
  //  


  /**
   * Set the value of level
   * @param new_var the new value of level
   */
  void setLevel ( Level new_var )   {
      level = new_var;
  }

  /**
   * Get the value of level
   * @return the value of level
   */
  Level getLevel ( )   {
    return level;
  }
private:


  void initAttributes ( ) ;

};

#endif // COLLISIONHANDLER_H
