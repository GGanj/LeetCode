#include <vector>

class Solution1 {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        std::vector<int>::iterator iter = nums.begin();
        int preInt = INT_MAX, res = 0;
        while(iter != nums.end()) {
            if(*iter != preInt) {
                preInt = *iter;
                ++res;
                ++iter;
                continue;
            }
            nums.erase(iter);
        }

        return res;
    }
};

// fast than solution 1
class Solution2 {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) {
            return nums.size();
        }
        int i = 0, j = 1, res = 1;
        while(j < nums.size()) {
            if(nums[i] == nums[j]) {
                ++j;
                continue;
            }
            ++i;
            nums[i] = nums[j];
            ++j;
            ++res;
        }

        return res;
    }
};