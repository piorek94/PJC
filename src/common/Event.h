//
// Created by przemek on 22.06.16.
//

#ifndef PJC_EVENT_H
#define PJC_EVENT_H

#include <string>

namespace pjcCommon {

    /**
     * Base class representing application event
     */
    class Event {
    private:

    public:
        Event() = default;
        std::string getName() const;
        ~Event() = default;
    };
}

#endif //PJC_EVENT_H
