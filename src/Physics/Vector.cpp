#include "Vector.h"

template<typename T> inline T Vector<T>::length_squared() const {
    return *this * *this;
}
