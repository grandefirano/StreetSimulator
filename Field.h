//
// Created by User on 2025-04-05.
//

#ifndef FIELD_H
#define FIELD_H

struct Field {
    int x, y;

    bool operator==(const Field &other) const {
        return (x==other.x)&&(y==other.y);
    };
};

#endif //FIELD_H
