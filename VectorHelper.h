
#ifndef VECTORHELPER_H
#define VECTORHELPER_H

#include <vector>
#include <algorithm>
template <typename T>
bool contains(const std::vector<T> &list, const T &element) {
    return std::find(list.begin(), list.end(), element) != list.end();
}

template <typename T>
std::vector<T> withoutElement(T &elementToRemove, std::vector<T> &fullList) {
    auto others = fullList;
    std::remove(others.begin(), others.end(), elementToRemove);
    others.pop_back();
    return others;
}


#endif //VECTORHELPER_H
