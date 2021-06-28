//
// Created by Ben on 6/10/2021.
//

#ifndef CLASSSCHEDULER_DIRECTORY_H
#define CLASSSCHEDULER_DIRECTORY_H

#include <deque>
#include <map>

template <typename T> class DirectoryIterator;

template <typename T>
class Directory {
public:
    static Directory<T>* instance() {
        if(inst == nullptr) inst = new Directory<T>();
        return inst;
    }

    int size();

    T& getByID(int id);

    void addMember(const T & sec);

    void populate(std::deque<T*>& list);

    std::deque<int> asIntDeque(int start = 0);

    DirectoryIterator<T> begin();

    DirectoryIterator<T> end();

private:
    Directory() = default;

    static Directory<T> *inst;

    std::map<const int, T> data;
};

#include "Directory.cpp"
#include "DirectoryIterator.h"

#endif //CLASSSCHEDULER_DIRECTORY_H
