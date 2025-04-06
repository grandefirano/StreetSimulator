
#ifndef RELATIVEDIRECTION_H
#define RELATIVEDIRECTION_H

/**
 * @brief Class that represents relative direction of an objects. Consist of 3 states as moving backwards is not allowed.
 * Used specifically for generalizing the intersection layout, despite the global world approaching direction.
 */
enum RelativeDirection {
    REL_STRAIGHT,REL_LEFT,REL_RIGHT
};

#endif //RELATIVEDIRECTION_H
