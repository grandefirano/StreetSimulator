
#ifndef VECTORHELPER_H
#define VECTORHELPER_H

#include <vector>
#include <algorithm>

/**
 * @brief Checks if the object is placed inside the given list.
 * @tparam T Type of element object.
 * @param list List to search the element in.
 * @param element Element that is searched inside the list.
 * @return True if object is found inside the list, false if it is not.
 */
template <typename T>
bool contains(const std::vector<T> &list, const T &element) {
    return std::find(list.begin(), list.end(), element) != list.end();
}

/**
 * @brief Returns list without specified element.
 * @tparam T Type of element object.
 * @param elementToRemove Object to be removed from the list.
 * @param fullList List of all the elements.
 * @return Copy of the list of all elements with specified element removed.
 */
template <typename T>
std::vector<T> withoutElement(T &elementToRemove, std::vector<T> &fullList) {
    auto others = fullList;
    std::remove(others.begin(), others.end(), elementToRemove);
    others.pop_back();
    return others;
}


#endif //VECTORHELPER_H
