
#ifndef DIRECTIONEXCEPTION_H
#define DIRECTIONEXCEPTION_H

/**
 * @brief Exception to be thrown when the field cannot be parsed to Direction.
 */
class DirectionException :public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid direction";
    }
};

#endif //DIRECTIONEXCEPTION_H
