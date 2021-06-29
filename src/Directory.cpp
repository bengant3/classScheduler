//
// Created by Ben on 6/10/2021.
//

template <typename T>
Directory<T>* Directory<T>::inst = nullptr;

template <typename T>
int Directory<T>::size() {
    return data.size();
}

template <typename T>
T& Directory<T>::getByID(int id) {
    return data.at(id);
}

template <typename T>
void Directory<T>::addMember(const T &sec) {
    data[sec.getID()] = sec;
}

template <typename T>
void Directory<T>::populate(std::deque<T*>& list) {
    for(T* s : list)
        data.insert(std::pair<int, T>(s->getID(), *s));
}

template <typename T>
std::deque<int> Directory<T>::asIntDeque(int start) {
    std::deque<int> ret;
    std::deque<int> helper;
    for(auto item : data) {
        (item.first < start ? helper : ret).push_back(item.first);
    }
    while(!helper.empty()) {
        ret.push_back(helper.front());
        helper.pop_front();
    }
    return ret;
}

template <typename T>
DirectoryIterator<T> Directory<T>::begin() {
    auto p = data.begin();
    return DirectoryIterator<T>(p);
}

template <typename T>
DirectoryIterator<T> Directory<T>::end() {
    auto p = data.end();
    return DirectoryIterator<T>(p);
}