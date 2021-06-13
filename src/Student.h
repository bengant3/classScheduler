//
// Created by Ben on 5/18/2021.
//

#ifndef CLASSSCHEDULER_STUDENT_H
#define CLASSSCHEDULER_STUDENT_H

#include "Section.h"
#include <string>
#include <vector>

class Section;

class Student {
public:
    Student() = default;
    Student(std::string n, size_t id);
    Student(std::string n, size_t id, std::vector<Section*>& s);
    std::string getName() const;
    size_t getID() const;
    std::vector<Section*> getPreferences() const;
    std::vector<Section*> getSchedule() const;
    void setPreference(Section& s);
    void setPreferences(std::vector<Section*>& s);

private:
    std::string name;
    size_t studentID;
    std::vector<Section*> preferences;
    std::vector<Section*> enrolled;
};


#endif //CLASSSCHEDULER_STUDENT_H
