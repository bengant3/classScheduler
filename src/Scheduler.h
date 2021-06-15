//
// Created by Ben on 5/18/2021.
//

#ifndef CLASSSCHEDULER_SCHEDULER_H
#define CLASSSCHEDULER_SCHEDULER_H

#include <map>
#include <vector>

class Student;


class Scheduler {
public:
    Scheduler();

    void schedule(std::vector<Student*>& s);

    double getAccuracy() const;

private:
    //std::vector<Student*> students;
    std::pair<size_t, size_t> accuracy;
    std::map<size_t, Timeslot> classSchedule;
    std::vector<Timeslot> timeslots;

    bool checkSchedForTimeslot(std::vector<Section*> sched, Timeslot ts);
};

#include "Scheduler.cpp"

#endif //CLASSSCHEDULER_SCHEDULER_H
