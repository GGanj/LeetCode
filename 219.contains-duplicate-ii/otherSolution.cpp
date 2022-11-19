#include <vector>
#include <unordered_map>

class Solution1 {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> traces;
        for(int i = 0; i < nums.size(); ++i) {
            if(traces.find(nums[i]) != traces.end() && (i - traces[nums[i]] <= k)) {
                return true;
            } else {
                traces[nums[i]] = i;
            }
        }
        return false;

    }
};

class Solution2 {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        int left = 0, right = 0;
        std::unordered_map<int, int> traces;
        while(right <= k && right < nums.size()) {
            if(traces[nums[right]]) {
                return true;
            }else {
                ++traces[nums[right]];
                ++right;
            }
        }
        while(right < nums.size()) {
            traces.erase(nums[left]);
            ++left;
            if(traces[nums[right]]) {
                return true;
            }else {
                ++traces[nums[right]];
                ++right;
            }
        }
        return false;
    }
};