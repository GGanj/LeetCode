#include <string>
#include <unordered_map>

class Solution1 {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> myMap;
        int maxSize = 0;
        int left = 0;
        for(int i = 0; i < s.size(); i++) {
            if(myMap.find(s[i]) != myMap.end()) {
                for(; left <= myMap[s[i]]; ++left) {
                    myMap.erase(s[left]);
                }
            }
            myMap[s[i]] = i;
            if(myMap.size() > maxSize) {
                maxSize = myMap.size();
            }
        }
        return maxSize;
    }
};

class Solution2 {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> window;

        int leftFlag = 0, rightFlag = 0;
        int res = 0; // 记录结果
        while (rightFlag < s.size()) {
            char rightChar = s[rightFlag];
            rightFlag++;
            // 进行窗口内数据的一系列更新
            window[rightChar]++;
            // 判断左侧窗口是否要收缩
            while (window[rightChar] > 1) {
                char leftChar = s[leftFlag];
                leftFlag++;
                // 进行窗口内数据的一系列更新
                window[leftChar]--;
            }
            // 在这里更新答案
            res = res > (rightFlag - leftFlag) ? res : (rightFlag - leftFlag);
        }
        return res;
    }
};