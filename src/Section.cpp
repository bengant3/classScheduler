//
// Created by Ben on 5/18/2021.
//

#include <stdexcept>
#include "Directory.h"

Section::Section() : time(null), maxSize(10) {}

Section::Section(std::string n, size_t id, size_t size) : name(n), classID(id), classSize(0), maxSize(size),
                                                            time(unscheduled) {}

Section::Section(Section&& s) : name(s.name), classID(s.classID), classSize(s.classSize), maxSize(s.maxSize),
                                roster(std::move(s.roster)), time(s.time) {}

bool Section::operator!=(Section& other) const {
    //if both are null, return false; if one is null, return true
    if(isNull() || other.isNull()) return isNull() != other.isNull();
    //note that operator!= doesn't check roster for equivalence
    return (name != other.name || classID != other.classID || classSize != other.classSize || time != other.time);
}

std::string Section::shortName() const {
    return name.substr(0, name.find(':'));
}
std::string Section::longName() const {
    return name;
}

size_t Section::getID() const {
    return classID;
}

size_t Section::size() const {
    return classSize;
}

size_t Section::maxCapacity() const {
    return maxSize;
}

std::deque<Student*> Section::getRoster() const {
    std::deque<Student*> ret;
    Directory<Student>* stuDirectory = Directory<Student>::instance();
    for(int i : roster)
        ret.push_back(&stuDirectory->getByID(i));
    return ret;
}

bool Section::isScheduled() const {
    return time!=unscheduled;
}

bool Section::isFull() const {
    return (classSize == maxSize);
}

Timeslot Section::getTime() const {
    return time;
}

void Section::scheduleAt(Timeslot ts) {
    time = ts;
}

void Section::addStudent(int s) {
    Directory<Student>* stuDirectory = Directory<Student>::instance();
    if(!isFull()) {
        roster.push_back(s);
        ++classSize;
        stuDirectory->getByID(s).setEnrolled(classID);
    } else {
        throw std::out_of_range("Class is full");
    }
}

void Section::removeStudent(int s) {
    Directory<Student>* stuDirectory = Directory<Student>::instance();
    auto it = roster.begin();
    while(it != roster.end()) {
        if(*it == s) {
            roster.erase(it);
            --classSize;
            stuDirectory->getByID(s).unenroll(classID);
            break;
        }
        ++it;
    }
}

void Section::clear() {
    roster.clear();
}

bool Section::isNull() const {
    return time==null;
}