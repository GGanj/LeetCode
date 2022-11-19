#include <vector>
#include <string>

class Solution1 {
public:
    std::vector<std::string> keys = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    std::vector<std::string> res;
    std::vector<std::string> letterCombinations(std::string digits) {
        if(digits.size() == 0) {
            return {};
        }
        backTrack(digits, 0, "");
        return res;
    }

    void backTrack(std::string digits, int index, std::string subStr) {
        if(subStr.size() == digits.size()) {
            res.push_back(subStr);
            return;
        }
        for(;index < digits.size(); ++index) {
            int digit = digits[index] - '0' - 2;
            std::string::iterator iter;
            for(iter = keys[digit].begin(); iter < keys[digit].end(); ++iter) {
                subStr += *iter;
                backTrack(digits, index + 1, subStr);
                subStr.pop_back();
            }
        }
    }
};

class Solution2 {
public:
    std::vector<std::string> keys = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    std::vector<std::string> res;
    std::vector<std::string> letterCombinations(std::string digits) {
        if(digits.size() == 0) {
            return {};
        }
        backTrack(digits, 0, "");
        return res;
    }

    void backTrack(std::string digits, int index, std::string subStr) {
        if(index == digits.size()) {
            res.push_back(subStr);
            return;
        }
        for(;index < digits.size(); ++index) {
            if(index != subStr.size()) {
                return;
            }
            int digit = digits[index] - '0' - 2;
            std::string::iterator iter;
            for(iter = keys[digit].begin(); iter < keys[digit].end(); ++iter) {
                subStr += *iter;
                backTrack(digits, index + 1, subStr);
                subStr.pop_back();
            }
        }
    }
};