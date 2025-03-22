#include "library.hpp"
#include <vector>
#include <deque>

namespace template_library {
    int josephus_problem(const std::vector<int>& nums, int k) {
        if (nums.empty()) {
            return -1;
        }

        std::deque<int> deque(nums.begin(), nums.end());

        while (deque.size() > 1) {
            
            int steps = (k - 1) % deque.size();
            for (int i = 0; i < steps; ++i) {
                deque.push_back(deque.front());
                deque.pop_front();
            }
            deque.pop_front();
        }
        return deque.front();
    }
}