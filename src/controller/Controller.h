//
// Created by przemek on 22.06.16.
//

#ifndef PJC_CONTROLLER_H
#define PJC_CONTROLLER_H

#include "src/common/Event.h"
#include "src/model/Model.h"
#include "src/view/View.h"
#include "src/util/BlockingQueue.h"

namespace pjcController {

    /**
     * Controller facade class
     */
    class Controller {
    public:
        Controller(pjcUtil::BlockingQueue<pjcCommon::Event> &outputBQ,
                   pjcUtil::BlockingQueue<pjcCommon::Event> &inputBQ,
                   pjcModel::Model &model);
        void start();

    private:
        pjcUtil::BlockingQueue<pjcCommon::Event> &outputBQ;
        pjcUtil::BlockingQueue<pjcCommon::Event> &inputBQ;
        pjcModel::Model &model;
    };

}

#endif //PJC_CONTROLLER_H
