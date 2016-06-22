#include "src/controller/Controller.h"

int main( int argc, char* args[] )
{
    pjcUtil::BlockingQueue<pjcCommon::Event> viewControllerBQ;
    pjcUtil::BlockingQueue<pjcCommon::Event> controllerViewBQ;
    pjcModel::Model model;
    auto viewThread = pjcView::View::run(viewControllerBQ, controllerViewBQ);
    pjcController::Controller controller(controllerViewBQ, viewControllerBQ, model);
    controller.start();

    viewThread.join();
    return 0;
}
