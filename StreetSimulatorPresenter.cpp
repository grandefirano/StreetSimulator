
#include "StreetSimulatorPresenter.h"

#include <vector>
#include <algorithm>


StreetSimulatorPresenter::StreetSimulatorPresenter(
    StreetSimulatorView *_view
) {
    view = _view;
    initPresenter();
}

void StreetSimulatorPresenter::initPresenter() {
}

void StreetSimulatorPresenter::nextFrame() {

    view->clear();
    //TODO jk refactor to pass size
    view->drawBackground(19,19);
    view->render();
    timeCount++;
}
