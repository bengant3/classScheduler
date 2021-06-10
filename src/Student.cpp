//
// Created by Ben on 5/18/2021.
//

#include "Student.h"

std::string Student::getName() const {
    return name;
}

size_t Student::getID() const {
    return studentID;
}

std::set<Section> Student::getPreferences() const {
    return preferences;
}

std::set<Section> Student::getSchedule() const {
    return enrolled;
}

void Student::setPreference(Section s) {
    preferences.insert(s);
}

void Student::setPreferences(std::set<Section> s) {
    if(s.size() + preferences.size() > 6)
        preferences.swap(s);
    else
        for(Section i : s)
            preferences.insert(i);
}
