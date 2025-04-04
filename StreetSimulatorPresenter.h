
#ifndef STREETSIMULATORPRESENTER_H
#define STREETSIMULATORPRESENTER_H
#include "StreetSimulatorView.h"


class StreetSimulatorPresenter {
private:
    StreetSimulatorView *view;
    int timeCount = 0;
    void initPresenter();

public:
    StreetSimulatorPresenter(
        StreetSimulatorView *_view
    );

    void nextFrame();
};


#endif //STREETSIMULATORPRESENTER_H
