
#ifndef LIGHT_H
#define LIGHT_H

#include "Field.h"

/**
 * @struct Light
 * @brief Represents street traffic light with its field position and color.
 */
struct Light {
    /**
     * @brief True if light color is green, red if it is red.
     */
    bool isGreen;
    /**
     * @brief Field position of the traffic light.
     */
    Field field;
};

#endif //LIGHT_H
