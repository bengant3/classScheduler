//
// Created by Ben on 5/18/2021.
//

#include "Controller.h"

void Controller::setUp(std::vector<Student> students, std::vector<Section> sections) {
    courseCatalog->populate(sections);
    studentList->populate(students);
}

void Controller::runScheduler() {
    double accuracy = scheduler.schedule(studentList->asVector());

    std::cout << "Completed scheduling with a " << accuracy*100 << "% success rate.\n\n";
    std::cout << "See result?\n1. Yes, by student\n2. Yes, by class\n3. No\n";
    char resp;
    std::cin >> resp;
    if(resp == 1) {
        for(Student s : *studentList) {
            std::cout << s.getName() << ": ";
            for(Section* const sec : s.getSchedule()) {
                std::cout << sec->shortName();
                if(sec != *(s.getSchedule().end()--)) std::cout << ", ";
            }
            std::cout << std::endl;
        }
    } else if (resp == 2) {
        for(Section s : *courseCatalog) {
            std::cout << s.shortName() << ": ";
                for(Student* const stu : s.getRoster()) {
                    std::cout << stu->getName();
                    if(stu != *(s.getRoster().end()--)) std::cout << ", ";
                }
            std::cout << std::endl;
        }
    }
}