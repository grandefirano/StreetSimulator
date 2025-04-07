
#ifndef DIRECTIONDELTA_H
#define DIRECTIONDELTA_H

/**
 * @brief Delta of the position that need to be taken in some direction, representation of Direction in a (x,y) manner.
 * Implemented specifically to translate the relative directions to the global world directions.
 * Created to make universals direction calculations for e.g. intersections and avoid if statements for each possible direction.
 */
struct DirectionDelta {
    /**
     *@brief Change of position in the horizontal axis, -1 means left, 1 means right.
     */
    int x;

    /**
     *@brief Change of position in the vertical axis, -1 means up, 1 means down.
     */
    int y;
};

#endif //DIRECTIONDELTA_H
