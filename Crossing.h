
#ifndef CROSSING_H
#define CROSSING_H
#include "Field.h"

/**
 * @struct Crossing
 * @brief Stores information about the field position and direction of the crossing.
 */
struct Crossing {
  /**
   * @brief Field position of the crossing.
   */
  Field field;
  /**
   * @brief Axis direction of the crossing, precise if crossing is vertical or horizontal.
   */
  bool isHorizontal;
  /**
   * @brief Default constructor that takes fields and axis direction parameters.
   * @param field Field position of the crossing.
   * @param isHorizontal Axis direction of the crossing, precise if crossing is vertical or horizontal.
   */
  Crossing(Field field, bool isHorizontal) :field(field), isHorizontal(isHorizontal) {}
};

#endif //CROSSING_H
