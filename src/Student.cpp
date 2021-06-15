//
// Created by Ben on 5/18/2021.
//

Student::Student(std::string n, size_t id) : name(n), studentID(id) {}

Student::Student(std::string n, size_t id, std::vector<Section*>& s) : name(n), studentID(id), preferences(s) {}

std::string Student::getName() const {
    return name;
}

size_t Student::getID() const {
    return studentID;
}

std::vector<Section*> Student::getPreferences() const {
    return preferences;
}

std::vector<Section*> Student::getSchedule() const {
    return enrolled;
}

void Student::setPreference(Section& s) {
    preferences.emplace_back(&s);
}

void Student::setPreferences(std::vector<Section*>& s) {
    if(s.size() + preferences.size() > 6)
        preferences.swap(s);
    else
        for(Section *i : s)
            preferences.emplace_back(i);
}
