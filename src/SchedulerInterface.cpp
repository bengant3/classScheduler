//
// Created by Ben on 5/18/2021.
//

#include "SchedulerInterface.h"

double SchedulerInterface::schedule(std::vector<Student*>& s) {
    scheduletron.schedule(s);
    return scheduletron.getAccuracy();
}