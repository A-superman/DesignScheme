#include <iostream>
#include <memory>
#include <mutex>
#include <queue>
#include <thread>
#include <chrono>

// eager(饿汉)pattern
#if 0
class TaskQueue {
public:
    TaskQueue(const TaskQueue&) = delete;
    TaskQueue& operator=(const TaskQueue&) = delete;
    static TaskQueue& getinstance() {
        return taskqueue_;
    }
private:
    TaskQueue() = default;
    static TaskQueue taskqueue_;
};
TaskQueue TaskQueue::taskqueue_ ; 
#endif
// lazy(懒汉)pattern
#if 0
class TaskQueue {
public:
    TaskQueue(const TaskQueue&) = delete;
    TaskQueue& operator=(const TaskQueue&) = delete;
    static TaskQueue& getinstance() {
         static TaskQueue taskqueue_;
        return taskqueue_;
    }
private:
    TaskQueue() = default;
};
#endif

// lazy(懒汉)pattern实现一个消息队列
class TaskQueue {
public:
    TaskQueue(const TaskQueue&) = delete;
    TaskQueue& operator=(const TaskQueue&) = delete;
    static TaskQueue& getinstance() {
         static TaskQueue taskqueue_;
        return taskqueue_;
    }
    void put(int task) {
        std::lock_guard<std::mutex> lock(mut);
        task_q.push(task);
        std::cout << "添加一个任务：" << task << std::endl;
    }
    int get() {
        int task = -1;
        if(!task_q.empty()) {
            std::lock_guard<std::mutex> lock(mut);
            task = task_q.front();
            task_q.pop();
        }
        if(task != -1) {
            std::cout << "取出一个任务：" << task << std::endl;
        } else {
            std::cout << "取出任务失败" << std::endl;
        }
        return task;
    }
    int getsize() {
        return task_q.size();
    }
private:
    TaskQueue() = default;
    std::queue<int> task_q;
    std::mutex mut;
};

int main() {
    TaskQueue& taskqueue = TaskQueue::getinstance();
    std::thread putTask([&](){
        for(int i = 0; i < 100; ++i) {
            taskqueue.put(i);
            std::this_thread::sleep_for(std::chrono::seconds(10));
        }
    });
    std::thread getTask([&](){
        while(true) {
            taskqueue.get();
            std::this_thread::sleep_for(std::chrono::seconds(10));
            std::cout << "任务数量：" << taskqueue.getsize() << std::endl;
        }
    });
    putTask.join();
    getTask.join();
    return 0;
}
