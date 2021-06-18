//
// Created by Ben on 6/13/2021.
//

/**
 * Tests for iterator equality.
 * @param rhs The iterator to compare against.
 * @return True if *this and rhs point to the same element.
 */
template <typename T> bool DirectoryIterator<T>::operator==(const DirectoryIterator<T>& rhs) const
{
    return ptr == rhs.ptr;
}

/**
 * Tests for iterator inequality.
 * @param rhs The iterator to compare against.
 * @return False if *this and rhs point to the same element.
 */
template <typename T> bool DirectoryIterator<T>::operator!=(const DirectoryIterator<T>& rhs) const
{
    return ptr != rhs.ptr;
}

/**
 * Dereference operator.
 * @return A T & to the value pointed to by *this.
 */
template <typename T> T& DirectoryIterator<T>::operator*()
{
    return ptr->second;
}

/**
 * Dereference operator.
 * @return A constant T & to the value pointed to by *this.
 */
template <typename T> const T& DirectoryIterator<T>::operator*() const
{
    return ptr->second;
}

/**
 * Dereference operator.
 * @return A pointer to the value pointed to by this.
 */
template <typename T> T* DirectoryIterator<T>::operator->()
{
    return &(ptr->second);
}

/**
 * Dereference operator.
 * @return A pointer to the value pointed to by this.
 */
template <typename T> const T* DirectoryIterator<T>::operator->() const
{
    return &(ptr->second);
}

/**
 * Preincrement operator.
 * @return *this after the increment.
 */
template <typename T> DirectoryIterator<T>& DirectoryIterator<T>::operator++()
{
    ++ptr;
    return *this;
}

/**
 * Postincrement operator.
 * @return The iterator before the increment.
 */
template <typename T> DirectoryIterator<T> DirectoryIterator<T>::operator++(int32_t)
{
    ptr++;
    return *this;
}

/**
 * Predecrement operator.
 * @return *this after the decrement.
 */
template <typename T> DirectoryIterator<T>& DirectoryIterator<T>::operator--()
{
    --ptr;
    return *this;
}

/**
 * Postdecrement operator.
 * @return The iterator before the decrement.
 */
template <typename T> DirectoryIterator<T> DirectoryIterator<T>::operator--(int32_t)
{
    ptr--;
    return *this;
}

///**
// * Subscript operator.
// * Must call to const operator[].  Do not reimplement!!!
// * @param index offset from current position.
// * @return the T & to the value at the index offset from *this.
// */
//template <typename T> T& DirectoryIterator<T>::operator[](int32_t index)
//{
//    return const_cast<T&>(static_cast<const DirectoryIterator<T>*>(this)->operator[](index));
//}
//
///**
// * Subscript operator.
// * @param index offset from current position.
// * @return the const T & to the value at the index offset from *this.
// */
//template <typename T> const T& DirectoryIterator<T>::operator[](int32_t index) const
//{
//    return *(ptr + index);
//}

template <typename T>
DirectoryIterator<T>::DirectoryIterator(typename std::map<int,T>::iterator p)
{


    ptr = p;
}

/**
 * Free function to make arithmetic addition commutative.
 *
 * @param offset offset from current position
 * @param iter array list iterator to offset
 * @return an offset DirectoryIterator
 */
template <typename T>
DirectoryIterator<T> operator+(int32_t offset, const DirectoryIterator<T>& iter)
{
    DirectoryIterator<T> ret(iter.ptr + offset);
    return ret;
}

///**
// * Tests for iterator equality.
// * @param rhs The iterator to compare against.
// * @return True if *this and rhs point to the same element.
// */
//template <typename T>
//bool DirectoryConstIterator<T>::operator==(const DirectoryConstIterator<T>& rhs) const
//{
//    return *ptr == rhs.*ptr;
//}
//
///**
// * Tests for iterator inequality.
// * @param rhs The iterator to compare against.
// * @return False if *this and rhs point to the same element.
// */
//template <typename T>
//bool DirectoryConstIterator<T>::operator!=(const DirectoryConstIterator<T>& rhs) const
//{
//    return *ptr != rhs.*ptr;
//}
//
///**
// * Dereference operator.
// * @return A constant reference to the value pointed to by *this.
// */
//template <typename T> const T& DirectoryConstIterator<T>::operator*() const
//{
//    return *ptr;
//}
//
///**
// * Dereference operator.
// * @return A pointer to the value pointed to by *this.
// */
//template <typename T> const T* DirectoryConstIterator<T>::operator->() const
//{
//    return ptr;
//}
//
///**
// * Preincrement operator.
// * @return *this after the increment.
// */
//template <typename T> DirectoryConstIterator<T>& DirectoryConstIterator<T>::operator++()
//{
//    return ++ptr;
//}
//
///**
// * Postincrement operator.
// * @return The iterator before the increment.
// */
//template <typename T> DirectoryConstIterator<T> DirectoryConstIterator<T>::operator++(int32_t)
//{
//    return ptr++;
//}
//
///**
// * Predecrement operator.
// * @return *this after the decrement.
// */
//template <typename T> DirectoryConstIterator<T>& DirectoryConstIterator<T>::operator--()
//{
//    return --ptr;
//}
//
///**
// * Postdecrement operator.
// * @return The iterator before the decrement.
// */
//template <typename T> DirectoryConstIterator<T> DirectoryConstIterator<T>::operator--(int32_t)
//{
//    return ptr--;
//}
//
///**
// * Returns an iterator offset elements forward
// * @param offset distance to move forward
// * @return the moved iterator.
// */
//template <typename T>
//DirectoryConstIterator<T> DirectoryConstIterator<T>::operator+(int32_t offset) const
//{
//    return ptr + offset;
//}
//
///**
// * Returns an iterator offset elements backwards
// * @param offset distance to move back
// * @return the moved iterator.
// */
//template <typename T>
//DirectoryConstIterator<T> DirectoryConstIterator<T>::operator-(int32_t offset) const
//{
//    return ptr - offset;
//}
//
///**
// * Iterator subtraction (equivalent to pointer subtraction).
// * @param rhs Iterator to subtract
// * @return distance between iterators
// */
//template <typename T>
//int DirectoryConstIterator<T>::operator-(const DirectoryConstIterator<T>& rhs) const
//{
//    return (ptr - rhs.ptr);
//}
//
///**
// * Increments this iterator by offset
// * @param offset distance to move forward
// * @return *this after the operation
// */
//template <typename T>
//DirectoryConstIterator<T>& DirectoryConstIterator<T>::operator+=(const int32_t offset)
//{
//    return ptr += offset;
//}
//
///**
// * Decrements this iterator by offset
// * @param offset distance to move backwards
// * @return *this after the operation.
// */
//template <typename T>
//DirectoryConstIterator<T>& DirectoryConstIterator<T>::operator-=(const int32_t offset)
//{
//    return ptr -= offset;
//}
//
///**
// * Subscript operator.
// * @param index offset from current position.
// * @return the const reference to the value at the index offset from *this.
// */
//template <typename T> const T& DirectoryConstIterator<T>::operator[](const int32_t index) const
//{
//    return *(ptr + index);
//}
//
//template <typename T>
//DirectoryConstIterator<T> operator+(const int32_t offset, const DirectoryConstIterator<T>& iter)
//{
//    return (iter.ptr + offset);
//}
//*/