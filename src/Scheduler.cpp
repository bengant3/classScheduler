//
// Created by Ben on 5/18/2021.
//

#include <algorithm>
#include "Section.h"

const double THRESHOLD = 0.95;

Scheduler::Scheduler() {
    timeslots = {MWF9, MWF10, MWF11, MWF12, MWF1, MWF2, MWF3, MW4, TH930, TH11, TH1, TH230, TH4};
}

bool Scheduler::helper(std::deque<int>::iterator curStudent, std::deque<Section*> prefs, int tsIter,
                       const std::deque<int>::iterator& end, Directory<Student>* stuDirectory) {

    if(accuracy.second > 25 && getAccuracy() < THRESHOLD) return false;

    if(curStudent == end) return true; //success
    if(prefs.empty()) {
        ++curStudent;
        return helper(curStudent, stuDirectory->getByID(*curStudent).getPreferences(), 0, end, stuDirectory); //next student
    }
    if(tsIter == timeslots.size()) { //no timeslots for this course work; failure, skip to next
        prefs.pop_back();
        return helper(curStudent, prefs, 0, end, stuDirectory);
    }
    Section* nextClass = prefs.back();
    Student* stu = &stuDirectory->getByID(*curStudent);



    if(nextClass->isScheduled()) {
        if(!checkSchedForTimeslot(stu->getEnrolled(), timeslots[tsIter]) && !nextClass->isFull()) {
            ++accuracy.first;
            nextClass->addStudent(stu->getID());
        }
        prefs.pop_back();
        ++accuracy.second;
        return helper(curStudent, prefs, 0, end, stuDirectory);
    } else {
        nextClass->scheduleAt(timeslots[tsIter]);
        if(!checkSchedForTimeslot(stu->getEnrolled(), timeslots[tsIter])) {
            ++accuracy.first;
            nextClass->addStudent(stu->getID());
        }
        prefs.pop_back();
        ++accuracy.second;
        while(!helper(curStudent, prefs, tsIter, end, stuDirectory)) {
            if(stu->getEnrolled().back() == nextClass) {
                --accuracy.first;
                nextClass->removeStudent(stu->getID());
            }
            prefs.push_back(nextClass);
            --accuracy.second;
            ++tsIter;
            //nextClass->scheduleAt(timeslots[tsIter]);
        }
    }

    std::cout << "got to bottom?";
    return true;

    /*
    while(accuracy.second < 25 || getAccuracy() > THRESHOLD) {
        Student* stu = &stuDirectory->getByID(*curStudent);
        std::deque<Section*> unscheduled;
        for(Section* sect : stu->getPreferences()) {    //enrolls student in unfilled, scheduled classes
            ++accuracy.second;
            if(sect->isScheduled()) {
                if(!sect->isFull()) {
                    ++accuracy.first;
                    sect->addStudent(stu->getID());
                }
            } else unscheduled.emplace_back(sect);
        }
        //schedules class in first available timeslot for student; enrolls student
        bool scheduleNext = [&](std::deque<Section*> unsched){
            if(unsched.empty()) {
                return helper(++curStudent, stuDirectory);
            } else {
                Section* sect = unsched.back();
                for(int tsIter = 0;
                    tsIter < timeslots.size() && checkSchedForTimeslot(stu->getEnrolled(), timeslots[tsIter]); ++tsIter);
                if(tsIter < timeslots.size()) {
                    sect->scheduleAt(timeslots[tsIter]);
                    ++accuracy.first;
                    sect->addStudent(stu->getID());
                }
                unsched.pop_back();
                return scheduleNext(unsched);
            }
        };
        bool done = scheduleNext(unscheduled);
    }
     ****/
}


void Scheduler::schedule(std::deque<int>& students) {
    Directory<Student>* stuDirectory = Directory<Student>::instance();
    helper(students.begin(), stuDirectory->getByID(*students.begin()).getPreferences(), 0,
           students.end(), stuDirectory);



    /*
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
     */
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