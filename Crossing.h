
#ifndef CROSSING_H
#define CROSSING_H
#include "Field.h"

struct Crossing {
  Field field;
  bool isHorizontal;

  Crossing(Field field, bool isHorizontal) :field(field), isHorizontal(isHorizontal) {}
};

#endif //CROSSING_H
