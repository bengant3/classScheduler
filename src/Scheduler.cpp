//
// Created by Ben on 5/18/2021.
//

#include <algorithm>
#include "Section.h"

Scheduler::Scheduler() {
    timeslots = {MWF9, MWF10, MWF11, MWF12, MWF1, MWF2, MWF3, MW4, TH930, TH11, TH1, TH230, TH4};
}

void Scheduler::schedule(std::deque<int>& students) {
    Directory<Student>* stuDirectory = Directory<Student>::instance();
    for(int si : students) {
        Student* stu = &stuDirectory->getByID(si);
        std::deque<Section*> unscheduled;
        for(Section* sect : stu->getPreferences()) {
            ++accuracy.second;
            if(sect->isScheduled()) {
                if(!sect->isFull()) {
                    ++accuracy.first;
                    sect->addStudent(stu->getID());
                }
            } else {
                unscheduled.emplace_back(sect);
            }
        }
        while (!unscheduled.empty()) {
            Section* sect = unscheduled.back();
            int tsIter = 0;
            while (tsIter < timeslots.size() && checkSchedForTimeslot(stu->getEnrolled(), timeslots[tsIter]))
                ++tsIter;
            // if all time slots are full, class is not scheduled
            // realistically, this should never happen though, b/c a student would have to take like 15 classes.
            if(tsIter < timeslots.size()) {
                sect->scheduleAt(timeslots[tsIter]);
                ++accuracy.first;
                sect->addStudent(stu->getID());
            }
            unscheduled.pop_back();
        }
    }


    //std::for_each(students.begin(), students.begin(), enroll);


}

double Scheduler::getAccuracy() const {
    return accuracy.first == 0 ? 0 : (double)accuracy.first/(double)accuracy.second;
}

bool Scheduler::checkSchedForTimeslot(std::deque<Section*> sched, Timeslot ts) {
    for(Section* s : sched) {
        if (s->isScheduled() && s->getTime() == ts) return true;
    }
    return false;
}