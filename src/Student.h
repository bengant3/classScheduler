//
// Created by Ben on 5/18/2021.
//

#ifndef CLASSSCHEDULER_STUDENT_H
#define CLASSSCHEDULER_STUDENT_H

#include "Section.h"
#include <string>
#include <deque>

class Section;

class Student {
public:
    Student() = default;
    Student(std::string n, size_t id);
    Student(std::string n, size_t id, std::deque<int>& s);

    Student(const Student& s) = default;
    Student& operator=(const Student& s) = default;

    Student(Student&& s);
    Student& operator=(Student&& s) = default;

    bool operator!=(Student& other) const;
    std::string getName() const;
    size_t getID() const;
    std::deque<Section*> getPreferences();
    std::deque<Section*> getEnrolled();
    void setPreference(int s);
    void setPreferences(std::deque<int> s);
    void setEnrolled(int s);
    void unenroll(int s);

private:
    std::string name;
    size_t studentID;
    std::deque<int> preferences;
    std::deque<int> enrolled;

};

#include "Student.cpp"

#endif //CLASSSCHEDULER_STUDENT_H
