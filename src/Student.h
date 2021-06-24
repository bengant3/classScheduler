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

    Student(const Student& s) = default;
    Student& operator=(const Student& s) = default;

    Student(Student&& s);
    Student& operator=(Student&& s) = default;

    bool operator!=(Student& other) const;
    std::string getName() const;
    size_t getID() const;
    std::vector<Section*>& getPreferences();
    std::vector<Section*>& getSchedule();
    void setPreference(Section& s);
    void setPreferences(std::vector<Section*>& s);
    void setSchedule(Section& s);

private:
    std::string name;
    size_t studentID;
    std::vector<Section*> preferences;
    std::vector<Section*> enrolled;
};

#include "Student.cpp"

#endif //CLASSSCHEDULER_STUDENT_H
