//
// Created by Ben on 5/18/2021.
//

#ifndef CLASSSCHEDULER_SCHEDULERINTERFACE_H
#define CLASSSCHEDULER_SCHEDULERINTERFACE_H

#include "Scheduler.h"

class SchedulerInterface {
public:
    SchedulerInterface() = default;

    double schedule(std::vector<Student*>& s);
private:
    Scheduler scheduletron;
};


#endif //CLASSSCHEDULER_SCHEDULERINTERFACE_H