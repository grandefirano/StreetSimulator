
#ifndef DIRECTIONEXCEPTION_H
#define DIRECTIONEXCEPTION_H

#include <bits/streambuf_iterator.h>

class DirectionException :public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid direction";
    }
};

#endif //DIRECTIONEXCEPTION_H
