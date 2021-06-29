//
// Created by Ben on 5/18/2021.
//

#include "Controller.h"

static std::string timeslotStrings[] = {"null", "unscheduled", "MWF9", "MWF10", "MWF11", "MWF12", "MWF1", "MWF2", "MWF3",
                                     "MW4", "TH930", "TH11", "TH1", "TH230", "TH4"};

Controller::Controller() {
    courseCatalog = Directory<Section>::instance();
    studentList = Directory<Student>::instance();
}

void Controller::setUp(std::deque<Student*>& students, std::deque<Section*>& sections) {
    courseCatalog->populate(sections);
    studentList->populate(students);
}

void Controller::resetDirectories() {
    for(Section& sec : *courseCatalog) {
        while(!sec.getRoster().empty()) {
            Student* stu = sec.getRoster().back();
            sec.removeStudent(stu->getID());
        }
        sec.scheduleAt(unscheduled);
    }
}

double Controller::runScheduler(bool verbose, int start) {
    std::deque<int> newDeque = studentList->asIntDeque(start);
    double accuracy = scheduler.schedule(newDeque);

    if(verbose) {
        std::cout << "Completed scheduling with a " << accuracy * 100 << "% success rate.\n\n";
        std::cout << "See result?\n"
                    << "1. Yes, by student\n"
                    << "2. Yes, by student, first 10\n"
                    << "3. Yes, by class\n"
                    << "4. Yes, by class, first 10\n"
                    << "5. No\n";
        char resp;
        std::cin >> resp;

        std::string result = "";

        if (resp == '1' || resp == '2') {
            int iter = 0;
            for (auto s = studentList->begin(); s != studentList->end() && (resp == '2' && iter < 10); ++s, ++iter) {
                result += s->getName() + (s->getName().size() < 14 ? ": \t\t" : ": \t");
                for (Section *const sec : s->getEnrolled()) {
                    result += sec->shortName();
                    if (sec != *(--(s->getEnrolled().end()))) result += ", ";
                }
                result += "\n";
            }
        } else if (resp == '3' || resp == '4') {
            int iter = 0;
            for (auto s = courseCatalog->begin(); s != courseCatalog->end() && (resp == '4' && iter < 10); ++s, ++iter) {
                result += s->shortName() + " (" + timeslotStrings[s->getTime()] + ") : \t";
                for (Student *const stu : s->getRoster()) {
                    result += stu->getName();
                    if (stu != *(--(s->getRoster().end()))) result += ", ";
                }
                result += "\n";
            }
        }
        std::cout << result << std::endl << "done. ";
    }
    return accuracy;
}