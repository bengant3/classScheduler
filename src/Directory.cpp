//
// Created by Ben on 6/10/2021.
//

template <typename T>
Directory<T>* Directory<T>::inst = nullptr;

template <typename T>
T& Directory<T>::getByID(int id) {
    return data[id];
}

template <typename T>
void Directory<T>::addMember(const T &sec) {
    data[sec.getID()] = sec;
}

template <typename T>
void Directory<T>::populate(std::vector<T*>& list) {

    for(T* s : list) {

        auto a2 = &*s;
        auto pairr = std::pair<int, T>(s->getID(), std::move(*s));
        auto a3 = &(pairr.second);

        /*** moving student/section s calls move for vector member variables. perhaps this is the where the problem is */
        data.emplace(s->getID(), std::move(*s));

        auto a4 = &data.at(s->getID());



        a2 = a4;
        ;

    }

    auto a1 = &((data.begin())->second);


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
    auto p = data.begin();
    return DirectoryIterator<T>(p);
}

template <typename T>
DirectoryIterator<T> Directory<T>::end() {
    auto p = data.end();
    auto ret = DirectoryIterator<T>(p);

    return ret;
}