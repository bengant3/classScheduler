//
// Created by Ben on 5/18/2021.
//

#ifndef CLASSSCHEDULER_CONTROLLER_H
#define CLASSSCHEDULER_CONTROLLER_H

#include "Section.h"
#include "Directory.h"
#include "SchedulerInterface.h"
#include <deque>

#include <iostream>

class Controller {
public:
    Controller();

    void setUp(std::deque<Student*>& students, std::deque<Section*>& sections);

    double runScheduler(bool verbose = true, int start = 0);
private:
    Directory<Section>* courseCatalog;
    Directory<Student>* studentList;
    SchedulerInterface scheduler;
};


#endif //CLASSSCHEDULER_CONTROLLER_H
