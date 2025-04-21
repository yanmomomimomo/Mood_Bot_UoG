#ifndef EVENTBUS_HPP
#define EVENTBUS_HPP

#include <unordered_map>
#include <vector>
#include <functional>
#include <string>
#include <mutex>
#include <iostream>

class EventBus {
public:
    using Handler = std::function<void(int)>;

    void subscribe(const std::string& topic, Handler h);
    void publish(const std::string& topic, int value = 1) ;

private:
    std::unordered_map<std::string,std::vector<Handler>> handlers_;
    std::mutex mutex_;
};

#endif // EVENTBUS_HPP
