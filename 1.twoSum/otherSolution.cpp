#include <iostream>
#include <vector>
#include <map>

class Solution1 {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if( (nums[i] + nums[j]) == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

class Solution2 {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::map<int, int> myMap;
        for(int i = 0; i < nums.size(); i++) {
            myMap[nums[i]] = i;
        }
        for(int i = 0 ; i < nums.size(); i++) {
           std::map<int, int>::iterator res =  myMap.find(target - nums[i]);
           if(res != myMap.end() && i != res->second) {
               return {i, res->second};
           }
        }
        return {};
    }
};

class Solution3 {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::map<int, int> myMap;
        for(int i = 0; i < nums.size(); ++i) {
             std::map<int, int>::iterator res =  myMap.find(target - nums[i]);
             if(res != myMap.end()) {
                 return {res->second, i};
             }
             myMap[nums[i]] = i;
        }
        return {};
    }
};