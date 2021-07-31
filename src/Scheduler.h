//
// Created by Ben on 5/18/2021.
//

#ifndef CLASSSCHEDULER_SCHEDULER_H
#define CLASSSCHEDULER_SCHEDULER_H

#include <map>
#include <deque>

class Student;


class Scheduler {
public:
    Scheduler();

    void schedule(std::deque<int>& s);

    double getAccuracy() const;

private:
    std::pair<size_t, size_t> accuracy;
    std::map<size_t, Timeslot> classSchedule;
    std::deque<Timeslot> timeslots;

    bool checkSchedForTimeslot(std::deque<Section*> sched, Timeslot ts);

    bool helper(std::deque<int>::iterator curStudent, std::deque<Section*> prefs, int tsIter,
                const std::deque<int>::iterator& end, Directory<Student>* stuDirectory);

};

#include "Scheduler.cpp"

#endif //CLASSSCHEDULER_SCHEDULER_H
