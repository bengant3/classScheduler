//
// Created by Ben on 5/18/2021.
//

#include <stdexcept>

Section::Section() : time(null) {}

Section::Section(std::string n, size_t id, size_t size) : name(n), classID(id), classSize(size), time(unscheduled) {}

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

std::set<Student*> Section::getRoster() const {
    return roster;
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

void Section::addStudent(Student& s) {
    if(!isFull()) {
        roster.insert(&s);
        s.setSchedule(*this);
    } else {
        throw std::out_of_range("Class is full");
    }
}

void Section::removeStudent(Student& s) {
    roster.erase(&s);
}

void Section::clear() {
    roster.clear();
}

bool Section::isNull() const {
    return time==null;
}