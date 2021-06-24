//
// Created by Ben on 6/10/2021.
//

#ifndef CLASSSCHEDULER_DIRECTORY_H
#define CLASSSCHEDULER_DIRECTORY_H

#include <vector>
#include <map>

template <typename T> class DirectoryIterator;

template <typename T>
class Directory {
public:
    Directory() = default;

    T& getByID(int id);

    void addMember(const T & sec);

    void populate(std::vector<T*>& list);

    std::vector<T*>& asVector(std::vector<T*>& toReturn);

    DirectoryIterator<T> begin();

    DirectoryIterator<T> end();

private:
    std::map<const int, T> data;
};

#include "Directory.cpp"
#include "DirectoryIterator.h"

#endif //CLASSSCHEDULER_DIRECTORY_H
