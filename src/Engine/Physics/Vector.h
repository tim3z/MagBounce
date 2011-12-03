/*
 * Vector.h
 *
 *  Created on: 07.11.2011
 *      Author: moritz
 */

#ifndef _VECTOR_H_
#define _VECTOR_H_

template<class T>
struct Vector {
private:
    T x, y;
    // cached_length and length_dirty may be modified in const methods.
    mutable T cached_length;
    mutable bool length_dirty;

public:
    Vector()
            : x(0), y(0), cached_length(0), length_dirty(false) {
    }

    Vector(const Vector<T>& v)
            : x(v.x), y(v.y), cached_length(0), length_dirty(true) {
    }

    Vector(const T x, const T y)
            : x(x), y(y), cached_length(0), length_dirty(true) {
    }

    const Vector<T>& operator=(const Vector<T>& v) {
        x = v.x;
        y = v.y;
        cached_length = v.cached_length;
        length_dirty = v.length_dirty;
        return *this;
    }

    ~Vector() {
    }

    bool operator==(const Vector<T>& v) const {
        return (x == v.x && y == v.y);
    }

    bool operator!=(const Vector<T>& v) const {
        return (x != v.x || y != v.y);
    }

    const Vector<T> operator-() const {
        return Vector<T>(-x, -y);
    }

    const Vector<T> operator+(const Vector<T>& v) const {
        return Vector<T>(x + v.x, y + v.y);
    }

    const Vector<T> operator-(const Vector<T>& v) const {
        return Vector<T>(x - v.x, y - v.y);
    }

    const Vector<T>& operator+=(const Vector<T>& v) {
        x += v.x;
        y += v.y;
        length_dirty = true;
        return *this;
    }

    const Vector<T>& operator-=(const Vector<T>& v) {
        x -= v.x;
        y -= v.y;
        length_dirty = true;
        return *this;
    }

//  Allow wrong order (vector * scalar), for correct order see friend function below
    const Vector<T> operator*(const T scalar) const {
        return Vector<T>(x * scalar, y * scalar);
    }

    friend const Vector<T> operator*(const T scalar, const Vector<T> vector) {
        return Vector<T>(vector.x * scalar, vector.y * scalar);
    }

    const Vector<T> operator/(const T scalar) const {
        return Vector<T>(x / scalar, y / scalar);
    }

    const Vector<T>& operator*=(const T scalar) {
        x *= scalar;
        y *= scalar;
        length_dirty = true;
        return *this;
    }

    const Vector<T>& operator/=(const T scalar) {
        x /= scalar;
        y /= scalar;
        length_dirty = true;
        return *this;
    }

    T operator*(const Vector<T>& v) const {
        return x * v.x + y * v.y;
    }

    T getX() const {
        return x;
    }

    T getY() const {
        return y;
    }

    void setX(const T newX) {
        x = newX;
        length_dirty = true;
    }

    void setY(const T newY) {
        y = newY;
        length_dirty = true;
    }

    /**
     * Calculates the length of this vector.
     *
     * The behavior of this function on a Vector<int> is currently undefined.
     *
     * @return Length of this vector
     */
    T length() const;

    /**
     * Creates a normalized version of this vector.
     *
     * It is not guaranteed that the returned vector's length is exactly 1, due to possible rounding errors.
     * Be sure to check whether this vector's length is 0 before calling this function.
     * The behavior of this function on a Vector<int> is currently undefined.
     *
     * @return Normalized vector
     */
    Vector<T> normalized() const;

    /**
     * Normalizes this vector.
     *
     * It is not guaranteed that this vector's length is exactly 1 afterwards, due to possible rounding errors.
     * Be sure to check whether this vector's length is 0 before calling this function.
     * The behavior of this function on a Vector<int> is currently undefined.
     */
    void normalize();
};

/* *** IMPORTANT! ***
 * gcc needs all template function definitions in the header file or it will produce linker errors!
 * http://stackoverflow.com/questions/648900/c-templates-undefined-reference
 */
#include "Vector.hpp"

typedef Vector<float> Vector2D;

#endif /* _VECTOR_H_ */
