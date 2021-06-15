//
// Created by Ben on 5/18/2021.
//

Student::Student(std::string n, size_t id) : name(n), studentID(id) {}

Student::Student(std::string n, size_t id, std::vector<Section*>& s) : name(n), studentID(id), preferences(s) {}

bool Student::operator!=(Student& other) const {
    //note that unequivalence only checks name and id.
    return (studentID != other.getID() || name != other.getName());
}

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
    //if full schedule sent as param, erases the old; otherwise, adds param to existing.
    if(s.size() + preferences.size() > 6)
        preferences.swap(s);
    else
        for(Section *i : s)
            preferences.emplace_back(i);
}

void Student::setSchedule(Section& s) {
    enrolled.emplace_back(&s);
}