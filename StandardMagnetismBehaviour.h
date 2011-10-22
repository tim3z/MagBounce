
#ifndef STANDARDMAGNETISMBEHAVIOUR_H
#define STANDARDMAGNETISMBEHAVIOUR_H
#include "ForceBehaviour.h"

#include <string>

/**
  * class StandardMagnetismBehaviour
  * 
  */

class StandardMagnetismBehaviour : virtual public ForceBehaviour
{
public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  StandardMagnetismBehaviour ( );

  /**
   * Empty Destructor
   */
  virtual ~StandardMagnetismBehaviour ( );

  // Static Public attributes
  //  

  // Public attributes
  //  


  // Public attribute accessor methods
  //  


  // Public attribute accessor methods
  //  


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

#endif // STANDARDMAGNETISMBEHAVIOUR_H
