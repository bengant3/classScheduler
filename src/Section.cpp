//
// Created by Ben on 5/18/2021.
//

#include "Section.h"
#include <stdexcept>

std::set<size_t> Section::getRoster() const {
    return roster;
}

size_t Section::size() const {
    return classSize;
}

size_t Section::getID() const {
    return classID;
}

bool Section::isFull() const {
    return (roster.size() == classSize);
}

void Section::addStudent(Student const & s) {
    if(!isFull())
        roster.insert(s.getID());
    else
        throw std::out_of_range("Class is full");
}

void Section::removeStudent(Student const & s) {
    roster.erase(s.getID());
}

void Section::clear() {
    roster.clear();
}
