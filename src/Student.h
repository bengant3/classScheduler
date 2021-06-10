//
// Created by Ben on 5/18/2021.
//
#ifndef CLASSSCHEDULER_STUDENT_H
#define CLASSSCHEDULER_STUDENT_H

#include "Section.h"
#include <string>
#include <set>

class Section;

class Student {
public:
    std::string getName() const;
    size_t getID() const;
    std::set<Section*> getPreferences() const;
    std::set<Section*> getSchedule() const;
    void setPreference(Section& s);
    void setPreferences(std::set<Section*>& s);

private:
    std::string name;
    size_t studentID;
    std::set<Section*> preferences;
    std::set<Section*> enrolled;
};


#endif //CLASSSCHEDULER_STUDENT_H
