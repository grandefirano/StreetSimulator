
#ifndef DIRECTIONEXCEPTION_H
#define DIRECTIONEXCEPTION_H

class DirectionException :public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid direction";
    }
};

#endif //DIRECTIONEXCEPTION_H
