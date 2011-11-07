/*
 * Vector.h
 *
 *  Created on: 07.11.2011
 *      Author: moritz
 */

#ifndef _VECTOR_H_
#define _VECTOR_H_

template <typename T>
struct Vector {
    T x, y;

    Vector() : x(0), y(0) {}

    Vector(const Vector<T>& v) : x(v.x), y(v.y) {}

    Vector(const T x, const T y) : x(x), y(y) {}

    const Vector<T>& operator=(const Vector<T>& v) {
        x = v.x;
        y = v.y;
        return *this;
    }

    ~Vector() {}


    bool operator==(const Vector<T>& v) {
        return (x == v.x && y == v.y);
    }

    bool operator!=(const Vector<T>& v) {
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
        return *this;
    }

    const Vector<T>& operator-=(const Vector<T>& v) {
        x -= v.x;
        y -= v.y;
        return *this;
    }


    const Vector<T> operator*(const T scalar) const {
        return Vector<T>(x * scalar, y * scalar);
    }

    const Vector<T> operator/(const T scalar) const {
        return Vector<T>(x / scalar, y / scalar);
    }

    const Vector<T>& operator*=(const T scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    const Vector<T>& operator/=(const T scalar) {
        x /= scalar;
        y /= scalar;
        return *this;
    }


    T operator*(const Vector<T>& v) const {
        return x * v.x + y * v.y;
    }


    inline T length_squared() const;
};

#endif /* _VECTOR_H_ */
