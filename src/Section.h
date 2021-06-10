//
// Created by Ben on 5/18/2021.
//

#ifndef CLASSSCHEDULER_SECTION_H
#define CLASSSCHEDULER_SECTION_H

#include "Student.h"
#include <set>
#include <string>

class Student;

class Section {
public:

    std::string shortName() const;
    std::string longName() const;
    size_t getID() const;
    size_t size() const;
    std::set<Student*> getRoster();

    bool isFull() const;

    void addStudent(Student &s);
    void removeStudent(Student &s);
    void clear();

private:
    std::string name;
    size_t classID;
    size_t classSize;
    std::set<Student*> roster;
};


#endif //CLASSSCHEDULER_SECTION_H
