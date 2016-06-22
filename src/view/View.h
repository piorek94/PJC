//
// Created by przemek on 22.06.16.
//

#ifndef PJC_VIEW_H
#define PJC_VIEW_H

#include <thread>
#include "src/common/Event.h"
#include "src/util/BlockingQueue.h"

namespace pjcView {

    /**
     * View facade class
     */
    class View {
    public:
        static std::thread run(pjcUtil::BlockingQueue<pjcCommon::Event> &outputBQ,
                               pjcUtil::BlockingQueue<pjcCommon::Event> &inputBQ);

    private:
        View(pjcUtil::BlockingQueue<pjcCommon::Event> &outputBQ, pjcUtil::BlockingQueue<pjcCommon::Event> &inputBQ);
        void start();
        pjcUtil::BlockingQueue<pjcCommon::Event> &outputBQ;
        pjcUtil::BlockingQueue<pjcCommon::Event> &inputBQ;
    };

}


#endif //PJC_VIEW_H
