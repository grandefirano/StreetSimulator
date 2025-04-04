
#ifndef STREETSIMULATORVIEW_H
#define STREETSIMULATORVIEW_H
#include <vector>

class StreetSimulatorView {
public:
    virtual void clear()=0;

    virtual void drawBackground(int xFieldSize, int yFieldSize)=0;

    virtual void render()=0;
};

#endif //STREETSIMULATORVIEW_H
