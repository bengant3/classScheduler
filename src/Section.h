//
// Created by Ben on 5/18/2021.
//

#ifndef CLASSSCHEDULER_SECTION_H
#define CLASSSCHEDULER_SECTION_H

#include "Student.h"
#include <set>

class Section {
public:
    std::set<size_t> getRoster() const;
    size_t size() const;
    size_t getID() const;
    bool isFull() const;
    void addStudent(Student const &s);
    void removeStudent(Student const &s);
    void clear();

private:
    size_t classID;
    size_t classSize;
    std::set<size_t> roster;
};


#endif //CLASSSCHEDULER_SECTION_H
