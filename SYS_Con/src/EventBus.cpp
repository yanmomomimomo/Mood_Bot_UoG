#include "EventBus.hpp"

void EventBus::subscribe(const std::string& topic, Handler h){
    std::lock_guard<std::mutex> lk(mutex_);
    handlers_[topic].push_back(std::move(h));
}

void EventBus::publish(const std::string& topic, int value) {
    std::lock_guard<std::mutex> lock(mutex_);
    if (handlers_.count(topic)) {
        for (auto& h : handlers_[topic]) {
            h(value); 
        }
    }
}