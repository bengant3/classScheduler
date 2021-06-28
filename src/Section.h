//
// Created by Ben on 5/18/2021.
//

#ifndef CLASSSCHEDULER_SECTION_H
#define CLASSSCHEDULER_SECTION_H

#include "Student.h"
#include <set>
#include <string>

class Student;

enum Timeslot {null, unscheduled, MWF9, MWF10, MWF11, MWF12, MWF1, MWF2, MWF3, MW4, TH930, TH11, TH1, TH230, TH4};

class Section {
public:
    Section();
    Section(std::string n, size_t id, size_t size);

    Section(const Section& s) = default;
    Section& operator=(const Section& s) = default;

    Section(Section&& s);
    Section& operator=(Section&& s) = default;

    bool operator!=(Section& other) const;

    std::string shortName() const;
    std::string longName() const;
    size_t getID() const;
    size_t size() const;
    std::deque<Student*> getRoster() const;

    bool isScheduled() const;
    bool isFull() const;
    Timeslot getTime() const;

    void scheduleAt(Timeslot ts);

    void addStudent(int s);
    void removeStudent(int s);
    void clear();

private:
    std::string name;
    size_t classID;
    size_t classSize;
    std::deque<int> roster;
    Timeslot time;

    bool isNull() const;
};

#include "Section.cpp"

#endif //CLASSSCHEDULER_SECTION_H
