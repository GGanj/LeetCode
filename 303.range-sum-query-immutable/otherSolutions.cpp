#include <vector>

class NumArray1 {
public:
    std::vector<int> numArr;
    NumArray1(std::vector<int>& nums) {
        for(int i : nums) {
            numArr.push_back(i);
        }
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        for(int i = left; i <= right; ++i) {
            sum += numArr[i];
        }
        return sum;
    }
};