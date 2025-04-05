#ifndef FIELDVALUE_H
#define FIELDVALUE_H

enum FieldValue {
    FV_UP, FV_DOWN, FV_LEFT, FV_RIGHT, FV_INTERSECTION, FV_LIGHT, FV_ENVIRONMENT
};

inline FieldValue mapToFieldValue(const std::string &fieldValue) {
    if (fieldValue == "v") return FV_DOWN;
    if (fieldValue == "^") return FV_UP;
    if (fieldValue == ">") return FV_RIGHT;
    if (fieldValue == "<") return FV_LEFT;
    if (fieldValue == "x") return FV_INTERSECTION;
    if (fieldValue == "s") return FV_LIGHT;
    if (fieldValue == ".") return FV_ENVIRONMENT;
    throw std::invalid_argument("Invalid field value");
}

inline FieldValue takeFieldValue(const int x, const int y, const GridType &grid) {
    if (y < grid.size() && x < grid[y].size()) {
        return mapToFieldValue(grid[y][x]);
    }
    throw std::invalid_argument("Field is out of range");
}

inline FieldValue takeFieldValue(Field field, const GridType &grid) {
    if (field.y < grid.size() && field.x < grid[field.y].size()) {
        return mapToFieldValue(grid[field.y][field.x]);
    }
    throw std::invalid_argument("Field is out of range");
}

#endif //FIELDVALUE_H
