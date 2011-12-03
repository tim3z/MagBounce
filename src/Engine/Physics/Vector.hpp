#include <math.h>

// FIXME: what happens for a Vector<int>?
template<class T> T Vector<T>::length() const {
    if (length_dirty) {
        cached_length = sqrt(*this * *this);
        length_dirty = false;
    }
    return cached_length;
}

template<class T> Vector<T> Vector<T>::normalized() const {
    return *this / this->length(); // FIXME: what to do if the length is zero?
}

template<class T> void Vector<T>::normalize() {
    *this /= this->length(); // FIXME: what to do if the length is zero?
}
