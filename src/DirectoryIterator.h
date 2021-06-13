//
// Created by Ben on 6/13/2021.
//

#ifndef CLASSSCHEDULER_DIRECTORYITERATOR_H
#define CLASSSCHEDULER_DIRECTORYITERATOR_H

template <typename T>
class DirectoryIterator {
public:
    /**
     * Tests for iterator equality.
     * @param rhs The iterator to compare against.
     * @return True if *this and rhs point to the same element.
     */
    bool operator==(const DirectoryIterator<T>& rhs) const;

    /**
     * Tests for iterator inequality.
     * @param rhs The iterator to compare against.
     * @return False if *this and rhs point to the same element.
     */
    bool operator!=(const DirectoryIterator<T>& rhs) const;

    /**
     * Dereference operator.
     * @return A T & to the value pointed to by *this.
     */
    T& operator*();

    /**
     * Dereference operator.
     * @return A constant T & to the value pointed to by *this.
     */
    const T& operator*() const;

    /**
     * Dereference operator.
     * @return A pointer to the value pointed to by this.
     */
    T* operator->();

    /**
     * Dereference operator.
     * @return A pointer to the value pointed to by this.
     */
    const T* operator->() const;

    /**
     * Preincrement operator.
     * @return *this after the increment.
     */
    DirectoryIterator<T>& operator++();

    /**
     * Postincrement operator.
     * @return The iterator before the increment.
     */
    DirectoryIterator<T> operator++(int);

    /**
     * Predecrement operator.
     * @return *this after the decrement.
     */
    DirectoryIterator<T>& operator--();

    /**
     * Postdecrement operator.
     * @return The iterator before the decrement.
     */
    DirectoryIterator<T> operator--(int);

    /**
     * Subscript operator.
     * Must call to const operator[].  Do not reimplement!!!
     * @param index offset from current position.
     * @return the T & to the value at the index offset from *this.
     */
    T& operator[](int index);

    /**
     * Subscript operator.
     * @param index offset from current position.
     * @return the const T & to the value at the index offset from *this.
     */
    const T& operator[](int index) const;

private:
    /**
     * Creates an iterator pointing to the same element as the provided pointer.
     * @param ptr
     */
    explicit DirectoryIterator(T* ptr);

    friend class Directory<T>;

    /**
     * Pointer to the actual element.
     */
    T* mPtr;
};

#include "DirectoryIterator.cpp"

#endif //CLASSSCHEDULER_DIRECTORYITERATOR_H
