#ifndef SIGN_H
#define SIGN_H

#include "Field.h"

/**
 * @brief Type of the sign, which specify its meaning.
 */
enum SignType {
    PRIORITY, NO_PRIORITY
};

/**
 * @struct Sign
 * @brief Representation of the sign that stores its type and field position of its place.
 */
struct Sign {
    /**
     * @brief Field position of the sign.
     */
    Field field;
    /**
     * @brief Type of the sign, which specify its meaning.
     */
    SignType type;

    /**
     * Constructor of the Sign.
     * @param _field Field position of the sign.
     * @param _type Type of the sign, which specify its meaning.
     */
    Sign(const Field &_field, const SignType &_type) : field(_field), type(_type) {
    }
};

#endif //SIGN_H
