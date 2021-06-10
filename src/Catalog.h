//
// Created by Ben on 5/18/2021.
//

#ifndef CLASSSCHEDULER_CATALOG_H
#define CLASSSCHEDULER_CATALOG_H

#include <map>
#include <vector>
#include "Section.h"

class Catalog {
public:
    Section& getByID(int id);

    void addMember(const Section & sec);

    void populate(std::vector<Section>& list);

private:
    std::map<int, Section> coursesList;
};


#endif //CLASSSCHEDULER_CATALOG_H
