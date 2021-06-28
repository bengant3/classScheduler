//
// Created by Ben on 5/18/2021.
//

#include <stdexcept>
#include "Directory.h"

Section::Section() : time(null) {}

Section::Section(std::string n, size_t id, size_t size) : name(n), classID(id), classSize(size), time(unscheduled) {}

Section::Section(Section&& s) : name(s.name), classID(s.classID), classSize(s.classSize),
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
    return (roster.size() == classSize);
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
        stuDirectory->getByID(s).setEnrolled(classID);
    } else {
        throw std::out_of_range("Class is full");
    }
}

void Section::removeStudent(int s) {
    auto it = roster.begin();
    while(it != roster.end()) {
        if(*it == s) {
            roster.erase(it);
            break;
        }
    }
}

void Section::clear() {
    roster.clear();
}

bool Section::isNull() const {
    return time==null;
}