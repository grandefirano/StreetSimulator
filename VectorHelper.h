
#ifndef VECTORHELPER_H
#define VECTORHELPER_H

#include <vector>
#include <algorithm>
template <typename T>
bool contains(const std::vector<T> &list, const T &element) {
    return std::find(list.begin(), list.end(), element) != list.end();
}


#endif //VECTORHELPER_H
