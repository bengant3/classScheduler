//
// Created by Ben on 5/18/2021.
//

#ifndef CLASSSCHEDULER_SCHEDULERINTERFACE_H
#define CLASSSCHEDULER_SCHEDULERINTERFACE_H

#include "Scheduler.h"

class SchedulerInterface {
public:
    double schedule(std::list<Student>& s);
private:
    Scheduler scheduletron;
};


#endif //CLASSSCHEDULER_SCHEDULERINTERFACE_H
