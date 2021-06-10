//
// Created by Ben on 6/10/2021.
//

#include "Directory.h"

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
std::vector<T*>& Directory<T>::asVector() {
    std::vector<T> ret;
    for(std::pair<int,T>& item : data) {
        ret.emplace(&item.second);
    }
    return ret;
}

template <typename T>
T* Directory<T>::begin() {
    return data.begin();
}

template <typename T>
T* Directory<T>::end() {
    return data.end();
}