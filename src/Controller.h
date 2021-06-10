//
// Created by Ben on 5/18/2021.
//

#ifndef CLASSSCHEDULER_CONTROLLER_H
#define CLASSSCHEDULER_CONTROLLER_H

#include "Section.h"
#include "Student.h"
#include "Directory.h"
#include "SchedulerInterface.h"
#include <vector>

#include <iostream>

class Controller {
public:
    void setUp(std::vector<Student> students, std::vector<Section> sections);

    void runScheduler();

private:
    Directory<Section>* courseCatalog;
    Directory<Student>* studentList;
    SchedulerInterface scheduler;
};


#endif //CLASSSCHEDULER_CONTROLLER_H
