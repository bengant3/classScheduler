//
// Created by Ben on 6/10/2021.
//

template <typename T>
T& Directory<T>::getByID(int id) {
    return data[id];
}

template <typename T>
void Directory<T>::addMember(const T &sec) {
    data[sec.getID()] = sec;
}

template <typename T>
void Directory<T>::populate(std::vector<T>& list) {
    for(const T& s : list) {
        data[s.getID()] = s;
    }
}

template <typename T>
std::vector<T*>& Directory<T>::asVector(std::vector<T*>& toReturn) {
    //potentially clear toReturn and/or throw exception if it isn/t empty
    for(std::pair<const int,T>& item : data) {
        toReturn.emplace_back(&item.second);
    }
    return toReturn;
}

template <typename T>
DirectoryIterator<T> Directory<T>::begin() {
    return DirectoryIterator<T>(data.begin());
}

template <typename T>
DirectoryIterator<T> Directory<T>::end() {
    auto ret = DirectoryIterator<T>(data.end());

    return ret;
}