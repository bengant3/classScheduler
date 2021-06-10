//
// Created by Ben on 6/10/2021.
//

#ifndef CLASSSCHEDULER_DIRECTORY_H
#define CLASSSCHEDULER_DIRECTORY_H

#include <vector>
#include <map>

template <typename T>
class Directory {
public:
    T& getByID(int id);

    void addMember(const T & sec);

    void populate(std::vector<T>& list);

    std::vector<T*>& asVector();

    T* begin();

    T* end();

private:
    std::map<int, T> data;
};


#endif //CLASSSCHEDULER_DIRECTORY_H
