#ifndef SIGN_H
#define SIGN_H

#include "Field.h"

enum SignType {
    PRIORITY, NO_PRIORITY
};

struct Sign {
    Field field;
    SignType type;

    Sign(const Field &_field, const SignType &_type) : field(_field), type(_type) {
    }
};

#endif //SIGN_H
