//
// Created by Ben on 5/18/2021.
//

#include "Section.h"
#include <stdexcept>


Section::Section(std::string n, size_t id, size_t size) : name(n), classID(id), classSize(size) {}

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

bool Section::isFull() const {
    return (roster.size() == classSize);
}

void Section::addStudent(Student& s) {
    if(!isFull())
        roster.insert(&s);
    else
        throw std::out_of_range("Class is full");
}

void Section::removeStudent(Student& s) {
    roster.erase(&s);
}

void Section::clear() {
    roster.clear();
}
