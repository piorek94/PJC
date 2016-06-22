//
// Created by przemek on 22.06.16.
//

#include "Controller.h"
#include <iostream>

namespace pjcController {

    Controller::Controller(pjcUtil::BlockingQueue<pjcCommon::Event> &outputBQ,
                           pjcUtil::BlockingQueue<pjcCommon::Event> &inputBQ,
                           pjcModel::Model &model)
            : outputBQ{outputBQ}, inputBQ{inputBQ}, model{model} {

    }

    void Controller::start() {
        outputBQ.push(pjcCommon::Event());
        while (true) {
            auto event = inputBQ.pop();
            std::cout << "Controller it works! " << event.getName() <<  std::endl;
            break;
        }
    }


}
