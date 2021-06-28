//
// Created by Ben on 5/18/2021.
//

#include "Directory.h"

Student::Student(std::string n, size_t id) : name(n), studentID(id) {}

Student::Student(std::string n, size_t id, std::deque<int>& s) : name(n), studentID(id), preferences(s) {}

Student::Student(Student&& s) : name(s.name), studentID(s.studentID),
                                preferences(std::move(s.preferences)), enrolled(std::move(s.enrolled)) {}

bool Student::operator!=(Student& other) const {
    //note that unequivalence only checks name and id.
    return (studentID != other.getID() || name != other.getName());
}

std::string Student::getName() const {
    return name;
}

size_t Student::getID() const {
    return studentID;
}

std::deque<Section*> Student::getPreferences() {
    std::deque<Section*> ret;
    Directory<Section>* secDirectory = Directory<Section>::instance();
    for(int i : preferences)
        ret.push_back(&secDirectory->getByID(i));
    return ret;
}

std::deque<Section*> Student::getEnrolled() {
    std::deque<Section*> ret;
    Directory<Section>* secDirectory = Directory<Section>::instance();
    for(int i : enrolled)
        ret.push_back(&secDirectory->getByID(i));
    return ret;
}

void Student::setPreference(int s) {
    preferences.push_back(s);
}

void Student::setPreferences(std::deque<int> s) {
    //if full schedule sent as param, erases the old; otherwise, adds param to existing.
    if(s.size() + preferences.size() > 6)
        preferences.swap(s);
    else
        for(int i : s)
            preferences.push_back(i);
}

void Student::setEnrolled(int s) {
    enrolled.push_back(s);
}