//
// Created by Ben on 5/18/2021.
//

#include "Scheduler.h"
#include <algorithm>
#include "Section.h"

Scheduler::Scheduler() {
    timeslots = {MWF9, MWF10, MWF11, MWF12, MWF1, MWF2, MWF3, MW4, TH930, TH11, TH1, TH230, TH4};
}

void Scheduler::schedule(std::list<Student>& s) {
    students = &s;

//    auto enroll = [*this](){
//        for(Section sect : )
//    };
//    std::for_each(students->begin(), students->begin(), enroll);

    for(Student stu : s) {
        for(Section sect : stu.getPreferences()) {
            ++accuracy.second;
            if(classSchedule.contains(sect.getID())) {
                if(!classSchedule[sect.getID()].isFull()) {

                }
            }
        }
        for(Section sect : stu.getPreferences()) {
            if(!classSchedule.contains(sect.getID())) {

            }
        }
    }





}

double Scheduler::getAccuracy() const {
    return (double)accuracy.first/(double)accuracy.second;
}