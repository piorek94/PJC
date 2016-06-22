//
// Created by przemek on 22.06.16.
//

#include <iostream>
#include <thread>
#include "View.h"

namespace pjcView {

    View::View(pjcUtil::BlockingQueue<pjcCommon::Event> &outputBQ,
               pjcUtil::BlockingQueue<pjcCommon::Event> &inputBQ) : outputBQ{outputBQ}, inputBQ{inputBQ} {

    }

    void View::start() {
        while (true) {
            auto event = inputBQ.pop();
            std::cout << "View::Start " << event.getName() << std::endl;
            break;
        }
        outputBQ.push(pjcCommon::Event());
    }

    std::thread View::run(pjcUtil::BlockingQueue<pjcCommon::Event> &outputBQ,
                          pjcUtil::BlockingQueue<pjcCommon::Event> &inputBQ) {
        return std::thread(&View::start, View(outputBQ, inputBQ));
    }
}
