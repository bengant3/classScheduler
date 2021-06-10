//
// Created by Ben on 5/18/2021.
//

#ifndef CLASSSCHEDULER_SCHEDULER_H
#define CLASSSCHEDULER_SCHEDULER_H

#include <map>
#include <vector>

class Student;

enum Timeslot {MWF9, MWF10, MWF11, MWF12, MWF1, MWF2, MWF3, MW4, TH930, TH11, TH1, TH230, TH4};

class Scheduler {
public:
    Scheduler();

    void schedule(std::vector<Student*>& s);

    double getAccuracy() const;

private:
    std::vector<Student*> students;
    std::pair<size_t, size_t> accuracy;
    std::map<size_t, Timeslot> classSchedule;
    std::vector<Timeslot> timeslots;
};


#endif //CLASSSCHEDULER_SCHEDULER_H
