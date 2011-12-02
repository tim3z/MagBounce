#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/vector_expression.hpp>

typedef boost::numeric::ublas::vector<float> Vector2D;
// TODO: provide good macros or subclass which overloads all relevant operators
#define Vector2D() Vector2D(2)

#endif // VECTOR2D_H
