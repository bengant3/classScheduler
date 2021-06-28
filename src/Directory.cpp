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
//    std::deque<int> helper; //decided not to import deque class
//    int i = 0;
    for(std::pair<const int,T>& item : data)
        ret.push_back(item.first);
//    for(auto it = data.begin()+start; it != data.begin(); ++it)
//        ret.push_back(it->first);
//    for(auto it = data.begin(); it != data.begin()+start; ++it)
//        ret.push_back(it->first);
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