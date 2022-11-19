#include <string>
#include <vector>
#include <unordered_map>
class Solution1 {
public:
    int strStr(std::string haystack, std::string needle) {
        std::string::iterator nIter = needle.begin(), hIter = haystack.begin();
        int n = haystack.find(needle);
        return n;
    }
};

class Solution2 {
public:
    int dp[255][255] = {0};
    int strStr(std::string haystack, std::string needle) {
        kmp(needle);
        int hLength = haystack.size(), nLength = needle.size();
        int needleState = 0;
        for(int i = 0; i < hLength; ++i) {
            needleState = dp[needleState][haystack[i]];
            if(needleState == nLength) {
                return i - nLength + 1;
            }
        }
        return -1;
    }

    void kmp(std::string pat) {
        int patLength = pat.size();
        int prefix = 0;
        dp[0][pat[0]] = 1;
        for(int i = 1; i < pat.length(); ++i) {
            for(int j = 0; j < 255; ++j) {
                dp[i][j] = dp[prefix][j];
            }
            dp[i][pat[i]] = i + 1;
            prefix= dp[prefix][pat[i]];
        }
    }
};

class Solution3 {
public:
    std::vector<std::unordered_map<char, int>> dp;
    int strStr(std::string haystack, std::string needle) {
        kmp(needle);
        int hLength = haystack.size(), nLength = needle.size();
        int needleState = 0;
        for(int i = 0; i < hLength; ++i) {
            if(dp[needleState].find(haystack[i]) == dp[needleState].end()) {
                needleState = 0;
                continue;
            }
            needleState = dp[needleState][haystack[i]];
            if(needleState == nLength) {
                return i - nLength + 1;
            }
        }
        return -1;
    }

    void kmp(std::string pat) {
        int patLength = pat.size();
        int prefix = 0;
        std::unordered_map<char, int> stateBegin;
        stateBegin[pat[0]] = 1;
        dp.push_back(stateBegin);
        for(int i = 1; i < pat.length(); ++i) {
            std::unordered_map<char, int> newState = dp[prefix];
            newState[pat[i]] = i + 1;
            dp.push_back(newState);
            prefix= dp[prefix][pat[i]];
        }
    }
};