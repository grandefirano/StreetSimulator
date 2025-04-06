#ifndef FIELDVALUE_H
#define FIELDVALUE_H
#include <stdexcept>

enum FieldValue {
    FV_UP, FV_DOWN, FV_LEFT, FV_RIGHT, FV_INTERSECTION, FV_LIGHT, FV_ENVIRONMENT,FV_PRIORITY_SIGN, FV_NO_PRIORITY_SIGN, FV_CROSSING,FV_PEDESTRIAN_SPAWN
};

inline FieldValue mapToFieldValue(const std::string &fieldValue) {
    if (fieldValue == "v") return FV_DOWN;
    if (fieldValue == "^") return FV_UP;
    if (fieldValue == ">") return FV_RIGHT;
    if (fieldValue == "<") return FV_LEFT;
    if (fieldValue == "x") return FV_INTERSECTION;
    if (fieldValue == "s") return FV_LIGHT;
    if (fieldValue == "p") return FV_PRIORITY_SIGN;
    if (fieldValue == "u") return FV_NO_PRIORITY_SIGN;
    if (fieldValue == ".") return FV_ENVIRONMENT;
    if (fieldValue == "c") return FV_CROSSING;
    if (fieldValue == "g") return FV_PEDESTRIAN_SPAWN;
    throw std::invalid_argument("Invalid field value");
}


#endif //FIELDVALUE_H
