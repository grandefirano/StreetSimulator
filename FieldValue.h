#ifndef FIELDVALUE_H
#define FIELDVALUE_H
#include <stdexcept>

/**
 * @brief Value that is stored by the world map field.
 */
enum FieldValue {
    /**
     * Road with direction up.
     */
    FV_UP,
    /**
 * Road with direction down.
 */
    FV_DOWN,
    /**
     * Road with direction left.
     */
    FV_LEFT,
    /**
     * Road with direction right.
     */
    FV_RIGHT,
    /**
     * Road elements that is part of intersection.
     */
    FV_INTERSECTION,
    /**
     * Traffic light.
     */
    FV_LIGHT,
    /**
    * Background environment without significance.
    */
    FV_ENVIRONMENT,
    /**
     * Road priority sign.
     */
    FV_PRIORITY_SIGN,
    /**
     * Road yield sign.
     */
    FV_NO_PRIORITY_SIGN,
    /**
     * Crosswalk.
     */
    FV_CROSSING,
    /**
     * Generation place of new pedestrians.
     */
    FV_PEDESTRIAN_SPAWN
};

/**
 * @brief Mapper from string value to FieldValue.
 * @param fieldValue string text representation of the field value.
 * @return Field value based on the string text.
 */
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
