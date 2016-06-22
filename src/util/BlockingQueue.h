//
// Created by przemek on 22.06.16.
//

#ifndef PJC_BLOCKINGQUEUE_H
#define PJC_BLOCKINGQUEUE_H

#include <mutex>
#include <queue>
#include <condition_variable>

namespace pjcUtil {

    template<typename T>
    class BlockingQueue {
    private:
        std::queue<T> queue;
        std::mutex mutex;
        std::condition_variable conditionVariable;

    public:
        BlockingQueue() = default;
        BlockingQueue(const BlockingQueue& other) = delete;
        BlockingQueue& operator=(const BlockingQueue& other) = delete;

        void push(T& value) {
            std::unique_lock<std::mutex> lock(mutex);
            queue.push(value);
            lock.unlock();
            conditionVariable.notify_one();
        }

        void push(T&& rvalue) {
            std::unique_lock<std::mutex> lock(mutex);
            queue.push(std::move(rvalue));
            lock.unlock();
            conditionVariable.notify_one();
        }

        T pop() {
            std::unique_lock<std::mutex> lock(mutex);
            if (queue.empty()) {
                conditionVariable.wait(lock);
            }
            auto value = queue.front();
            queue.pop();
            return value;
        }
    };

}

#endif //PJC_BLOCKINGQUEUE_H
