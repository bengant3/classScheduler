//
// Created by Ben on 6/13/2021.
//

#ifndef CLASSSCHEDULER_DIRECTORYITERATOR_H
#define CLASSSCHEDULER_DIRECTORYITERATOR_H

// an alternative implementation is to have a list of ids/keys and iterating over that,
// accessing elements in map key-by-key

template <typename T>
class DirectoryIterator {
public:

    /**only constuctor is private and requires T* param*/
    DirectoryIterator() = delete;

    bool operator==(const DirectoryIterator<T>& rhs) const;
    bool operator!=(const DirectoryIterator<T>& rhs) const;

    T& operator*();
    const T& operator*() const;
    T* operator->();
    const T* operator->() const;

    DirectoryIterator<T>& operator++();
    DirectoryIterator<T> operator++(int);
    DirectoryIterator<T>& operator--();
    DirectoryIterator<T> operator--(int);

//    /**
//     * Subscript operator.
//     * Must call to const operator[].  Do not reimplement!!!
//     * @param index offset from current position.
//     * @return the T & to the value at the index offset from *this.
//     */
//    T& operator[](int index);
//
//    /**
//     * Subscript operator.
//     * @param index offset from current position.
//     * @return the const T & to the value at the index offset from *this.
//     */
//    const T& operator[](int index) const;

private:
    /**
     * Creates an iterator pointing to the same element as the provided pointer.
     * @param ptr
     */
    //explicit DirectoryIterator(T* ptr);

    explicit DirectoryIterator(typename std::map<int,T>::iterator& p);

    friend class Directory<T>;

    /**
     * Pointer to the actual element.
     */
    typename std::map<int,T>::iterator ptr;
};

#include "DirectoryIterator.cpp"

#endif //CLASSSCHEDULER_DIRECTORYITERATOR_H
