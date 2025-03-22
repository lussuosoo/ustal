#include "library.hpp"
#include <map>
#include <queue>
#include <string>
#include <utility>

namespace template_library {

    void EventScheduler::add_event(int time, const std::string& event) {
        events[time] = event;
        time_queue.push(time);
    }

    std::string EventScheduler::process_next() {
        if (time_queue.empty()) {
            return "";
        }

        
        int next_time = time_queue.top();
        time_queue.pop();


        auto it = events.find(next_time);
        if (it != events.end()) {
            std::string event = it->second;
            events.erase(it);
            return event;
        }

        return "";
    }

}