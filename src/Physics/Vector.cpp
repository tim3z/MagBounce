#include "Vector.h"
#include <math.h>

// TODO: what happens for a Vector<int>?
template<class T> T Vector<T>::length() const {
    if (length_dirty) {
        cached_length = sqrt(*this * *this);
        length_dirty = false;
    }
    return cached_length;
}

template<class T> Vector<T> Vector<T>::normalized() const {
    return *this / this->length();
}

template<class T> void Vector<T>::normalize() {
    *this /= this->length();
}
