//
// Created by Ben on 5/18/2021.
//

#include "Controller.h"

Controller::Controller() {
    courseCatalog = new Directory<Section>;
    studentList = new Directory<Student>;
}

void Controller::setUp(std::vector<Student> students, std::vector<Section> sections) {
    courseCatalog->populate(sections);
    studentList->populate(students);
}

void Controller::runScheduler() {
    std::vector<Student*> newVector;
    double accuracy = scheduler.schedule(studentList->asVector(newVector));

    std::cout << "Completed scheduling with a " << accuracy*100 << "% success rate.\n\n";
    std::cout << "See result?\n1. Yes, by student\n2. Yes, by class\n3. No\n";
    char resp;
    std::cin >> resp;

    std::string result = "";

    if(resp == '1') {
        for(auto s = studentList->begin(); s != studentList->end(); ++s) {
            result += s->getName() + (s->getName().size() < 6 ? ": \t\t" : ": \t");
            for(Section* const sec : s->getSchedule()) {
                result += sec->shortName();
                if(sec != *(--(s->getSchedule().end()))) result += ", ";
            }


            result += "\n";
        }
    } else if (resp == '2') {
        for(Section &s : *courseCatalog) {
            result += s.shortName() + ": ";
                for(Student* const stu : s.getRoster()) {
                    result += stu->getName();
                    if(stu != *(s.getRoster().end()--)) result += ", ";
                }
            result += "\n";
        }
    }
    std::cout << result << std::endl << "done. ";
}