//
// Created by Ben on 5/18/2021.
//

#include "Catalog.h"

#include <deque>

Section& Catalog::getByID(int id) {
    return coursesList[id];
}

void Catalog::addMember(const Section &sec) {
    coursesList[sec.getID()] = sec;
}

void Catalog::populate(std::deque<Section>& list) {
    for(const Section& s : list) {
        coursesList[s.getID()] = s;
    }
}